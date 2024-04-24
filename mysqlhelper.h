#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <QtSql>

class MySqlHelper
{
public:
    MySqlHelper();
    ~MySqlHelper();

    QString getDBName() const;
    void connect();

private:
    const QString dbName="liaoliao";
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery query;

    bool existDB();
    bool createDB();
    void closeConnection();
};

#endif // MYSQLHELPER_H
