#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QDebug>
#include <QBuffer>
#include <QSqlQuery>
#include <QRegExp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <QStringListModel>
#include <QList>
#include <QListView>
#include "conge.h"
#include "vector"
using namespace std;



class Employe
{
private:

    QString nom;
    QString prenom;
    QString login;
    QString motDePasse;
    int telephoneTravail;
    QString adresseMail;
    QString adresse;
    QString dateNaissance;
    QString profession;
    QString typeContrat;
    int cin;
    QString dateEmbouche;
    QString service;
    QString sexe;
    QString nationnalite;
    QString adresseTravail;
    QString etatCivil;
    QString numeroPasseport;
    QByteArray image;
    int nss;
public:



    Employe();
    Employe(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,int,int,int);
    ~Employe();
    bool AjoutEmploye();
    bool ModifierEmploye();
    bool SupprimerEmploye();
    bool RechercherInstEmploye(unsigned long long);
    QSqlQueryModel *AfficherEmploye();
    bool RechercherEmployeParNom(QString);
    vector <QString> AfficheEmployeParNom(QString);
    bool RechercherEmployeParNomPrenom(QString,QString);
    void AjoutImage(QString);


    void SetNom(QString nom)
        {
            this->nom = nom;
        }
        QString GetNom()
        {
            return this->nom;
        }
        void SetPrenom(QString prenom)
        {
            this->prenom = prenom;
        }
        QString GetPrenom()
        {
            return this->prenom;
        }
        void SetLogin(QString login)
        {
            this->login = login;
        }
        QString GetLogin()
        {
            return this->login;
        }
        void SetMotDePasse(QString motDePasse)
        {
            this->motDePasse = motDePasse;
        }
        QString GetMotDePasse()
        {
            return this->motDePasse;
        }
        void SetAdresseMail(QString adresseMail)
        {
            this->adresseMail = adresseMail;
        }
        QString GetAdresseMail()
        {
            return this->adresseMail;
        }
        void SetAdresse(QString adresse)
        {
            this->adresse = adresse;
        }
        QString GetAdresse()
        {
            return this->adresse;
        }
        void SetDateNaissance(QString dateNaissance)
        {
            this->dateNaissance = dateNaissance;
        }
        QString GetDateNaissance()
        {
            return this->dateNaissance;
        }
        void SetProfession(QString profession)
        {
            this->profession = profession;
        }
        QString GetProfession()
        {
            return this->profession;
        }
        void SetTypeContrat(QString typeContrat)
        {
            this->typeContrat = typeContrat;
        }
        QString GetTypeContrat()
        {
            return this->typeContrat;
        }
        void SetDateEmbouche(QString dateEmbouche)
        {
            this->dateEmbouche = dateEmbouche;
        }
        QString GetDateEmbouche()
        {
            return this->dateEmbouche;
        }
        void SetService(QString service)
        {
            this->service = service;
        }
        QString GetService()
        {
            return this->service;
        }
        void SetSexe(QString sexe)
        {
            this->sexe = sexe;
        }
        QString GetSexe()
        {
            return this->sexe;
        }
        void SetNationnalite(QString nationnalite)
        {
            this->nationnalite = nationnalite;
        }
        QString GetNationnalite()
        {
            return this->nationnalite;
        }
        void SetAdresseTravail(QString adresseTravail)
        {
            this->adresseTravail = adresseTravail;
        }
        QString GetAdresseTravail()
        {
            return this->adresseTravail;
        }
        void SetEtatCivil(QString etatCivil)
        {
            this->etatCivil = etatCivil;
        }
        QString GetEtatCivil()
        {
            return this->etatCivil;
        }
        void SetNumeroPasseport(QString numeroPasseport)
        {
            this->numeroPasseport = numeroPasseport;
        }
        QString GetNumeroPasseport()
        {
            return this->numeroPasseport;
        }

        void SetNss(int nss)
            {
               this->nss = nss;
            }
            int GetNss()
            {
                return this->nss;
            }
            void SetCin(int cin)
            {
                this->cin = cin;
            }
            int GetCin()
            {
                return this->cin;
            }
            void SetTelephoneTravail(int telephoneTravail)
            {
                this->telephoneTravail = telephoneTravail;
            }
            int GetTelephoneTravail()
            {
                return this->telephoneTravail;
            }


            void SetImage(QByteArray  image)
               {
                   this->image = image;
               }
               QByteArray  GetImage()
               {
                   return this->image;
               }

};

#endif // EMPLOYE_H
