#pragma once

#include "AliceObjectMacros.h"
#include "AliceIPluginComponent.h"
#include "AlicePluginExports.h"

namespace sdr
{
	class DemoPluginComponent final : public alice::IPluginComponent
	{
		ALICE_DECLARE_OBJECT_TYPE(DemoPluginComponent, IPluginComponent)
	public:
		~DemoPluginComponent() override;

		bool InitialiseEvent() override;
		void InitialisationFinishedEvent() override;
		void FinaliseEvent() override;
	};
}

ALICE_PLUGIN_EXPORT_INTERFACES(sdr::DemoPluginComponent, /*AbiMajorValue*/ 1, "Alice", "DemoPlugin", "Demo Plugin", "1.0.0");