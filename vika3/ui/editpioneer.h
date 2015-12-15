#ifndef EDITPIONEER_H
#define EDITPIONEER_H

#include "data_types/pioneer.h"
#include "data_types/relation.h"
#include "data_types/computer.h"
#include "services/pioneerservice.h"
#include "services/relationservice.h"
#include "services/computerservice.h"

#include <QDialog>

namespace Ui {
class editPioneer;
}

class editPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit editPioneer(QWidget *parent = 0);
    ~editPioneer();

    void setPioneer(Pioneer pio);
    bool errorCheck(string name, string sex, string birthyear, string deathyear, string description);
    void displayRelatedComputers();
    void displayUnrelatedComputers();


private slots:
    void on_button_edit_pioneer_clicked();
    void on_list_unrelated_computers_clicked(const QModelIndex &);
    void on_list_related_computers_clicked(const QModelIndex &);
    void on_button_cancel_clicked();


    void on_button_remove_relation_clicked();

    void on_button_add_relation_clicked();

    void on_pushButton_browse_image_clicked();

private:
    Ui::editPioneer *ui;
    PioneerService pioService;
    RelationService relService;
    ComputerService compService;
    Relation rel;
    vector<Computer> relatedComputers, unrelatedComputers;
    QByteArray image;

    int pioID;
};

#endif // EDITPIONEER_H
