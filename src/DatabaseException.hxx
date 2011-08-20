/* (C) Maciej Poleski 2011 */

#ifndef DATABASEEXCEPTION_HXX
#define DATABASEEXCEPTION_HXX

#include <stdexcept>
#include <QtCore/QString>
#include <QtSql/QSqlError>

/**
 * @brief Wyjątek sygnalizuje błąd podczas pracy z bazą danych.
 * Zgodny wstecz z ISO C++
 **/
class DatabaseException : public std::runtime_error
{

public:
    /**
     * @brief Rodzina wyjątków pojawiających się przy problemach z bazą danych
     *
     * @param message Wiadomość w stylu ISO C++
     * @param error Wiadomość z modułu Sql
     **/
    explicit DatabaseException (QString message, QSqlError error = QSqlError()) throw();
    virtual ~DatabaseException() throw();

    /**
     * @brief Zwraca QSqlError związany z wyjątkiem
     *
     * @return QSqlError
     **/
    virtual QSqlError getError() const throw();

    /**
     * @brief Zwraca QSqlError związany z wyjątkiem
     *
     * @return QSqlError
     **/
    virtual operator QSqlError() const throw();

private:
    QSqlError error;
};

#endif // DATABASEEXCEPTION_HXX
