#include <QtCore/QTextCodec>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>

#include "src/MainWindow.hxx"
#include "src/DatabaseException.hxx"

int main (int argc, char** argv)
{
    QApplication app (argc, argv);

    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("UTF-8"));
    QTextCodec::setCodecForLocale (QTextCodec::codecForName ("UTF-8"));
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    if (QSqlDatabase::isDriverAvailable ("QSQLITE") == false) {
        QMessageBox::critical (0, "Nie znaleziono sterownika bazy danych",
                               "Próba odnalezienia sterownika bazy danych"
                               " SQLite zakończyła się niepowodzeniem.\nNie"
                               " mogę kontynuować.");
        return 1;
    }

    try {

        MainWindow mainWindow;
        mainWindow.show();

        return app.exec();
    } catch (const DatabaseException& exception) {
        QMessageBox::critical (0, "Błąd bazy danych", QString ("Nastąpił wyjątek"
                               " podczas pracy z bazą danych, nie mogę"
                               " kontynuować.\n\nstd::what(): ") + exception.what() +
                               "\n\nKomunikat SQL: " +
                               exception.getError().text());
        return 2;
    } catch (...) {
        QMessageBox::critical (0, "Niezidentyfikowany wyjątek", "Wystąpił"
                               " niezidentyfikowany wyjątek. Nie potrafię podać"
                               " jego przyczyny. Nie mogę kontynuować.");
        return -1;
    }

}
