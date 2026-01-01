#include "SolidBaseCommand.h"
#include "SolidDesignerCommand.h"
#include <utility>  
#include "AliceIOperation.h"


using namespace alice;
using namespace sdr;

AppCommandBase::AppCommandBase() noexcept
	: m_id()
	, m_strModuleId(GuidUtils::ToWString(soliddesignercommand::MODULE_ID))
{

}

AppCommandBase::AppCommandBase(std::string id) noexcept
	: m_id(std::move(id))
	, m_strModuleId(GuidUtils::ToWString(soliddesignercommand::MODULE_ID))
{

}

AppCommandBase::~AppCommandBase()
{

}

std::string_view AppCommandBase::Id() const noexcept
{
	return m_id;
}

const std::wstring& AppCommandBase::ModuleId() const noexcept
{
	return m_strModuleId;
}

bool AppCommandBase::IsSupported() const
{
	// Default implementation assumes that the command is always supported.
    // Derived commands should override this when the availability depends
    // on more specific runtime context.
	return true;
}

bool AppCommandBase::IsVisible() const
{
	// By default, visibility follows support.
    // Override in derived classes if a supported command still needs to
    // be hidden (e.g. experimental features, debug-only commands).
	return IsSupported();
}

bool AppCommandBase::IsEnabled() const
{
	// By default, a supported command is also enabled.
    // Typical overrides check current document, selection, or mode.
	return IsSupported();
}

bool AppCommandBase::IsChecked() const
{
	// Default: command is not a toggle, thus never "checked".
	// Toggle commands (e.g. show/hide grid, orthographic mode) should
	// return their current on/off state here.
	return false;
}

std::string AppCommandBase::DisabledReason() const
{
	// Default implementation does not provide an explicit reason.
    // Override in derived classes if you want to show a specific message
    // when the command is disabled (e.g. "No active document").
	return std::string{};
}

std::unique_ptr<alice::IOperation> AppCommandBase::Execute(const alice::CommandParameter& pCmdParam)
{
	// Base class has no behavior. This is intentionally a "pure default"
    // implementation so that:
    //   - Call sites can rely on ICommand::Execute existing;
    //   - Real commands are forced to override Execute with actual work.
    //
    // Returning nullptr indicates that no undoable operation has been
    // created. It is safe for non-undoable UI actions (dialogs, mode
    // switches, etc.).
	return nullptr;
}

void AppCommandBase::SetId(std::string id) noexcept
{
	// Store the new identifier. This function is intended to be called
    // only during construction of derived command classes.
	m_id = std::move(id);
}

void AppCommandBase::SetModuleId(const std::wstring& id) noexcept
{
	m_strModuleId = id;
}

