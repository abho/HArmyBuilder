#include "database.h"

DataBase::DataBase(QObject *parent) :
    QObject(parent)
{
    if(openDB())
        createInitDBs();
}

bool DataBase::openDB()
{
    // Find QSLite driver
    mDB = QSqlDatabase::addDatabase("QSQLITE");
    mDB.setDatabaseName("armybuilder.db");
    // Open databasee
    return mDB.open();
}

bool DataBase::createInitDBs()
{    // Create table "person"
    bool ret = true;

    QSqlQuery query;

    ret = query.exec("create table if not exists races "
                     "(id integer primary key, "
                     "name varchar(20))");
    if(!ret)
        return ret;

    ret = query.exec("create table if not exists specialrules "
                     "(id integer primary key, "
                     "name varchar(20), "
                     "description varchar(30), "
                     "mod varchar(30),"
                     "race integer)");
    if(!ret)
        return ret;
    ret = query.exec("create table if not exists optiontyp "
                     "(id integer primary key, "
                     "name varchar(20)");
    if(!ret)
        return ret;


    ret = query.exec("create table if not exists options "
                     "(id integer primary key, "
                     "name varchar(20),"
                     "typ integer,"
                     "description varchar(30),"
                     "mod varchar(30))");

    return ret;

}

QSqlDatabase & DataBase::coreDataBase()
{
    return mDB;
}

bool DataBase::addRace(const QString &name)
{
    QSqlQuery query;

    if(!query.exec("select count(id) from races where name = '"+name+"'")){
        qDebug() << Q_FUNC_INFO << query.lastError();
        return false;
    } else {
        query.next();
        qDebug()<< Q_FUNC_INFO << query.value(0).toInt();
        if(query.value(0).toInt()>0)
            return false;

        if(!query.exec("select max(id) from races")){
            qDebug() << Q_FUNC_INFO << query.lastError();
            return false;
        } else {
            query.next();
            int nr= query.value(0).toInt()+1;
            query.prepare("INSERT INTO races (id, name) "
                               "VALUES (?, ?)");
                 query.addBindValue(nr);
                 query.addBindValue(name);
            if(!query.exec()){
                qDebug() << Q_FUNC_INFO << query.lastError();
                return false;
            }
        }
    }
    return true;
}

bool DataBase::rmRace(const QString &name)
{
    QSqlQuery query;

    if(!query.exec("delete from races where name = '"+name+"'")){
        qDebug() << Q_FUNC_INFO << query.lastError();
        return false;
    }
    return true;
}
