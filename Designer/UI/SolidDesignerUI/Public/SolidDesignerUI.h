#pragma once
// 此头文件包含DLL导出的宏
#include "AliceMacroDefinitions.h"
#include <iostream>

#if defined(_WIN32)
#ifdef SOLID_DESIGNER_UI_HOME
#define SOLID_DESIGNER_UI_EXPORT DLL_EXPORT
#else
#define SOLID_DESIGNER_UI_EXPORT DLL_IMPORT
#endif
#else
#define SOLID_DESIGNER_UI_EXPORT __attribute__((visibility("default")))
#endif

#include "AliceGuidUtils.h"
namespace soliddesignerui
{
	extern const Guid MODULE_ID;
}



