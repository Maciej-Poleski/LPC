/* (C) Maciej Poleski 2011 */

#include "MainWidget.hxx"

#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHeaderView>

#include "ExamplesTableModel.hxx"
#include "DatabaseException.hxx"
#include "ExampleDialog.hxx"

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

    connect (examplesView, SIGNAL (clicked (QModelIndex)), this, SLOT (showSelectedExample (QModelIndex)));
    connect (addExampleButton, SIGNAL (clicked (bool)), this, SLOT (addNewExample()));
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
