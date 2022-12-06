#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "profil.h"
#include "client_profil.h"
#include "client_interface.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    QString user=ui->username_line->text();
    QString password=ui->password_line->text();
    QString cuser=ui->username_line->text();
    QString cpassword =ui->password_line->text();

    QSqlQuery query;
     profil P1;
     client_profil P2;
     bool login,loginc;
     login=P1.login(user,password);
     loginc=P2.loginc(cuser,cpassword);


    if(login)
    {
      hide();
      Dialog secwindow;
      secwindow.setModal(true);
      secwindow.exec();
    }else if(loginc){

    hide();
    client_interface s2;
    s2.setModal(true);
    s2.exec();


    }
    else
    QMessageBox::information(this,"Login","the user or the password is not correct ! ");
}


void MainWindow::on_pushButton_2_clicked()
{
ui->loginWidgets->setCurrentIndex(1);

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->loginWidgets->setCurrentIndex(0);
    QString user=ui->username_signup_line->text();
    QString password=ui->password_signup_line->text();

    profil P(user,password);
    bool test=P.ajouterP();

    QMessageBox msgBox;

    if(test)
          {
            QMessageBox::information(this,"sign up","done !");

        }
        else

        QMessageBox::information(this,"sign up","failed!");




}


//------------------------------------------------------------------------login---stylesheet-------input-----------------------------------------------------------------

void MainWindow::on_username_line_textChanged(const QString &arg1)
{
    ui->username_line->setStyleSheet("border-bottom: 1.5px solid white ;color:white;font-weight:600;border-radius:0px; ");
}


void MainWindow::on_username_line_editingFinished()
{
    ui->username_line->setStyleSheet("border-bottom: 1px solid white ;color:white; ");

}


void MainWindow::on_username_signup_line_textChanged(const QString &arg1)
{
    ui->username_signup_line->setStyleSheet("border-bottom: 1.5px solid white ;color:white;font-weight:600;border-radius:0px; ");

}


void MainWindow::on_username_signup_line_editingFinished()
{
    ui->username_signup_line->setStyleSheet("border-bottom: 1px solid white ;color:white;border-radius:0px; ");

}




void MainWindow::on_password_line_textChanged(const QString &arg1)
{
    ui->password_line->setStyleSheet("border-bottom: 1.5px solid white ;color:white;font-weight:600; border-radius:0px;");

}


void MainWindow::on_password_line_editingFinished()
{
    ui->password_line->setStyleSheet("border-bottom: 1px solid white ;color:white; ");

}


void MainWindow::on_password_signup_line_textChanged(const QString &arg1)
{
    ui->password_signup_line->setStyleSheet("border-bottom: 1.5px solid white ;color:white;font-weight:600;border-radius:0px; ");

}


void MainWindow::on_password_signup_line_editingFinished()
{
    ui->password_signup_line->setStyleSheet("border-bottom: 1px solid white ;color:white; ");

}






void MainWindow::on_pushButton_4_clicked()
{
    ui->loginWidgets->setCurrentIndex(0);
}
