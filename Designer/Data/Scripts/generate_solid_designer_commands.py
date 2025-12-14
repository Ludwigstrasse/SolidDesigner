#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#Author: Yoichiro Nambu
#Date: 2025.12.12
"""
Generate SolidDesignerCommands.h from CommandsConfig.xml

Usage:
    python generate_solid_designer_commands.py \
        --xml  path/to/CommandsConfig.xml \
        --out  path/to/SolidDesignerCommands.h
"""

import argparse
import sys
import textwrap
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from pathlib import Path
from typing import List, Dict, Set

print("[DEBUG] argv:", sys.argv)

@dataclass
class CommandSpec:
    id: str
    label: str
    category: str


def parse_commands(xml_path: Path) -> List[CommandSpec]:
    """
    Parse CommandsConfig.xml and return a flat list of CommandSpec.
    """
    try:
        tree = ET.parse(str(xml_path))
    except ET.ParseError as e:
        print(f"[ERROR] Failed to parse XML '{xml_path}': {e}", file=sys.stderr)
        sys.exit(1)

    root = tree.getroot()

    # 兼容两种写法：<CommandsConfig> 或 <commands>
    commands_nodes = []
    if root.tag.lower().endswith("commandsconfig"):
        commands_nodes = root.findall(".//commands/command")
    else:
        commands_nodes = root.findall(".//command")

    specs: List[CommandSpec] = []

    for elem in commands_nodes:
        cid = elem.get("id")
        if not cid:
            continue
        label = elem.get("label", "")
        category = elem.get("category", "")

        specs.append(CommandSpec(id=cid.strip(),
                                 label=label.strip(),
                                 category=category.strip()))

    if not specs:
        print(f"[WARN] No <command> elements found in '{xml_path}'", file=sys.stderr)

    # 检查重复 id
    seen_ids: Set[str] = set()
    duplicates: Set[str] = set()
    for c in specs:
        if c.id in seen_ids:
            duplicates.add(c.id)
        seen_ids.add(c.id)
    if duplicates:
        print("[ERROR] Duplicate command id(s) detected:", file=sys.stderr)
        for d in sorted(duplicates):
            print(f"  - {d}", file=sys.stderr)
        sys.exit(1)

    # 排序：按 id 排一下，保证生成文件稳定
    specs.sort(key=lambda c: c.id)
    return specs


def id_to_const_name(cmd_id: str) -> str:
    """
    Convert 'file.save' -> 'FILE_SAVE'
    """
    result_chars = []
    for ch in cmd_id:
        if ch.isalnum():
            result_chars.append(ch.upper())
        else:
            # '.' '-' ' ' 等全部归一成 '_'
            result_chars.append('_')
    name = "".join(result_chars)

    # 去掉重复的 '_'（比如 ".."）
    # 連続する '_' を除去（例：".."）
    while "__" in name:
        name = name.replace("__", "_")

    # 去掉头尾 '_'
    # 先頭・末尾の '_' を削除
    name = name.strip("_")

    # 如果第一个字符是数字，前面加前缀
    # 先頭が数字の場合は接頭辞を付与
    if name and name[0].isdigit():
        name = "CMD_" + name

    if not name:
        raise ValueError(f"Cannot convert command id '{cmd_id}' to a valid C++ name")

    return name


def generate_header(specs: List[CommandSpec],
                    out_path: Path,
                    namespace_root: str = "sdr",
                    namespace_leaf: str = "Cmd") -> None:
    """
    Generate SolidDesignerCommands.h into out_path.
    """
    # 检查常量名是否冲突
    # 定数名の衝突をチェック
    const_map: Dict[str, CommandSpec] = {}
    collisions: Dict[str, List[str]] = {}

    for c in specs:
        const_name = id_to_const_name(c.id)
        if const_name in const_map:
            collisions.setdefault(const_name, []).append(c.id)
        else:
            const_map[const_name] = c

    if collisions:
        print("[ERROR] Different command ids mapped to the same C++ name:", file=sys.stderr)
        for cname, ids in collisions.items():
            all_ids = [const_map[cname].id] + ids
            print(f"  {cname}: {', '.join(all_ids)}", file=sys.stderr)
        sys.exit(1)

    lines: List[str] = []

    lines.extend(
        [
            "// -----------------------------------------------------------------------------",
            "//  SolidDesignerCommands.h",
            "//",
            "//  AUTO-GENERATED FILE. DO NOT EDIT BY HAND.",
            "//",
            "//  Generated from: CommandsConfig.xml",
            "// -----------------------------------------------------------------------------",
            "",
            "#pragma once",
            "#include <string_view>",
            "",
            f"namespace {namespace_root}",
            "{",
            f"    namespace {namespace_leaf}",
            "    {",
            "        // NOTE:",
            "        //   - Each constant is a std::string_view to the command id as defined",
            "        //     in CommandsConfig.xml.",
            "        //   - Use these constants in ICommand::Id() implementations, Ribbon/Menu",
            "        //     bindings, etc. Never hard-code string literals like \"file.save\".",
            "",
        ]
    )

    # 按 category 分组输出，便于阅读
    # category ごとにグループ化して出力（可読性向上）
    by_category: Dict[str, List[CommandSpec]] = {}
    for c in specs:
        cat = c.category or "uncategorized"
        by_category.setdefault(cat, []).append(c)

    for cat in sorted(by_category.keys()):
        lines.append(f"        // === Category: {cat} ===")
        for c in by_category[cat]:
            const_name = id_to_const_name(c.id)

            # label 作为注释
            # label をコメントとして付与
            label_comment = f" // {c.label}" if c.label else ""
            lines.append(
                f'        inline constexpr std::string_view {const_name:<30} = "{c.id}";{label_comment}'
            )
        lines.append("")

    lines.extend(
        [
            "    }} // namespace {0}".format(namespace_leaf),
            "}} // namespace {0}".format(namespace_root),
            "",
        ]
    )

    out_path.write_text("\n".join(lines), encoding="utf-8")
    print(f"[INFO] Generated {out_path} ({len(specs)} commands).")


def main(argv: List[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Generate SolidDesignerCommands.h from CommandsConfig.xml"
    )
    parser.add_argument("--xml", required=True, help="Path to CommandsConfig.xml")
    parser.add_argument("--out", required=True, help="Path to SolidDesignerCommands.h")
    parser.add_argument(
        "--namespace-root", default="sdr", help="Root namespace (default: sdr)"
    )
    parser.add_argument(
        "--namespace-leaf", default="Cmd", help="Leaf namespace (default: Cmd)"
    )

    args = parser.parse_args(argv)

    xml_path = Path(args.xml).resolve()
    out_path = Path(args.out).resolve()

    if not xml_path.is_file():
        print(f"[ERROR] XML file not found: {xml_path}", file=sys.stderr)
        return 1

    specs = parse_commands(xml_path)
    generate_header(
        specs,
        out_path,
        namespace_root=args.namespace_root,
        namespace_leaf=args.namespace_leaf,
    )
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
