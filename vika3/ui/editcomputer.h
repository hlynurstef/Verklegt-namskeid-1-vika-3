#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>

namespace Ui {
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();

private:
    Ui::editComputer *ui;
};

#endif // EDITCOMPUTER_H
