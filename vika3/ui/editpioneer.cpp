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
