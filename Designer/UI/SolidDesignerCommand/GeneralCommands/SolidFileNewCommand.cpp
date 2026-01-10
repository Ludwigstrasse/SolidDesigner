#include "SolidFileNewCommand.h"
#include "AliceIOperation.h"
#include "SolidDesignerCommands.h"
#include "AliceIDocumentManager.h"
#include "AliceIMainWindow.h"
#include "AliceCommandParameter.h"
#include "AliceCoreAppUtil.h"
#include "AliceISession.h"
#include "AliceDiagnosticMacro.h"

using namespace alice;
using namespace sdr;

SolidFileNewCommand::~SolidFileNewCommand()
{

}

SolidFileNewCommand::SolidFileNewCommand() noexcept
	: AppCommandBase(std::string(Cmd::FILE_NEW))
{

}

std::string SolidFileNewCommand::DisabledReason() const
{
	return std::string();
}

bool SolidFileNewCommand::IsEnabled() const
{
	return true;
}

bool SolidFileNewCommand::IsVisible() const
{
	return true;
}

bool SolidFileNewCommand::IsSupported() const
{
	return true;
}

std::unique_ptr<alice::IOperation> SolidFileNewCommand::Execute(const alice::CommandParameter& param)
{
	ISession* pSession = CoreAppUtil::GetCurrentSession();
	DIAG_RETURN_NULL_IF_FALSE(pSession, "pSession is null", "hananiah", "2025.12.25");

	// 此处弹出creo 风格的新建对话框，选择文档类型，填写文档名称,Common Name
	std::wstring strFileName;


	IDocument* pDoc = pSession->CreateDocument(strFileName);
	DIAG_RETURN_NULL_IF_FALSE(pDoc, "pDoc is null", "hananiah", "2025.12.25");

	// 新建文档之后，Alice平台层中如何切换WorkBench
	// 不同的文档对应不同的workbench

	return nullptr;
}
