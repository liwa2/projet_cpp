#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QChartView>
#include<QtCharts>
#include<QChart>
#include <QPainter>
#include <QCalendarWidget>
#include <iostream>



namespace Ui {
class client_interface;
}

class client_interface : public QDialog
{
    Q_OBJECT

public:
    explicit client_interface(QWidget *parent = nullptr);
    ~client_interface();



private slots:
    void on_pushButton_clicked();

private:
Ui::client_interface *ui;
};

#endif // CLIENT_INTERFACE_H
