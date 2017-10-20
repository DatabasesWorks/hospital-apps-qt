#ifndef LISTINGEMPLOYE_H
#define LISTINGEMPLOYE_H

#include <QDialog>
#include "employe.h"

namespace Ui {
class listingEmploye;
}

class listingEmploye : public QDialog
{
    Q_OBJECT
    
public:
    explicit listingEmploye(QWidget *parent = 0);
    ~listingEmploye();
    
private:
    Ui::listingEmploye *ui;
    Employe employe;
};

#endif // LISTINGEMPLOYE_H
