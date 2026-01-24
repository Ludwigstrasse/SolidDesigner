#include "SolidFileNewCommand.h"
#include "AliceIOperation.h"
#include "SolidDesignerCommands.h"
#include "AliceIDocumentManager.h"
#include "AliceIMainWindow.h"
#include "AliceCommandParameter.h"
#include "AliceCoreAppUtil.h"
#include "AliceISession.h"
#include "AliceDiagnosticMacro.h"
#include "AliceIUiApplicationFactory.h"
#include "AliceIUiApplication.h"
#include "SolidNewFileDialog.h"
#include <QMainWindow>
#include "AliceIWorkBenchManager.h"

using namespace alice;
using namespace sdr;

namespace
{
    static IMainWindow* GetMainWindow()
    {
        IUiApplicationFactory* pAppFactory = IUiApplicationFactory::Get();
        if (!pAppFactory)
            return nullptr;
        IUiApplication* pApp = pAppFactory->GetUiApplication();
        if (!pApp)
            return nullptr;
        // AliceIUiApplication returns const IMainWindow*, but we need non-const methods.
        return const_cast<IMainWindow*>(pApp->GetMainWindow());
    }
}
SolidFileNewCommand::~SolidFileNewCommand()
{

}

SolidFileNewCommand::SolidFileNewCommand() noexcept
	: AppCommandBase(std::string(Cmd::FILE_NEW))
{

}

std::string SolidFileNewCommand::DisabledReason() const
{
    if (CoreAppUtil::GetCurrentSession() == nullptr)
        return "Session is not available.";

    ISession* session = CoreAppUtil::GetCurrentSession();
    if (session && session->GetDocumentManager() == nullptr)
        return "Document manager is not available.";

    if (GetMainWindow() == nullptr)
        return "Main window is not available.";
	return std::string();
}

bool SolidFileNewCommand::IsEnabled() const
{
    return IsSupported();
}

bool SolidFileNewCommand::IsVisible() const
{
    return IsSupported();
}

bool SolidFileNewCommand::IsSupported() const
{
    ISession* session = CoreAppUtil::GetCurrentSession();
    if (!session)
        return false;

    IDocumentManager* docMgr = session->GetDocumentManagerFw();
    if (!docMgr)
        return false;

    IMainWindow* pMainWindow = GetMainWindow();
    if (!pMainWindow)
        return false;

    return true;
}

std::unique_ptr<alice::IOperation> SolidFileNewCommand::Execute(const alice::CommandParameter& param)
{
	ISession* pSession = CoreAppUtil::GetCurrentSession();
	DIAG_RETURN_NULL_IF_FALSE(pSession, "pSession is null", "hananiah", "2025.12.25");

    IMainWindow* pMainWindow = GetMainWindow();
    DIAG_RETURN_NULL_IF_FALSE(pMainWindow, "pMainWindow is null", "hananiah", "2026.01.16");
	QMainWindow* pParent = pMainWindow->AsQMainWindow();

    SolidNewFileDialog::NewFileRequest oRequest;
    if (!SolidNewFileDialog::GetNewFileRequest(pParent, oRequest))
        return nullptr;

	IDocument* pDoc = pSession->CreateDocument(oRequest.kind, oRequest.name.toStdWString());
	DIAG_RETURN_NULL_IF_FALSE(pDoc, "Failed to create a new document", "hananiah", "2025.12.25");

    // Workbench switching: pick by document kind (ResolveWorkbenchByDocument).
    if (IWorkBenchManager* pWbMgr = pMainWindow->GetWorkbenchManager())
    {
        std::string wbId = pWbMgr->ResolveWorkbenchByDocument(pDoc);
        if (!wbId.empty())
            pWbMgr->ActivateWorkBench(wbId, pDoc);
        else
            pWbMgr->ActiveStartupWorkbench(pDoc);
    }

    // TODO: each document opens exactly one default 3D view.
    // MdiViewManagerQt::OpenPrimaryView replaces the pane content, so this call is idempotent.
    pMainWindow->OpenView("view.model3d", pDoc, oRequest.name.toStdWString());
	return nullptr;
}
