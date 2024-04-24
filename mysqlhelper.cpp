#include "mysqlhelper.h"


MySqlHelper::MySqlHelper(){}

MySqlHelper::~MySqlHelper()
{
    closeConnection();
}

void MySqlHelper::connect()
{
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("Abc123...");
    db.open();

    if (!existDB())
        createDB();
    else
        db.setDatabaseName(dbName);
}

QString MySqlHelper::getDBName() const  {
    return dbName;
}

bool MySqlHelper::existDB()
{
    QStringList databases;

    if (query.exec("SHOW DATABASES"))
        while (query.next())
            databases << query.value(0).toString();

    if (databases.contains(dbName))
        return true;
    return false;
}

bool MySqlHelper::createDB()
{
    if (query.exec(QString("CREATE DATABASE %1").arg(dbName))){
        db.setDatabaseName(dbName);
        return true;
    }

    return false;
}

void MySqlHelper::closeConnection()
{
    db.close();
    db.removeDatabase(dbName);
}
