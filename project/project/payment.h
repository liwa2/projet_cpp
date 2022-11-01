#ifndef PAYMENT_H
#define PAYMENT_H
#include "dialog.h"
#include <string.h>
#include <iostream>
#include <QSqlQuery>

#include <QtDebug>
#include <QObject>
#include<vector>
#include <QSqlQueryModel>
#include <list>
class payment
{
private:
QString id_payment,service_type,date,payment_method,cardname;
int salary,bill;

public:

    payment();
    payment(QString id ,QString d,QString type,int salaryy,int billl,QString method,QString card){
        this->id_payment=id;
        this->date=d;
        this->service_type=type;
        this->salary=salaryy;
        this->bill=billl;
        this->payment_method=method;
        this->cardname=card;
    };

    QString getId_payment();
    QString getService_type();
    QString getDate();
    int getSalary();
    int getBill();
    QString getpayment_method();
    QString getcardname();

    void setId_payment(QString);
    void setService_type(QString);
    void setDate(QString);
    void setSalary(int);
    void setBill(int);
    void setpayment_method(QString);
    void setcardname(QString);


    bool add_payment();
    QSqlQueryModel*  afficher_payment(QString order);
    bool modify_payment();
    QSqlQueryModel* search_payment(QString id,QString variable);
    bool delete_payment(QString id);

    int employee_salary(QString id);
    int client_bill(QString id);

    void satistic_1(int &bill,int &salary);
    void satistic_2(int s[],int b[]);
};

#endif // PAYMENT_H
