#include "moreinfopioneer.h"
#include "ui_moreinfopioneer.h"
#include "utilities/constants.h"
#include <QDebug>
#include <QPixmap>


using namespace std;

MoreInfoPioneer::MoreInfoPioneer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfoPioneer){
    ui->setupUi(this);
}

MoreInfoPioneer::~MoreInfoPioneer(){
    delete ui;
}

void MoreInfoPioneer::setPioneer(Pioneer pioneer){

    //-------------------------- Printing info --------------------------

    ui->label_name->setText(QString::fromStdString(pioneer.getName()));
    if(pioneer.getSex() == constants::MALE){
        ui->label_sex->setText(QString::fromStdString("Male"));
    }
    else{
        ui->label_sex->setText(QString::fromStdString("Female"));
    }

    ui->label_yearBorn->setText(QString::number(pioneer.getByear()));
    if(pioneer.getDyear() == 0){
        ui ->label_yearDied->setText(QString::fromStdString("Still alive!"));
    }
    else{
        ui ->label_yearDied->setText(QString::number(pioneer.getDyear()));
    }
    ui->textBrowser_description->setText(QString::fromStdString(pioneer.getDescription()));

    getRelationList(pioneer);

    if(!(pioneer.getImageByteArray().isEmpty())){
        QPixmap pixmap = QPixmap();
        pixmap.loadFromData(pioneer.getImageByteArray());
        pixmap = pixmap.scaledToWidth( 130 );
        ui->label_image->setPixmap(pixmap);
        //ui->label_image->setScaledContents(true);
    }
}

void MoreInfoPioneer::getRelationList(Pioneer pioneer){

    //---------------- Printing & getting relation info from database ----------------

    string relationList;

    relation = (relationService.relationSearch(pioneer.getName(), constants::REL_PIO_NAME));

    for(unsigned int i=0; i < relation.size(); i++){
        relationList += relation[i].getCompName();
        if((i+1) < relation.size()){
            relationList += ", ";
        }
    }
    if(relation.size() == 0){
        ui -> textBrowser_relation -> setText(QString::fromStdString("Unknown relations"));
    }
    else
        ui -> textBrowser_relation -> setText(QString::fromStdString(relationList));
}


void MoreInfoPioneer::on_pushButton_close_clicked(){
    this->close();
}


