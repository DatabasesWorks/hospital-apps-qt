/********************************************************************************
** Form generated from reading UI file 'employe.ui'
**
** Created: Sun 8. Mar 14:21:30 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_H
#define UI_EMPLOYE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Employe
{
public:
    QLabel *label_nom;
    QLabel *label_NSS;
    QLabel *label_ID;
    QLabel *label_passport;
    QLabel *label_CIN;
    QLabel *label_12;
    QFrame *line;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_3;
    QLabel *label_service;
    QLineEdit *lineEdit_nom;
    QLabel *label_image;
    QComboBox *comboBox_service;
    QLineEdit *lineEdit_NSS;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_passport;
    QLineEdit *lineEdit_CIN;
    QFrame *line_2;
    QLabel *label_7;
    QFrame *line_3;
    QLabel *label_15;
    QLabel *label_sexe;
    QComboBox *comboBox_sexe;
    QLabel *label_etatCivil;
    QComboBox *comboBox_EtatCivil;
    QLabel *label_nationnalite;
    QLineEdit *lineEdit_nationnalite;
    QLabel *label_dateNaissance;
    QDateEdit *dateEdit_dateNaissance;
    QFrame *line_4;
    QLabel *label_20;
    QLabel *label_adresse;
    QLineEdit *lineEdit_adresse;
    QLabel *label_adresseTravail;
    QLineEdit *lineEdit_adresseTravail;
    QLineEdit *lineEdit_telephoneTravail;
    QLabel *label_telephoneTravail;
    QLabel *label_mailTravail;
    QLineEdit *lineEdit_mailTravail;
    QFrame *line_5;
    QLabel *label_profession;
    QLineEdit *lineEdit_profession;
    QLabel *label_contrat;
    QComboBox *comboBox_contrat;
    QLabel *label_embouche;
    QDateEdit *dateEdit_dateEmbouche;
    QLabel *label_24;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QPushButton *pushButton_supprmier;
    QPushButton *pushButton_Edit;
    QPushButton *pushButton;
    QLabel *label_motdepasse;
    QLineEdit *lineEdit_motdepasse;
    QLabel *label_confirmermotdepasse;
    QLineEdit *lineEdit_confirmermotdepasse;
    QLineEdit *lineEdit_nom_2;
    QLabel *label_passport_2;
    QLineEdit *lineEdit_telephoneTravail_2;
    QDateEdit *dateEdit_dateNaissance_2;
    QComboBox *comboBox_sexe_2;
    QLineEdit *lineEdit_adresseTravail_2;
    QLineEdit *lineEdit_ID_2;
    QLabel *label_service_2;
    QLineEdit *lineEdit_prenom_2;
    QLineEdit *lineEdit_passport_2;
    QLabel *label_sexe_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_NSS_2;
    QLabel *label_21;
    QLineEdit *lineEdit_nationnalite_2;
    QLabel *label_image_2;
    QLabel *label_dateNaissance_2;
    QLabel *label_ID_2;
    QFrame *line_6;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QLabel *label_profession_2;
    QLabel *label_contrat_2;
    QLabel *label_prenom_2;
    QPushButton *pushButton_supprmier_2;
    QLineEdit *lineEdit_motdepasse_2;
    QComboBox *comboBox_EtatCivil_2;
    QLabel *label_CIN_2;
    QFrame *line_7;
    QLineEdit *lineEdit_profession_2;
    QComboBox *comboBox_service_2;
    QLabel *label_nom_2;
    QFrame *line_8;
    QLabel *label_adresseTravail_2;
    QLabel *label_adresse_2;
    QLineEdit *lineEdit_confirmermotdepasse_2;
    QLabel *label_13;
    QComboBox *comboBox_contrat_2;
    QDateEdit *dateEdit_dateEmbouche_2;
    QLabel *label_NSS_2;
    QFrame *line_9;
    QLabel *label_motdepasse_2;
    QPushButton *pushButton_Ajouter_2;
    QLabel *label_16;
    QLabel *label_25;
    QLabel *label_mailTravail_2;
    QLabel *label_nationnalite_2;
    QLabel *label_embouche_2;
    QLabel *label_etatCivil_2;
    QFrame *line_10;
    QLabel *label_confirmermotdepasse_2;
    QLineEdit *lineEdit_CIN_2;
    QLineEdit *lineEdit_mailTravail_2;
    QLineEdit *lineEdit_adresse_2;
    QLabel *label_telephoneTravail_2;
    QPushButton *pushButton_Edit_2;

    void setupUi(QDialog *Employe)
    {
        if (Employe->objectName().isEmpty())
            Employe->setObjectName(QString::fromUtf8("Employe"));
        Employe->resize(873, 690);
        label_nom = new QLabel(Employe);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(40, 130, 111, 16));
        label_NSS = new QLabel(Employe);
        label_NSS->setObjectName(QString::fromUtf8("label_NSS"));
        label_NSS->setGeometry(QRect(20, 340, 151, 16));
        label_ID = new QLabel(Employe);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));
        label_ID->setGeometry(QRect(30, 370, 141, 16));
        label_passport = new QLabel(Employe);
        label_passport->setObjectName(QString::fromUtf8("label_passport"));
        label_passport->setGeometry(QRect(30, 400, 141, 16));
        label_CIN = new QLabel(Employe);
        label_CIN->setObjectName(QString::fromUtf8("label_CIN"));
        label_CIN->setGeometry(QRect(30, 430, 141, 16));
        label_12 = new QLabel(Employe);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 10, 81, 16));
        line = new QFrame(Employe);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 50, 861, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_Ajouter = new QPushButton(Employe);
        pushButton_Ajouter->setObjectName(QString::fromUtf8("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(10, 70, 93, 28));
        pushButton_3 = new QPushButton(Employe);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 70, 93, 28));
        label_service = new QLabel(Employe);
        label_service->setObjectName(QString::fromUtf8("label_service"));
        label_service->setGeometry(QRect(20, 190, 141, 16));
        lineEdit_nom = new QLineEdit(Employe);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(180, 130, 201, 21));
        label_image = new QLabel(Employe);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(660, 130, 161, 161));
        comboBox_service = new QComboBox(Employe);
        comboBox_service->setObjectName(QString::fromUtf8("comboBox_service"));
        comboBox_service->setGeometry(QRect(180, 190, 201, 22));
        lineEdit_NSS = new QLineEdit(Employe);
        lineEdit_NSS->setObjectName(QString::fromUtf8("lineEdit_NSS"));
        lineEdit_NSS->setGeometry(QRect(180, 340, 201, 22));
        lineEdit_ID = new QLineEdit(Employe);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(180, 370, 201, 22));
        lineEdit_passport = new QLineEdit(Employe);
        lineEdit_passport->setObjectName(QString::fromUtf8("lineEdit_passport"));
        lineEdit_passport->setGeometry(QRect(180, 400, 201, 22));
        lineEdit_CIN = new QLineEdit(Employe);
        lineEdit_CIN->setObjectName(QString::fromUtf8("lineEdit_CIN"));
        lineEdit_CIN->setGeometry(QRect(180, 430, 201, 22));
        line_2 = new QFrame(Employe);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 320, 401, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(Employe);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 310, 71, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        line_3 = new QFrame(Employe);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(460, 320, 391, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(Employe);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(460, 310, 101, 16));
        label_15->setFont(font);
        label_sexe = new QLabel(Employe);
        label_sexe->setObjectName(QString::fromUtf8("label_sexe"));
        label_sexe->setGeometry(QRect(520, 340, 151, 16));
        comboBox_sexe = new QComboBox(Employe);
        comboBox_sexe->setObjectName(QString::fromUtf8("comboBox_sexe"));
        comboBox_sexe->setGeometry(QRect(570, 340, 111, 22));
        label_etatCivil = new QLabel(Employe);
        label_etatCivil->setObjectName(QString::fromUtf8("label_etatCivil"));
        label_etatCivil->setGeometry(QRect(490, 370, 151, 16));
        comboBox_EtatCivil = new QComboBox(Employe);
        comboBox_EtatCivil->setObjectName(QString::fromUtf8("comboBox_EtatCivil"));
        comboBox_EtatCivil->setGeometry(QRect(570, 370, 111, 22));
        label_nationnalite = new QLabel(Employe);
        label_nationnalite->setObjectName(QString::fromUtf8("label_nationnalite"));
        label_nationnalite->setGeometry(QRect(480, 400, 91, 16));
        lineEdit_nationnalite = new QLineEdit(Employe);
        lineEdit_nationnalite->setObjectName(QString::fromUtf8("lineEdit_nationnalite"));
        lineEdit_nationnalite->setGeometry(QRect(570, 400, 201, 22));
        label_dateNaissance = new QLabel(Employe);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(440, 430, 121, 16));
        dateEdit_dateNaissance = new QDateEdit(Employe);
        dateEdit_dateNaissance->setObjectName(QString::fromUtf8("dateEdit_dateNaissance"));
        dateEdit_dateNaissance->setGeometry(QRect(570, 430, 110, 22));
        line_4 = new QFrame(Employe);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(20, 540, 401, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_20 = new QLabel(Employe);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 530, 151, 16));
        label_20->setFont(font);
        label_adresse = new QLabel(Employe);
        label_adresse->setObjectName(QString::fromUtf8("label_adresse"));
        label_adresse->setGeometry(QRect(110, 560, 71, 16));
        lineEdit_adresse = new QLineEdit(Employe);
        lineEdit_adresse->setObjectName(QString::fromUtf8("lineEdit_adresse"));
        lineEdit_adresse->setGeometry(QRect(180, 560, 201, 22));
        label_adresseTravail = new QLabel(Employe);
        label_adresseTravail->setObjectName(QString::fromUtf8("label_adresseTravail"));
        label_adresseTravail->setGeometry(QRect(50, 590, 131, 16));
        lineEdit_adresseTravail = new QLineEdit(Employe);
        lineEdit_adresseTravail->setObjectName(QString::fromUtf8("lineEdit_adresseTravail"));
        lineEdit_adresseTravail->setGeometry(QRect(180, 590, 201, 22));
        lineEdit_telephoneTravail = new QLineEdit(Employe);
        lineEdit_telephoneTravail->setObjectName(QString::fromUtf8("lineEdit_telephoneTravail"));
        lineEdit_telephoneTravail->setGeometry(QRect(180, 620, 201, 22));
        label_telephoneTravail = new QLabel(Employe);
        label_telephoneTravail->setObjectName(QString::fromUtf8("label_telephoneTravail"));
        label_telephoneTravail->setGeometry(QRect(40, 620, 131, 16));
        label_mailTravail = new QLabel(Employe);
        label_mailTravail->setObjectName(QString::fromUtf8("label_mailTravail"));
        label_mailTravail->setGeometry(QRect(60, 650, 131, 16));
        lineEdit_mailTravail = new QLineEdit(Employe);
        lineEdit_mailTravail->setObjectName(QString::fromUtf8("lineEdit_mailTravail"));
        lineEdit_mailTravail->setGeometry(QRect(180, 650, 201, 22));
        line_5 = new QFrame(Employe);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(460, 540, 391, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_profession = new QLabel(Employe);
        label_profession->setObjectName(QString::fromUtf8("label_profession"));
        label_profession->setGeometry(QRect(480, 560, 71, 16));
        lineEdit_profession = new QLineEdit(Employe);
        lineEdit_profession->setObjectName(QString::fromUtf8("lineEdit_profession"));
        lineEdit_profession->setGeometry(QRect(570, 560, 201, 22));
        label_contrat = new QLabel(Employe);
        label_contrat->setObjectName(QString::fromUtf8("label_contrat"));
        label_contrat->setGeometry(QRect(450, 590, 111, 16));
        comboBox_contrat = new QComboBox(Employe);
        comboBox_contrat->setObjectName(QString::fromUtf8("comboBox_contrat"));
        comboBox_contrat->setGeometry(QRect(570, 590, 111, 22));
        label_embouche = new QLabel(Employe);
        label_embouche->setObjectName(QString::fromUtf8("label_embouche"));
        label_embouche->setGeometry(QRect(440, 620, 111, 16));
        dateEdit_dateEmbouche = new QDateEdit(Employe);
        dateEdit_dateEmbouche->setObjectName(QString::fromUtf8("dateEdit_dateEmbouche"));
        dateEdit_dateEmbouche->setGeometry(QRect(570, 620, 110, 22));
        label_24 = new QLabel(Employe);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(460, 530, 151, 16));
        label_24->setFont(font);
        label_prenom = new QLabel(Employe);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(20, 160, 131, 16));
        lineEdit_prenom = new QLineEdit(Employe);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(180, 160, 201, 21));
        pushButton_supprmier = new QPushButton(Employe);
        pushButton_supprmier->setObjectName(QString::fromUtf8("pushButton_supprmier"));
        pushButton_supprmier->setGeometry(QRect(260, 70, 93, 28));
        pushButton_Edit = new QPushButton(Employe);
        pushButton_Edit->setObjectName(QString::fromUtf8("pushButton_Edit"));
        pushButton_Edit->setGeometry(QRect(110, 70, 141, 28));
        pushButton = new QPushButton(Employe);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 70, 101, 28));
        label_motdepasse = new QLabel(Employe);
        label_motdepasse->setObjectName(QString::fromUtf8("label_motdepasse"));
        label_motdepasse->setGeometry(QRect(80, 460, 91, 16));
        lineEdit_motdepasse = new QLineEdit(Employe);
        lineEdit_motdepasse->setObjectName(QString::fromUtf8("lineEdit_motdepasse"));
        lineEdit_motdepasse->setGeometry(QRect(180, 460, 201, 22));
        label_confirmermotdepasse = new QLabel(Employe);
        label_confirmermotdepasse->setObjectName(QString::fromUtf8("label_confirmermotdepasse"));
        label_confirmermotdepasse->setGeometry(QRect(10, 490, 171, 16));
        lineEdit_confirmermotdepasse = new QLineEdit(Employe);
        lineEdit_confirmermotdepasse->setObjectName(QString::fromUtf8("lineEdit_confirmermotdepasse"));
        lineEdit_confirmermotdepasse->setGeometry(QRect(180, 490, 201, 22));
        lineEdit_nom_2 = new QLineEdit(Employe);
        lineEdit_nom_2->setObjectName(QString::fromUtf8("lineEdit_nom_2"));
        lineEdit_nom_2->setGeometry(QRect(290, 270, 201, 21));
        label_passport_2 = new QLabel(Employe);
        label_passport_2->setObjectName(QString::fromUtf8("label_passport_2"));
        label_passport_2->setGeometry(QRect(140, 540, 141, 16));
        lineEdit_telephoneTravail_2 = new QLineEdit(Employe);
        lineEdit_telephoneTravail_2->setObjectName(QString::fromUtf8("lineEdit_telephoneTravail_2"));
        lineEdit_telephoneTravail_2->setGeometry(QRect(290, 760, 201, 22));
        dateEdit_dateNaissance_2 = new QDateEdit(Employe);
        dateEdit_dateNaissance_2->setObjectName(QString::fromUtf8("dateEdit_dateNaissance_2"));
        dateEdit_dateNaissance_2->setGeometry(QRect(680, 570, 110, 22));
        comboBox_sexe_2 = new QComboBox(Employe);
        comboBox_sexe_2->setObjectName(QString::fromUtf8("comboBox_sexe_2"));
        comboBox_sexe_2->setGeometry(QRect(680, 480, 111, 22));
        lineEdit_adresseTravail_2 = new QLineEdit(Employe);
        lineEdit_adresseTravail_2->setObjectName(QString::fromUtf8("lineEdit_adresseTravail_2"));
        lineEdit_adresseTravail_2->setGeometry(QRect(290, 730, 201, 22));
        lineEdit_ID_2 = new QLineEdit(Employe);
        lineEdit_ID_2->setObjectName(QString::fromUtf8("lineEdit_ID_2"));
        lineEdit_ID_2->setGeometry(QRect(290, 510, 201, 22));
        label_service_2 = new QLabel(Employe);
        label_service_2->setObjectName(QString::fromUtf8("label_service_2"));
        label_service_2->setGeometry(QRect(130, 330, 141, 16));
        lineEdit_prenom_2 = new QLineEdit(Employe);
        lineEdit_prenom_2->setObjectName(QString::fromUtf8("lineEdit_prenom_2"));
        lineEdit_prenom_2->setGeometry(QRect(290, 300, 201, 21));
        lineEdit_passport_2 = new QLineEdit(Employe);
        lineEdit_passport_2->setObjectName(QString::fromUtf8("lineEdit_passport_2"));
        lineEdit_passport_2->setGeometry(QRect(290, 540, 201, 22));
        label_sexe_2 = new QLabel(Employe);
        label_sexe_2->setObjectName(QString::fromUtf8("label_sexe_2"));
        label_sexe_2->setGeometry(QRect(630, 480, 151, 16));
        pushButton_2 = new QPushButton(Employe);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(800, 210, 101, 28));
        lineEdit_NSS_2 = new QLineEdit(Employe);
        lineEdit_NSS_2->setObjectName(QString::fromUtf8("lineEdit_NSS_2"));
        lineEdit_NSS_2->setGeometry(QRect(290, 480, 201, 22));
        label_21 = new QLabel(Employe);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(130, 670, 151, 16));
        label_21->setFont(font);
        lineEdit_nationnalite_2 = new QLineEdit(Employe);
        lineEdit_nationnalite_2->setObjectName(QString::fromUtf8("lineEdit_nationnalite_2"));
        lineEdit_nationnalite_2->setGeometry(QRect(680, 540, 201, 22));
        label_image_2 = new QLabel(Employe);
        label_image_2->setObjectName(QString::fromUtf8("label_image_2"));
        label_image_2->setGeometry(QRect(770, 270, 161, 161));
        label_dateNaissance_2 = new QLabel(Employe);
        label_dateNaissance_2->setObjectName(QString::fromUtf8("label_dateNaissance_2"));
        label_dateNaissance_2->setGeometry(QRect(550, 570, 121, 16));
        label_ID_2 = new QLabel(Employe);
        label_ID_2->setObjectName(QString::fromUtf8("label_ID_2"));
        label_ID_2->setGeometry(QRect(140, 510, 141, 16));
        line_6 = new QFrame(Employe);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(570, 680, 391, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(Employe);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 210, 93, 28));
        label_8 = new QLabel(Employe);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(130, 450, 71, 16));
        label_8->setFont(font);
        label_profession_2 = new QLabel(Employe);
        label_profession_2->setObjectName(QString::fromUtf8("label_profession_2"));
        label_profession_2->setGeometry(QRect(590, 700, 71, 16));
        label_contrat_2 = new QLabel(Employe);
        label_contrat_2->setObjectName(QString::fromUtf8("label_contrat_2"));
        label_contrat_2->setGeometry(QRect(560, 730, 111, 16));
        label_prenom_2 = new QLabel(Employe);
        label_prenom_2->setObjectName(QString::fromUtf8("label_prenom_2"));
        label_prenom_2->setGeometry(QRect(130, 300, 131, 16));
        pushButton_supprmier_2 = new QPushButton(Employe);
        pushButton_supprmier_2->setObjectName(QString::fromUtf8("pushButton_supprmier_2"));
        pushButton_supprmier_2->setGeometry(QRect(370, 210, 93, 28));
        lineEdit_motdepasse_2 = new QLineEdit(Employe);
        lineEdit_motdepasse_2->setObjectName(QString::fromUtf8("lineEdit_motdepasse_2"));
        lineEdit_motdepasse_2->setGeometry(QRect(290, 600, 201, 22));
        comboBox_EtatCivil_2 = new QComboBox(Employe);
        comboBox_EtatCivil_2->setObjectName(QString::fromUtf8("comboBox_EtatCivil_2"));
        comboBox_EtatCivil_2->setGeometry(QRect(680, 510, 111, 22));
        label_CIN_2 = new QLabel(Employe);
        label_CIN_2->setObjectName(QString::fromUtf8("label_CIN_2"));
        label_CIN_2->setGeometry(QRect(140, 570, 141, 16));
        line_7 = new QFrame(Employe);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(570, 460, 391, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        lineEdit_profession_2 = new QLineEdit(Employe);
        lineEdit_profession_2->setObjectName(QString::fromUtf8("lineEdit_profession_2"));
        lineEdit_profession_2->setGeometry(QRect(680, 700, 201, 22));
        comboBox_service_2 = new QComboBox(Employe);
        comboBox_service_2->setObjectName(QString::fromUtf8("comboBox_service_2"));
        comboBox_service_2->setGeometry(QRect(290, 330, 201, 22));
        label_nom_2 = new QLabel(Employe);
        label_nom_2->setObjectName(QString::fromUtf8("label_nom_2"));
        label_nom_2->setGeometry(QRect(150, 270, 111, 16));
        line_8 = new QFrame(Employe);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(110, 190, 861, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_adresseTravail_2 = new QLabel(Employe);
        label_adresseTravail_2->setObjectName(QString::fromUtf8("label_adresseTravail_2"));
        label_adresseTravail_2->setGeometry(QRect(160, 730, 131, 16));
        label_adresse_2 = new QLabel(Employe);
        label_adresse_2->setObjectName(QString::fromUtf8("label_adresse_2"));
        label_adresse_2->setGeometry(QRect(220, 700, 71, 16));
        lineEdit_confirmermotdepasse_2 = new QLineEdit(Employe);
        lineEdit_confirmermotdepasse_2->setObjectName(QString::fromUtf8("lineEdit_confirmermotdepasse_2"));
        lineEdit_confirmermotdepasse_2->setGeometry(QRect(290, 630, 201, 22));
        label_13 = new QLabel(Employe);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 150, 81, 16));
        comboBox_contrat_2 = new QComboBox(Employe);
        comboBox_contrat_2->setObjectName(QString::fromUtf8("comboBox_contrat_2"));
        comboBox_contrat_2->setGeometry(QRect(680, 730, 111, 22));
        dateEdit_dateEmbouche_2 = new QDateEdit(Employe);
        dateEdit_dateEmbouche_2->setObjectName(QString::fromUtf8("dateEdit_dateEmbouche_2"));
        dateEdit_dateEmbouche_2->setGeometry(QRect(680, 760, 110, 22));
        label_NSS_2 = new QLabel(Employe);
        label_NSS_2->setObjectName(QString::fromUtf8("label_NSS_2"));
        label_NSS_2->setGeometry(QRect(130, 480, 151, 16));
        line_9 = new QFrame(Employe);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(130, 680, 401, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label_motdepasse_2 = new QLabel(Employe);
        label_motdepasse_2->setObjectName(QString::fromUtf8("label_motdepasse_2"));
        label_motdepasse_2->setGeometry(QRect(190, 600, 91, 16));
        pushButton_Ajouter_2 = new QPushButton(Employe);
        pushButton_Ajouter_2->setObjectName(QString::fromUtf8("pushButton_Ajouter_2"));
        pushButton_Ajouter_2->setGeometry(QRect(120, 210, 93, 28));
        label_16 = new QLabel(Employe);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(570, 450, 101, 16));
        label_16->setFont(font);
        label_25 = new QLabel(Employe);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(570, 670, 151, 16));
        label_25->setFont(font);
        label_mailTravail_2 = new QLabel(Employe);
        label_mailTravail_2->setObjectName(QString::fromUtf8("label_mailTravail_2"));
        label_mailTravail_2->setGeometry(QRect(170, 790, 131, 16));
        label_nationnalite_2 = new QLabel(Employe);
        label_nationnalite_2->setObjectName(QString::fromUtf8("label_nationnalite_2"));
        label_nationnalite_2->setGeometry(QRect(590, 540, 91, 16));
        label_embouche_2 = new QLabel(Employe);
        label_embouche_2->setObjectName(QString::fromUtf8("label_embouche_2"));
        label_embouche_2->setGeometry(QRect(550, 760, 111, 16));
        label_etatCivil_2 = new QLabel(Employe);
        label_etatCivil_2->setObjectName(QString::fromUtf8("label_etatCivil_2"));
        label_etatCivil_2->setGeometry(QRect(600, 510, 151, 16));
        line_10 = new QFrame(Employe);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(130, 460, 401, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_confirmermotdepasse_2 = new QLabel(Employe);
        label_confirmermotdepasse_2->setObjectName(QString::fromUtf8("label_confirmermotdepasse_2"));
        label_confirmermotdepasse_2->setGeometry(QRect(120, 630, 171, 16));
        lineEdit_CIN_2 = new QLineEdit(Employe);
        lineEdit_CIN_2->setObjectName(QString::fromUtf8("lineEdit_CIN_2"));
        lineEdit_CIN_2->setGeometry(QRect(290, 570, 201, 22));
        lineEdit_mailTravail_2 = new QLineEdit(Employe);
        lineEdit_mailTravail_2->setObjectName(QString::fromUtf8("lineEdit_mailTravail_2"));
        lineEdit_mailTravail_2->setGeometry(QRect(290, 790, 201, 22));
        lineEdit_adresse_2 = new QLineEdit(Employe);
        lineEdit_adresse_2->setObjectName(QString::fromUtf8("lineEdit_adresse_2"));
        lineEdit_adresse_2->setGeometry(QRect(290, 700, 201, 22));
        label_telephoneTravail_2 = new QLabel(Employe);
        label_telephoneTravail_2->setObjectName(QString::fromUtf8("label_telephoneTravail_2"));
        label_telephoneTravail_2->setGeometry(QRect(150, 760, 131, 16));
        pushButton_Edit_2 = new QPushButton(Employe);
        pushButton_Edit_2->setObjectName(QString::fromUtf8("pushButton_Edit_2"));
        pushButton_Edit_2->setGeometry(QRect(220, 210, 141, 28));

        retranslateUi(Employe);

        QMetaObject::connectSlotsByName(Employe);
    } // setupUi

    void retranslateUi(QDialog *Employe)
    {
        Employe->setWindowTitle(QApplication::translate("Employe", "Dialog", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("Employe", "Nom de l'employ\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_NSS->setText(QApplication::translate("Employe", "Num\303\251ro S\303\251curit\303\251 Sociale : ", 0, QApplication::UnicodeUTF8));
        label_ID->setText(QApplication::translate("Employe", "Num\303\251ro d'identification :", 0, QApplication::UnicodeUTF8));
        label_passport->setText(QApplication::translate("Employe", "   Num\303\251ro de Passport :", 0, QApplication::UnicodeUTF8));
        label_CIN->setText(QApplication::translate("Employe", "               Num\303\251ro CIN :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Employe", "Employ\303\251es", 0, QApplication::UnicodeUTF8));
        pushButton_Ajouter->setText(QApplication::translate("Employe", "Enregitrer", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Employe", "Annuler", 0, QApplication::UnicodeUTF8));
        label_service->setText(QApplication::translate("Employe", "Service de l'employ\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_image->setText(QApplication::translate("Employe", "IMAGE_", 0, QApplication::UnicodeUTF8));
        comboBox_service->clear();
        comboBox_service->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Radiologie/IRM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Cardiologie", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "finaci\303\250re", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("Employe", "IDs Sociale", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Employe", "Status Sociale", 0, QApplication::UnicodeUTF8));
        label_sexe->setText(QApplication::translate("Employe", "Sexe : ", 0, QApplication::UnicodeUTF8));
        comboBox_sexe->clear();
        comboBox_sexe->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Homme", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Femme", 0, QApplication::UnicodeUTF8)
        );
        label_etatCivil->setText(QApplication::translate("Employe", "Etat Civile :", 0, QApplication::UnicodeUTF8));
        comboBox_EtatCivil->clear();
        comboBox_EtatCivil->insertItems(0, QStringList()
         << QApplication::translate("Employe", "C\303\251libataire", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Mari\303\251", 0, QApplication::UnicodeUTF8)
        );
        label_nationnalite->setText(QApplication::translate("Employe", "Nationnalit\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_dateNaissance->setText(QApplication::translate("Employe", "Date de Naissance :", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Employe", "Contacte Informations", 0, QApplication::UnicodeUTF8));
        label_adresse->setText(QApplication::translate("Employe", "Adresse :", 0, QApplication::UnicodeUTF8));
        label_adresseTravail->setText(QApplication::translate("Employe", "Adresse de travail :", 0, QApplication::UnicodeUTF8));
        label_telephoneTravail->setText(QApplication::translate("Employe", "Telephone de travail :", 0, QApplication::UnicodeUTF8));
        label_mailTravail->setText(QApplication::translate("Employe", "E-mail de travail :", 0, QApplication::UnicodeUTF8));
        label_profession->setText(QApplication::translate("Employe", "Profession :", 0, QApplication::UnicodeUTF8));
        label_contrat->setText(QApplication::translate("Employe", "Type de contrat :", 0, QApplication::UnicodeUTF8));
        comboBox_contrat->clear();
        comboBox_contrat->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Annuel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Payer A l'acte", 0, QApplication::UnicodeUTF8)
        );
        label_embouche->setText(QApplication::translate("Employe", "Date d'embouche :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Employe", "Position", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("Employe", "Prenom de l'employ\303\251 :", 0, QApplication::UnicodeUTF8));
        pushButton_supprmier->setText(QApplication::translate("Employe", "Supprimer", 0, QApplication::UnicodeUTF8));
        pushButton_Edit->setText(QApplication::translate("Employe", "Modifier et Enregistrer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Employe", "Charger image ", 0, QApplication::UnicodeUTF8));
        label_motdepasse->setText(QApplication::translate("Employe", "Mot de Passe : ", 0, QApplication::UnicodeUTF8));
        label_confirmermotdepasse->setText(QApplication::translate("Employe", "Confirmer le mot de Passe :", 0, QApplication::UnicodeUTF8));
        label_passport_2->setText(QApplication::translate("Employe", "   Num\303\251ro de Passport :", 0, QApplication::UnicodeUTF8));
        comboBox_sexe_2->clear();
        comboBox_sexe_2->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Homme", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Femme", 0, QApplication::UnicodeUTF8)
        );
        label_service_2->setText(QApplication::translate("Employe", "Service de l'employ\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_sexe_2->setText(QApplication::translate("Employe", "Sexe : ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Employe", "Charger image ", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Employe", "Contacte Informations", 0, QApplication::UnicodeUTF8));
        label_image_2->setText(QApplication::translate("Employe", "IMAGE_", 0, QApplication::UnicodeUTF8));
        label_dateNaissance_2->setText(QApplication::translate("Employe", "Date de Naissance :", 0, QApplication::UnicodeUTF8));
        label_ID_2->setText(QApplication::translate("Employe", "Num\303\251ro d'identification :", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Employe", "Annuler", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Employe", "IDs Sociale", 0, QApplication::UnicodeUTF8));
        label_profession_2->setText(QApplication::translate("Employe", "Profession :", 0, QApplication::UnicodeUTF8));
        label_contrat_2->setText(QApplication::translate("Employe", "Type de contrat :", 0, QApplication::UnicodeUTF8));
        label_prenom_2->setText(QApplication::translate("Employe", "Prenom de l'employ\303\251 :", 0, QApplication::UnicodeUTF8));
        pushButton_supprmier_2->setText(QApplication::translate("Employe", "Supprimer", 0, QApplication::UnicodeUTF8));
        comboBox_EtatCivil_2->clear();
        comboBox_EtatCivil_2->insertItems(0, QStringList()
         << QApplication::translate("Employe", "C\303\251libataire", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Mari\303\251", 0, QApplication::UnicodeUTF8)
        );
        label_CIN_2->setText(QApplication::translate("Employe", "               Num\303\251ro CIN :", 0, QApplication::UnicodeUTF8));
        comboBox_service_2->clear();
        comboBox_service_2->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Radiologie/IRM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Cardiologie", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "finaci\303\250re", 0, QApplication::UnicodeUTF8)
        );
        label_nom_2->setText(QApplication::translate("Employe", "Nom de l'employ\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_adresseTravail_2->setText(QApplication::translate("Employe", "Adresse de travail :", 0, QApplication::UnicodeUTF8));
        label_adresse_2->setText(QApplication::translate("Employe", "Adresse :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Employe", "Employ\303\251es", 0, QApplication::UnicodeUTF8));
        comboBox_contrat_2->clear();
        comboBox_contrat_2->insertItems(0, QStringList()
         << QApplication::translate("Employe", "Annuel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Employe", "Payer A l'acte", 0, QApplication::UnicodeUTF8)
        );
        label_NSS_2->setText(QApplication::translate("Employe", "Num\303\251ro S\303\251curit\303\251 Sociale : ", 0, QApplication::UnicodeUTF8));
        label_motdepasse_2->setText(QApplication::translate("Employe", "Mot de Passe : ", 0, QApplication::UnicodeUTF8));
        pushButton_Ajouter_2->setText(QApplication::translate("Employe", "Enregitrer", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Employe", "Status Sociale", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Employe", "Position", 0, QApplication::UnicodeUTF8));
        label_mailTravail_2->setText(QApplication::translate("Employe", "E-mail de travail :", 0, QApplication::UnicodeUTF8));
        label_nationnalite_2->setText(QApplication::translate("Employe", "Nationnalit\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_embouche_2->setText(QApplication::translate("Employe", "Date d'embouche :", 0, QApplication::UnicodeUTF8));
        label_etatCivil_2->setText(QApplication::translate("Employe", "Etat Civile :", 0, QApplication::UnicodeUTF8));
        label_confirmermotdepasse_2->setText(QApplication::translate("Employe", "Confirmer le mot de Passe :", 0, QApplication::UnicodeUTF8));
        label_telephoneTravail_2->setText(QApplication::translate("Employe", "Telephone de travail :", 0, QApplication::UnicodeUTF8));
        pushButton_Edit_2->setText(QApplication::translate("Employe", "Modifier et Enregistrer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Employe: public Ui_Employe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_H
