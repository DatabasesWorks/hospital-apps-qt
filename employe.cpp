#include "employe.h"
using namespace std;
Employe::Employe()
{
    nom="";
    prenom="";
    login="";
    motDePasse="";
    adresseMail="";
    adresse="";
    dateNaissance="";
    profession="";
    typeContrat="";
    dateEmbouche="";
    service="";
    sexe="";
    nationnalite="";
    adresseTravail="";
    etatCivil="";
    nss=0;
    numeroPasseport="";
    cin=0;
    telephoneTravail=0;


}
Employe::Employe(QString nom, QString prenom, QString login, QString motDePasse, QString adresseMail, QString adresse, QString dateNaissance, QString profession, QString typeContrat, QString dateEmbouche, QString service, QString sexe, QString nationnalite, QString etatCivil,QString adresseTravail,QString numeroPasseport, int nss,  int cin, int telephoneTravail)
{
    this->nom=nom;
    this->prenom=prenom;
    this->login=login;
    this->motDePasse=motDePasse;
    this->adresseMail=adresseMail;
    this->adresse=adresse;
    this->dateNaissance=dateNaissance;
    this->profession=profession;
    this->typeContrat=typeContrat;
    this->dateEmbouche=dateEmbouche;
    this->service=service;
    this->sexe=sexe;
    this->nationnalite=nationnalite;
    this->adresseTravail=adresseTravail;
    this->etatCivil=etatCivil;
    this->nss=nss;
    this->numeroPasseport=numeroPasseport;
    this->cin=cin;
    this->telephoneTravail=telephoneTravail;
}

Employe::~Employe()
{

}

bool Employe::AjoutEmploye()
{
    QSqlQuery query;
    QString tel=QString::number(telephoneTravail);
    QString nss1=QString::number(nss);
    QString cin1=QString::number(cin);


    query.prepare("INSERT INTO Employe VALUES (:nom,:prenom,:login,:motDepasse,:adresseMail,:adresse,:tel,:dateNaissance,:profession,:typeContrat,:dateEmbouche,:service,:nss1,:numpas,:cin1,:sexe,:nationnalite,:adresseTravail,:etatCivil,:image)");


    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":login",login);
    query.bindValue(":motDePasse",motDePasse);

    query.bindValue(":adresseMail",adresseMail);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);
    query.bindValue(":dateNaissance",dateNaissance);

    query.bindValue(":profession",profession);
    query.bindValue(":typeContrat",typeContrat);
    query.bindValue(":dateEmbouche",dateEmbouche);
    query.bindValue(":service",service);

    query.bindValue(":nss1",nss1);
    query.bindValue(":numpas",numeroPasseport);
    query.bindValue(":cin1",cin1);
    query.bindValue(":sexe",sexe);
    query.bindValue(":nationnalite",nationnalite);

    query.bindValue(":adresseTravail",adresseTravail);
    query.bindValue(":etatCivil",etatCivil);
    query.bindValue(":image", image, QSql::Binary);


return (query.exec());

}


bool Employe::ModifierEmploye(){
    if (!login.isEmpty())
    {

        QSqlQuery query;
        query.prepare("Update Employe set nom=:nom,prenom=:prenom,motdepasse=:motdepasse,adressemail=:adressemail,adresse=:adresse,telephonetravail=:telephonetravail,datenaissance=:datenaissance,profession=:profession,typecontrat=:typecontrat,dateembouche=:dateembouche,service=:service,nss=:nss,numpassport=:numpassport,cin=:cin,sexe=:sexe,nationnalite=:nationnalite,adressetravail=:adressetravail,etatcivil=:etatcivil,image=:image  where login=:login");

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":login",login);
        query.bindValue(":motdepasse",motDePasse);
        query.bindValue(":adressemail",adresseMail);
        query.bindValue(":adresse",adresse);
        query.bindValue(":telephonetravail",telephoneTravail);
        query.bindValue(":datenaissance",dateNaissance);
        query.bindValue(":profession",profession);
        query.bindValue(":typecontrat",typeContrat);
        query.bindValue(":dateembouche",dateEmbouche);
        query.bindValue(":service",service);

        query.bindValue(":nss",nss);
        query.bindValue(":numpassport",numeroPasseport);
        query.bindValue(":cin",cin);
        query.bindValue(":sexe",sexe);
        query.bindValue(":nationnalite",nationnalite);
        query.bindValue(":adressetravail",adresseTravail);
        query.bindValue(":etatcivil",etatCivil);

        query.bindValue(":image", image);

        query.exec();
        qDebug()<<"L'employe à était modifié avec succeés !";
        return true;
    }

    else {

        qDebug()<<"L'employe n'existe pas dans la base de données";
        return false;
    }

}

bool Employe::RechercherInstEmploye(unsigned long long LoginUtilisateur)
{


    QSqlQuery query;
    QByteArray array;
    if (LoginUtilisateur!=0)
    {
    query.prepare("Select * from Employe where login=:login");
    query.bindValue(":login", LoginUtilisateur);
    if (query.exec())
    {
    while(query.next())
    {

        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        login=(query.value(2).toString());
        qDebug()<<"dsqd" <<login;
        motDePasse=(query.value(3).toString());
        adresseMail=(query.value(4).toString());
        adresse=(query.value(5).toString());
        telephoneTravail=(query.value(6).toInt());
        dateNaissance=(query.value(7).toString());
        dateEmbouche=(query.value(10).toString());
        profession=(query.value(8).toString());
        typeContrat=(query.value(9).toString());
        service=(query.value(11).toString());
        nss=(query.value(12).toInt());
        numeroPasseport=(query.value(13).toString());
        cin=(query.value(14).toInt());
        sexe=(query.value(15).toString());
        nationnalite=(query.value(16).toString());
        adresseTravail=(query.value(17).toString());
        etatCivil=(query.value(18).toString());
        array = query.value(19).toByteArray();
        QBuffer buffer(&array);
        image=(array);

    }
        return true;
    }
    }

    else
        return false;
}

bool Employe::SupprimerEmploye()
{
    QSqlQuery query;
    if (!login.isEmpty())
    {
        qDebug()<<"L'employe a été supprimé avec succès !";
        query.prepare("Delete from  Employe where (nom=:nom and prenom=:prenom) and login=:login");
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":login",login);
        query.exec();
        return true;
    }
    else
    {
        qDebug()<<"Cet employe n'existe pas dans la base de données !";
        return false;
    }
}

void  Employe::AjoutImage(QString fileName){


    if (fileName.isEmpty())
    {
        qDebug()<<"EMPTY EMPTY !!!!!";

        fileName="employe-image_standard.png";

    }
    QImage imageTMP(fileName);

    QByteArray byteArray;

    QBuffer buffer(&byteArray);

    imageTMP.save(&buffer, "PNG");

    image=byteArray;
}

bool Employe::RechercherEmployeParNomPrenom(QString nomUtilisateur,QString prenomUtilisateur)
{

    QSqlQuery query;
    QByteArray array;
    if (nomUtilisateur!="")
    {
    query.prepare("Select * from Employe where  nom=:nom and prenom=:prenom");
    query.bindValue(":nom", nomUtilisateur);
    query.bindValue(":prenom", prenomUtilisateur);
    query.exec();
    while(query.next())
    {

        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        login=(query.value(2).toString());
        motDePasse=(query.value(3).toString());
        adresseMail=(query.value(4).toString());
        adresse=(query.value(5).toString());
        telephoneTravail=(query.value(6).toInt());
        dateNaissance=(query.value(7).toString());
        dateEmbouche=(query.value(10).toString());
        profession=(query.value(8).toString());
        typeContrat=(query.value(9).toString());
        service=(query.value(11).toString());
        nss=(query.value(12).toInt());
        numeroPasseport=(query.value(13).toString());
        cin=(query.value(14).toInt());
        sexe=(query.value(15).toString());
        nationnalite=(query.value(16).toString());
        adresseTravail=(query.value(17).toString());
        etatCivil=(query.value(18).toString());
        array = query.value(19).toByteArray();
        QBuffer buffer(&array);
        image=(array);

    }
        return true;
    }

    else
        return false;

}

bool Employe::RechercherEmployeParNom(QString nomUtilisateur)
{

    QSqlQuery query;
    QByteArray array;
    if (nomUtilisateur!="")
    {
    query.prepare("Select * from Employe where nom=:nom");
    query.bindValue(":nom", nomUtilisateur);
    query.exec();
    while(query.next())
    {
        qDebug()<<"ENTER ENTER";
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        login=(query.value(2).toString());
        motDePasse=(query.value(3).toString());
        adresseMail=(query.value(4).toString());
        adresse=(query.value(5).toString());
        telephoneTravail=(query.value(6).toInt());
        dateNaissance=(query.value(7).toString());
        dateEmbouche=(query.value(10).toString());
        profession=(query.value(8).toString());
        typeContrat=(query.value(9).toString());
        service=(query.value(11).toString());
        nss=(query.value(12).toInt());
        numeroPasseport=(query.value(13).toString());
        cin=(query.value(14).toInt());
        sexe=(query.value(15).toString());
        nationnalite=(query.value(16).toString());
        adresseTravail=(query.value(17).toString());
        etatCivil=(query.value(18).toString());
        array = query.value(19).toByteArray();
        QBuffer buffer(&array);
        image=(array);

    }
        return true;
    }

    else
        return false;

}

QSqlQueryModel *Employe::AfficherEmploye(){
    QSqlQueryModel * model= new QSqlQueryModel ();
    model->setQuery("select * from Employe");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Login"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse Mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse d'habitation"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de Naissance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Profession"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Type de contrat"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Date d'embouchement"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Service"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Numéro de sécurité social"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("Numéro de passeport"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("Carte d'identité nationnale"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(16, Qt::Horizontal, QObject::tr("Nationnalite"));
    model->setHeaderData(17, Qt::Horizontal, QObject::tr("Adresse de travail"));
    model->setHeaderData(18, Qt::Horizontal, QObject::tr("Etat civil"));
    model->setHeaderData(19, Qt::Horizontal, QObject::tr("Image"));


    return model;




}





vector<QString> Employe::AfficheEmployeParNom(QString nomUtilisateur)
{


    vector <QString>vectEmploye;
    QSqlQuery query;
    query.prepare("Select * from Employe where nom=:nom");
    query.bindValue(":nom",nomUtilisateur);
    if (query.exec())
    {
        while (query.next())
        {
            vectEmploye.push_back(query.value(0).toString()+" "+query.value(1).toString());
        }
    }



return vectEmploye;
}






















