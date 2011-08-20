/* (C) Maciej Poleski 2011 */

#include "MainWidget.hxx"

#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHeaderView>

#include "ExamplesTableModel.hxx"
#include "DatabaseException.hxx"

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
    examplesView->setModel (examplesModel);
    examplesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
