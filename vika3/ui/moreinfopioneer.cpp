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

    //------------------- Printing info -------------------

    ui->label_name->setText(QString::fromStdString(pioneer.getName()));
    ui->label_sex->setText(QString::fromStdString(pioneer.getSex()));
    ui->label_yearBorn->setText(QString::number(pioneer.getByear()));
    if(pioneer.getDyear() == 0){
        ui ->label_yearDied->setText(QString::fromStdString("Still alive!"));
    }
    else{
        ui ->label_yearDied->setText(QString::number(pioneer.getDyear()));
    }
    ui->textBrowser_description->setText(QString::fromStdString(pioneer.getDescription()));
}

void MoreInfoPioneer::on_pushButton_close_clicked()
{
    this->close();
}
