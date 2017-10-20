#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include "qdialog.h"
#include <QDialog>
#include"patient.h"
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include "printview.h"
#include "Chambre.h"

#include"Hospitalisation.h"

#include <QMessageBox>
RDV * temprdv;
#include"QDebug"
#include "printview.h"
#include <qprinter.h>
#include "QPrintPreviewDialog.h"
Patient * temppat;
Chambre * tempch;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/ons_2/projetQTons/BDclinique.sqlite");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              qApp->tr("unable to connect"), QMessageBox::Cancel);
        // return false;
    }
    else
    {
        QMessageBox::information(0, qApp->tr(" open database"),
                                 qApp->tr(" connected"
                                          ), QMessageBox::Ok);
        //return true;
    }
    ui->comboBox_modif_patirnt->setModel(p.update_cin());


    ui->comboBox_supp_patient->setModel(p.update_cin());
    ui->comboBoxmodifierchambre->setModel(c.update_id());
    ui->comboBoxsuppchambre->setModel(c.update_id());


    ui->consulterpatienttv->setModel(temppat->consulter_Patient());
    ui->consulterchambretv->setModel(tempch->consulter_Chambre());
    ui->hospitalisationmodTV->setModel(temph->consulter_Hospitalisation());


    ui->RechercheView->hide();
    ui->numfichele->setValidator(new QIntValidator(0,100000,this));

    // ui->numPatientle->setValidator(new QIntValidator(0,100000000,this));
    ui->datecreationfiche->setDate(QDate::currentDate());//dateedit avec la date systéme
    ui->datedebutajoutle->setDate(QDate::currentDate());
    ui->datefinajoutle->setDate(QDate::currentDate());


    // ui->datecreationfiche->setDate(QDate::fromString("12/02/2014","MM/dd/yyyy"));//modifier le contenu de dateedit
    ui->consulterpatienttv->setModel(temppat->consulter_Patient());

}

MainWindow::~MainWindow()
{
    delete ui;
}
//ajouter patient
void MainWindow::on_commandLinkButton_2_clicked()
{
    QString  datefiche=ui->datecreationfiche->text();
    int  numfiche=ui->numfichele->text().toInt();
    QString nomPatien=ui->nomfichele->text();
    QString prenomPatient=ui->PrnomPatientle->text();

    int CINPatient=ui->CINpatientle->text().toInt();
    QString sexePatient=ui->SexePatientle->text();

    QString AdressePatient=ui->AdressePatientle->text();
    QString date_Nais_Patient=ui->datenaissle_2->text() ;
    QString Profession =ui->Professiopatientle->text();
    int num_tel_Patient =ui->numPatientle->text().toInt();

    Patient p(  datefiche,  numfiche, nomPatien, prenomPatient, CINPatient, sexePatient, AdressePatient, date_Nais_Patient , Profession , num_tel_Patient);


    if (p.ajouter_Patient())
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr(" un element a été ajouter"
                                          ), QMessageBox::Ok);
        ui->consulterpatienttv->setModel(temppat->consulter_Patient());
        ui->comboBox_modif_patirnt->setModel(p.update_cin());
    }
    else
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr("probleme d'ajout "
                                          ), QMessageBox::Ok);


    }


    //currentText()
}


//modifier patient
void MainWindow::on_modifier_clicked()
{

    QString str = " Vous voulez vraiment modifier \n l employé ayant la CINPatient:";
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret)
    {
    case QMessageBox::Ok:
    {
        Patient e1(ui->date_modifi->text(),
                   ui->num_modif->text().toInt(),
                   ui->nom_modif->text(),
                   ui->prenom_modif->text(),
                   ui->sexe_modif->text(),

                   ui->adress_modif->text(),
                   ui->date_cre_modif->text() ,
                   ui->profision_modif->text(),
                   ui->num_modif->text().toInt());
        if (e1.modifier_Patient(p.get_cinpatient()))
            QMessageBox ::information(0, qApp->tr("modifier"),qApp->tr("Le patient a été modifié"), QMessageBox::Ok);
        ui->modifierTV->setModel(temppat->consulter_Patient());
        break;}
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }
}
//modifier chambre patient
void MainWindow::on_modifierchambrePB_clicked()
{
    QString str = " Vous voulez vraiment modifier \n la chambre ayant l'id:"+ ui->comboBoxmodifierchambre->currentText();
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret)
    {
    case QMessageBox::Ok:
    {
        Chambre e1(//na7i id w aamel constructeur
                    ui->typechambremodle->text(),
                    ui->coutjourmodle->text().toInt(),

                    ui->coutsuppmodle->text().toInt());
        if (e1.modifier_Chambre(c.get_id_chambre()))//c.get_id
            QMessageBox ::information(0, qApp->tr("modifier"),qApp->tr("La chambre a été modifié"), QMessageBox::Ok);
        ui->modifierchambretv->setModel(tempch->consulter_Chambre());
        break;}
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }
}

//chercher patient
void MainWindow::on_recherchele_textChanged(const QString &arg1)
{
    ui->RechercheView->setModel(temppat->chercher(arg1));
    ui->RechercheView->show();
    qDebug()<<"je suis la ";
}


//supprimer patient
void MainWindow::on_supprimerPatientPB_clicked()
{

   // QString numfiche=ui->comboBox_supp_patient->currentText();

    QString str = " Vous voulez vraiment supprimer \n le patient  ayant cette numfiche ";
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:
        if (temppat->supprimerPatient(p.get_cinpatient()))
            QMessageBox ::information(0, qApp->tr("Suppression"),
                                      qApp->tr("Le patient a été supprimé"), QMessageBox::Ok);

        ui->comboBox_supp_patient->setModel(temppat->update_cin());
        ui->suppPatientView->setModel(temppat->consulter_Patient());
        ui->comboBox_modif_patirnt->setModel(temppat->update_cin());
        break;
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }




}

void MainWindow::on_imprimer_clicked()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::ScreenResolution);
    QPrintPreviewDialog dlg(&printer);
    PrintView view;
    view.setModel(ui->RechercheView->model());
    connect(&dlg, SIGNAL(paintRequested(QPrinter*)),
            &view, SLOT(print(QPrinter*)));
    dlg.exec();
#endif
}


void MainWindow::on_AjouterchambrePB_clicked()
{


    int id_chambre=ui->idchambrele->text().toInt();
    QString type_chambre=ui->typechambrele->text();


    int cout_jour=ui->coutjourle->text().toInt();

    int cout_supp =ui->coutsupple->text().toInt();

    Chambre c( id_chambre,type_chambre,   cout_jour, cout_supp);


    if (c.ajouter_Chambre())
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr(" un element a été ajouter"
                                          ), QMessageBox::Ok);
        ui->consulterchambretv->setModel(tempch->consulter_Chambre());

    }
    else
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr("probleme d'ajout "
                                          ), QMessageBox::Ok);


    }


}

void MainWindow::on_recherchechambrele_textChanged(const QString &arg1)
{
    ui->RechercheViewchambre->setModel(tempch->chercherChambre(arg1));
    ui->RechercheViewchambre->show();
    qDebug()<<"je suis la ";
}



void MainWindow::on_supprimerchambrePB_clicked()
{
    QString id_chambre=ui->comboBoxsuppchambre->currentText();



    QString str = " Vous voulez vraiment supprimer \n la chambre  ayant cette id ";
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:
        if (tempch->supprimerChambre(c.get_id_chambre()))//c.get_id
            QMessageBox ::information(0, qApp->tr("Suppression"),
                                      qApp->tr("La chambre a été supprimé"), QMessageBox::Ok);

        ui->tvsuppchambre->setModel(tempch->consulter_Chambre());
        ui->comboBoxmodifierchambre->setModel(c.update_id());
        ui->comboBoxsuppchambre->setModel(c.update_id());

        //ui->comboBoxmodifierchambre->setmode
        break;
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }



}


void MainWindow::on_commandLinkButton_clicked()
{


    int  CINPatient=ui->cinRDVle->text().toInt();
    QString nomPatien=ui->nomrdvle->text();
    QString prenomPatient=ui->prenomrdvle->text();


    QString DateRDV=ui->dateRDVle->text();

    QString HeureRDV=ui->heurele->text();
    QString CommentaireRDV=ui->commentairele->text() ;



    RDV R(  CINPatient,nomPatien, prenomPatient, DateRDV, HeureRDV, CommentaireRDV);



    if (R.ajouter_RDV())
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr(" un element a été ajouter"
                                          ), QMessageBox::Ok);

        ui->consulterRDVtv->setModel(temprdv->consulter_RDV());

    }
    else
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr("probleme d'ajout "
                                          ), QMessageBox::Ok);


    }
}


void MainWindow::on_commandLinkButton_3_clicked()
{
    int CINPatient =ui->cinrechercherdvle->text().toInt();


    QSqlQueryModel *model =temprdv->rechercheRDV(CINPatient);
    int CINrech = model->data(model->index(0, 0)).toInt();

    if(CINPatient== CINrech)
    {
        QString str = " Vous voulez vraiment supprimer \n le patient ayant le CIN :"+ ui->cinrechercherdvle->text();
        int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
            if (temprdv->supprimerRDV(CINPatient))
                QMessageBox ::information(0, qApp->tr("Suppression"),
                                          qApp->tr("Le RDV a été supprimé"), QMessageBox::Ok);

            ui->consulterRDVtv->setModel(temprdv->consulter_RDV());

            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }


    }
}

/*void rendezv::on_rechercherdvmodpb_clicked()
{
    int CINPatient =ui->modrdvle->text().toInt();

    QSqlQueryModel *model =temprdv->rechercheRDV(CINPatient);
    int cinRech = model->data(model->index(4, 0)).toInt();
    if(CINPatient==cinRech)
    {  ui->nomrdvmodle->setText(model->data(model->index(0,0)).toString());
       ui->prenomrdvmodle->setText(model->data(model->index(0, 1)).toString());
       ui->dateRDVmodle->setText(model->data(model->index(0,2)).toString());
       //ui->date_modif->setText(model->data(model->index(0, 7)).toString());
       ui->heuremodle->setText(model->data(model->index(0, 3)).toString());
        ui->commentairemodle->setText(model->data(model->index(0, 4)).toString());
}}
*/

/*void rendezv::on_modifRDV_clicked()
{
    QString str = " Vous voulez vraiment modifier \n l employé ayant la CINPatient:"+ ui->modrdvle->text();
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret)
    {
      case QMessageBox::Ok:
       {
           RDV e1(ui->modrdvle->text().toInt(),
                       ui->nomrdvmodle->text(),

                   ui->prenomrdvmodle->text(),
                   ui->dateRDVmodle->text(),

                   ui->heuremodle->text().toInt(),
                  ui->commentairemodle->text());


          if (e1.modifierRDV())
           {
              QMessageBox ::information(0, qApp->tr("modifier"),qApp->tr("Le RDV a été modifié"), QMessageBox::Ok);
         ui->modifTV->setModel(temprdv->consulter_RDV());
          break;}
      case QMessageBox::Cancel:
          break;
      default:
          // should never be reached
          break;

    }
}}*/










void MainWindow::on_rechercheidrdvle_textChanged(const QString &arg1)
{
    qDebug()<<"jesuis la";
    ui->RechercheViewrdv->setModel(temprdv->chercher(arg1));
    ui->RechercheViewrdv->show();
}

void MainWindow::on_print_clicked()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::ScreenResolution);
    QPrintPreviewDialog dlg(&printer);
    PrintView view;
    view.setModel(ui->RechercheViewrdv->model());
    connect(&dlg, SIGNAL(paintRequested(QPrinter*)),
            &view, SLOT(print(QPrinter*)));
    dlg.exec();
#endif
}



void MainWindow::on_ajouthospitalisationPB_clicked()
{
    QString  type_chambre=ui->typechambreajoutle->text();
    int  cout_jour=ui->coutjourajoutle->text().toInt();


    int tva=ui->tvaajoutle->text().toInt();
    QDate date_debut=ui->datedebutajoutle->date();

    QDate date_fin=ui->datefinajoutle->date();


    Hospitalisation h(  type_chambre,   cout_jour, tva, date_debut, date_fin);


    if (h.ajouter_Hospitalisation())
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr(" un element a été ajouter"
                                          ), QMessageBox::Ok);
        ui->consultehosptv->setModel(temph->consulter_Hospitalisation());

    }
    else
    {
        QMessageBox::information(this, qApp->tr("ajouter"),
                                 qApp->tr("probleme d'ajout "
                                          ), QMessageBox::Ok);

    }

}

void MainWindow::on_comboBoxsupphospitalisation_currentIndexChanged(const QString &arg1)
{
   /* QString c=ui->comboBoxsupphospitalisation_2->currentText();
    QSqlQuery query ;
    query.prepare("select * from Hospitalisation where type_chambre="+c+" ");
    if (query.exec())

    {
        while(query.next())
        {
            ui->typechambresupphosple->setText(query.value(0).toString());
            ui->coutjoursupphosple->setText(query.value(1).toString());
            ui->tvasupple->setText(query.value(2).toString());
            ui->datedebutsupple->setDate(query.value(3).toDate());
            ui->datefinsupple->setDate(query.value(4).toDate());

        }

    }*/

}

void MainWindow::on_supprimerhospitalisationPB_clicked()
{
    QString type_chambre=ui->comboBoxsupphospitalisation_2->currentText();

    //temppat->setcin(numfiche.toInt());
    qDebug()<<"hihihihihihi";
    QString str = " Vous voulez vraiment supprimer \n la chambre  ayant cette id ";
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:
        if (temph->supprimerHospitalisation())
            QMessageBox ::information(0, qApp->tr("Suppression"),
                                      qApp->tr("La chambre a été supprimé"), QMessageBox::Ok);

        //ui->tvsuppchambre>setModel(tempch->consulter_Chambre());
        break;
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }


}

void MainWindow::on_comboBoxsmodhospitalisation_currentIndexChanged(const QString &arg1)
{
    QString type_chambre=ui->comboBoxsmodhospitalisation->currentText();
    QSqlQuery query ;
    query.prepare("select * from Hospitalisation where type_chambre='+Hospiatlisation+' ");
    if (query.exec())

    {
        while(query.next())
        {
            ui->typechambremod->setText(query.value(0).toString());
            ui->coutjourmod->setText(query.value(1).toString());
            ui->tvachambremod->setText(query.value(2).toString());
            ui->datedebutmod->setDate(query.value(3).toDate());
            ui->datefinmod->setDate(query.value(4).toDate());



        }}}

void MainWindow::on_modifierhospPB_clicked()
{
    QString str = " Vous voulez vraiment modifier \n la chambre ayant l'id:"+ ui->comboBoxsmodhospitalisation->currentText();
    int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret)
    {
    case QMessageBox::Ok:
    {
        Hospitalisation e1(

                    ui->typechambremod->text(),


                    ui->coutjourmod->text().toInt(),

                    ui->tvachambremod->text().toInt(),
                    ui->datedebutmod->date(),
                    ui->datefinmod->date());
        if (e1.modifier_Hospitalisation())
            QMessageBox ::information(0, qApp->tr("modifier"),qApp->tr("La chambre a été modifié"), QMessageBox::Ok);
        ui->hospitalisationmodTV->setModel(temph->consulter_Hospitalisation());
        break;}
    case QMessageBox::Cancel:
        break;
    default:
        // should never be reached
        break;
    }
}




void MainWindow::on_rechercheidhosple_textChanged(const QString &arg1)
{
    ui->RechercheViewhosp->setModel(temph->chercher(arg1));
    ui->RechercheViewhosp->show();
    qDebug()<<"je suis la ";

}



void MainWindow::on_comboBox_modif_patirnt_textChanged(const QString &arg1)
{
    /*
    Monsieur mé 7abtch tekhdem ??!!!!

qDebug()<<"uuuuuuuuuu"<<arg1;
    QString a=ui->comboBox_modif_patirnt->currentText();
    qDebug()<<"combooooooooxxxxxxxxxxx = "<<a;
    p.get_patient(a);
    ui->date_modifi->setText(p.get_datefiche());
    ui->num_modif->setText(QString::number(p.get_numfiche()));
    ui->nom_modif->setText(p.get_nomPatient());
    ui->prenom_modif->setText(p.get_prenomPatient());
    ui->sexe_modif->setText(p.get_sexe());
    ui->adress_modif->setText(p.get_adresse());
    ui->date_cre_modif->setText(p.get_dateNaisssance());
    ui->profision_modif->setText(p.get_profession());
    ui->tel_modif->setText(QString::number(p.get_numTel()));*/
}

void MainWindow::on_cin_modif_2_textChanged(const QString &arg1)
{

    p.set_cinpatient(arg1.toInt());

    p.get_patient(arg1);
    ui->date_modifi->setText(p.get_datefiche());
    ui->num_modif->setText(QString::number(p.get_numfiche()));
    ui->nom_modif->setText(p.get_nomPatient());
    ui->prenom_modif->setText(p.get_prenomPatient());
    ui->sexe_modif->setText(p.get_sexe());
    ui->adress_modif->setText(p.get_adresse());
    ui->date_cre_modif->setText(p.get_dateNaisssance());
    ui->profision_modif->setText(p.get_profession());
    ui->tel_modif->setText(QString::number(p.get_numTel()));
}




void MainWindow::on_cin_supp_patient_textChanged(const QString &arg1)
{
    qDebug()<<arg1;
    p.set_cinpatient(arg1.toInt());
    p.get_patient(arg1);
    ui->datesupple->setText(p.get_datefiche());
    ui->numsupple->setText(QString::number(p.get_numfiche()));
    ui->nomsupple->setText(p.get_nomPatient());
    ui->prenomsupple->setText(p.get_prenomPatient());
    ui->sexesupp->setText(p.get_sexe());
    ui->adressesupple->setText(p.get_adresse());
    ui->datenaissupple->setText(p.get_dateNaisssance());
    ui->professionsupple->setText(p.get_profession());
    ui->telsupple->setText(QString::number(p.get_numTel()));
}

void MainWindow::on_suppchambrele_textChanged(const QString &arg1)
{
    qDebug()<<arg1;
    c.set_id_chambre(arg1.toInt());
    c.get_chambre(arg1);
    ui->typechambresupple->setText(c.gettype_chambre());
    ui->coutjoursupple->setText(QString::number(c.get_coutjour()));
     ui->coutsuppsupple->setText(QString::number(c.get_coutsupp()));

}
void MainWindow::on_modchamble_textChanged(const QString &arg1)
{
    c.set_id_chambre(arg1.toInt());
qDebug()<<"jhgbuigiukh"<<arg1;
    c.get_chambre(arg1);
    ui->typechambremodle->setText(c.gettype_chambre());
    ui->coutjourmodle->setText(QString::number(c.get_coutjour()));
     ui->coutsuppmodle->setText(QString::number(c.get_coutsupp()));


}
