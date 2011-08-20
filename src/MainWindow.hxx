/* (C) Maciej Poleski 2011 */

#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QtGui/QMainWindow>

class MainWidget;


/**
 * @brief Główne okno aplikacji.
 **/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Przejmuje obowiązek zamkniecia bazy danych.
     **/
    MainWindow () throw(std::bad_alloc);
    virtual ~MainWindow();

private:
    MainWidget *centralWidget;
};

#endif // MAINWINDOW_HXX
