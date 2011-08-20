/* (C) Maciej Poleski 2011 */

#ifndef EXAMPLEDIALOG_HXX
#define EXAMPLEDIALOG_HXX

#include <QtGui/QDialog>
#include <QtGui/QAbstractItemView>

class ExamplesTableModel;
class QPushButton;
class QLabel;
class QGridLayout;
class QDataWidgetMapper;
class QTextEdit;

/**
 * @brief Małe okno dialogowe pozwalające na podgląd wybranego pomysłu.
 **/
class ExampleDialog : public QDialog
{
    Q_OBJECT

    class Delegate;

public:
    explicit ExampleDialog (QWidget* parent = 0, Qt::WindowFlags f = 0);
    /**
     * @brief Ustawia okno dialogowe do śledzenia podanych danych.
     *
     * @param model Model który będzie śledzony.
     * @param index Wiersz który będzie widoczny w oknie.
     **/
    void setup (ExamplesTableModel* model, const QModelIndex &index);

public slots:
    virtual void accept();
    virtual void reject();

private:
    QPushButton *readyButton;
    QPushButton *cancelButton;
    QLabel *commentLabel;
    QLabel *codeLabel;
    QTextEdit *commentTextEdit;
    QTextEdit *codeTextEdit;
    QGridLayout *layout;
    QDataWidgetMapper *dataWidgetMapper;
};

#endif // EXAMPLEDIALOG_HXX
