#include "payment.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include <iostream>
#include <QDateTime>
using namespace std;
payment::payment()
{
    this->id_payment="";
    this->date="";
    this->service_type="";
    this->salary=0;
    this->bill=0;
    this->payment_method="";
    this->cardname="";
}

QString payment::getId_payment(){return id_payment;}
QString payment::getService_type(){return  service_type;}
QString payment::getDate(){return  date;}
int payment::getSalary(){return  salary;}
int payment::getBill(){return bill;}

void payment::setId_payment(QString id){this->id_payment=id;}
void payment::setService_type(QString service){this->service_type=service;}
void payment::setDate(QString d){this->date=d;}
void payment::setSalary(int s){this->salary=s;}
void payment::setBill(int b){this->bill=b;}

bool payment::add_payment(){
    QSqlQuery query;
     query.prepare( "INSERT INTO payment (id_payment, date_payment, service_type, salary_employee, client_bill, payment_method, cardname) "
                       "VALUES (:id_payment, :date_payment, :service_type, :salary_employee, :client_bill, :payment_method, :cardname)" );
         query.bindValue(":id_payment",id_payment);
         query.bindValue(":date_payment",date);
         query.bindValue(":service_type",service_type);
         query.bindValue(":salary_employee",salary);
         query.bindValue(":client_bill",bill);
         query.bindValue(":payment_method",payment_method);
         query.bindValue(":cardname",cardname);

return query.exec();

}

QSqlQueryModel* payment::afficher_payment(QString order)  {
    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="id_payment")
        {
            model->setQuery("select * from payment order by id_payment ASC ");
        }
        if(order=="salary_employee")
        {
            model->setQuery("select * from payment order by salary_employee desc ");
        }
       if(order=="client_bill")
        {
            model->setQuery("select * from payment order by client_bill desc ");
        }
       if(order=="cardname")
        {
             model->setQuery("select * from payment order by cardname desc ");
        }
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_payment"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_payment"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("service_type"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("salary_employee"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("client_bill"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("payment_method"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("cardname"));
    return model;
}

bool payment::modify_payment(){
    QSqlQuery query;
   query.prepare( "UPDATE payment SET id_payment=:id_payment , date_payment=:date_payment , service_type=:service_type , salary_employee=:salary_employee , client_bill=:client_bill ,"
                  " payment_method=:payment_method , cardname=:cardname WHERE id_payment=:id_payment ");
         query.bindValue(":id_payment",id_payment);
         query.bindValue(":date_payment",date);
         query.bindValue(":service_type",service_type);
         query.bindValue(":salary_employee",salary);
         query.bindValue(":client_bill",bill);
         query.bindValue(":payment_method",payment_method);
         query.bindValue(":cardname",cardname);

return query.exec();

}

QSqlQueryModel* payment::search_payment(QString id,QString variable){

QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;
if(variable=="id_payment")
 {
 model->setQuery("SELECT * FROM payment WHERE  (id_payment like '"+id+"%""')  ");
 }
if(variable=="salary_employee")
{
model->setQuery("SELECT * FROM payment WHERE  (salary_employee like '"+id+"%""')  ");
}
if(variable=="client_bill")
 {
 model->setQuery("SELECT * FROM payment WHERE  (client_bill like '"+id+"%""')  ");
 }
if(variable=="cardname")
 {
 model->setQuery("SELECT * FROM payment WHERE  (cardname like '"+id+"%""')  ");
 }
if(variable=="payment_method")
 {
 model->setQuery("SELECT * FROM payment WHERE  (payment_method like '"+id+"%""')  ");
 }
if(variable=="service_type")
 {
 model->setQuery("SELECT * FROM payment WHERE  (service_type like '"+id+"%""')  ");
 }
if(variable=="date_payment")
 {
 model->setQuery("SELECT * FROM payment WHERE  (date_payment like '"+id+"%""')  ");
 }
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_payment"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_payment"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("service_type"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("salary_employee"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("client_bill"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("payment_method"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("cardname"));
query.exec();
    return  model;
}

bool payment::delete_payment(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from payment where id_payment=:id_payment");
         query.bindValue(0, id);

        return query.exec();

}


int payment::employee_salary(QString id)
{
    QSqlQuery query;
    QString role;
    int age=0,role_salary=0;
    float x=0,salary=0;
         query.prepare(" select role,age from employee where id_payment='"+id+"'");
         if(query.exec())
         {
           while(query.next())
            {
             role=query.value(0).toString();
             age=query.value(1).toInt() ;

            }
           if(age<30)
             {
               x=0.5;
             }
           if(age>=30 && age<35)
             {
               x=1;
             }
           if(age>=35)
             {
               x=1.5;
             }

           if(role=="travelagent")
            {
              role_salary=28000;
            }

           if(role=="economymanager")
            {
               role_salary=73000;
            }
           if(role=="travelmanager")
            {
               role_salary=33000;
            }
           if(role=="marketingmanager")
            {
               role_salary=84000;
            }
           if(role=="administrativemanager")
            {
               role_salary=44000;
            }
           if(role=="softwareengineer")
            {
               role_salary=60000;
            }



           salary=role_salary * x;

           qDebug() << age << role << role_salary << x << salary;
           return  (int)salary;
         }
         else{
             QMessageBox::information(nullptr,"sign up","done !");
             return -1;
         }




}




int payment::client_bill(QString id){
  QSqlQuery query1;
  int vip=0;
  float reduction=1;
  query1.prepare(" select vip from client where id_payment='"+id+"'");
     if(query1.exec())
     {
         while (query1.next())
         {
            vip=query1.value(0).toInt();
         }

     }

     if(vip==1)
         reduction=0.75;

    //get from reservation
    QSqlQuery query;
    int nbr_place=0;
    QString date_aller,date_retour,id_reservation;
    float price_day,price_place;
    query.prepare(" select NBR_PLACE,ID_RESERVATION,DATE_ALLER,DATE_RETOUR from reservation where id_payment='"+id+"'");
         if(query.exec())
         {
             while (query.next())
             {
                 nbr_place=query.value(0).toInt();
                 id_reservation=query.value(1).toString();
                 date_aller=query.value(2).toString();
                 date_retour=query.value(3).toString();

             }
         }

 //calculate the number of days from the first day of the trip until the last day
QDate Date,Date2;
    if(date_aller[2]==QChar('/') && date_aller[5]==QChar('/'))
       Date = QDate::fromString(date_aller,"MM/dd/yyyy");
    if(date_aller[1]==QChar('/') && date_aller[4]==QChar('/'))
        Date = QDate::fromString(date_aller,"M/dd/yyyy");
    if(date_aller[2]==QChar('/') && date_aller[4]==QChar('/'))
        Date = QDate::fromString(date_aller,"MM/d/yyyy");
    if(date_aller[1]==QChar('/') && date_aller[3]==QChar('/'))
        Date = QDate::fromString(date_aller,"M/d/yyyy");

    if(date_retour[2]==QChar('/') && date_retour[5]==QChar('/'))
        Date2 = QDate::fromString(date_retour,"MM/dd/yyyy");
    if(date_retour[1]==QChar('/') && date_retour[4]==QChar('/'))
        Date2 = QDate::fromString(date_retour,"M/dd/yyyy");
    if(date_retour[2]==QChar('/') && date_retour[4]==QChar('/'))
        Date2 = QDate::fromString(date_retour,"MM/d/yyyy");
    if(date_retour[1]==QChar('/') && date_retour[3]==QChar('/'))
        Date2 = QDate::fromString(date_retour,"M/d/yyyy");


   QDate d(Date.year(),Date.month(),Date.day());
   QDate d2(Date2.year(),Date2.month(),Date2.day());

   int nbr_days= d.daysTo(d2);
   qDebug() <<d.daysTo(d2);

   int visa=0;

   if(nbr_days<=30)
       visa=80*nbr_place;
   if(nbr_days<=180 && nbr_days>30)
       visa=160*nbr_place;
   if(nbr_days>180)
       visa=230*nbr_place;




//------------------------------------------------------------------

         //get from accommodation
         QSqlQuery query2;
         QString motransport="";
         int rate=0;
         int hotel_reservation_price,transport_price;
         query2.prepare("select HOTEL_RATE,MOTRANSPORT from accommodation where id_reservation='"+id_reservation+"'");
         if(query2.exec())
         {
             while (query2.next())
             {
                 rate=query2.value(0).toInt();
                 motransport=query2.value(1).toString();
             }
         }



         if(rate<=3)
             hotel_reservation_price=30*nbr_days*nbr_place;
         if(rate==4)
             hotel_reservation_price=60*nbr_days*nbr_place;
         if(rate==5)
             hotel_reservation_price=110*nbr_days*nbr_place;
         if(rate==6)
             hotel_reservation_price=300*nbr_days*nbr_place;


         if(nbr_days<=30)
         {
          if(motransport=="Public transport")
              transport_price=0;
          if(motransport=="Taxis")
              transport_price=30*nbr_place;
          if(motransport=="Bolt Buisness car")
              transport_price=60*nbr_place;
         }
         if(nbr_days>30 && nbr_days<=90)
         {
          if(motransport=="Public transport")
              transport_price=0;
          if(motransport=="Taxis")
              transport_price=60*nbr_place;
          if(motransport=="Bolt Buisness car")
              transport_price=100*nbr_place;
         }
         if(nbr_days>90)
         {
          if(motransport=="Public transport")
              transport_price=0;
          if(motransport=="Taxis")
              transport_price=100*nbr_place;
          if(motransport=="Bolt Buisness car")
              transport_price=200*nbr_place;
         }


int bill=(visa+transport_price+hotel_reservation_price)*reduction ;


         return bill;
}





void payment::satistic_1(int &bill, int &salary){

    QSqlQuery query;
    query.prepare("select sum(CLIENT_BILL),sum(SALARY_EMPLOYEE) from payment");
    if(query.exec())
    {
        while (query.next())
        {
        bill=query.value(0).toInt();
        salary=query.value(1).toInt();
        }
    }
}




void payment::satistic_2(int s[], int b[]){
    int year=2019;
    QString year_string=QString::number(year);
 int i=0;


 QSqlQuery query;
 while(year<2023)
 {
   query.prepare("select sum(CLIENT_BILL),sum(SALARY_EMPLOYEE) from payment where (date_payment like '""%"+year_string+"')");
   if(query.exec())
   {
     while (query.next())
      {
       b[i]=query.value(0).toInt();
       s[i]=query.value(1).toInt();
      }
    }
   year++;
   i++;
   year_string=QString::number(year);
 }
}





