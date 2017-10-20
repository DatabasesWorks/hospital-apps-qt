#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include "patient.h"
#include "Chambre.h"
#include"Hospitalisation.h"
#include"RDV.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_commandLinkButton_2_clicked();

    void on_rechercherPB_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_modifierpatientPB_clicked();

    void on_chercher_clicked();

    void on_modifier_clicked();

    void on_supprimerPB_clicked();

    void on_recherchele_textChanged(const QString &arg1);

    void on_supprimerPatientPB_clicked();

    void on_imprimer_clicked();




 void   on_comboBoxsmodhospitalisation_currentIndexChanged(const QString &arg1);


    void on_comboBox_supp_patient_currentIndexChanged(const QString &arg1);

    void on_commandLinkButton_10_clicked();

    void on_rechercheidrdvle_cursorPositionChanged(int arg1, int arg2);

    void on_rechercherdvPB_clicked();

    void on_commandLinkButton_clicked();

    void on_AjouterchambrePB_clicked();

    void on_recherchechambrele_textChanged(const QString &arg1);

    void on_comboBoxsuppchambre_currentIndexChanged(int index);

    void on_comboBoxsuppchambre_currentIndexChanged(const QString &arg1);

    void on_comboBoxmodifierchambre_currentIndexChanged(const QString &arg1);

    void on_commandLinkButton_12_clicked();

    void on_supprimerchambrePB_clicked();

    void on_modifRDV_clicked();

    void on_rechercheidrdvle_textChanged(const QString &arg1);

    void on_print_clicked();

    void on_modifRDV_3_clicked();

    void on_modifierchambrePB_clicked();

    void on_ajouthospitalisationPB_clicked();

    void on_comboBoxsupphospitalisation_currentIndexChanged(const QString &arg1);

    void on_supprimerhospitalisationPB_clicked();


    void on_modifierhospPB_clicked();

    void on_rechercheidhosple_textEdited(const QString &arg1);

    void on_rechercheidhosple_textChanged(const QString &arg1);


    void on_comboBox_modif_patirnt_textChanged(const QString &arg1);

    void on_cin_modif_2_textChanged(const QString &arg1);

    void on_comboBox_supp_patient_textChanged(const QString &arg1);

    void on_cin_supp_patient_textChanged(const QString &arg1);

    void on_suppchambrele_textChanged(const QString &arg1);

    void on_modchamble_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
     Patient * temppat;
     Chambre * tempch;
     Hospitalisation * temph;
     Patient p;
     Chambre c;
    RDV *temprdv;
};

#endif // MAINWINDOW_H
