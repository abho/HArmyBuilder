#include "editor.h"
#include "ui_editor.h"

Editor::Editor(DataBase &db,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor),mDB(db),mRaceModel(this,mDB.coreDataBase())
{
    ui->setupUi(this);
}

Editor::~Editor()
{
    delete ui;
}

void Editor::on_tabWidget_2_currentChanged(int index)
{
    if(index == 0){
        mRaceModel.setTable("races");
        mRaceModel.setEditStrategy(QSqlTableModel::OnRowChange);
        mRaceModel.select();
        ui->tableView->setModel(&mRaceModel);
    }
}

void Editor::on_pushButtonRace_clicked()
{
    if( !ui->lineEditRace->text().isEmpty()){
        qDebug() << Q_FUNC_INFO << mDB.addRace(ui->lineEditRace->text());

        mRaceModel.query()
    }
}

void Editor::on_pushButtonRMRace_clicked()
{
    if( !ui->lineEditRace->text().isEmpty()){
        qDebug() << Q_FUNC_INFO << mDB.rmRace(ui->lineEditRace->text());
    }
}
