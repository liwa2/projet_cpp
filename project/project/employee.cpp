#include "employee.h"

employee::employee()
{

}

bool employee::add_employee(){
    QSqlQuery query;
     query.prepare( "INSERT INTO employee (ID_EMPLOYEE, ID_PAYMENT, FIRST_NAME, NAME, AGE,EMAIL, ADRESS, PHONE_NUMBER, ROLE) "
                       "VALUES (:ID_EMPLOYEE, :ID_PAYMENT, :FIRST_NAME, :NAME, :AGE, :EMAIL, :ADRESS, :PHONE_NUMBER, :ROLE)" );
         query.bindValue(":ID_EMPLOYEE",id_employee);
         query.bindValue(":ID_PAYMENT",id_employee);
         query.bindValue(":FIRST_NAME",first_name);
         query.bindValue(":NAME",name);
          query.bindValue(":AGE",age);
         query.bindValue(":EMAIL",email);
         query.bindValue(":ADRESS",adress);
          query.bindValue(":PHONE_NUMBER",phone_number);
         query.bindValue(":ROLE",role);

return query.exec();
}

QSqlQueryModel*  employee::afficher_employee(QString order)
{

    QSqlQueryModel *model = new QSqlQueryModel();

        if(order=="id_employee")
        {
            model->setQuery("select * from employee order by ID_EMPLOYEE ASC ");
        }
        if(order=="name")
        {
            model->setQuery("select * from reservation order by NAME desc ");
        }
       if(order=="age")
        {
            model->setQuery("select * from reservation order by AGE desc ");
        }

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYEE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_PAYMENT"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("FIRST_NAME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("NAME"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESS"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("PHONE_NUMBER"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));

    return model;
}

bool employee::modify_employee(){
    QSqlQuery query;
   query.prepare( "UPDATE employee SET ID_EMPLOYEE=:ID_EMPLOYEE , ID_PAYMENT=:ID_PAYMENT , FIRST_NAME=:FIRST_NAME , NAME=:NAME , AGE=:AGE ,"
                  " EMAIL=:EMAIL , ADRESS=:ADRESS,PHONE_NUMBER=:PHONE_NUMBER,ROLE=:ROLE WHERE ID_EMPLOYEE=:ID_EMPLOYEE ");
   query.bindValue(":ID_EMPLOYEE",id_employee);
   query.bindValue(":ID_PAYMENT",id_employee);
   query.bindValue(":FIRST_NAME",first_name);
   query.bindValue(":NAME",name);
    query.bindValue(":AGE",age);
   query.bindValue(":EMAIL",email);
   query.bindValue(":ADRESS",adress);
    query.bindValue(":PHONE_NUMBER",phone_number);
   query.bindValue(":ROLE",role);

return query.exec();
}

QSqlQueryModel* employee::search_employee(QString id,QString variable)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="ID_EMPLOYEE")
     {
     model->setQuery("SELECT * FROM employee WHERE  (ID_EMPLOYEE like '"+id+"%""')  ");
     }
    if(variable=="ID_PAYMENT")
    {
    model->setQuery("SELECT * FROM employee WHERE  (ID_PAYMENT like '"+id+"%""')  ");
    }
    if(variable=="FIRST_NAME")
     {
     model->setQuery("SELECT * FROM employee WHERE  (FIRST_NAME like '"+id+"%""')  ");
     }
    if(variable=="NAME")
     {
     model->setQuery("SELECT * FROM employee WHERE  (NAME like '"+id+"%""')  ");
     }
    if(variable=="AGE")
     {
     model->setQuery("SELECT * FROM employee WHERE  (AGE like '"+id+"%""')  ");
     }
    if(variable=="EMAIL")
     {
     model->setQuery("SELECT * FROM employee WHERE  (EMAIL like '"+id+"%""')  ");
     }
    if(variable=="ADRESS")
     {
     model->setQuery("SELECT * FROM employee WHERE  (ADRESS like '"+id+"%""')  ");
     }
    if(variable=="PHONE_NUMBER")
     {
     model->setQuery("SELECT * FROM employee WHERE  (PHONE_NUMBER like '"+id+"%""')  ");
     }
    if(variable=="ROLE")
     {
     model->setQuery("SELECT * FROM employee WHERE  (ROLE like '"+id+"%""')  ");
     }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYEE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_PAYMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("FIRST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESS"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("PHONE_NUMBER"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ROLE"));
    query.exec();
        return  model;
}

bool employee::delete_employee(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from employee where ID_EMPLOYEE=:ID_EMPLOYEE");
         query.bindValue(0, id);

        return query.exec();
}
