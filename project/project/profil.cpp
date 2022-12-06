#include "profil.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "mainwindow.h"
#include <iostream>
using namespace std;
profil::profil()
{
user=""; pass="";
}

profil::profil(QString username,QString password){

this->user=username;
this->pass=password;

}


QString profil::getuser(){return  user;}
QString profil::getpass(){return pass;}

void profil::setuser(QString user){this->user=user;}
void profil::setpass(QString pass){this->pass=pass;}

/*QSqlQueryModel*  profil::recherche(QString user,QString pass){
    QSqlQueryModel* model=new QSqlQueryModel();

        QString request ="SELECT * FROM admin where username='"+user+"' and password='"+pass+"'" ;
        model->setQuery(request);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("userr_id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("username"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));
return model;

}*/


bool profil::ajouterP()
{

    QSqlQuery query;
     query.prepare( "INSERT INTO userr (userr_id, username, password) "
                       "VALUES (userr_id.nextval,:username, :password)" );
         query.bindValue(":username", user);
         query.bindValue(":password", pass);
return query.exec();

}

bool profil::login(QString user, QString pass){
   /* QSqlQuery query1;
       query1.prepare("SELECT userr_id FROM userr WHERE username ='firas'");
      if(query1.exec()) {
       while (query1.next()) {
              int id = query1.value(0).toInt();
                printf("id: %d \n",id);
          }}*/
  QSqlQuery query;

        QString select ="select * from userr where username='"+user+"' and password='"+pass+"'";

        query.prepare(select);
      if(query.exec())
      {
        int count=0;

         while(query.next())
         {
             count++;
         }
       printf("count: %d \n",count);
        if(count!=0)
        {
            return true;
        }
        else if(count==0)
        {
            return false;
        }

      }

}



