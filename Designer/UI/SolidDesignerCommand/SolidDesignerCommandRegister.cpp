#include "SolidDesignerCommandRegister.h"
#include "AliceDiagnosticMacro.h"
#include "AliceISession.h"
#include "AliceICommandRouter.h"
#include "AliceICommandRegistry.h"
#include "SolidDesignerCommandFactory.h"
#include "SolidDesignerCommand.h"
#include "AliceCoreAppUtil.h"

using namespace sdr;
using namespace alice;

bool SolidDesignerCommandRegister::RegisterCommands()
{
	ISession* pSession = CoreAppUtil::GetCurrentSession();
	DIAG_RETURN_FALSE_IF_FALSE(pSession, "pSession is null", "hananiah", "2025.11.2");

	const std::shared_ptr<alice::ICommandRouter>& pCmdRouter = pSession->GetCommandRouter();
	DIAG_RETURN_FALSE_IF_FALSE(pCmdRouter, "pCmdRouter is null", "hananiah", "2025.11.2");
	ICommandRegistry* pCmdRegistry = pCmdRouter->GetCommandRegistry();
	DIAG_RETURN_FALSE_IF_FALSE(pCmdRegistry, "pCmdRouter is null", "hananiah", "2025.11.2");

	SolidDesignerCommandFactory& oCmdFactory = SolidDesignerCommandFactory::GetInstance();
	std::vector<std::shared_ptr<alice::ICommand>> vecCommands = oCmdFactory.CreateCommands();
	for (const auto& pCmd : vecCommands)
	{
		pCmdRegistry->RegisterCommand(pCmd);
	}

	return true;
}

bool SolidDesignerCommandRegister::UnRegisterCommands()
{
	ISession* pSession = CoreAppUtil::GetCurrentSession();
	DIAG_RETURN_FALSE_IF_FALSE(pSession, "pSession is null", "hananiah", "2025.11.2");

	const std::shared_ptr<alice::ICommandRouter>& pCmdRouter = pSession->GetCommandRouter();
	DIAG_RETURN_FALSE_IF_FALSE(pCmdRouter, "pCmdRouter is null", "hananiah", "2025.11.2");

	ICommandRegistry* pCmdRegistry = pCmdRouter->GetCommandRegistry();
	DIAG_RETURN_FALSE_IF_FALSE(pCmdRegistry, "pCmdRouter is null", "hananiah", "2025.11.2");

	std::wstring strModuleId = GuidUtils::ToWString(soliddesignercommand::MODULE_ID);
	pCmdRegistry->UnRegisterCommandByModule(strModuleId);
	return true;
}

sdr::SolidDesignerCommandRegister& SolidDesignerCommandRegister::GetInstance()
{
	static SolidDesignerCommandRegister s_Instance;
	return s_Instance;
}

