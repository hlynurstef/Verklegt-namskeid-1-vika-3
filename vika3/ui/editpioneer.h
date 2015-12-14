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
private slots:
    //void on_button_edit_pioneer_clicked();

private:
    Ui::editPioneer *ui;
};

#endif // EDITPIONEER_H
