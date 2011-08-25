/* (C) Maciej Poleski 2011 */

#include "ExampleDialog.hxx"

#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QDataWidgetMapper>

#include "ExamplesTableModel.hxx"

ExampleDialog::ExampleDialog (QWidget* parent, Qt::WindowFlags f) :
    QDialog (parent, f), dataWidgetMapper (0)
{
    readyButton = new QPushButton ("Gotowe");
    cancelButton = new QPushButton ("Anuluj");
    commentLabel = new QLabel ("Komentarz:");
    codeLabel = new QLabel ("Kod:");
    commentTextEdit = new QTextEdit;
    commentTextEdit->setAcceptRichText (false);
    codeTextEdit = new QTextEdit;
    layout = new QGridLayout;

    layout->addWidget (commentLabel, 0, 0, 1, 2);
    layout->addWidget (commentTextEdit, 1, 0, 1, 2);
    layout->addWidget (codeLabel, 2, 0, 1, 2);
    layout->addWidget (codeTextEdit, 3, 0, 1, 2);
    layout->addWidget (readyButton, 4, 0, 1, 1);
    layout->addWidget (cancelButton, 4, 1, 1, 1);
    setLayout (layout);

    connect (readyButton, SIGNAL (clicked (bool)), this, SLOT (accept()));
    connect (cancelButton, SIGNAL (clicked (bool)), this, SLOT (reject()));
}

void ExampleDialog::setup (ExamplesTableModel* model, const QModelIndex& index)
{
    dataWidgetMapper = new QDataWidgetMapper (this);
    dataWidgetMapper->setSubmitPolicy (QDataWidgetMapper::ManualSubmit);
    dataWidgetMapper->setModel (model);
    dataWidgetMapper->addMapping (commentTextEdit, 0);
    dataWidgetMapper->addMapping (codeTextEdit, 1);
    dataWidgetMapper->setCurrentModelIndex (index);
}

void ExampleDialog::accept()
{
    dataWidgetMapper->submit();
    QDialog::accept();
}

void ExampleDialog::reject()
{
    dataWidgetMapper->revert();
    QDialog::reject();
}

