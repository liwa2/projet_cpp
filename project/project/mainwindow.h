#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dialog.h>
#include <QMainWindow>
#include <QMessagebox>
#include"notif_space.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString cuser,cpass;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_username_line_textChanged(const QString &arg1);

    void on_username_line_editingFinished();

    void on_username_signup_line_textChanged(const QString &arg1);

    void on_username_signup_line_editingFinished();

    void on_password_line_textChanged(const QString &arg1);

    void on_password_line_editingFinished();

    void on_password_signup_line_textChanged(const QString &arg1);

    void on_password_signup_line_editingFinished();






    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
