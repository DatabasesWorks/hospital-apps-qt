#ifndef PAIEMENT_H
#define PAIEMENT_H
#include "employe.h"
#include "QSqlError"
class FichePaie
{
private :
unsigned long long IdPaiement;
QString loginEmploye;
float montantTTC;
QString datePaiement;
QString commentaireResponsable;

public:
    FichePaie();
    FichePaie (QString,float,QString,QString);
    bool AjoutPaiement();
    bool RechercherPaiement(QString);

    QSqlQueryModel *ConsulterPaiement();
    bool AffichePaiementGlobal();
    unsigned long long GetIdPaiement()
    {
        return IdPaiement;
    }
    void SetIdPaiement(unsigned long long IdPaiement)
    {
        this->IdPaiement=IdPaiement;
    }

    void setLoginEmploye(QString loginEmploye)
    {
        this->loginEmploye=loginEmploye;;
    }
    QString getLoginEmploye()
    {
        return loginEmploye;
    }

    float GetMontantTTC(){

        return montantTTC;
    }
    void SetMontantTTC(float montantTTC)
    {
        this->montantTTC=montantTTC;
    }

    QString GetDatePaiement(){
        return datePaiement;
    }
    void SetDatePaiement(){
        this->datePaiement=datePaiement;

    }
    QString GetCommentaireResponsable(){
        return commentaireResponsable;
    }
    void SetCommentaireResponsable(QString commentaireResponsable){

        this->commentaireResponsable=commentaireResponsable;
    }








};

#endif // PAIEMENT_H
