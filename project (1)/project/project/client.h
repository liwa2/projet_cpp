#ifndef CLIENT_H
#define CLIENT_H
#include <string.h>
#include <iostream>
#include <QSqlQuery>

#include <QtDebug>
#include <QObject>
#include<vector>
#include <QSqlQueryModel>
#include <list>
class client
{
private:
    QString id_client , id_payment , name , first_name , email,phone_number ;
    int age  , vip;



public:
    client();
    client(QString id_c,QString id_p,QString name,int age,QString phone_n,QString first_n,QString email,int vip){
        this->id_client=id_c;
        this->id_payment=id_p;
        this->name=name;
        this->first_name=first_n;
        this->email=email;
        this->age=age;
        this->phone_number=phone_n;
        this->vip=vip;
    }
    bool add_client();
    QSqlQueryModel* afficher_client(QString order);
    bool modif_client();
    QSqlQueryModel* search_client(QString id_c,QString variable);
    bool delete_client(QString id);
};

#endif // CLIENT_H
