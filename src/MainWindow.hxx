/* (C) Maciej Poleski 2011 */

#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QtGui/QMainWindow>

class DatabaseException;
class MainWidget;

#ifdef _WIN32
#ifdef LPCCore_EXPORTS
#define WIN32_EXPORT __declspec(dllexport)
#else
#define WIN32_EXPORT __declspec(dllimport)
#endif
#else
#define WIN32_EXPORT
#endif

/**
 * @brief Główne okno aplikacji.
 **/
class WIN32_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Przejmuje obowiązek zamkniecia bazy danych.
     **/
    MainWindow () throw(std::bad_alloc,DatabaseException);
    virtual ~MainWindow();

private:
    MainWidget *centralWidget;
};

#endif // MAINWINDOW_HXX
