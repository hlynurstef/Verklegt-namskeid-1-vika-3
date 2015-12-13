#ifndef ADDPIONEER_H
#define ADDPIONEER_H
#include <string>
#include <vector>
#include "services/pioneerservice.h"
#include "data_types/pioneer.h"

#include <QDialog>

namespace Ui {
class AddPioneer;
}

class AddPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit AddPioneer(QWidget *parent = 0);
    ~AddPioneer();

    bool errorCheck(string name, string sex, string birthyear, string deathyear, string description);
private slots:
    void on_button_add_pioneer_clicked();

private:
    Ui::AddPioneer *ui;
    PioneerService pioService;
};

#endif // ADDPIONEER_H
