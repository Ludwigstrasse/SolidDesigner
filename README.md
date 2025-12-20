# SolidDesigner

**An open‑source platform for parametric CAD, high‑fidelity CAE, and topology optimization — with simulation‑driven design and AI assistance.**

> Goal: a professional‑grade system comparable to Creo Parametric that supports solid/surface modeling, assembly, drafting, structural mechanics, CFD, multiphysics, and optimization — where simulations can drive the design itself.

---

## Quick Links

- **JIRA Board**: https://hananiah.atlassian.net/jira/software/c/projects/AL/boards/3
- **Public Wiki (GitHub)**: https://github.com/hananiahhsu/SolidDesignerWiki
- **Design Wiki (Confluence, access required)**: https://hananiah.atlassian.net/wiki/spaces/~5e2301040f45160ca25e42e3/overview?homepageId=65963

---

## Table of Contents

- [Vision & Scope](#vision--scope)
- [What’s in the Box](#whats-in-the-box)
- [Project Layout & Architecture](#project-layout--architecture)
- [Core Concepts](#core-concepts)
- [Capabilities](#capabilities)
- [Roadmap](#roadmap)
- [Build & Run](#build--run)
- [Dependencies](#dependencies)
- [Getting Started](#getting-started)
- [Plugin & Scripting](#plugin--scripting)
- [Data & File Formats](#data--file-formats)
- [Diagnostics, Logging & QA](#diagnostics-logging--qa)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)
- [FAQ](#faq)

---

## Vision & Scope

SolidDesigner aims to be a **full‑stack, engineering‑grade** CAD/CAE platform:

- **Parametric CAD**: robust part/assembly modeling, sketches/constraints, history‑based features, and drafting.
- **CAE**: built‑in solvers and/or adapters for **structural mechanics (FEA)**, **fluid dynamics (CFD)**, **multiphysics**.
- **Optimization**: **topology/shape/size** optimization; reinforcement/weight reduction; simulation‑driven design loops.
- **AI Assistance**: an engineering “copilot” for constraint inference, feature intent detection, design space exploration, and solver configuration suggestions.
- **Extensibility**: modular architecture with a stable plugin and scripting API.

> **Status**: Active development (pre‑alpha). APIs and file formats may change.

---

## What’s in the Box

- A modern C++17/20 codebase with a **foundation submodule (“Alice”)**.
- A **desktop application** (“SolidDesigner”) built on the foundation.
- A clean separation between **Core/Data/Interaction/UI** layers.
- Early implementations of the **feature graph**, **parametric constraints**, **diagnostics/logging**, and **plugin hosting**.
- A long‑term plan for **CAE solvers** (FEA/CFD) and **optimization**.

---

## Project Layout & Architecture

**Physical Structure**

```
Physical Structure
    |
    |----- Alice  (submodule)
    |         |
    |         |---- Bootstrap
    |         |---- Core
    |         |---- Data
    |         |---- Interaction
    |         |---- UI
    |
    |----- SolidDesigner  (application)
              |
              |-- APP
              |-- DATA
              |-- Interaction
              |-- UI
              |-- Plugins
```

### Layered Architecture (high‑level)

- **Alice/Core** — platform primitives, base utilities (memory, threading, diagnostics, math, units, geometry abstractions).
- **Alice/Data** — parametric model, feature/operation graph, constraint & dimension system, document/session services.
- **Alice/Interaction** — selection/picking, manipulators, command pipeline, undo/redo transactions, interaction graph.
- **Alice/UI** — Qt‑based (planned) shell, dockable panes, property browser, ribbon/menus/shortcuts.
- **SolidDesigner/APP** — the product layer: application lifecycle, persistence, project/workspace, plugins, scripting.
- **SolidDesigner/DATA/Interaction/UI** — product‑specific extensions over Alice layers.

> The **Alice** submodule is intentionally reusable and engine‑like; **SolidDesigner** composes it into a complete product.

---

## Core Concepts

- **Feature Graph**: All modeling operations (Sketch, Extrude, Revolve, Fillet, Pattern, Boolean, etc.) are nodes in a directed acyclic graph with **history & dependencies**. Rebuilds propagate deterministically.
- **Constraint System**: Geometric and dimensional constraints with solver back‑ends (sketch constraints today; 3D constraints planned).
- **Parametric Design**: Named parameters (dims, materials, BCs) can drive both geometry and analysis; supports expressions and units.
- **Simulation‑Driven Design**: Analyses evaluate candidate designs; results feed back to parameters (e.g., automate weight reduction to meet stress targets).
- **Multi‑representation Geometry**: Solid/surface/B‑Rep abstractions with tolerances; mesh generation for analysis; CAD↔CAE consistency.
- **Transactions**: Every command runs inside a transaction; full undo/redo; meaningful error messages via diagnostics engine.

---

## Capabilities

### CAD (current/planned)

- Sketching with constraints and dimensions
- History‑based modeling: extrude/revolve/sweep/loft, fillet/chamfer, shell, pattern, boolean ops
- Assembly: mates/constraints; top‑down context (WIP)
- Drafting: views, sections, dimensions, GD&T (planned)

### CAE (current/planned)

- **Structural (FEA)**: linear static, modal; material library; boundary conditions; mesh controls (planned iterative expansion)
- **CFD**: incompressible flows (steady/transient); turbulence models; boundary conditions (planned)
- **Multiphysics**: thermal‑structural, FSI (long‑term)

### Optimization (planned)

- Topology optimization (SIMP/level‑set)
- Shape/size optimization; constraints (stress, displacement, frequency, pressure drop, etc.)
- Design space exploration; surrogate modeling

### AI Assistance (planned)

- Constraint/feature intent inference from user actions
- Command autocompletion; parameter suggestions
- Design space recommendation; automatic DOE
- Solver setup & meshing suggestions based on context

> See **[Roadmap](#roadmap)** and **JIRA** for item‑level progress.

---

## Roadmap

Planning and backlog are tracked in **JIRA**:  
https://hananiah.atlassian.net/jira/software/c/projects/AL/boards/3

High‑level milestones (subject to change):

1. **P0 — Modeling Foundations**: stable feature graph, robust sketcher, core modeling ops, transaction system, persistence.
2. **P1 — Meshing & FEA MVP**: tet/hex mesh pipeline; linear static/modal; basic post‑processing.
3. **P2 — CFD MVP**: mesh & solver integration for incompressible flows; pressure/velocity/temperature fields; post‑processing.
4. **P3 — Optimization**: SIMP topology optimization; closed‑loop parameter updates; constraint handling.
5. **P4 — AI Copilot v1**: constraint inference, command suggestions, solver presets; learning from project history.

Detailed design docs live in **Confluence** (access required). A public subset lives in the **GitHub Wiki**.

---

## Build & Run

### Prerequisites (indicative)

- **CMake ≥ 3.22**
- **C++17/20** toolchain (MSVC v143, Clang 15+, or GCC 11+)
- **Qt 5 (for UI; planned/optional if building headless tools)
- **Eigen** (math), **fmt**, **spdlog**
- **OpenCascade (OCC)** for B‑Rep (primary geometry backend; alternatives pluggable in future)
- **(Optional)** VTK/OCCT visualization, CGAL/Gmsh/TetGen for meshing, OpenMP/TBB for parallelism, CUDA for GPU paths

> Exact versions and options may evolve; consult JIRA/Wiki for up‑to‑date build notes.

### Get the source

```bash
git clone --recurse-submodules https://github.com/hananiahhsu/SolidDesigner.git
cd SolidDesigner
# If you forgot --recurse-submodules
git submodule update --init --recursive
```

### Windows (MSVC, x64)

```bash
cmake -S . -B build -G "Visual Studio 17 2022" -A x64 ^
  -DCMAKE_INSTALL_PREFIX=%CD%/install ^
  -DSD_WITH_QT=ON ^
  -DSD_WITH_OCC=ON

cmake --build build --config Release --parallel
cmake --install build --config Release
```

### Linux (GCC/Clang + Ninja)

```bash
cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=$PWD/install \
  -DSD_WITH_QT=ON \
  -DSD_WITH_OCC=ON

cmake --build build --parallel
cmake --install build
**Headless/CI builds**: If you don't have Qt available, disable the GUI target with `-DSD_BUILD_DESIGNER=OFF`.
```

Run the app (paths may differ):

```bash
# Windows
install/bin/SolidDesigner.exe

# Linux
./install/bin/SolidDesigner
```

---

## Dependencies

This project is **modular**: most third‑party libraries are optional or pluggable.

- **Geometry**: OpenCascade (default); abstractions allow future kernels
- **Math**: Eigen
- **I/O**: fmt
- **Logging**: spdlog (backend), unified diagnostics facade in “Alice”
- **UI**: Qt 6 (widgets/QtQuick — TBD)
- **Meshing**: OCCT mesher, Gmsh, TetGen (adapters planned)
- **Solvers**: in‑house FEA/CFD; adapters to external solvers (future)
- **Visualization**: OCCT/VTK (planned)

Use `-DSD_WITH_<LIB>=ON/OFF` CMake options (see `CMakeLists.txt`) to toggle modules.

---

## Getting Started

A typical workflow target (end state):

1. **Create a project** and set default units/tolerances.
2. **Sketch** on a plane; use constraints/dimensions.
3. Create features: **Extrude**, **Revolve**, **Fillet**, **Shell**, **Pattern**…
4. **Assemble** parts; add mates/constraints.
5. **Mesh** the model (global + local controls).
6. Define **materials** and **boundary conditions**.
7. Run **FEA/CFD**; inspect stress/strain, modes, flow fields.
8. **Drive parameters** from results (e.g., reduce thickness until stress ≤ target).
9. Save as a **project** and export **STEP/IGES** or mesh files.

---

## Plugin & Scripting

- **Plugin ABI**: clean C++ interfaces for geometry ops, meshing, solvers, importers/exporters, and UI add‑ins.
- **Isolation**: stable ownership model and cross‑DLL safety (foundation provides Owning/Weak/Guard pointer utilities).
- **Scripting (planned)**: Python API to automate modeling, set up studies, post‑process results, and orchestrate design loops.
- **AI hooks (planned)**: register custom design advisors and ML models for intent prediction and optimization.

---

## Data & File Formats

### Native project format (in progress)

The native format is intended to be:

- **Structured**: metadata + typed payloads (geometry, mesh, results, thumbnails, etc.)
- **Versioned**: schema versioning with explicit upgrade pipeline
- **Incremental-friendly**: designed for partial reload and future cloud/workspace workflows
- **Stable-identity aware**: object IDs survive save/load, copy/paste, and upgrades

> The public wiki will host the canonical specification once the format stabilizes.

### Interoperability (planned / incremental)

- **CAD Interop**: STEP/IGES import/export (others via adapters)
- **Mesh/Results**: standard mesh/results formats for external solvers/post (VTK, MED, etc., planned)
- **Units**: consistent unit system with explicit metadata; dimensioned parameters in expressions

---

## Diagnostics, Logging & QA

- Unified **DiagnosticsEngine** with severity levels, source locations, and pluggable sinks (console, file, UI panel).
- Optional **spdlog** backend for fast, thread‑aware logging.
- **Assertions** and **defensive checks** across DLL boundaries.
- **Testing** via CTest; fixtures for geometry, meshing, solver correctness; reproducible cases attached to JIRA.

---

## Contributing

Contributions are welcome.

- Review JIRA epics/tasks and the GitHub Wiki for context.
- Discuss larger proposals before opening a PR.
- Follow the project’s code style (clang-format file planned) and include unit tests.
- Keep commits small and well-described; link to JIRA tickets where applicable.

Suggested first contributions:

- Fix build issues on a specific platform/compiler
- Add focused tests (geometry, persistence, constraint solving)
- Add documentation: design notes, diagrams, or minimal “how it works” sections

> Repository-level contributor docs (planned): `CONTRIBUTING.md`, `CODE_OF_CONDUCT.md`.

---

## License

This repository is licensed under **GNU GPL v3.0**. See `LICENSE` for the full text.

> Note: third‑party libraries may have their own licenses; ensure compliance when redistributing binaries.

---

## Acknowledgments

This project stands on the shoulders of giants: OpenCascade, Eigen, fmt, spdlog, Qt, and the broader open‑source community.  
Special thanks to contributors and researchers in CAD/CAE/CFD/optimization.

---

## FAQ

**How close is this to production tools like Creo?**  
The aspiration is parity for core workflows with a modern, open architecture. Today the project is pre‑alpha; many capabilities are WIP.

**Is there a scripting API?**  
A Python API is planned. Early internal scaffolding exists; public API is forthcoming.

**Which solver stack is used?**  
Early in‑house solvers are being prototyped. Adapters to external solvers (e.g., meshers/post) are planned.

**Will AI features require internet access?**  
No. The intent is to support offline inference with local models, with optional cloud integrations.

**Where can I track progress?**  
JIRA (roadmap/backlog) and the public GitHub wiki. Detailed design docs are in Confluence (access required).
