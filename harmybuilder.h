#ifndef HARMYBUILDER_H
#define HARMYBUILDER_H

#include <QMainWindow>
#include <QDebug>
#include "database.h"
#include "editor.h"

namespace Ui {
    class HArmyBuilder;
}

class HArmyBuilder : public QMainWindow
{
    Q_OBJECT

public:
    explicit HArmyBuilder(QWidget *parent = 0);
    ~HArmyBuilder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HArmyBuilder *ui;
    DataBase mDB;
    Editor *mEditor;
};

#endif // HARMYBUILDER_H
