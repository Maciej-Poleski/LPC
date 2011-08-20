/* (C) Maciej Poleski 2011 */

#ifndef EXAMPLESTABLEMODEL_HXX
#define EXAMPLESTABLEMODEL_HXX

#include <QSqlTableModel>


class ExamplesTableModel : public QSqlTableModel
{

public:
    /**
     * @brief Model zarządzający danymi z tabeli examples ze wskazanej bazy danych.
     *
     * @param name Nazwa bazy danych
     * @param parent ... Defaults to 0.
     **/
    ExamplesTableModel (QString name, QObject* parent = 0);
};

#endif // EXAMPLESTABLEMODEL_HXX
