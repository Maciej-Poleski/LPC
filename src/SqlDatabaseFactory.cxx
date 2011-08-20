/* (C) Maciej Poleski 2011 */

#include "SqlDatabaseFactory.hxx"

#include <QtSql/QSqlQuery>

#include <QtCore/QDebug>

QSqlDatabase SqlDatabaseFactory::getDatabase (QString name)
throw (DatabaseException)
{
    QSqlDatabase database = QSqlDatabase::addDatabase ("QSQLITE",name);
    database.setDatabaseName (name);
    if (database.open() == false) {
        throw DatabaseException ("Próba otwarcia bazy danych nie powiodła się",database.lastError());
    }

    if (QSqlQuery ("SELECT * FROM examples", database).exec() == false) {
        QSqlQuery query ("CREATE TABLE examples("
                         "Komentarz TEXT,"
                         "Kod TEXT"
                         ")",
                         database);
        query.exec();   // FIXME: Dlaczego to zwraca false?
    }
    return database;
}
