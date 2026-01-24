//Owner: hananiah
#include "SolidNewFileDialog.h"
#include <QPushButton>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QSplitter>
#include <QGroupBox>
#include "AliceQxPtrUtils.h"

using namespace sdr;

namespace
{
    static SolidNewFileDialog::TypeId ReadType(const QListWidget* list)
    {
        if (auto* it = list ? list->currentItem() : nullptr)
            return static_cast<SolidNewFileDialog::TypeId>(it->data(Qt::UserRole).toInt());
        return SolidNewFileDialog::TypeId::Part;
    }

    static SolidNewFileDialog::SubTypeId ReadSubType(const QListWidget* list)
    {
        if (auto* it = list ? list->currentItem() : nullptr)
            return static_cast<SolidNewFileDialog::SubTypeId>(it->data(Qt::UserRole).toInt());
        return SolidNewFileDialog::SubTypeId::Default;
    }
}

SolidNewFileDialog::SolidNewFileDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("New"));
    setModal(true);
    setMinimumSize(700, 420);

    BuildUi_();
    PopulateTypes_();
    PopulateSubtypes_(TypeId::Part);

    // Default selections
    m_typeList->setCurrentRow(0);
    m_subTypeList->setCurrentRow(0);
    m_useTemplate->setChecked(true);

    // Wire events 
    QObject::connect(m_typeList, &QListWidget::currentRowChanged, this, [this](int /*row*/) {
        const TypeId type = ReadType(m_typeList);
        PopulateSubtypes_(type);
        SyncFromUi_();
        UpdateOkEnabled_();
    });
    QObject::connect(m_subTypeList, &QListWidget::currentRowChanged, this, [this](int /*row*/) {
        SyncFromUi_();
        UpdateOkEnabled_();
    });
    QObject::connect(m_nameEdit, &QLineEdit::textChanged, this, [this](const QString&) {
        SyncFromUi_();
        UpdateOkEnabled_();
    });
    QObject::connect(m_useTemplate, &QCheckBox::toggled, this, [this](bool) {
        SyncFromUi_();
        UpdateOkEnabled_();
    });

    SyncFromUi_();
    UpdateOkEnabled_();
}

SolidNewFileDialog::~SolidNewFileDialog()
{

}

bool SolidNewFileDialog::GetNewFileRequest(QWidget* parent, NewFileRequest& outRequest)
{
    SolidNewFileDialog dlg(parent);
    if (dlg.exec() != QDialog::Accepted)
        return false;

    outRequest = dlg.Request();
    if (outRequest.name.trimmed().isEmpty())
        return false;

    return true;
}

void SolidNewFileDialog::BuildUi_()
{
    QVBoxLayout* pRootLayout = QX_NEW_QOBJECT(QVBoxLayout, this);
    DIAG_RETURN_VOID_IF_FALSE(pRootLayout, "pRootLayout is null", "hananiah", "2025.12.25");
    pRootLayout->setContentsMargins(12, 12, 12, 12);
    pRootLayout->setSpacing(10);

    // Two-column: type/subtype lists
    QSplitter* pSplit = QX_NEW_QWIDGET(QSplitter, this);
    DIAG_RETURN_VOID_IF_FALSE(pSplit, "pSplit is null", "hananiah", "2025.12.25");
    pSplit->setOrientation(Qt::Horizontal);
    pRootLayout->addWidget(pSplit, /*stretch*/ 1);

    QGroupBox* pLeftBox = QX_NEW_QWIDGET(QGroupBox, tr("Type"), this);
    QGroupBox* pRightBox = QX_NEW_QWIDGET(QGroupBox, tr("Subtype"), this);

    QVBoxLayout* pLeftLayout = QX_NEW_QOBJECT(QVBoxLayout, pLeftBox);
    DIAG_RETURN_VOID_IF_FALSE(pLeftLayout, "pLeftLayout is null", "hananiah", "2025.12.25");
    QVBoxLayout* pRightLayout = QX_NEW_QOBJECT(QVBoxLayout, pRightBox);
    DIAG_RETURN_VOID_IF_FALSE(pRightLayout, "pRightLayout is null", "hananiah", "2025.12.25");
    m_typeList = QX_NEW_QWIDGET(QListWidget, pLeftBox);
    m_subTypeList = QX_NEW_QWIDGET(QListWidget, pRightBox);

    pLeftLayout->addWidget(m_typeList);
    pRightLayout->addWidget(m_subTypeList);

    pSplit->addWidget(pLeftBox);
    pSplit->addWidget(pRightBox);
    pSplit->setStretchFactor(0, 1);
    pSplit->setStretchFactor(1, 1);

    // Form area
    QGroupBox* pFormBox = QX_NEW_QWIDGET(QGroupBox, tr("Settings"), this);
    QFormLayout* pForm = new QFormLayout(pFormBox);
    DIAG_RETURN_VOID_IF_FALSE(pForm, "pForm is null", "hananiah", "2025.12.25");
    pFormBox->setLayout(pForm);
    pRootLayout->addWidget(pFormBox);

    m_nameEdit = QX_NEW_QWIDGET(QLineEdit, this);
    DIAG_RETURN_VOID_IF_FALSE(m_nameEdit, "m_nameEdit is null", "hananiah", "2025.12.25");
    m_nameEdit->setPlaceholderText(tr("Name (e.g. Part1)"));
    pForm->addRow(tr("Name"), m_nameEdit);

    m_useTemplate = QX_NEW_QWIDGET(QCheckBox, tr("Use default template"), this);
    DIAG_RETURN_VOID_IF_FALSE(m_useTemplate, "m_useTemplate is null", "hananiah", "2025.12.25");
    pForm->addRow(QString(), m_useTemplate);

    m_kindLabel = QX_NEW_QWIDGET(QLabel, this);
    DIAG_RETURN_VOID_IF_FALSE(m_kindLabel, "m_kindLabel is null", "hananiah", "2025.12.25");
    m_kindLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    pForm->addRow(tr("DocumentKind"), m_kindLabel);

    // Buttons
    m_buttons = QX_NEW_QWIDGET(QDialogButtonBox, QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    DIAG_RETURN_VOID_IF_FALSE(m_buttons, "m_buttons is null", "hananiah", "2025.12.25");
    pRootLayout->addWidget(m_buttons);
    QObject::connect(m_buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    QObject::connect(m_buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void SolidNewFileDialog::PopulateTypes_()
{
    m_typeList->clear();
    auto addType = [this](TypeId t) {
        auto* pItem = QX_EMPLACE_ITEM(nullptr, QListWidgetItem, TypeText_(t), m_typeList);
        DIAG_RETURN_VOID_IF_FALSE(pItem, "pItem is null", "hananiah", "2025.12.25");
        pItem->setData(Qt::UserRole, static_cast<int>(t));
    };
    addType(TypeId::Part);
    addType(TypeId::Assembly);
    addType(TypeId::Drawing);
    addType(TypeId::Sketch);
}

void SolidNewFileDialog::PopulateSubtypes_(TypeId type)
{
    m_subTypeList->clear();
    auto addSubType = [this](SubTypeId st) {
        auto* pItem = QX_EMPLACE_ITEM(nullptr, QListWidgetItem, SubTypeText_(st), m_subTypeList);
        DIAG_RETURN_VOID_IF_FALSE(pItem, "pItem is null", "hananiah", "2025.12.25");
        pItem->setData(Qt::UserRole, static_cast<int>(st));
    };

    // Keep it minimal yet expandable.
    switch (type)
    {
    case TypeId::Part:
        addSubType(SubTypeId::Solid);
        addSubType(SubTypeId::Sheetmetal);
        break;
    case TypeId::Assembly:
        addSubType(SubTypeId::Default);
        break;
    case TypeId::Drawing:
        addSubType(SubTypeId::Default);
        addSubType(SubTypeId::Layout);
        break;
    case TypeId::Sketch:
        addSubType(SubTypeId::Default);
        break;
    default:
        addSubType(SubTypeId::Default);
        break;
    }

    m_subTypeList->setCurrentRow(0);
}

void SolidNewFileDialog::SyncFromUi_()
{
    m_request.type = ReadType(m_typeList);
    m_request.subtype = ReadSubType(m_subTypeList);
    m_request.kind = MapToDocumentKind_(m_request.type, m_request.subtype);
    m_request.name = m_nameEdit->text().trimmed();
    m_request.useDefaultTemplate = m_useTemplate->isChecked();

    QString kindText;
    switch (m_request.kind)
    {
    case alice::DocumentKind::Part:
        kindText = tr("Part");
        break;
    case alice::DocumentKind::Assembly:
        kindText = tr("Assembly");
        break;
    case alice::DocumentKind::Drawing: 
        kindText = tr("Drawing"); 
        break;
    case alice::DocumentKind::Sketch: 
        kindText = tr("Sketch");
        break;
    default:
        kindText = tr("Unknown"); 
        break;
    }
    m_kindLabel->setText(kindText);
}

void SolidNewFileDialog::UpdateOkEnabled_()
{
    const bool ok = !m_nameEdit->text().trimmed().isEmpty();
    if (QAbstractButton* btn = m_buttons->button(QDialogButtonBox::Ok))
        btn->setEnabled(ok);
}

alice::DocumentKind SolidNewFileDialog::MapToDocumentKind_(TypeId type, SubTypeId /*subtype*/) noexcept
{
    // conventional mapping in Alice:
    // - Part/Solid/Sheetmetal -> DocumentKind::Part
    // - Assembly -> DocumentKind::Assembly
    // - Drawing/Layout -> DocumentKind::Drawing
    // - Sketch -> DocumentKind::Sketch
    switch (type)
    {
    case TypeId::Part: 
        return alice::DocumentKind::Part;
    case TypeId::Assembly: 
        return alice::DocumentKind::Assembly;
    case TypeId::Drawing: 
        return alice::DocumentKind::Drawing;
    case TypeId::Sketch: 
        return alice::DocumentKind::Sketch;
    default: 
        return alice::DocumentKind::Part;
    }
}

QString SolidNewFileDialog::TypeText_(TypeId type)
{
    switch (type)
    {
    case TypeId::Part: 
        return tr("Part");
    case TypeId::Assembly:
        return tr("Assembly");
    case TypeId::Drawing: 
        return tr("Drawing");
    case TypeId::Sketch:
        return tr("Sketch");
    default:
        return tr("Part");
    }
}

QString SolidNewFileDialog::SubTypeText_(SubTypeId st)
{
    switch (st)
    {
    case SubTypeId::Default:
        return tr("Default");
    case SubTypeId::Solid: 
        return tr("Solid");
    case SubTypeId::Sheetmetal:
        return tr("Sheetmetal");
    case SubTypeId::Layout: 
        return tr("Layout");
    default: 
        return tr("Default");
    }
}
