#ifndef EDITPIONEER_H
#define EDITPIONEER_H

#include "data_types/pioneer.h"
#include "services/pioneerservice.h"

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

private slots:
    void on_button_edit_pioneer_clicked();

    void on_button_cancel_clicked();

private:
    Ui::editPioneer *ui;
    PioneerService pioService;
    int pioID;
};

#endif // EDITPIONEER_H
