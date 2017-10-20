#include "employeui.h"
#include "ui_employeui.h"
#include "employe.h"

using namespace std;

employeui::employeui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employeui)
{



    fileNameImage="";
    AppelAffiche=true;
    AppelAffichePaiement=true;
    AppelAfficheConge=true;
    ui->setupUi(this);
    QPixmap pixmap("employe-image_standard.png");
    PixTrueIcon=QPixmap("True_icon.png");
    PixFalseIcon=QPixmap("False_icon.png");
    ui->label_image->setPixmap(pixmap);
    InitIndication();
    Pointage.FileToDB();
    ui->tableViewPointage->setModel(Pointage.ConsulterPointageGlobale());
    ui->tableViewPointage->resizeColumnsToContents();





}

employeui::~employeui()
{
    delete ui;
}

void employeui::SetOuputMessage(QString message ,bool state)
{
    if (!state)
        ui->label_SortieApplication->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->label_SortieApplication->setStyleSheet("color: rgb(0, 180, 0);");

    ui->label_SortieApplication->setText(message);


}

void employeui::SetOuputMessagePointage(QString message ,bool state)
{
    if (!state)
        ui->SortieApplicationPointage->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->SortieApplicationPointage->setStyleSheet("color: rgb(0, 180, 0);");

    ui->SortieApplicationPointage->setText(message);

}

void employeui::SetOuputMessagePaiement(QString message ,bool state)
{
    if (!state)
        ui->SortieApplicationPaiement->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->SortieApplicationPaiement->setStyleSheet("color: rgb(0, 180, 0);");

    ui->SortieApplicationPaiement->setText(message);

}

void employeui::SetOuputMessageConge(QString message ,bool state)
{
    if (!state)
        ui->SortieApplicationConge->setStyleSheet("color: rgb(255, 0, 0);");
    else
        ui->SortieApplicationConge->setStyleSheet("color: rgb(0, 180, 0);");

    ui->SortieApplicationConge->setText(message);

}

void employeui::on_pushButton_ChargerImage_clicked()
{
    QString fileName=QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.doc *.rtf);;All files (*.*)"),0 );
    QPixmap pixmap;
    if (QFile::exists(fileName))
    {
        fileNameImage=fileName;
        pixmap=fileName;
        ui->label_image->setPixmap(pixmap);
    }

}

void employeui::AfficheEmployeInstantane(Employe EmployeAafficher)
{

    QString tel=QString::number(EmployeAafficher.GetTelephoneTravail());
    QString nss=QString::number(EmployeAafficher.GetNss());
    QString cin=QString::number(EmployeAafficher.GetCin());
    QPixmap pixmap;

    AppelAffiche=false;
    ui->lineEdit_nom->setText(EmployeAafficher.GetNom());
    ui->lineEdit_prenom->setText(EmployeAafficher.GetPrenom());
    ui->lineEdit_ID->setText(EmployeAafficher.GetLogin());
    ui->lineEdit_motdepasse->setText(EmployeAafficher.GetMotDePasse());
    ui->lineEdit_adresseTravail->setText(EmployeAafficher.GetAdresseTravail());
    ui->lineEdit_adresse->setText(EmployeAafficher.GetAdresse());
    ui->lineEdit_telephoneTravail->setText(tel);
    ui->lineEdit_mailTravail->setText(EmployeAafficher.GetAdresseMail());
    ui->dateEdit_dateNaissance->setDate(QDate::fromString(EmployeAafficher.GetDateNaissance(),"dd/MM/yyyy"));
    ui->dateEdit_dateEmbouche->setDate(QDate::fromString(EmployeAafficher.GetDateEmbouche(),"dd/MM/yyyy"));
    ui->lineEdit_profession->setText(EmployeAafficher.GetProfession());
    ui->comboBox_contrat->setCurrentIndex(ui->comboBox_contrat->findData(EmployeAafficher.GetTypeContrat(), Qt::DisplayRole));
    ui->comboBox_service->setCurrentIndex(ui->comboBox_service->findData(EmployeAafficher.GetService(),Qt::DisplayRole));
    ui->comboBox_sexe->setCurrentIndex(ui->comboBox_sexe->findData(EmployeAafficher.GetSexe(), Qt::DisplayRole));
    ui->comboBox_EtatCivil->setCurrentIndex(ui->comboBox_EtatCivil->findData(EmployeAafficher.GetEtatCivil(), Qt::DisplayRole));

    ui->lineEdit_NSS->setText(nss);
    ui->lineEdit_CIN->setText(cin);
    ui->lineEdit_passport->setText(EmployeAafficher.GetNumeroPasseport());
    ui->lineEdit_nationnalite->setText(EmployeAafficher.GetNationnalite());
    ui->lineEdit_adresseTravail->setText(EmployeAafficher.GetAdresseTravail());
    ui->lineEdit_confirmermotdepasse->setText(EmployeAafficher.GetMotDePasse());

    pixmap.loadFromData(EmployeAafficher.GetImage());
    ui->label_image->setPixmap(pixmap);
    AppelAffiche=true;



}

void employeui::on_lineEdit_ID_cursorPositionChanged(int arg1, int arg2)
{

    if (ui->checkBox_IDSearch->isChecked())
    {
        unsigned long long login=ui->lineEdit_ID->text().toLongLong();
        Employe EmployeAchercher;
        EmployeAchercher.RechercherInstEmploye(login);

        if (!EmployeAchercher.GetLogin().isEmpty())
        {
            AfficheEmployeInstantane(EmployeAchercher);
        }
        else
            EnClear(1);
    }
    else
    {
        if (AppelAffiche)
            verifID();
    }

}

void employeui::on_pushButton_supprmier_clicked()
{
    Employe EmployeAsupprimer;
    unsigned long long loginUtilisateur=ui->lineEdit_ID->text().toLongLong();
    if (EmployeAsupprimer.RechercherInstEmploye(loginUtilisateur))
    {

        if (EmployeAsupprimer.SupprimerEmploye())
        {
            EnClear(0);
            SetOuputMessage("L'employé à été supprimé avec succès ",true);
        }
        else
            SetOuputMessage("L'employé n'as pas été supprimé, Vérifiez vos donneés et réessayez encore ",false);

    }



}

void employeui::on_pushButton_Annuler_clicked()
{
    ui->comboBox_Nom->clear();
    EnClear(0);
    ui->label_SortieApplication->clear();

}

void employeui::EnClear(int choix){
    if (!choix)
    {
        ui->lineEdit_ID->clear();
    }
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_adresseTravail->clear();
    ui->lineEdit_CIN->clear();
    ui->comboBox_contrat->setCurrentIndex(-1);
    ui->comboBox_EtatCivil->setCurrentIndex(-1);
    ui->comboBox_sexe->setCurrentIndex(-1);
    ui->comboBox_service->setCurrentIndex(-1);
    ui->dateEdit_dateEmbouche->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->dateEdit_dateNaissance->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->lineEdit_confirmermotdepasse->clear();
    ui->lineEdit_motdepasse->clear();
    ui->lineEdit_mailTravail->clear();
    ui->lineEdit_nationnalite->clear();
    ui->lineEdit_NSS->clear();
    ui->lineEdit_profession->clear();
    ui->lineEdit_telephoneTravail->clear();
    ui->lineEdit_passport->clear();
    QPixmap pixmap("employe-image_standard.png");
    ui->label_image->setPixmap(pixmap);

    ui->label_NomControl->clear();
    ui->label_PrenomControl->clear();
    ui->label_ServiceControl->clear();
    ui->label_NssControl->clear();
    ui->label_PassportControl->clear();
    ui->label_PasswordConfirmControl->clear();
    ui->label_PasswordControl->clear();
    ui->label_CinControl->clear();
    ui->label_AdresseControl->clear();
    ui->label_AdresseTravailControl->clear();
    ui->label_mailControl->clear();
    ui->label_TelephoneTravailControl->clear();
    ui->label_IDControl->clear();
    ui->label_SexeControl->clear();
    ui->label_EtatCivilControl->clear();
    ui->label_NationnaliteControl->clear();
    ui->label_DateNaissanceControl->clear();
    ui->label_professionControl->clear();
    ui->label_ContratControl->clear();
    ui->label_DateEmbouchementControl->clear();
}

void employeui::EnClearPaiement(){
    ui->lineEdit_IDPaiementEmploye->clear();
    ui->lineEdit_MontantTTC->clear();
    ui->dateEdit_Paiement->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->textEdit_PaiementResponsable->clear();

    ui->label_IDPaiementControl->clear();
    ui->label_MontantControl->clear();
    ui->label_DatePaiementControl->clear();
    ui->SortieApplicationPaiement->clear();


}

void employeui::EnClearConge(){

    ui->lineEdit_IDCongeEmploye->clear();
    ui->comboBox_TypeConge->setCurrentIndex(-1);
    ui->dateEdit_DebutConge->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->dateEdit_FinConge->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->textEdit_Responsable->clear();
    ui->textEdit_Employe->clear();

    ui->label_IDCongeControl->clear();
    ui->label_typeCongeControl->clear();
    ui->label_DateDebutCongeControl->clear();
    ui->label_DateFinCongeControl->clear();
    ui->SortieApplicationConge->clear();

}

void employeui::on_comboBox_Nom_editTextChanged(const QString &arg1)
{

    EnClear(0);
    Employe EmployeAchercher;
    QString nomUtilisateur;
    nomUtilisateur=ui->comboBox_Nom->lineEdit()->text();
    if (nomUtilisateur=="")
    {
        ui->comboBox_Nom->clear();
    }
    prenomRecherche=nomUtilisateur;
    prenomRecherche.remove(nomRecherche+" ");
    qDebug()<<nomUtilisateur<<" "<<nomRecherche<<prenomRecherche;





    EmployeAchercher.RechercherEmployeParNom(nomUtilisateur);
    if (!EmployeAchercher.GetLogin().isEmpty())
    {
        nomRecherche=EmployeAchercher.GetNom();
        AfficheEmployeParNom();
        SetOuputMessage(lastOutputMessage,true);

    }
    else
    {
        if (ui->comboBox_Nom->itemData(0).toString()=="" || ui->comboBox_Nom->currentText()=="")
            SetOuputMessage("Aucune Résultat trouvé",false);

    }

    if (EmployeAchercher.RechercherEmployeParNomPrenom(nomRecherche,prenomRecherche))
    {
        if (!EmployeAchercher.GetLogin().isEmpty())
        {
            AfficheEmployeInstantane(EmployeAchercher);
            SetOuputMessage(lastOutputMessage,true);
        }
        else
        {
            EnClear(0);

        }
    }


}

void employeui::AfficheEmployeParNom()
{

    Employe employeAchercher;

    QString nomUtilisateur=ui->comboBox_Nom->lineEdit()->text();
    vector <QString> vectEmploye;
    vectEmploye=employeAchercher.AfficheEmployeParNom(nomUtilisateur);
    if (vectEmploye[0]!="")
    {
        ui->comboBox_Nom->clear();
        for (int i=0;i!=vectEmploye.size();i++)
        {
            ui->comboBox_Nom->addItem(vectEmploye[i]);
        }


QString r=QString::number(vectEmploye.size());

        QString Message(r+" Resultat de recherche trouvés");
        lastOutputMessage=Message;
        SetOuputMessage(Message,true);
    }




}


void employeui::on_pushButton_Save_clicked()
{
    unsigned long long loginUtilsateur;
    loginUtilsateur=ui->lineEdit_ID->text().toLongLong();
    Employe EmployeTest;
    EmployeTest.RechercherInstEmploye(loginUtilsateur);
    if (EmployeTest.GetLogin().isEmpty())
    {
        QString numeropassport,datenaissance,dateembouche,nom,prenom,login,motdepasse,adressemail,adresse,profession,typecontrat,service,sexe,nationnalite,adressetravail,etatcivil;
        int telephonetravail,nss,cin;

        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_prenom->text();
        login=ui->lineEdit_ID->text();
        adressemail=ui->lineEdit_mailTravail->text();
        adresse=ui->lineEdit_adresse->text();
        profession=ui->lineEdit_profession->text();
        typecontrat=ui->comboBox_contrat->currentText();
        service=ui->comboBox_service->currentText();
        sexe=ui->comboBox_sexe->currentText();
        nationnalite=ui->lineEdit_nationnalite->text();
        adressetravail=ui->lineEdit_adresseTravail->text();
        etatcivil=ui->comboBox_EtatCivil->currentText();


        nss=ui->lineEdit_NSS->text().toInt();
        numeropassport=ui->lineEdit_passport->text();
        telephonetravail=ui->lineEdit_telephoneTravail->text().toInt();
        cin=ui->lineEdit_CIN->text().toInt();
        datenaissance=ui->dateEdit_dateNaissance->text();
        dateembouche=ui->dateEdit_dateEmbouche->text();
        motdepasse=ui->lineEdit_motdepasse->text();

        VerifNom();
        VerifPrenom();
        VerifService();
        VerifNSS();
        VerifPassport();
        VerifCIN();
        VerifPassword();
        VerifPasswordIndiv();
        VerifAdresse();
        VerifAdresseTravail();
        VerifTelephoneTravail();
        VerifMail();
        VerifSexe();
        VerifEtatCivil();
        VerifNationnalite();
        VerifdateNaissance();
        VerifProfession();
        VerifTypeContrat();
        VerifDateEmbouchement();




        if (VerifProfession() && VerifTypeContrat() && VerifDateEmbouchement() && VerifNationnalite() && VerifdateNaissance() && VerifSexe() && VerifEtatCivil() && VerifTelephoneTravail() && VerifMail() && VerifAdresse() && VerifAdresseTravail() && VerifNom() && VerifPrenom() && VerifService() && VerifNSS() && VerifPassport() && VerifCIN() && VerifPassword() && VerifPasswordIndiv())
        {
            Employe NewEmploye(nom,prenom,login,motdepasse,adressemail,adresse,datenaissance,profession,typecontrat,dateembouche,service,sexe,nationnalite,etatcivil,adressetravail,numeropassport,nss,cin,telephonetravail);
            NewEmploye.AjoutImage(fileNameImage);
            NewEmploye.AjoutEmploye();
            EnClear(0);
            SetOuputMessage("L'employé a été ajouté avec succès ! ",true);

            fileNameImage="";
        }
        else
            SetOuputMessage("L'employé n'as pas été ajouté, Veuillez verifier les champs à saisir !",false);

    }
    else if (EmployeTest.GetLogin().toLongLong()==loginUtilsateur)
    {
        SetOuputMessage("L'employé que vous-voulez ajouter existe déjà dans la base de données",false);

    }
}

void employeui::on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifNom();
}

void employeui::on_lineEdit_prenom_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifPrenom();
}

void employeui::on_lineEdit_NSS_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifNSS();
}

void employeui::on_lineEdit_passport_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifPassport();
}

void employeui::on_lineEdit_CIN_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifCIN();
}

void employeui::on_lineEdit_confirmermotdepasse_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifPassword();
}

void employeui::on_comboBox_service_currentIndexChanged(int index)
{
    if (AppelAffiche)
        VerifService();
}

void employeui::on_lineEdit_motdepasse_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifPasswordIndiv();

}

void employeui::on_lineEdit_adresse_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifAdresse();
}

void employeui::on_lineEdit_adresseTravail_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifAdresseTravail();
}

void employeui::on_lineEdit_telephoneTravail_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifTelephoneTravail();
}

void employeui::on_lineEdit_mailTravail_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifMail();
}

void employeui::on_comboBox_sexe_currentIndexChanged(int index)
{
    if (AppelAffiche)
        VerifSexe();
}

void employeui::on_comboBox_EtatCivil_currentIndexChanged(int index)
{
    if (AppelAffiche)
        VerifEtatCivil();
}

void employeui::on_lineEdit_nationnalite_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifNationnalite();
}

void employeui::on_dateEdit_dateNaissance_dateChanged(const QDate &date)
{
    if (AppelAffiche)
        VerifdateNaissance();
}

void employeui::on_dateEdit_dateEmbouche_dateChanged(const QDate &date)
{
    if (AppelAffiche)
        VerifDateEmbouchement();
}

void employeui::on_lineEdit_profession_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffiche)
        VerifProfession();
}

void employeui::on_comboBox_contrat_currentIndexChanged(const QString &arg1)
{
    if (AppelAffiche)
        VerifTypeContrat();
}

bool employeui::VerifNom()
{


    /*QRegExp("[^a-zA-Z\\d\\s]*/
    if (ui->lineEdit_nom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom->text().isEmpty())
    {
        ui->label_NomControl->setPixmap(PixFalseIcon);
        ui->label_NomControl->setToolTip( tr("Le nom de l'employé doit comporté seulement des lettres alphabétique !"));
        return false;
    }
    else
    {
        ui->label_NomControl->setPixmap(PixTrueIcon);
        return true;
    }

}

bool employeui::VerifPrenom()
{

    if (ui->lineEdit_prenom->text().contains(QRegExp("[^a-zA-Z ]")) || ui->lineEdit_prenom->text().isEmpty())
    {
        ui->label_PrenomControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_PrenomControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool employeui::VerifNSS()
{


    if (ui->lineEdit_NSS->text().contains(QRegExp("[^0-9]")) || ui->lineEdit_NSS->text().isEmpty())
    {
        ui->label_NssControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_NssControl->setPixmap(PixTrueIcon);
        return true;
    }


}

bool employeui::VerifPassport()
{


    if (ui->lineEdit_passport->text().contains(QRegExp("[^a-zA-Z0-9]")) || ui->lineEdit_passport->text().isEmpty())
    {
        ui->label_PassportControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_PassportControl->setPixmap(PixTrueIcon);
        return true;
    }


}

bool employeui::VerifCIN()
{


    if (ui->lineEdit_CIN->text().contains(QRegExp("[^0-9]")) || ui->lineEdit_CIN->text().isEmpty() || ui->lineEdit_CIN->text().length()!=8)
    {
        ui->label_CinControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_CinControl->setPixmap(PixTrueIcon);
        return true;
    }


}

bool employeui::VerifPassword()
{

    if (!ui->lineEdit_motdepasse->text().isEmpty() && !ui->lineEdit_confirmermotdepasse->text().isEmpty())
    {
        if (ui->lineEdit_motdepasse->text()==ui->lineEdit_confirmermotdepasse->text())
        {
            ui->label_PasswordConfirmControl->setPixmap(PixTrueIcon);

            return true;
        }
        else
        {
            ui->label_PasswordConfirmControl->setPixmap(PixFalseIcon);

            return false;
        }
    }
    else
        return false;

}

bool employeui::VerifService()
{
    if (ui->comboBox_service->currentIndex()>-1)
    {
        ui->label_ServiceControl->setPixmap(PixTrueIcon);
        return true;
    }
    else
    {
        ui->label_ServiceControl->setPixmap(PixFalseIcon);
        return false;

    }
}

bool employeui::VerifPasswordIndiv()
{
    if (ui->lineEdit_motdepasse->text().length()<6 || ui->lineEdit_motdepasse->text().isEmpty())
    {
        ui->label_PasswordControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_PasswordControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool employeui::VerifAdresse()
{
    if (ui->lineEdit_adresse->text().isEmpty())
    {
        ui->label_AdresseControl->setPixmap(PixFalseIcon);
        return false;
    }
    else

    {
        ui->label_AdresseControl->setPixmap(PixTrueIcon);

        return true;
    }
}

bool employeui::VerifAdresseTravail(){


    if (ui->lineEdit_adresseTravail->text().isEmpty())
    {
        ui->label_AdresseTravailControl->setPixmap(PixFalseIcon);
        return false;
    }
    else

    {
        ui->label_AdresseTravailControl->setPixmap(PixTrueIcon);

        return true;
    }
}

bool employeui::VerifTelephoneTravail(){

    if (ui->lineEdit_telephoneTravail->text().isEmpty() || ui->lineEdit_telephoneTravail->text().contains(QRegExp("[^0-9]")) || ui->lineEdit_telephoneTravail->text().length()!=8)
    {
        ui->label_TelephoneTravailControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_TelephoneTravailControl->setPixmap(PixTrueIcon);
        return true;
    }



}

bool employeui::VerifMail(){

    if (ui->lineEdit_mailTravail->text().isEmpty() || (ui->lineEdit_mailTravail->text().lastIndexOf("@",-1)>ui->lineEdit_mailTravail->text().lastIndexOf(".",-1)) || ui->lineEdit_mailTravail->text().lastIndexOf("@",-1)==-1 || ui->lineEdit_mailTravail->text().lastIndexOf("@",-1)==-1)
    {
        ui->label_mailControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_mailControl->setPixmap(PixTrueIcon);
        return true;


    }
}

bool employeui::VerifSexe()
{
    if (ui->comboBox_sexe->currentIndex()>-1)
    {
        ui->label_SexeControl->setPixmap(PixTrueIcon);
        return true;
    }
    else
    {
        ui->label_SexeControl->setPixmap(PixFalseIcon);
        return false;
    }
}

bool employeui::VerifEtatCivil(){
    if (ui->comboBox_EtatCivil->currentIndex()>-1)
    {
        ui->label_EtatCivilControl->setPixmap(PixTrueIcon);
        return true;
    }
    else
    {
        ui->label_EtatCivilControl->setPixmap(PixFalseIcon);
        return false;
    }
}

bool employeui::VerifNationnalite(){

    if (ui->lineEdit_nationnalite->text().isEmpty() || ui->lineEdit_nationnalite->text().contains(QRegExp("[0-9 ]")) || ui->lineEdit_nationnalite->text().length()<3)
    {
        ui->label_NationnaliteControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_NationnaliteControl->setPixmap(PixTrueIcon);
        return true;
    }



}

bool employeui::VerifDateEmbouchement()
{
    if ((ui->dateEdit_dateEmbouche->date().year() - ui->dateEdit_dateNaissance->date().year())>0)
    {

        ui->label_DateEmbouchementControl->setPixmap(PixTrueIcon);

        return true;
    }
    else
    {
        ui->label_DateEmbouchementControl->setPixmap(PixFalseIcon);
        return false;
    }

}

bool employeui::VerifdateNaissance()
{
    if (ui->dateEdit_dateNaissance->date()==QDate::fromString("01/01/1800","dd/MM/yyyy"))
    {
        ui->label_DateNaissanceControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_DateNaissanceControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool employeui::VerifProfession()
{
    if (ui->lineEdit_profession->text().isEmpty() || ui->lineEdit_profession->text().length()<3)
    {
        ui->label_professionControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_professionControl->setPixmap(PixTrueIcon);
        return true;

    }




}

bool employeui::VerifTypeContrat(){
    if (ui->comboBox_contrat->currentIndex()>-1)
    {
        ui->label_ContratControl->setPixmap(PixTrueIcon);
        return true;
    }
    else
    {
        ui->label_ContratControl->setPixmap(PixFalseIcon);
        return false;

    }



}

bool employeui::verifID(){
    if (ui->lineEdit_ID->text().isEmpty() || ui->lineEdit_ID->text().length()<3 || ui->lineEdit_ID->text().contains(QRegExp("[^0-9]")))
    {
        ui->label_IDControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_IDControl->setPixmap(PixTrueIcon);
        return true;

    }




}

bool employeui::verifIDPointage(){
    if (ui->lineEdit_IDRechercherPointage->text().contains(QRegExp("[^0-9]")))
    {
        ui->label_RechercherPointageControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_RechercherPointageControl->setPixmap(PixTrueIcon);
        return true;

    }
}

bool employeui::verifIDPaiement(){
    if (ui->lineEdit_IDPaiementEmploye->text().isEmpty() || ui->lineEdit_IDPaiementEmploye->text().length()<3 || ui->lineEdit_IDPaiementEmploye->text().contains(QRegExp("[^0-9]")))
    {
        ui->label_IDPaiementControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_IDPaiementControl->setPixmap(PixTrueIcon);
        return true;

    }




}

bool employeui::VerifMontantTTCPaiement(){

    if (ui->lineEdit_MontantTTC->text().isEmpty() || ui->lineEdit_MontantTTC->text().contains(QRegExp("[^.0-9]")) || ui->lineEdit_MontantTTC->text().length()<3 || ui->lineEdit_MontantTTC->text().length()>8)
    {
        ui->label_MontantControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {
        ui->label_MontantControl->setPixmap(PixTrueIcon);
        return true;
    }



}

bool employeui::VerifdateFichePaie()
{
    if (ui->dateEdit_Paiement->date()==QDate::fromString("01/01/1800","dd/MM/yyyy"))
    {
        ui->label_DatePaiementControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_DatePaiementControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool employeui::verifIDConge(){
    if (ui->lineEdit_IDCongeEmploye->text().isEmpty() || ui->lineEdit_IDCongeEmploye->text().length()<3 || ui->lineEdit_IDCongeEmploye->text().contains(QRegExp("[^0-9]")))
    {
        ui->label_IDCongeControl->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->label_IDCongeControl->setPixmap(PixTrueIcon);
        return true;

    }




}

bool employeui::VerifTypeConge(){
    if (ui->comboBox_TypeConge->currentIndex()>-1)
    {
        ui->label_typeCongeControl->setPixmap(PixTrueIcon);
        return true;
    }
    else
    {
        ui->label_typeCongeControl->setPixmap(PixFalseIcon);
        return false;
    }
}

bool employeui::VerifdateDebutConge()
{
    if (ui->dateEdit_DebutConge->date()==QDate::fromString("01/01/1800","dd/MM/yyyy"))
    {
        ui->label_DateDebutCongeControl->setPixmap(PixFalseIcon);
        return false;
    }
    else
    {

        ui->label_DateDebutCongeControl->setPixmap(PixTrueIcon);
        return true;
    }
}

bool employeui::VerifDateFinConge()
{
    if (((ui->dateEdit_DebutConge->date().year() - ui->dateEdit_FinConge->date().year())>=0) && ((ui->dateEdit_FinConge->date().month() - ui->dateEdit_DebutConge->date().month())>=0) &&  ((ui->dateEdit_FinConge->date().day() - ui->dateEdit_DebutConge->date().day())>0))
    {

        ui->label_DateFinCongeControl->setPixmap(PixTrueIcon);

        return true;
    }
    else
    {
        ui->label_DateFinCongeControl->setPixmap(PixFalseIcon);
        return false;
    }

}

void employeui::on_pushButton_Edit_clicked()
{
    Employe EmployeAmodifier;
    unsigned long long loginUtilisateur=ui->lineEdit_ID->text().toLongLong();
    EmployeAmodifier.RechercherInstEmploye(loginUtilisateur);
    if (!EmployeAmodifier.GetLogin().isEmpty())
    {
        EmployeAmodifier.SetNom(ui->lineEdit_nom->text());
        EmployeAmodifier.SetPrenom(ui->lineEdit_prenom->text());
        EmployeAmodifier.SetLogin(ui->lineEdit_ID->text());
        EmployeAmodifier.SetAdresseMail(ui->lineEdit_mailTravail->text());
        EmployeAmodifier.SetAdresse(ui->lineEdit_adresse->text());
        EmployeAmodifier.SetProfession(ui->lineEdit_profession->text());
        EmployeAmodifier.SetTypeContrat(ui->comboBox_contrat->currentText());
        EmployeAmodifier.SetService(ui->comboBox_service->currentText());
        EmployeAmodifier.SetSexe(ui->comboBox_sexe->currentText());
        EmployeAmodifier.SetNationnalite(ui->lineEdit_nationnalite->text());
        EmployeAmodifier.SetAdresseTravail(ui->lineEdit_adresseTravail->text());
        EmployeAmodifier.SetEtatCivil(ui->comboBox_EtatCivil->currentText());


        EmployeAmodifier.SetNss(ui->lineEdit_NSS->text().toInt());
        EmployeAmodifier.SetNumeroPasseport(ui->lineEdit_passport->text());
        EmployeAmodifier.SetTelephoneTravail(ui->lineEdit_telephoneTravail->text().toInt());
        EmployeAmodifier.SetCin(ui->lineEdit_CIN->text().toInt());
        EmployeAmodifier.SetDateNaissance(ui->dateEdit_dateNaissance->text());
        EmployeAmodifier.SetDateEmbouche(ui->dateEdit_dateEmbouche->text());
        EmployeAmodifier.SetMotDePasse(ui->lineEdit_motdepasse->text());

        if (fileNameImage!="")
        {
            EmployeAmodifier.AjoutImage(fileNameImage);
        }
        fileNameImage="";



        VerifNom();
        VerifPrenom();
        VerifService();
        VerifNSS();
        VerifPassport();
        VerifCIN();
        VerifPassword();
        VerifPasswordIndiv();
        VerifAdresse();
        VerifAdresseTravail();
        VerifTelephoneTravail();
        VerifMail();
        VerifSexe();
        VerifEtatCivil();
        VerifNationnalite();
        VerifdateNaissance();
        VerifProfession();
        VerifTypeContrat();
        VerifDateEmbouchement();
        if (VerifProfession() && VerifTypeContrat() && VerifDateEmbouchement() && VerifNationnalite() && VerifdateNaissance() && VerifSexe() && VerifEtatCivil() && VerifTelephoneTravail() && VerifMail() && VerifAdresse() && VerifAdresseTravail() && VerifNom() && VerifPrenom() && VerifService() && VerifNSS() && VerifPassport() && VerifCIN() && VerifPassword() && VerifPasswordIndiv())
        {
            EmployeAmodifier.ModifierEmploye();
            SetOuputMessage("L'employé à été modifié avec succès ",true);
        }
        else
            SetOuputMessage("L'employé n'as pas été modifié, Veuillez verifier les champs à saisir !",false);

    }
    else
    {

        SetOuputMessage("L'employé que vous voulez modifier n'existe pas dans la base de données",false);




    }
}



void employeui::on_pushButton_AjoutConge_clicked()
{
    QString typeconge,loginemploye,commentaireresponsable,commentaireemploye,datedebutConge,datefinConge;



    typeconge=ui->comboBox_TypeConge->currentText();
    datedebutConge=ui->dateEdit_DebutConge->date().toString();
    datefinConge=ui->dateEdit_FinConge->date().toString();
    commentaireresponsable=ui->textEdit_Responsable->toPlainText();
    commentaireemploye=ui->textEdit_Employe->toPlainText();
    loginemploye=ui->lineEdit_IDCongeEmploye->text();


    verifIDConge();
    VerifTypeContrat();
    VerifdateDebutConge();
    VerifDateFinConge();

    unsigned long long loginUtilsateur;
    loginUtilsateur=ui->lineEdit_IDCongeEmploye->text().toLongLong();
    loginemploye=ui->lineEdit_IDCongeEmploye->text();
    Employe EmployeTest;
    EmployeTest.RechercherInstEmploye(loginUtilsateur);


    if (EmployeTest.GetLogin().isEmpty())
    {
        SetOuputMessageConge("L'employé assosié au conge n'existe pas dans la base de données",false);
    }
    else
    {

        if (verifIDConge() && VerifTypeConge() && VerifdateDebutConge() && VerifdateDebutConge())
        {

            Conge newConge(loginemploye,typeconge,commentaireresponsable,commentaireemploye,datedebutConge,datefinConge);
            newConge.AjoutConge();
            SetOuputMessageConge("Le congé à été ajouté avec succès",true);
        }
        else
        {
            SetOuputMessageConge("Le congé n'as pas été ajouté,Vérifiez les champs à saisir",false);
        }

    }


}

void employeui::on_pushButton_ModifierConge_clicked()
{
    Conge CongeAmodifier;
    CongeAmodifier.RechercherConge(ui->lineEdit_IDCongeEmployeRechercher->text());
    if (!CongeAmodifier.getLoginEmploye().isEmpty())
    {
        verifIDConge();
        VerifTypeConge();
        VerifdateDebutConge();
        VerifDateFinConge();

        if (verifIDConge() && VerifTypeConge() && VerifdateDebutConge() && VerifDateFinConge())
        {
            CongeAmodifier.setIdConge(ui->lineEdit_IDCongeEmployeRechercher->text().toLongLong());
            CongeAmodifier.setLoginEmploye(ui->lineEdit_IDCongeEmploye->text());
            CongeAmodifier.setTypeConge(ui->comboBox_TypeConge->currentText());
            CongeAmodifier.setCommentaireEmploye(ui->textEdit_Employe->toPlainText());
            CongeAmodifier.setCommentaireResponsable(ui->textEdit_Responsable->toPlainText());
            CongeAmodifier.setDateDebutConge(ui->dateEdit_DebutConge->text());
            CongeAmodifier.setDateFinConge(ui->dateEdit_FinConge->text());

            CongeAmodifier.ModifierConge();

            SetOuputMessageConge("Le conge à été modifié avec succès",true);
        }
        else
            SetOuputMessageConge("Le congé n'as pas été modifié,Verfiez les champs à saisir",false);

    }
    else
        SetOuputMessageConge("Le conge que vous voulez modifier n'existe pas dans la base de données",false);
}

void employeui::on_lineEdit_IDCongeEmployeRechercher_cursorPositionChanged(int arg1, int arg2)
{

    QString login=ui->lineEdit_IDCongeEmployeRechercher->text();
    Conge CongeAchercher;
    CongeAchercher.RechercherConge(login);


    if (!CongeAchercher.getLoginEmploye().isEmpty())
    {

        AfficheCongeInstantaneConge(CongeAchercher);
        SetOuputMessageConge("1 Résultat trouvé",true);

    }


    else
    {
        EnClearConge();
        SetOuputMessageConge("Aucun Résultat trouvé",false);
    }



}

void employeui::AfficheCongeInstantaneConge(Conge CongeAafficher)
{

    AppelAfficheConge=false;
    ui->lineEdit_IDCongeEmploye->setText(CongeAafficher.getLoginEmploye());
    ui->comboBox_TypeConge->setCurrentIndex(ui->comboBox_TypeConge->findData(CongeAafficher.getTypeConge(), Qt::DisplayRole));
    ui->dateEdit_DebutConge->setDate(QDate::fromString(CongeAafficher.getDateDebutConge(),"dd/MM/yyyy"));
    ui->dateEdit_FinConge->setDate(QDate::fromString(CongeAafficher.getDateFinConge(),"dd/MM/yyyy"));
    ui->textEdit_Employe->setText(CongeAafficher.getCommentaireEmploye());
    ui->textEdit_Responsable->setText(CongeAafficher.getCommentaireResponsable());
    AppelAfficheConge=true;
}

void employeui::on_pushButton_SupprimerConge_clicked()
{
    Conge CongeAmodifier;
    CongeAmodifier.RechercherConge(ui->lineEdit_IDCongeEmployeRechercher->text());
    if (!CongeAmodifier.getLoginEmploye().isEmpty())
    {
        CongeAmodifier.setIdConge(ui->lineEdit_IDCongeEmployeRechercher->text().toLongLong());
        CongeAmodifier.setLoginEmploye(ui->lineEdit_IDCongeEmploye->text());
        CongeAmodifier.setTypeConge(ui->comboBox_TypeConge->currentText());
        CongeAmodifier.setCommentaireEmploye(ui->textEdit_Employe->toPlainText());
        CongeAmodifier.setCommentaireResponsable(ui->textEdit_Responsable->toPlainText());
        CongeAmodifier.setDateDebutConge(ui->dateEdit_DebutConge->text());
        CongeAmodifier.setDateFinConge(ui->dateEdit_FinConge->text());
        CongeAmodifier.SupprimerConge();
        SetOuputMessageConge("Le conge à été supprimé avec succès",true);

    }
    else
        SetOuputMessageConge("Le conge n'as pas été supprimé,Verifiez le login de l'employé",false);







}

void employeui::on_pushButton_AjoutPaiement_clicked()
{

    QString loginemploye,commentaireresponsable,datePaiement;
    float montantTTC;

    loginemploye=ui->lineEdit_IDPaiementEmploye->text();
    commentaireresponsable=ui->textEdit_PaiementResponsable->toPlainText();
    datePaiement=ui->dateEdit_Paiement->text();
    montantTTC=ui->lineEdit_MontantTTC->text().toFloat();

    verifIDPaiement();
    VerifMontantTTCPaiement();
    VerifdateFichePaie();

    unsigned long long loginUtilsateur;
    loginUtilsateur=ui->lineEdit_IDPaiementEmploye->text().toLongLong();
    loginemploye=ui->lineEdit_IDPaiementEmploye->text();
    Employe EmployeTest;
    EmployeTest.RechercherInstEmploye(loginUtilsateur);
    if (EmployeTest.GetLogin().isEmpty())
    {
        SetOuputMessagePaiement("L'employé assosié à la fiche de paie n'existe pas dans la base de données",false);
    }
    else
    {
        if (verifIDPaiement() && VerifMontantTTCPaiement() && VerifdateFichePaie())
        {
            FichePaie NewPaiement(loginemploye,montantTTC,datePaiement,commentaireresponsable);
            NewPaiement.AjoutPaiement();
            SetOuputMessagePaiement("La Fiche de paie à été ajouté avec succès",true);
            qDebug()<<"AJOUT AJOUT";
        }
        else
            SetOuputMessagePaiement("La Fiche de paie n'as pas été ajouté,Vérifiez les champs à saisir",false);
    }
}

void employeui::AffichePaiementInstantane(FichePaie PaiementAafficher)
{
    QString montant=QString::number(PaiementAafficher.GetMontantTTC());

    AppelAffichePaiement=false;
    ui->lineEdit_IDPaiementEmploye->setText(PaiementAafficher.getLoginEmploye());
    ui->lineEdit_MontantTTC->setText(montant);
    ui->dateEdit_Paiement->setDate(QDate::fromString(PaiementAafficher.GetDatePaiement(),"dd/MM/yyyy"));
    ui->textEdit_PaiementResponsable->setText(PaiementAafficher.GetCommentaireResponsable());
    AppelAffichePaiement=true;

}

void employeui::on_lineEdit_IDPaiementEmployeRecherche_cursorPositionChanged(int arg1, int arg2)
{
    QString login=ui->lineEdit_IDPaiementEmployeRecherche->text();
    FichePaie PaiementAchercher;
    PaiementAchercher.RechercherPaiement(login);


    if (!PaiementAchercher.getLoginEmploye().isEmpty())
    {

        AffichePaiementInstantane(PaiementAchercher);
        SetOuputMessagePaiement("1 Résultat trouvé",true);
    }
    else
    {
        EnClearPaiement();
        SetOuputMessagePaiement("Aucun Résultat trouvé",false);
    }



}

void employeui::on_lineEdit_IDRechercherPointage_cursorPositionChanged(int arg1, int arg2)
{
    int RowCount;
    QString login=ui->lineEdit_IDRechercherPointage->text();
    pointage point;
    verifIDPointage();

    ui->tableViewPointage->setModel(Pointage.ConsulterPointageParticulier(login,&RowCount));
    QString r = QString::number(RowCount);
    if (RowCount==0)
        SetOuputMessagePointage("Aucun Résultat trouvés",false);
    else
        SetOuputMessagePointage(r+" Résultats trouvés",true);


}

void employeui::InitIndication(){
    ui->lineEdit_nom->setToolTip( tr("Le nom de l'employé doit non-vide et seulement composé par des lettres alphabétique !"));

    ui->lineEdit_prenom->setToolTip(tr("Le prenom de l'employé doit être non-vide et seulement composé par des lettres alphabétique !"));
    ui->comboBox_service->setToolTip(tr("Un service doit être choisi !"));
    ui->lineEdit_NSS->setToolTip(tr("Le numéro de sécurité social doit être non-vide et seulement composé par des chiffres!"));
    ui->lineEdit_ID->setToolTip(tr("Le numéro d'identification (Login) doit être non-vide et seulement composé seulement des numéros et doit comporté plus deux numéros !"));
    ui->lineEdit_passport->setToolTip(tr("Le numéro de passeport doit être non-vide et seulement composé par des lettres alphabétique et des chiffres !"));
    ui->lineEdit_CIN->setToolTip(tr("Le numéro de carte d'identité (CIN) doit être non-vide et seulement composé par  des chifrres, Exactment huit chiffres !"));
    ui->lineEdit_motdepasse->setToolTip(tr("Le mot de passe doit être non-vide et comporte plus que 5 caractères !"));
    ui->lineEdit_confirmermotdepasse->setToolTip(tr("Le champ mot de passe et confirmer mot de passe doivent êtres identiques !"));
    ui->lineEdit_adresse->setToolTip(tr("L'adresse d'habitation doit être non-vide !"));
    ui->lineEdit_adresseTravail->setToolTip(tr("L'adresse de travail doit être non-vide !"));
    ui->lineEdit_telephoneTravail->setToolTip(tr("Le telephone de travail doit être non-vide et seulement composé par des chiffres, Exactement composé de huite chiffres !"));
    ui->lineEdit_mailTravail->setToolTip(tr("Le mail doit être non-vide, comporte le caractère '@' et '.' et le @ doit être positionné avant le '.'"));
    ui->comboBox_sexe->setToolTip(tr("Un sexe doit être choisi !"));
    ui->comboBox_EtatCivil->setToolTip(tr("Un etat civil doit être choisi !"));
    ui->lineEdit_nationnalite->setToolTip(tr("La nationnalité doit être non-vide et seulement composé par des lettres alphabétique,Plus que deux lettres !"));
    ui->dateEdit_dateNaissance->setToolTip(tr("La date de naissance doit être changé !"));
    ui->dateEdit_dateEmbouche->setToolTip(tr("La date d'embauche doit être changé est elle doit être supérieur à la date de naissance !"));
    ui->lineEdit_profession->setToolTip(tr("La profession doit être non-vide !"));
    ui->comboBox_contrat->setToolTip(tr("Un type de contrat doit être choisi !"));
    ui->comboBox_Nom->setToolTip(tr("Rechercher un ou plusieur employés par leur nom de famille"));
    ui->pushButton_Save->setToolTip(tr("Ajouter un employé"));
    ui->pushButton_Edit->setToolTip(tr("Modifier un employé"));
    ui->pushButton_supprmier->setToolTip(tr("Supprimer un employé"));
    ui->pushButton_Annuler->setToolTip(tr("Nettoyer la page gestion des employés"));
    ui->pushButton_ListingEmploye->setToolTip(tr("Afficher une liste complète des employés"));
    ui->pushButton_StatistiquesEmploye->setToolTip(tr("Afficher les statistiques"));
    ui->pushButton_ChargerImage->setToolTip(tr("Ajouter une image pour l'employé"));

    ui->lineEdit_IDCongeEmployeRechercher->setToolTip(tr("Rechercher un conge par son ID"));
    ui->lineEdit_IDCongeEmploye->setToolTip(tr("Le numéro d'identification (Login) doit être non-vide et seulement composé seulement des numéros et doit comporté plus deux numéros !"));
    ui->comboBox_TypeConge->setToolTip(tr("Un type de congé doit être choisi !"));
    ui->dateEdit_DebutConge->setToolTip(tr("La date de debut du congé doit être changé !"));
    ui->dateEdit_FinConge->setToolTip(tr("La date de fin du congé doit être changé et supérieur au moins d'une journée à la date de début du congé"));
    ui->textEdit_Responsable->setToolTip(tr("Ce champ n'est pas obligatoire !"));
    ui->textEdit_Employe->setToolTip(tr("Ce champ n'est pas obligatoire !"));
    ui->pushButton_AjoutConge->setToolTip(tr("Ajouter un congé"));
    ui->pushButton_ModifierConge->setToolTip(tr("Modifier un congé"));
    ui->pushButton_SupprimerConge->setToolTip(tr("Supprimer un congé"));
    ui->pushButton_NettoyerConge->setToolTip(tr("Nettoyer la page gestion des congés"));
    ui->pushButton_ListingConge->setToolTip(tr("Afficher une liste des congés"));

    ui->lineEdit_IDPaiementEmployeRecherche->setToolTip(tr("Rechercher une fiche de paie par son ID"));
    ui->lineEdit_IDPaiementEmploye->setToolTip(tr("Le numéro d'identification (Login) doit être non-vide et seulement composé seulement des numéros et doit comporté plus deux numéros !"));
    ui->lineEdit_MontantTTC->setToolTip(tr("Le montant doit être non-vide et ne doit pas dépasser huit chiffres, quatre avant et après la virgule !"));
    ui->dateEdit_Paiement->setToolTip(tr("La date de paiement doit être changé !"));
    ui->textEdit_PaiementResponsable->setToolTip(tr("Ce champ n'est pas obligatoire !"));
    ui->pushButton_AjoutPaiement->setToolTip(tr("Ajouter une fiche de paie"));
    ui->pushButton_ListingPaiement->setToolTip(tr("Afficher une liste des fiches de paie"));
    ui->pushButton_NettoyerPaiement->setToolTip(tr("Nettoyer la page gestion des fiches de paie"));

    ui->lineEdit_IDRechercherPointage->setToolTip(tr("Rechercher un pointage par le numéro d'identification de l'employé (Login)"));



}

void employeui::on_lineEdit_IDPaiementEmploye_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffichePaiement)
        verifIDPaiement();
}

void employeui::on_lineEdit_MontantTTC_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAffichePaiement)
        VerifMontantTTCPaiement();
}

void employeui::on_dateEdit_Paiement_dateChanged(const QDate &date)
{
    if (AppelAffichePaiement)
        VerifdateFichePaie();
}



void employeui::on_pushButton_ListingPaiement_clicked()
{
    ListingPaiement listFichePaie;
    listFichePaie.setModal(true);
    listFichePaie.exec();
}

void employeui::on_lineEdit_IDCongeEmploye_cursorPositionChanged(int arg1, int arg2)
{
    if (AppelAfficheConge)
        verifIDConge();
}

void employeui::on_comboBox_TypeConge_currentIndexChanged(int index)
{
    if (AppelAfficheConge)
        VerifTypeConge();
}

void employeui::on_dateEdit_DebutConge_dateChanged(const QDate &date)
{
    if (AppelAfficheConge)
        VerifdateDebutConge();
}

void employeui::on_dateEdit_FinConge_dateChanged(const QDate &date)
{
    if (AppelAfficheConge)
        VerifDateFinConge();
}

void employeui::on_pushButton_NettoyerConge_clicked()
{
    EnClearConge();
}





void employeui::on_pushButton_StatistiquesEmploye_clicked()
{
    Statistiques stat;
    stat.setModal(true);
    stat.exec();
}

void employeui::on_pushButton_ListingConge_clicked()
{
    ListingConge listConge;
    listConge.setModal(true);
    listConge.exec();
}

void employeui::on_pushButton_ListingEmploye_clicked()
{
    listingEmploye listEmploye;
    listEmploye.setModal(true);
    listEmploye.exec();
}


void employeui::on_pushButton_NettoyerPaiement_clicked()
{
    EnClearPaiement();
}
