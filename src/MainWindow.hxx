/* (C) Maciej Poleski 2011 */

#ifndef MAINWINDOW_HXX
#define MAINWINDOW_HXX

#include <QtGui/QMainWindow>

class ExamplesTableModel;
class QTableView;
class QDataWidgetMapper;

/**
 * @brief Główne okno aplikacji.
 **/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Przejmuje obowiązek zamkniecia bazy danych.
     *
     * @param database ...
     **/
    MainWindow () throw(std::bad_alloc);
    virtual ~MainWindow();

private:
    ExamplesTableModel *model;
    QTableView *view;
    QDataWidgetMapper *mapper;
};

#endif // MAINWINDOW_HXX
