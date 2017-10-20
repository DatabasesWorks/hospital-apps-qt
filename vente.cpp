#include "vente.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

vente::vente()
{

}
vente::vente( QString identifiant,float prix_Achat,float marge_B,int quantite)
{
    this->identifiant=identifiant;
    this->prix_Achat=prix_Achat;
    this->marge_B=marge_B;
    this->quantite=quantite;
}
bool vente::AjouterVente()
{

    QSqlQuery query;
    QString prix=QString::number(prix_Achat);
    QString marge=QString::number(marge_B);
    QString quantite1=QString::number(quantite);


    QString tmp= "insert into vente values('"+identifiant+"',"+prix+","+marge+","+quantite1+")";

    return(query.exec(tmp));
}
bool vente::RechercherInstVente(int  id_v)
{


    QSqlQuery query;
    QByteArray array;
    if (id_v!=0)
    {
    query.prepare("Select * from Vente where identifiant=:id_v");
    query.bindValue(":id_v", id_v);
    query.exec();

    while(query.next())
    {
        qDebug()<<"HEY HEY";

        identifiant=(query.value(0).toString());
        prix_Achat=(query.value(1).toFloat());
        qDebug()<<identifiant;
        marge_B=(query.value(2).toInt());
        quantite=(query.value(3).toInt());



    }
        return true;
    }

    else
        return false;
}


bool vente::ModifierVente(){
    if (!identifiant.isEmpty())
    {

        QSqlQuery query;
        query.prepare("Update Vente set prixAchat=:prix_Achat,margeBenificiere=:marge_B,quantite=:quantite where identifiant=:identifiant");

        query.bindValue(":identifiant",identifiant);
        query.bindValue(":prix_Achat",prix_Achat);
        query.bindValue(":marge_B",marge_B);
        query.bindValue(":quantite",quantite);

        query.exec();
        qDebug()<<"La vente à était modifié avec succeés !";
        return true;
    }

    else {

        qDebug()<<"La vente n'existe pas dans la base de données";
        return false;
    }
    }
