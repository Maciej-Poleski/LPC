/* (C) Maciej Poleski 2011 */

#include "MainWindow.hxx"

#include <QtGui/QApplication>
#include <QtGui/QTableView>
#include <QtGui/QDataWidgetMapper>
#include <QtGui/QMessageBox>
#include <QtGui/QHeaderView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>

#include "ExamplesTableModel.hxx"
#include "DatabaseException.hxx"

MainWindow::MainWindow () throw(std::bad_alloc) : QMainWindow()
{
    view = new QTableView;
    try {
        model = new ExamplesTableModel ("user.db");
        view->setModel (model);
    } catch (const DatabaseException& exception) {
        QMessageBox::critical (0, "Błąd bazy danych", exception.what()+QString("\nOdpowiedź bazy danych:\n")+exception.getError().text());
        qApp->exit (2);
    }
    view->horizontalHeader()->setStretchLastSection (true);
    setCentralWidget (view);
}

MainWindow::~MainWindow()
{
}

