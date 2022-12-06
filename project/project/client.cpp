#include "client.h"
#include "profil.h"
#include "client_profil.h"


client::client()
{

}
bool client::add_client(){
    QSqlQuery query;
     query.prepare( "INSERT INTO client (id_client, id_payment, name , first_name, email, age , phone_number , vip) "
                       "VALUES (:id_client, :id_payment, :name , :first_name, :email, :age , :phone_number , :vip)" );
         query.bindValue(":id_client",id_client);
         query.bindValue(":id_payment",id_payment);
         query.bindValue(":name",name);
         query.bindValue(":first_name",first_name);
         query.bindValue(":email",email);
         query.bindValue(":age",age);
         query.bindValue(":phone_number",phone_number);
         query.bindValue(":vip",vip);


    return query.exec();

}
// //////////////////////////////////////////// client login page

bool client_profil::ajoutercP()
{

    QSqlQuery query;
    query.prepare("INSERT INTO client_user(cusername, cpassword) "
                  "VALUES (:cusername, :cpassword)" );

                  query.bindValue(":cusername", cuser);
                  query.bindValue(":cpassword", cpass);
return query.exec();

}


bool client_profil::loginc(QString cuser, QString cpass){

    QSqlQuery query;

          QString select ="select * from client_user where cusername='"+cuser+"' and cpassword='"+cpass+"'";

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



QSqlQueryModel* client::afficher_client(QString order){
    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="id_client")
        {
           model->setQuery("select * from client order by id_client ASC ");
        }
        if(order=="id_payment")
        {
            model->setQuery("select * from client order by id_payment ASC ");
        }
        if(order=="name")
        {
            model->setQuery("select * from client order by name ASC ");
        }
        if(order=="first_name")
        {
            model->setQuery("select * from client order by first_name ASC ");
        }
       if(order=="age")
        {
             model->setQuery("select * from client order by age DESC ");
        }
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_payment"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("name"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("first_name"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("phone_number"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("vip"));
    return model;


}

bool client::modif_client(){
    QSqlQuery query;
   query.prepare( "UPDATE client SET id_client=:id_client , id_payment=:id_payment , name=:name , first_name=:first_name , email=:email ,"
                  " age=:age , phone_number=:phone_number , vip = :vip WHERE id_client=:id_client ");
         query.bindValue(":id_client",id_client);
         query.bindValue(":name",name);
         query.bindValue(":first_name",first_name);
         query.bindValue(":email",email);
         query.bindValue(":age",age);
         query.bindValue(":phone_number",phone_number);
         query.bindValue(":vip",vip);


return query.exec();

}


QSqlQueryModel* client ::search_client(QString id,QString variable){

    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="id_payment")
     {
     model->setQuery("SELECT * FROM client WHERE  (id_payment like '"+id+"%""')  ");
     }
    if(variable=="id_client")
    {
    model->setQuery("SELECT * FROM client WHERE  (id_client like '"+id+"%""')  ");
    }
    if(variable=="name")
     {
     model->setQuery("SELECT * FROM client WHERE  (name like '"+id+"%""')  ");
     }
    if(variable=="first_name")
     {
     model->setQuery("SELECT * FROM client WHERE  (first_name like '"+id+"%""')  ");
     }
    if(variable=="email")
     {
     model->setQuery("SELECT * FROM client WHERE  (email like '"+id+"%""')  ");
     }
    if(variable=="age")
     {
     model->setQuery("SELECT * FROM client WHERE  (age like '"+id+"%""')  ");
     }
    if(variable=="phone_number")
     {
     model->setQuery("SELECT * FROM client WHERE  (phone_number like '"+id+"%""')  ");
     }
    if(variable=="vip")
     {
     model->setQuery("SELECT * FROM client WHERE  (vip like '"+id+"%""')  ");
     }
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_payment"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("name"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("first_name"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("age"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("phone_number"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("vip"));
    query.exec();
        return  model;
}

bool client::delete_client(QString id){
    QSqlQuery query;
         query.prepare(" Delete from client where id_client=:id_client");
         query.bindValue(0, id);

        return query.exec();
}



void client::statpie(int &vip,int &rest){

   QSqlQuery query , query2 ;
   query.prepare("select count(vip) from client where vip=1" );
           if(query.exec())
           {
               while (query.next())
               {
               vip=query.value(0).toInt();

               }
           }
    query2.prepare("select count(vip) from client where vip=0" );
                   if(query2.exec())
                   {
                       while (query2.next())
                       {
                       rest=query2.value(0).toInt();

                       }
                   }

}

void client::stat2(int a[]){
    int age=0;
    QString age_string=QString::number(age);

 int i=0;


 QSqlQuery query;
 while(age<100)
 {
   query.prepare("select count(age) from client where (age like '""%"+age_string+"')");
   if(query.exec())
   {
     while (query.next())
      {
       a[i]=query.value(0).toInt();

      }
    }
   age=age+20;
   i++;
   age_string=QString::number(age);
 }
}




