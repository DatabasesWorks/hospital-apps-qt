#ifndef LISTINGCONGE_H
#define LISTINGCONGE_H

#include <QDialog>
#include "conge.h"

namespace Ui {
class ListingConge;
}

class ListingConge : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListingConge(QWidget *parent = 0);
    ~ListingConge();
    
private:
    Ui::ListingConge *ui;
    Conge conge;


};

#endif // LISTINGCONGE_H
