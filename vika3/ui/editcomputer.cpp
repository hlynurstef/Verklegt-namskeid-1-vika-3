#include "editcomputer.h"
#include "ui_editcomputer.h"

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
