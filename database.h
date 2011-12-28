#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtCore>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);

    bool openDB();
    QSqlDatabase & coreDataBase();
    bool addRace(const QString &name);
    bool rmRace(const QString &name);

signals:

public slots:

private:
    bool createInitDBs();
    QSqlDatabase mDB;
};

#endif // DATABASE_H
