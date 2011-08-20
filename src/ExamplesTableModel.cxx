/* (C) Maciej Poleski 2011 */

#include "ExamplesTableModel.hxx"
#include "SqlDatabaseFactory.hxx"

ExamplesTableModel::ExamplesTableModel (QString name, QObject* parent) :
    QSqlTableModel (parent, SqlDatabaseFactory::getDatabase (name))
{
    setTable ("examples");
    setEditStrategy (QSqlTableModel::OnManualSubmit);
    select();
}
