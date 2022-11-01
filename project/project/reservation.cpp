#include "reservation.h"
#include <QDate>
#include <QTextCharFormat>
#include "dialog.h"
#include <QList>
#include <list>

reservation::reservation()
{

}



bool reservation::add_reservation()
{
    QSqlQuery query;
     query.prepare( "INSERT INTO reservation (ID_RESERVATION, ID_CLIENT, ID_PAYMENT, NBR_PLACE, DESTINATION, DATE_ALLER, DATE_RETOUR) "
                       "VALUES (:ID_RESERVATION, :ID_CLIENT, :ID_PAYMENT, :NBR_PLACE, :DESTINATION, :DATE_ALLER, :DATE_RETOUR)" );
         query.bindValue(":ID_RESERVATION",id_reservation);
         query.bindValue(":ID_CLIENT",id_client);
         query.bindValue(":ID_PAYMENT",id_payment);
         query.bindValue(":NBR_PLACE",nbr_place);
         query.bindValue(":DESTINATION",destination);
         query.bindValue(":DATE_ALLER",date_aller);
         query.bindValue(":DATE_RETOUR",date_retour);

return query.exec();
}


QSqlQueryModel* reservation::afficher_reservation(QString order){

    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="id_reservation")
        {
            model->setQuery("select * from reservation order by id_reservation ASC ");
        }
        if(order=="nbr_place")
        {
            model->setQuery("select * from reservation order by nbr_place desc ");
        }
       if(order=="destination")
        {
            model->setQuery("select * from reservation order by destination desc ");
        }

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reservation"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_payment"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbr_place"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("destination"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_aller"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("date_retour"));

    return model;
}

bool reservation::modify_reservation(){

    QSqlQuery query;
   query.prepare( "UPDATE reservation SET ID_RESERVATION=:ID_RESERVATION , ID_CLIENT=:ID_CLIENT , ID_PAYMENT=:ID_PAYMENT , NBR_PLACE=:NBR_PLACE , DESTINATION=:DESTINATION ,"
                  " DATE_ALLER=:DATE_ALLER , DATE_RETOUR=:DATE_RETOUR WHERE ID_RESERVATION=:ID_RESERVATION ");
   query.bindValue(":ID_RESERVATION",id_reservation);
   query.bindValue(":ID_CLIENT",id_client);
   query.bindValue(":ID_PAYMENT",id_payment);
   query.bindValue(":NBR_PLACE",nbr_place);
   query.bindValue(":DESTINATION",destination);
   query.bindValue(":DATE_ALLER",date_aller);
   query.bindValue(":DATE_RETOUR",date_retour);

return query.exec();
}

QSqlQueryModel* reservation::search_reservation(QString id,QString variable){
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="id_reservation")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (id_reservation like '"+id+"%""')  ");
     }
    if(variable=="id_client")
    {
    model->setQuery("SELECT * FROM reservation WHERE  (id_client like '"+id+"%""')  ");
    }
    if(variable=="id_payment")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (id_payment like '"+id+"%""')  ");
     }
    if(variable=="nbr_place")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (nbr_place like '"+id+"%""')  ");
     }
    if(variable=="destination")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (destination like '"+id+"%""')  ");
     }
    if(variable=="date_aller")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (date_aller like '"+id+"%""')  ");
     }
    if(variable=="date_retour")
     {
     model->setQuery("SELECT * FROM reservation WHERE  (date_retour like '"+id+"%""')  ");
     }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_payment"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nbr_place"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("destination"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_aller"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date_retour"));
    query.exec();
        return  model;
}

bool reservation::delete_reservation(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from reservation where id_reservation=:id_reservation");
         query.bindValue(0, id);

        return query.exec();
}


void reservation::search_date(QString date){
QSqlQuery query;

query.prepare("select ID_RESERVATION,DATE_ALLER,DATE_RETOUR,DESTINATION,ID_CLIENT from reservation where DATE_ALLER='"+date+"' or DATE_RETOUR='"+date+"' ");

  if(query.exec())
  {
      while(query.next())
      {
        id_reservation=query.value(0).toString();
        date_aller = query.value(1).toString();
        date_retour = query.value(2).toString();
        destination = query.value(3).toString();
        id_client = query.value(4).toString();

      }
  }


}




void reservation::satistics(int count[])
{
    int year=2019,i=0;
    QString year_string=QString::number(year);
 QSqlQuery query;
 while(year<2023)
 {
   query.prepare("select count(*) from reservation where (date_aller like '""%"+year_string+"')");
   if(query.exec())
   {
     while (query.next())
      {
        count[i]=query.value(0).toInt() ;
      }
    }
   year++;
   i++;
   year_string=QString::number(year);
 }
}













