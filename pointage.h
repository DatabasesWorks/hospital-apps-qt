#ifndef POINTAGE_H
#define POINTAGE_H
#include "employe.h"
#include <iostream>
#include <string>
#include <fstream>
class pointage
{
private :
unsigned long long idPointage;
QString dateDebutPointage;
QString dateFinPointage;
QString loginEmploye;
public:
    pointage();
    pointage RechercherPointage(QString);
    void FileToDB();
    QSqlQueryModel *ConsulterPointageGlobale();
    QSqlQueryModel *ConsulterPointageParticulier(QString,int*);

};

#endif // POINTAGE_H
