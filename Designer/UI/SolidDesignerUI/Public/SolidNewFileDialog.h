#pragma once
#include "SolidDesignerUI.h"
#include "AliceDocumentKind.h"

#include <QDialog>
#include <QString>

class QListWidget;
class QLineEdit;
class QCheckBox;
class QLabel;
class QWidget;
class QDialogButtonBox;
namespace sdr
{
    class SOLID_DESIGNER_UI_EXPORT SolidNewFileDialog final : public QDialog
    {
    public:
        enum class TypeId
        {
            Part = 0,
            Assembly = 1,
            Drawing = 2,
            Sketch = 3,
        };

        enum class SubTypeId
        {
            Default = 0,
            Solid = 1,
            Sheetmetal = 2,
            Layout = 3,
        };

        struct NewFileRequest
        {
            TypeId type = TypeId::Part;
            SubTypeId subtype = SubTypeId::Solid;
            alice::DocumentKind kind = alice::DocumentKind::Part;
            QString name;
            bool useDefaultTemplate = true;
        };

        explicit SolidNewFileDialog(QWidget* parent = nullptr);
        ~SolidNewFileDialog() override;

        /// \brief Blocking modal helper.
        /// \return true if user clicks OK and the request is valid.
        static bool GetNewFileRequest(QWidget* parent, NewFileRequest& outRequest);

        /// \brief Current request snapshot (only meaningful after accept()).
        const NewFileRequest& Request() const { return m_request; }

    private:
        void BuildUi_();
        void PopulateTypes_();
        void PopulateSubtypes_(TypeId type);
        void SyncFromUi_();
        void UpdateOkEnabled_();

        static alice::DocumentKind MapToDocumentKind_(TypeId type, SubTypeId subtype) noexcept;
        static QString TypeText_(TypeId type);
        static QString SubTypeText_(SubTypeId st);

    private:
        QListWidget* m_typeList = nullptr;
        QListWidget* m_subTypeList = nullptr;
        QLineEdit* m_nameEdit = nullptr;
        QCheckBox* m_useTemplate = nullptr;
        QLabel* m_kindLabel = nullptr;
        QDialogButtonBox* m_buttons = nullptr;

        NewFileRequest m_request;
    };
}
