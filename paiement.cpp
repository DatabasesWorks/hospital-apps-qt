#include "paiement.h"

FichePaie::FichePaie(){
     loginEmploye="";
     montantTTC=0.0;
     datePaiement="";
     commentaireResponsable="";
}


bool FichePaie::RechercherPaiement(QString IdPaiementUtilisateur){
QSqlQuery query;
unsigned long long IdPaiementUtilisateur2=IdPaiementUtilisateur.toLongLong();

query.prepare("Select * from Paiement where IdPaiement=:IdPaiement");
query.bindValue(":IdPaiement",IdPaiementUtilisateur2);
if (query.exec())
{
    while (query.next()){


        IdPaiement=(query.value(0).toLongLong());
        loginEmploye=(query.value(1).toString());
        montantTTC=(query.value(2).toFloat());
        commentaireResponsable=(query.value(3).toString());
        datePaiement=(query.value(4).toString());

    }
}
return query.exec();
}





FichePaie::FichePaie(QString loginEmploye,float montantTTC,QString datePaiement,QString commentaireResponsable){
this->loginEmploye=loginEmploye;
this->montantTTC=montantTTC;
this->datePaiement=datePaiement;
this->commentaireResponsable=commentaireResponsable;
}

bool FichePaie::AjoutPaiement(){
    QSqlQuery query;
    query.prepare("INSERT INTO Paiement VALUES (NULL,:loginEmploye,:montantTTC,:commentaireResponsable,:datePaiement)");
    query.bindValue(":loginEmploye",loginEmploye);
    query.bindValue(":montantTTC",montantTTC);
    query.bindValue(":commentaireResponsable",commentaireResponsable);
    query.bindValue(":datePaiement",datePaiement);
 qDebug() << "SqLite error:" << query.lastError().text() << ", SqLite error code:" << query.lastError().number();
    return ((query.exec()));

}



QSqlQueryModel *FichePaie::ConsulterPaiement(){
    QSqlQueryModel * model= new QSqlQueryModel ();
    model->setQuery("select * from Paiement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID de la fiche de paie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Login de l'employe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant TTC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Commentaire Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de la paiement"));
    return model;

}


















