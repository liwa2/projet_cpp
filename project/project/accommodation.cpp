#include "accommodation.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
accommodation::accommodation()
{

}


bool accommodation::add_accommodation()
{
    QSqlQuery query;
     query.prepare( "INSERT INTO accommodation (ID_ACCOMMODATION, ID_RESERVATION, HOTEL_NAME, HOTEL_TELPH, HOTEL_RATE, MOTRANSPORT) "
                       "VALUES (:ID_ACCOMMODATION, :ID_RESERVATION, :HOTEL_NAME, :HOTEL_TELPH, :HOTEL_RATE, :MOTRANSPORT)" );
         query.bindValue(":ID_ACCOMMODATION",id_accommodation);
         query.bindValue(":ID_RESERVATION",id_reservation);
         query.bindValue(":HOTEL_NAME",hotel_name);
         query.bindValue(":HOTEL_TELPH",hotel_telph);
         query.bindValue(":HOTEL_RATE",hotel_rate);
         query.bindValue(":MOTRANSPORT",MOTransport);
return query.exec();

}


QSqlQueryModel* accommodation::afficher_accommodation(QString order){
    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="ID_ACCOMMODATION")
        {
            model->setQuery("select * from accommodation order by ID_ACCOMMODATION ASC ");
        }
        if(order=="HOTEL_RATE")
        {
            model->setQuery("select * from accommodation order by HOTEL_RATE desc ");
        }
       if(order=="HOTEL_NAME")
        {
            model->setQuery("select * from accommodation order by HOTEL_NAME desc ");
        }
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ACCOMMODATION"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOTEL_NAME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("HOTEL_TELPH"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("HOTEL_RATE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOTRANSPORT"));

    return model;
}


bool accommodation::modify_accommodation()
{
    QSqlQuery query;
   query.prepare( "UPDATE accommodation SET ID_ACCOMMODATION=:ID_ACCOMMODATION , ID_RESERVATION=:ID_RESERVATION , HOTEL_NAME=:HOTEL_NAME , HOTEL_TELPH=:HOTEL_TELPH , HOTEL_RATE=:HOTEL_RATE ,"
                  " MOTRANSPORT=:MOTRANSPORT  WHERE ID_ACCOMMODATION=:ID_ACCOMMODATION ");
   query.bindValue(":ID_ACCOMMODATION",id_accommodation);
   query.bindValue(":ID_RESERVATION",id_reservation);
   query.bindValue(":HOTEL_NAME",hotel_name);
   query.bindValue(":HOTEL_TELPH",hotel_telph);
   query.bindValue(":HOTEL_RATE",hotel_rate);
   query.bindValue(":MOTRANSPORT",MOTransport);
return query.exec();
}





QSqlQueryModel* accommodation::search_accommodation(QString id, QString variable)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="ID_ACCOMMODATION")
     {
     model->setQuery("SELECT * FROM accommodation WHERE  (ID_ACCOMMODATION like '"+id+"%""')  ");
     }
    if(variable=="ID_RESERVATION")
    {
    model->setQuery("SELECT * FROM accommodation WHERE  (ID_RESERVATION like '"+id+"%""')  ");
    }
    if(variable=="HOTEL_NAME")
     {
     model->setQuery("SELECT * FROM accommodation WHERE  (HOTEL_NAME like '"+id+"%""')  ");
     }
    if(variable=="HOTEL_TELPH")
     {
     model->setQuery("SELECT * FROM accommodation WHERE  (HOTEL_TELPH like '"+id+"%""')  ");
     }
    if(variable=="HOTEL_RATE")
     {
     model->setQuery("SELECT * FROM accommodation WHERE  (HOTEL_RATE like '"+id+"%""')  ");
     }
    if(variable=="MOTRANSPORT")
     {
     model->setQuery("SELECT * FROM accommodation WHERE  (MOTRANSPORT like '"+id+"%""')  ");
     }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ACCOMMODATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOTEL_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HOTEL_TELPH"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("HOTEL_RATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MOTRANSPORT"));
    query.exec();
        return  model;
}


bool accommodation::delete_accommodation(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from accommodation where ID_ACCOMMODATION=:ID_ACCOMMODATION");
         query.bindValue(0, id);
        return query.exec();
}





