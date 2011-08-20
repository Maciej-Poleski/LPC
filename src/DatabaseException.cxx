/* (C) Maciej Poleski 2011 */

#include "DatabaseException.hxx"

DatabaseException::DatabaseException (QString message, QSqlError error) throw() :
    runtime_error (message.toStdString()), error (error)
{
}

DatabaseException::~DatabaseException() throw()
{
}

QSqlError DatabaseException::getError() const throw()
{
    return static_cast<QSqlError> (*this);
}

DatabaseException::operator QSqlError() const throw()
{
    return error;
}
