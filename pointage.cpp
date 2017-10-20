#include "pointage.h"
using namespace std;
pointage::pointage()
{
}

pointage pointage::RechercherPointage(QString loginEmployeUtilisateur){
pointage PointageAConsulter;
QSqlQuery query;
query.prepare("Select * from Pointage where IdEmploye=:loginEmploye");
query.bindValue(":loginEmploye",loginEmployeUtilisateur);
if (query.exec())
{
    while (query.next()){

        PointageAConsulter.idPointage=(query.value(0).toLongLong());
        PointageAConsulter.loginEmploye=(query.value(1).toString());
        PointageAConsulter.dateDebutPointage=(query.value(2).toString());
        PointageAConsulter.dateFinPointage=(query.value(3).toString());

    }
}
return PointageAConsulter;
}



QSqlQueryModel *pointage::ConsulterPointageGlobale(){
    QSqlQueryModel * model= new QSqlQueryModel ();
    model->setQuery("select * from Pointage");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID du pointage"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("login de l'employe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Debut du pointage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin du pointage"));
    return model;

}


QSqlQueryModel *pointage::ConsulterPointageParticulier(QString IdEmployeUtilisateur, int *RowCount){
    QSqlQueryModel * model= new QSqlQueryModel ();




    model->setQuery("select * from Pointage where IdEmploye Like '%"+IdEmployeUtilisateur+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID du pointage"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("login de l'employe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Debut du pointage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin du pointage"));
    *RowCount=model->rowCount();
    return model;

}






void pointage::FileToDB(){

    const char * filename = "test.txt";
     ifstream fichier;
     fichier.open(filename,ios::in);
     string loginEmloye,DateInPointage,DateOutPointage,TimeInPointage,TimeOutPointage;
      QSqlQuery query;
     query.prepare("Delete from Pointage");
     query.exec();
     while (fichier>>loginEmloye)
     {
         fichier>>DateInPointage>>TimeInPointage>>DateOutPointage>>TimeOutPointage;

         QString dateIN=DateInPointage.c_str();
         QString timeIN=TimeInPointage.c_str();
         QString dateOut=DateOutPointage.c_str();
         QString timeOut=TimeOutPointage.c_str();


         query.prepare("Insert into Pointage Values (NULL,:IdEmploye,:dateDebutPointage,:dateFinPointage)");
         query.bindValue(":IdEmploye",loginEmloye.c_str());
         query.bindValue(":dateDebutPointage",dateIN+" "+timeIN);
         query.bindValue(":dateFinPointage",dateOut+" "+timeOut);
         query.exec();
     }



}













