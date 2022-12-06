#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string.h>
#include <iostream>
#include <QSqlQuery>

#include <QtDebug>
#include <QObject>
#include<vector>
#include <QSqlQueryModel>
#include <list>


class employee
{
private:
    QString id_employee,id_payment;
    QString first_name,name,age,email,adress,phone_number,role;
public:
    employee();
    employee(QString id_employee,QString id_payment ,QString first_name,QString name,QString age,QString email,QString adress,QString phone_number,QString role)
    {
        this->id_employee=id_employee;
        this->id_payment=id_payment;
        this->first_name=first_name;
        this->name=name;
        this->age=age;
        this->email=email;
        this->adress=adress;
        this->phone_number=phone_number;
        this->role=role;
    }
    bool add_employee();
    QSqlQueryModel*  afficher_employee(QString order);
    bool modify_employee();
    QSqlQueryModel* search_employee(QString id,QString variable);
    bool delete_employee(QString id);
};

#endif // EMPLOYEE_H
