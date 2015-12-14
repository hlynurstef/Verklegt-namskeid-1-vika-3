#include "editpioneer.h"
#include "ui_editpioneer.h"

editPioneer::editPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPioneer)
{
    ui->setupUi(this);
}

editPioneer::~editPioneer()
{
    delete ui;
}

void editPioneer::setPioneer(Pioneer pio){
    ui->edit_name->setText(QString::fromStdString(pio.getName()));
}

/*
void editPioneer::on_button_edit_pioneer_clicked()
{
    ui->edit_name->setText();
}
*/
