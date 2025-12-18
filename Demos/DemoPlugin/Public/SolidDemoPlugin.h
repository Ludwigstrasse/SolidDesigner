#pragma once
#include "AliceMacroDefinitions.h"

#ifdef ALICE_DEMO_PLUGIN_HOME
#define ALICE_DEMO_PLUGIN_EXPORT DLL_EXPORT
#else
#define ALICE_DEMO_PLUGIN_EXPORT DLL_IMPORT
#endif


