#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include "statclass.h"
#include "qcustomplot.h"

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT
    
public:
    explicit Statistiques(QWidget *parent = 0);
    ~Statistiques();
    
private:
    Ui::Statistiques *ui;
    StatClass statClass;
};

#endif // STATISTIQUES_H
