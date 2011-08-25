/* (C) Maciej Poleski 2011 */

#include "MainWidget.hxx"

#include <QtCore/QDebug>

#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QStyledItemDelegate>
#include <QtGui/QTextDocument>

#include "ExamplesTableModel.hxx"
#include "DatabaseException.hxx"
#include "ExampleDialog.hxx"

class MainWidget::Delegate : public QStyledItemDelegate
{
    virtual QString displayText(const QVariant& value, const QLocale& locale) const;
};

MainWidget::MainWidget (QWidget* parent, Qt::WindowFlags f) throw (DatabaseException) :
    QWidget (parent, f), examplesModel (0)
{
    addExampleButton = new QPushButton ("Dodaj nowy pomysł");
    examplesView = new QTableView;
    examplesView->horizontalHeader()->setStretchLastSection (true);
    layout = new QVBoxLayout;
    layout->addWidget (addExampleButton);
    layout->addWidget (examplesView);
    setLayout (layout);

    examplesModel = new ExamplesTableModel ("user.db", this);
    examplesModel->setEditStrategy (QSqlTableModel::OnManualSubmit);
    examplesView->setModel (examplesModel);
    examplesView->setColumnHidden (1, true);
    examplesView->setEditTriggers (QAbstractItemView::NoEditTriggers);
    delegate=new Delegate;
    examplesView->setItemDelegateForColumn(0,delegate);

    connect (examplesView, SIGNAL (clicked (QModelIndex)), this, SLOT (showSelectedExample (QModelIndex)));
    connect (addExampleButton, SIGNAL (clicked (bool)), this, SLOT (addNewExample()));
}

MainWidget::~MainWidget()
{
    delete delegate;
}

void MainWidget::showSelectedExample (const QModelIndex& index)
{
    ExampleDialog dialog (this);
    dialog.setup (examplesModel, index);
    if (dialog.exec() == QDialog::Accepted)
        examplesModel->submitAll();
    else
        examplesModel->revertAll();
}

void MainWidget::addNewExample()
{
    examplesModel->insertRows (examplesModel->rowCount(), 1);
    ExampleDialog dialog (this);
    dialog.setup (examplesModel, examplesModel->index (examplesModel->rowCount() - 1, 0));
    if(dialog.exec()==QDialog::Accepted)
        examplesModel->submitAll();
    else
        examplesModel->revertAll();
}

QString MainWidget::Delegate::displayText(const QVariant& value, const QLocale& locale) const
{
    QTextDocument document;
    document.setHtml(QStyledItemDelegate::displayText(value, locale));
    return document.toPlainText().split("\n",QString::SkipEmptyParts).join(" ");
}

