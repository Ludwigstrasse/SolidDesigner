#include "SolidDemoPluginComponent.h"
#include <iostream>

using namespace sdr;

namespace
{
	void TestInit()
	{
		std::cout << "calling init..." << std::endl;
	}

	void TestInitialisationFinished()
	{
		std::cout << "calling init finish..." << std::endl;
	}

	void TestFinalize()
	{
		std::cout << "calling finalize..." << std::endl;
	}
}

ALICE_IMPL_CONCRETE_OBJECT_TYPE(DemoPluginComponent, "DemoPlugin")
sdr::DemoPluginComponent::~DemoPluginComponent()
{

}

bool DemoPluginComponent::InitialiseEvent()
{
	TestInit();
	return true;
}

void DemoPluginComponent::InitialisationFinishedEvent()
{
	TestInitialisationFinished();
}

void DemoPluginComponent::FinaliseEvent()
{
	TestFinalize();
}