#include "listingemploye.h"
#include "ui_listingemploye.h"

listingEmploye::listingEmploye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listingEmploye)
{
    ui->setupUi(this);
    ui->tableViewEmploye->setModel(employe.AfficherEmploye());

}

listingEmploye::~listingEmploye()
{
    delete ui;
}
