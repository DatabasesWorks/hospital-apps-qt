#ifndef EMPLOYEUI_H
#define EMPLOYEUI_H

#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include "employe.h"
#include "statistiques.h"
#include "listingpaiement.h"
#include "listingconge.h"
#include "listingemploye.h"
#include "conge.h"
#include "paiement.h"
#include "QSqlError"
#include "qsqlerror.h"
#include "pointage.h"
#include "QAbstractItemView"

namespace Ui {
class employeui;
}

class employeui : public QDialog
{
    Q_OBJECT
    
public:
    explicit employeui(QWidget *parent = 0);
    void AfficheEmployeInstantane(Employe);
    void AfficheCongeInstantaneConge(Conge);
    void AffichePaiementInstantane(FichePaie);
    void AfficheEmployeParNom();
    void EnClear(int);
    void EnClearPaiement();
    void EnClearConge();
    void SetOuputMessage(QString,bool);
    void SetOuputMessagePointage(QString ,bool);
    void SetOuputMessagePaiement(QString,bool);
    void SetOuputMessageConge(QString,bool);
    bool VerifNom();
    bool VerifPrenom();
    bool VerifPassport();
    bool VerifNSS();
    bool VerifCIN();
    bool VerifPassword();
    bool VerifService();
    bool VerifPasswordIndiv();
    bool VerifAdresse();
    bool VerifAdresseTravail();
    bool VerifTelephoneTravail();
    bool VerifMail();
    bool VerifSexe();
    bool VerifEtatCivil();
    bool VerifNationnalite();
    bool VerifDateEmbouchement();
    bool VerifdateNaissance();
    bool VerifProfession();
    bool VerifTypeContrat();
    bool verifID();
    bool verifIDPaiement();
    bool verifIDPointage();
    bool VerifMontantTTCPaiement();
    bool VerifdateFichePaie();
    bool verifIDConge();
    bool VerifTypeConge();
    bool VerifdateDebutConge();
    bool VerifDateFinConge();
    void InitIndication();






    ~employeui();
    
private slots:

    void on_pushButton_ChargerImage_clicked();
    void on_lineEdit_ID_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_supprmier_clicked();
    void on_pushButton_Annuler_clicked();

    void on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_Nom_editTextChanged(const QString &arg1);

    void on_pushButton_Save_clicked();

    void on_lineEdit_prenom_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_NSS_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_passport_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_CIN_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_confirmermotdepasse_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_service_currentIndexChanged(int index);

    void on_lineEdit_motdepasse_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_adresse_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_adresseTravail_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_telephoneTravail_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_mailTravail_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_sexe_currentIndexChanged(int index);

    void on_comboBox_EtatCivil_currentIndexChanged(int index);

    void on_lineEdit_nationnalite_cursorPositionChanged(int arg1, int arg2);

    void on_dateEdit_dateNaissance_dateChanged(const QDate &date);

    void on_dateEdit_dateEmbouche_dateChanged(const QDate &date);

    void on_lineEdit_profession_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_contrat_currentIndexChanged(const QString &arg1);

    void on_pushButton_Edit_clicked();



    void on_pushButton_AjoutConge_clicked();

    void on_pushButton_ModifierConge_clicked();


    void on_lineEdit_IDCongeEmployeRechercher_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_SupprimerConge_clicked();

    void on_pushButton_AjoutPaiement_clicked();


    void on_lineEdit_IDPaiementEmployeRecherche_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_IDRechercherPointage_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_IDPaiementEmploye_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_MontantTTC_cursorPositionChanged(int arg1, int arg2);


    void on_dateEdit_Paiement_dateChanged(const QDate &date);


    void on_pushButton_ListingPaiement_clicked();

    void on_lineEdit_IDCongeEmploye_cursorPositionChanged(int arg1, int arg2);


    void on_comboBox_TypeConge_currentIndexChanged(int index);


    void on_dateEdit_DebutConge_dateChanged(const QDate &date);

    void on_dateEdit_FinConge_dateChanged(const QDate &date);



    void on_pushButton_NettoyerConge_clicked();



    void on_pushButton_ListingEmploye_clicked();

    void on_pushButton_StatistiquesEmploye_clicked();

    void on_pushButton_ListingConge_clicked();



    void on_pushButton_NettoyerPaiement_clicked();

private:
    QString fileNameImage;
    QString nomRecherche;
    QString prenomRecherche;
    QString lastOutputMessage;
    QPixmap PixTrueIcon;
    QPixmap PixFalseIcon;
    bool AppelAffiche;
    bool AppelAffichePaiement;
    bool AppelAfficheConge;
    bool ConditionPrimaire;
    Ui::employeui *ui;
    pointage Pointage;

};

#endif // EMPLOYEUI_H
