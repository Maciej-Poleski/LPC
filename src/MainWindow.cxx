/* (C) Maciej Poleski 2011 */

#include "MainWindow.hxx"
#include "MainWidget.hxx"

MainWindow::MainWindow () throw (std::bad_alloc,DatabaseException) : QMainWindow()
{
    centralWidget = new MainWidget();
    setCentralWidget (centralWidget);
    resize(500,300);
}

MainWindow::~MainWindow()
{
}

