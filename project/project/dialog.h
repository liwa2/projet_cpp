#ifndef DIALOG_H
#define DIALOG_H
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QChartView>
#include<QtCharts>
#include<QChart>
#include <QPainter>
#include <QCalendarWidget>
#include <iostream>
#include "notif_space.h"
#include "chatbox.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QVBoxLayout create_piechart();
    QVBoxLayout create_chart();


private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_24_clicked();

    void on_idclient_reservation_line_textChanged(const QString &arg1);

    void on_idclient_reservation_line_editingFinished();

    void on_idpayment_reservation_line_textChanged(const QString &arg1);

    void on_idpayment_reservation_line_editingFinished();

    void on_id_reservation_line_textChanged(const QString &arg1);

    void on_id_reservation_line_editingFinished();

    void on_nbrplaces_reservation_line_textChanged(const QString &arg1);

    void on_nbrplaces_reservation_line_editingFinished();

    void on_cityname_reservation_line_textChanged(const QString &arg1);

    void on_cityname_reservation_line_editingFinished();

    void on_searsh_reservation_line_textChanged(const QString &arg1);

    void on_searsh_reservation_line_editingFinished();

    void on_id_client_line_textChanged(const QString &arg1);

    void on_id_client_line_editingFinished();

    void on_firstname_client_line_textChanged(const QString &arg1);

    void on_firstname_client_line_editingFinished();

    void on_name_client_line_textChanged(const QString &arg1);

    void on_name_client_line_editingFinished();

    void on_email_client_line_textChanged(const QString &arg1);

    void on_email_client_line_editingFinished();

    void on_age_client_line_textChanged(const QString &arg1);

    void on_age_client_line_editingFinished();

    void on_phonenumber_client_line_textChanged(const QString &arg1);

    void on_phonenumber_client_line_editingFinished();

    void on_searsh_client_line_textChanged(const QString &arg1);

    void on_searsh_client_line_editingFinished();



    void on_id_payment_line_textChanged(const QString &arg1);

    void on_id_payment_line_editingFinished();

    void on_searsh_payment_line_textChanged(const QString &arg1);

    void on_searsh_payment_line_editingFinished();

    void on_id_emloyee_line_textChanged(const QString &arg1);

    void on_id_emloyee_line_editingFinished();

    void on_firstname_emloyee_line_textChanged(const QString &arg1);

    void on_firstname_emloyee_line_editingFinished();

    void on_name_employee_line_textChanged(const QString &arg1);

    void on_name_employee_line_editingFinished();

    void on_age_emloyee_line_textChanged(const QString &arg1);

    void on_age_emloyee_line_editingFinished();

    void on_email_emloyee_line_textChanged(const QString &arg1);

    void on_email_emloyee_line_editingFinished();

    void on_adress_emloyee_line_textChanged(const QString &arg1);

    void on_adress_emloyee_line_editingFinished();

    void on_phonenumber_emloyee_line_textChanged(const QString &arg1);

    void on_phonenumber_emloyee_line_editingFinished();

    void on_searsh_emloyee_line_textChanged(const QString &arg1);

    void on_searsh_emloyee_line_editingFinished();

    void on_id_accommodation_line_textChanged(const QString &arg1);

    void on_id_accommodation_line_editingFinished();

    void on_idreservation_accommodation_line_textChanged(const QString &arg1);

    void on_idreservation_accommodation_line_editingFinished();

    void on_hotelname_accommodation_line_textChanged(const QString &arg1);

    void on_hotelname_accommodation_line_editingFinished();

    void on_hoteltelph_accommodation_line_textChanged(const QString &arg1);

    void on_hoteltelph_accommodation_line_editingFinished();

    void on_hotelrate_accommodation_line_textChanged(const QString &arg1);

    void on_hotelrate_accommodation_line_editingFinished();

    void on_searsh_accommodation_line_textChanged(const QString &arg1);

    void on_searsh_accommodation_line_editingFinished();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();


    void on_pushButton_22_clicked();

    void on_payment_add_button_clicked();

    void on_payment_modify_button_clicked();

    void on_payment_search_button_clicked();

    void on_payment_delete_button_clicked();

    void on_payment_pdf_clicked();

    void on_client_add_button_clicked();

    void on_client_modify_button_clicked();

    void on_client_search_button_clicked();

    void on_client_delete_button_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_employee_add_button_clicked();

    void on_reservation_add_button_clicked();

    void on_reservation_modify_button_clicked();

    void on_reservation_search_button_clicked();

    void on_reservation_delete_button_clicked();

    void on_employee_modify_button_clicked();

    void on_employee_search_button_clicked();

    void on_employee_delete_button_clicked();

    void on_accommodation_add_button_clicked();

    void on_accommodation_modify_button_clicked();

    void on_accommodation_search_button_clicked();

    void on_accommodation_delete_button_clicked();

    void on_client_pdf_clicked();

    void on_reservation_pdf_clicked();

    void on_employe_pdf_clicked();

    void on_accommodation_pdf_clicked();

    void on_notif_clicked();

    void on_chat_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_piechart_client_customContextMenuRequested(const QPoint &pos);

public:
    Ui::Dialog *ui;
    notif_space *notif;
    chatbox *chat;


};



#endif // DIALOG_H
