#include "mainwindowAV.h"
#include "ui_mainwindowAV.h"
#include <QMessageBox>
#include"fournisseur.h"
#include"commande.h"
#include"vente.h"
#include"affichagebd_fournisseur.h"
#include"affichagebd_cmd.h"
#include"affichagebd_vente.h"
#include<QString>
#include <QPrintDialog>
#include <QPrinter>
namespace ui {
class fournisseur;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap graph("C:/Users/asus/Desktop/AchatVente/graphique.jpg");
    ui->label_2->setPixmap(graph);
    ui->label_3->setPixmap(graph);
    ui->label_5->setPixmap(graph);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_pb_clicked()
{
    QString id=ui->ID_FOU->text();
    QString nom= ui->NomLE->text();
    QString adresse =ui->AdresseLE->text();
    QString categorie =ui->CategorieLE->text();
    int tel =ui->TelLE->text().toInt();
    int fax =ui->FaxLE->text().toInt();
    QString adresse_mail = ui->AdresseLE_2->text();
    QString site_web = ui->SiteLE->text();
    QString comm_resa = ui->CommLE->text();

    fournisseur four(id,nom,adresse,categorie,tel,fax,adresse_mail,site_web,comm_resa) ;
    if (four.AjouterFour())
    {
        QMessageBox::information(0, qApp->tr("Ajout"),
            qApp->tr("Un Nouveau Fournisseur a été ajouter\n"), QMessageBox::Ok);
    }
    else
        QMessageBox::critical (0, qApp->tr("Ajout"),
            qApp->tr("Probleme d'Ajout\n"), QMessageBox::Ok);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString identifiant= ui->ID_LE->text();
    QString date_commande =ui->DATE_LE->text();
    float prix_unitaire =ui->PU_LE->text().toFloat();
    int quantite =ui->Q_LE->text().toInt();
    QString idf= ui->ID_FOU_C->text();
    QString identifiantArticle= ui->ID_AR->text();

    commande comm(identifiant,date_commande,prix_unitaire,quantite,idf,identifiantArticle) ;
    if (comm.AjouterComm())
    {
        QMessageBox::information(0, qApp->tr("Ajout"),
            qApp->tr("Une Nouvelle Commande a été ajouter\n"), QMessageBox::Ok);
    }
    else
        QMessageBox::critical (0, qApp->tr("Ajout"),
            qApp->tr("Probleme d'Ajout\n"), QMessageBox::Ok);
}

void MainWindow::on_pushButton_9_clicked()
{
    QString identifiant= ui->ID_AJ->text();
    float prix_Achat =ui->PA_AJ->text().toFloat();
    float marge_B =ui->MB_AJ->text().toFloat();
    int quantite =ui->QU_AJ->text().toInt();


    vente v(identifiant,prix_Achat,marge_B,quantite) ;
    if (v.AjouterVente())
    {
        QMessageBox::information(0, qApp->tr("Ajout"),
            qApp->tr("Une Vente a été valider\n"), QMessageBox::Ok);
    }
    else
        QMessageBox::critical (0, qApp->tr("Ajout"),
            qApp->tr("Probleme de validation\n"), QMessageBox::Ok);
}




void MainWindow::AfficherFournisseur(fournisseur fournisseurAfficher)
{
    QString tel1=QString::number(fournisseurAfficher.Gettel());
    QString fax1=QString::number(fournisseurAfficher.Getfax());

    ui->ID_FOU->setText(fournisseurAfficher.GetID());
    ui->NomLE->setText(fournisseurAfficher.Getnom());
    ui->AdresseLE->setText(fournisseurAfficher.Getadresse());
    ui->CategorieLE->setText(fournisseurAfficher.Getcategorie());
    ui->TelLE->setText(tel1);
    ui->FaxLE->setText(fax1);
    ui->AdresseLE_2->setText(fournisseurAfficher.Getadresssemail());
    ui->SiteLE->setText(fournisseurAfficher.Getsiteweb());
    ui->CommLE->setText(fournisseurAfficher.Getcommresa());



}




void MainWindow::on_ID_FOU_cursorPositionChanged(int arg1, int arg2)
{
fournisseur fournisseurAchercher;
    int idUtilsateur=ui->ID_FOU->text().toInt();
fournisseurAchercher.RechercherInstFour(idUtilsateur);
qDebug()<<fournisseurAchercher.GetID();
if (!fournisseurAchercher.GetID().isEmpty())
AfficherFournisseur(fournisseurAchercher);
}


void MainWindow::on_modif_pb_clicked()
{   QString id, nom,adresse,categorie;
    int tel,fax;
    QString adresse_mail,site_web,comm_resa;
    fournisseur fournisseurmodif;
    fournisseurmodif.SetID(ui->ID_FOU->text());
    fournisseurmodif.Setnom(ui->NomLE->text());
    fournisseurmodif.Setadresse(ui->AdresseLE->text());
    fournisseurmodif.Setcategorie(ui->CategorieLE->text());
    fournisseurmodif.Settel(ui->TelLE->text().toInt());
    fournisseurmodif.Setfax(ui->FaxLE->text().toInt());
    fournisseurmodif.Setadressemail(ui->AdresseLE_2->text());
    fournisseurmodif.Setsiteweb(ui->SiteLE->text());
    fournisseurmodif.Setcommresa(ui->CommLE->text());
    fournisseurmodif.ModifierFournisseur();

fournisseur four(id,nom,adresse,categorie, tel, fax,adresse_mail,site_web,comm_resa) ;
if (four.ModifierFournisseur())
{
    QMessageBox::critical(0, qApp->tr("Modification"),
        qApp->tr("Probléme de Modification"), QMessageBox::Ok);
}
else
    QMessageBox::information(0, qApp->tr("Ajout"),
        qApp->tr("Fournisseur a été modifier\n"), QMessageBox::Ok);


}

void MainWindow::on_pushButton_2_clicked()
{
    ui->ID_FOU->clear();
    ui->NomLE->clear();
    ui->AdresseLE->clear();
    ui->CategorieLE->clear();
    ui->TelLE->clear();
    ui->FaxLE->clear();
    ui->AdresseLE_2->clear();
    ui->SiteLE->clear();
    ui->CommLE->clear();
}

void MainWindow::on_supp_pb_clicked()
{QString id, nom,adresse,categorie;
    int tel,fax;
    QString adresse_mail,site_web,comm_resa;
    fournisseur Supp;
    int idUtilsateurS=ui->ID_FOU->text().toInt();
    if (Supp.RechercherInstFour(idUtilsateurS))
    Supp.SupprimerFournisseur();

    fournisseur four(id,nom,adresse,categorie, tel, fax,adresse_mail,site_web,comm_resa) ;

    if (four.SupprimerFournisseur())
    {
        QMessageBox::critical(0, qApp->tr("Suppresion"),
            qApp->tr("Probléme de Suppresion"), QMessageBox::Ok);
    }
    else
        QMessageBox::information(0, qApp->tr("Ajout"),
            qApp->tr("Fournisseur a été supprimer\n"), QMessageBox::Ok);
}

void MainWindow::AfficherCommande(commande commandeAfficher)
{
    QString prix=QString::number(commandeAfficher.Getprix());
    QString quantite=QString::number(commandeAfficher.Getquantite());


    ui->ID_LE->setText(commandeAfficher.Getid());
    ui->DATE_LE->setText(commandeAfficher.Getdate());
    ui->PU_LE->setText(prix);
    ui->Q_LE->setText(quantite);
    ui->ID_FOU_C->setText(commandeAfficher.Getidf());
    ui->ID_AR->setText(commandeAfficher.GetIDA());





}

void MainWindow::on_ID_LE_cursorPositionChanged(int arg1, int arg2)
{
    commande commandeAchercher;
    int id=ui->ID_LE->text().toInt();
    commandeAchercher.RechercherInstComm(id);
    qDebug()<<commandeAchercher.Getid();
    if (!commandeAchercher.Getid().isEmpty())
    AfficherCommande(commandeAchercher);
}


void MainWindow::on_pushButton_7_clicked()
{
    QString identifiant,date_commande,idf,identifiantArticle;
    float prix_unitaire;
    int quantite;


       commande commandemodif;
       commandemodif.Setid(ui->ID_LE->text());
       commandemodif.Setdate(ui->DATE_LE->text());
       commandemodif.Setprix(ui->PU_LE->text().toFloat());
       commandemodif.Setquantite(ui->Q_LE->text().toInt());
       commandemodif.Setidf(ui->ID_FOU_C->text());
       commandemodif.SetIDA(ui->ID_AR->text());

       commandemodif.ModifierCommande();


       commande comm(identifiant,date_commande,prix_unitaire,quantite,idf,identifiantArticle) ;
       if (comm.ModifierCommande())
       {
           QMessageBox::critical(0, qApp->tr("Modification Commande"),
               qApp->tr("probléme de Modification\n"), QMessageBox::Ok);
       }
       else
           QMessageBox::information(0, qApp->tr("Ajout"),
               qApp->tr("Une Commande a été modifier\n"), QMessageBox::Ok);



}

void MainWindow::on_pushButton_6_clicked()
{
    QString identifiant,date_commande,idf,identifiantArticle;
    float prix_unitaire;
    int quantite;

        commande Supp;
        int id=ui->ID_LE->text().toInt();
        if (Supp.RechercherInstComm(id))
        Supp.SupprimerCommande();

        commande comm(identifiant,date_commande,prix_unitaire,quantite,idf,identifiantArticle) ;
        if (comm.SupprimerCommande())
        {
            QMessageBox::critical(0, qApp->tr("Suppresion Commande"),
                qApp->tr("probléme de suppresion\n"), QMessageBox::Ok);
        }
        else
            QMessageBox::information(0, qApp->tr("Ajout"),
                qApp->tr("Une Commande a été supprimer\n"), QMessageBox::Ok);
}

void MainWindow::AfficherVente(vente venteAfficher)
{
    QString prix=QString::number(venteAfficher.Getprix());
    QString marge=QString::number(venteAfficher.Getmarge());
    QString quantite=QString::number(venteAfficher.Getquantite());


    ui->ID_AJ->setText(venteAfficher.Getid());
    ui->PA_AJ->setText(prix);
    ui->MB_AJ->setText(marge);
    ui->QU_AJ->setText(quantite);




}


void MainWindow::on_ID_AJ_cursorPositionChanged(int arg1, int arg2)
{

        vente venteAchercher;
        int id_v=ui->ID_AJ->text().toInt();
        venteAchercher.RechercherInstVente(id_v);
        qDebug()<<venteAchercher.Getid();
        if (!venteAchercher.Getid().isEmpty())
        AfficherVente(venteAchercher);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->ID_LE->clear();
    ui->DATE_LE->clear();
    ui->PU_LE->clear();
    ui->Q_LE->clear();
    ui->ID_FOU_C->clear();
    ui->ID_AR->clear();
}


void MainWindow::on_pushButton_11_clicked()
{
    QString identifiant ;
    float prix_Achat;
    float marge_B;
    int quantite;


      vente ventemodif;
       ventemodif.Setid(ui->ID_AJ->text());
       ventemodif.Setprix(ui->PA_AJ->text().toFloat());
       ventemodif.Setmarge(ui->MB_AJ->text().toFloat());
       ventemodif.Setquantite(ui->QU_AJ->text().toInt());
       ventemodif.ModifierVente();

       vente v(identifiant,prix_Achat,marge_B,quantite) ;
       if (v.ModifierVente())
       {
           QMessageBox::critical(0, qApp->tr("Modification"),
               qApp->tr("Probleme de Modification\n"), QMessageBox::Ok);
       }
       else
           QMessageBox::information(0, qApp->tr("Ajout"),
               qApp->tr("La Vente a été modifier avec succés\n"), QMessageBox::Ok);
}

void MainWindow::on_consult_pb_clicked()
{
    this->hide();
    AffichageBD_Fournisseur abdf  ;
    abdf.setModal(true);
    abdf.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    this->hide();
   affichageBD_cmd abdc  ;
    abdc.setModal(true);
    abdc.exec();
}


void MainWindow::on_pushButton_10_clicked()
{
    this->hide();
   AffichageBD_vente abdv  ;
    abdv.setModal(true);
    abdv.exec();
}


void MainWindow::on_pushButton_12_clicked()
{
    QPrinter printer;
   QPrintDialog printDialog( &printer, 0);
   if( QDialog::Accepted == printDialog.exec() ) {

   if( QPrinter::Landscape != printer.orientation() ) {
   printer.setOrientation(QPrinter::Landscape);
   }

   QPoint startPoint = QPoint(20, 20);
   QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
   for( int i = 0; i < 10; ++i ) {
   ui->impression_general->render( &printer, startPoint, printRegion, QWidget::DrawChildren);
   }
   }
   }


void MainWindow::on_pushButton_14_clicked()
{
    QPrinter printer;
   QPrintDialog printDialog( &printer, 0);
   if( QDialog::Accepted == printDialog.exec() ) {

   if( QPrinter::Landscape != printer.orientation() ) {
   printer.setOrientation(QPrinter::Landscape);
   }

   QPoint startPoint = QPoint(20, 20);
   QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
   for( int i = 0; i < 10; ++i ) {
   ui->impression_general->render( &printer, startPoint, printRegion, QWidget::DrawChildren);
   }
   }

}

void MainWindow::on_pushButton_13_clicked()
{
    QPrinter printer;
   QPrintDialog printDialog( &printer, 0);
   if( QDialog::Accepted == printDialog.exec() ) {

   if( QPrinter::Landscape != printer.orientation() ) {
   printer.setOrientation(QPrinter::Landscape);
   }

   QPoint startPoint = QPoint(20, 20);
   QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
   for( int i = 0; i < 10; ++i ) {
   ui->impression_general->render( &printer, startPoint, printRegion, QWidget::DrawChildren);
   }
   }
}
