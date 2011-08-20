/* (C) Maciej Poleski 2011 */

#ifndef SQLDATABASEFACTORY_HXX
#define SQLDATABASEFACTORY_HXX

#include <QtSql/QSqlDatabase>

#include "DatabaseException.hxx"

/**
 * @brief Odpowiada za dostarczenie połączenia do bazy danych.
 * Odpowiada również za ewentualne stworzenie i zainicjalizowanie tej bazy.
 **/
class SqlDatabaseFactory
{
public:
    /**
     * @brief Przygotowuje bazę danych i zwraca otwarte połączenie.
     *
     * @param name Nazwa pliku z bazą danych i jednocześnie połączenie
     * @return QSqlDatabase Otwarte połączenie
     **/
    static QSqlDatabase getDatabase (QString name)
    throw (DatabaseException);
};

#endif // SQLDATABASEFACTORY_HXX
