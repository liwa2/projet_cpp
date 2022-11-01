#ifndef PROFIL_H
#define PROFIL_H
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlDatabase>

class profil
{
private:
    QString user,pass;
    int id;
public:
    profil();
    profil(QString,QString);


    QString getuser();
    QString getpass();

    void setuser(QString);
    void setpass(QString);

    bool ajouterP();
    bool login(QString,QString);
    QSqlQueryModel* recherche(QString,QString);//unsued


};

#endif // PROFIL_H
