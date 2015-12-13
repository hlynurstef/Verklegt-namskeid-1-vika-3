#ifndef MOREINFOPIONEER_H
#define MOREINFOPIONEER_H
#include "data_types/pioneer.h"
#include "ui/mainwindow.h"

#include <QDialog>

namespace Ui {
class MoreInfoPioneer;
}

class MoreInfoPioneer : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfoPioneer(QWidget *parent = 0);
    ~MoreInfoPioneer();
    void displayPioneer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MoreInfoPioneer *ui;
    Pioneer pioneer;
    MainWindow mainwindow;
};

#endif // MOREINFOPIONEER_H
