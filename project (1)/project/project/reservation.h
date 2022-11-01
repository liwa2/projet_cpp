#ifndef RESERVATION_H
#define RESERVATION_H
#include <string.h>
#include <iostream>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<vector>
#include <QSqlQueryModel>
#include <QList>
#include <list>
#include "dialog.h"
class reservation
{
private:
    int nbr_place;
    QString id_reservation,id_client,id_payment,destination,date_aller,date_retour;
public:
    reservation();
    reservation( QString id_reservation,QString id_client,QString id_payment,QString destination,QString date_aller,QString date_retour,int nbr_place )
    {
        this->id_reservation=id_reservation;
        this->id_client=id_client;
        this->id_payment=id_payment;
        this->destination=destination;
        this->date_aller=date_aller;
        this->date_retour=date_retour;
        this->nbr_place=nbr_place;
    }
    bool add_reservation();
    QSqlQueryModel*  afficher_reservation(QString order);
    bool modify_reservation();
    QSqlQueryModel* search_reservation(QString id,QString variable);
    bool delete_reservation(QString id);
    //calendrier
    void search_date(QString date);

    void satistics(int count[]);

    QString  getid_reservation(){return id_reservation;}
    QString  getdate_aller(){return date_aller;}
    QString  getdate_retour(){return date_retour;}
    QString  getdestination(){return destination;}
    QString  getid_client(){return id_client;}

};

#endif // RESERVATION_H
