#ifndef CLIENT_PROFIL_H
#define CLIENT_PROFIL_H
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlDatabase>

class client_profil
{
private:
    QString cuser,cpass;


public:
    client_profil();
    client_profil(QString cuser,QString cpass){
     this->cuser=cuser;
     this->cpass=cpass;}



    bool add_client_profil();






    QString getcuser();
    QString getcpass();
    void setcuser(QString);
    void setcpass(QString);
    bool ajoutercP();
    bool loginc(QString,QString);
};

#endif // CLIENT_PROFIL_H
