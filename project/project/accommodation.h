#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H
#include "dialog.h"
#include <string.h>
#include <iostream>
#include <QSqlQueryModel>
#include <QSqlQuery>
class accommodation
{
 private:
    QString  id_reservation;
    QString  id_accommodation,hotel_telph;
    QString hotel_name,MOTransport ;
    int hotel_rate;
public:
    accommodation();
    accommodation(QString id_accommodation,QString id_reservation,QString hotel_name,QString hotel_telph,int hotel_rate,QString MOTransport)
    {
        this->id_accommodation=id_accommodation;
        this->id_reservation=id_reservation;
        this->hotel_name=hotel_name;
        this->hotel_telph=hotel_telph;
        this->hotel_rate=hotel_rate;
        this->MOTransport=MOTransport;
    }

   bool add_accommodation();
   QSqlQueryModel*  afficher_accommodation(QString order);
   bool modify_accommodation();
   QSqlQueryModel* search_accommodation(QString id,QString variable);
   bool delete_accommodation(QString id);

};

#endif // ACCOMMODATION_H
