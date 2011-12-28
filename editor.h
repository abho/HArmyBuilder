#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QSqlTableModel>
#include "database.h"

namespace Ui {
    class Editor;
}

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(DataBase &db,QWidget *parent = 0);
    ~Editor();

private slots:
    void on_tabWidget_2_currentChanged(int index);

    void on_pushButtonRace_clicked();

    void on_pushButtonRMRace_clicked();

private:
    Ui::Editor *ui;
DataBase &mDB;
    QSqlTableModel mRaceModel;
};

#endif // EDITOR_H
