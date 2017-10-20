#include "listingpaiement.h"
#include "ui_listingpaiement.h"

ListingPaiement::ListingPaiement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListingPaiement)
{
    ui->setupUi(this);
   ui->tableViewPaiment->setModel(fichePaie.ConsulterPaiement());
   ui->tableViewPaiment->resizeColumnsToContents();

}

ListingPaiement::~ListingPaiement()
{
    delete ui;
}
