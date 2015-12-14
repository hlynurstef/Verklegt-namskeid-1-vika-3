#include "editcomputer.h"
#include "ui_editcomputer.h"
#include "QMessageBox"


editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer)
{
    ui->setupUi(this);

}

editComputer::~editComputer()
{
    delete ui;
}

void editComputer::on_pushButton_editcomputer_clicked()
{
    QString name, wasItBuilt, buildYear, type, description;
    name = ui->label_name->text();
    wasItBuilt = ui->label_buildYear->text();
    buildYear = ui->label_buildYear->text();
    type = ui->label_type->text();
    description = ui->label_description->text();

    QSqlQuery query;
    query.prepare("update Computers set computer_name='"+name+"', build_year='"+buildYear+"', computer_type='"+type+"', was_built= '"+wasItBuilt+"', description= '"+description+"'");

    if(query.exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Update"));
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }

}
