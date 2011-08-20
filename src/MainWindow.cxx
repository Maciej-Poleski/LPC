/* (C) Maciej Poleski 2011 */

#include "MainWindow.hxx"
#include "MainWidget.hxx"

MainWindow::MainWindow () throw (std::bad_alloc) : QMainWindow()
{
    centralWidget = new MainWidget();
    setCentralWidget (centralWidget);
}

MainWindow::~MainWindow()
{
}

