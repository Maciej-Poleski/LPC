/* (C) Maciej Poleski 2011 */

#ifndef MAINWIDGET_HXX
#define MAINWIDGET_HXX

#include <QtGui/QWidget>

#include "DatabaseException.hxx"

class ExamplesTableModel;
class QTableView;
class QPushButton;
class QVBoxLayout;

/**
 * @brief Główny widget okna głównego.
 * Zawiera model i widok
 **/
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Inicjalizuje widget tworząc model i widok bazy danych użytkownika.
     *
     * @param parent ... Defaults to 0.
     * @param f ... Defaults to 0.
     **/
    explicit MainWidget (QWidget* parent = 0, Qt::WindowFlags f = 0)
    throw (DatabaseException);
private:
    QPushButton* addExampleButton;
    QTableView* examplesView;
    QVBoxLayout* layout;

    ExamplesTableModel* examplesModel;
};

#endif // MAINWIDGET_HXX
