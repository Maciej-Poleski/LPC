#include <QtCore/QTextCodec>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>

#include "src/MainWindow.hxx"

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

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
