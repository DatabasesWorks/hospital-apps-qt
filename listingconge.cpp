#include "listingconge.h"
#include "ui_listingconge.h"

ListingConge::ListingConge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListingConge)
{
    ui->setupUi(this);
    ui->tableViewConge->setModel(conge.AfficherConge());
}

ListingConge::~ListingConge()
{
    delete ui;
}
