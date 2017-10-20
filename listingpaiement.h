#ifndef LISTINGPAIEMENT_H
#define LISTINGPAIEMENT_H

#include <QDialog>
#include <paiement.h>
namespace Ui {
class ListingPaiement;
}

class ListingPaiement : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListingPaiement(QWidget *parent = 0);
    ~ListingPaiement();
    
private:
    Ui::ListingPaiement *ui;
    FichePaie fichePaie;

};

#endif // LISTINGPAIEMENT_H
