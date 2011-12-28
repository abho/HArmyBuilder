#include "harmybuilder.h"
#include "ui_harmybuilder.h"

HArmyBuilder::HArmyBuilder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HArmyBuilder),mEditor(NULL)
{
    ui->setupUi(this);
}

HArmyBuilder::~HArmyBuilder()
{
    delete ui;
    if( mEditor != NULL)
        delete mEditor;
}

void HArmyBuilder::on_pushButton_clicked()
{
    if (mEditor == NULL){
        mEditor = new Editor(mDB);
    }
        mEditor->show();
}
