#ifndef EDITPIONEER_H
#define EDITPIONEER_H

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

private:
    Ui::editPioneer *ui;
};

#endif // EDITPIONEER_H
