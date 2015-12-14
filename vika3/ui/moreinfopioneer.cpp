#include "moreinfopioneer.h"
#include "ui_moreinfopioneer.h"
#include "utilities/constants.h"
#include <QDebug>

using namespace std;

MoreInfoPioneer::MoreInfoPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoPioneer)
{
    ui->setupUi(this);
}

MoreInfoPioneer::~MoreInfoPioneer(){
    delete ui;
}

void MoreInfoPioneer::setPioneer(Pioneer pioneer){
    ui->show_single_pioneer->clearContents();

    ui->show_single_pioneer->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(pioneer.getName())));
    ui->show_single_pioneer->setItem(1, 0, new QTableWidgetItem(QString::fromStdString(pioneer.getSex())));
    ui->show_single_pioneer->setItem(2, 0, new QTableWidgetItem(QString::number(pioneer.getByear())));
    ui->show_single_pioneer->setItem(3, 0, new QTableWidgetItem(QString::number(pioneer.getDyear())));
    ui->show_single_pioneer->setItem(4, 0, new QTableWidgetItem(QString::fromStdString(pioneer.getDescription())));
}

void MoreInfoPioneer::on_pushButton_clicked(){
    this->done(1);
}
