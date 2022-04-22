#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        ui->widget->set_num(5);
        ui->widget_2->set_num(10);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        qDebug()<<"widget1的值是:"<<ui->widget->get_num();//widget类似于：smallwaiget *widget=new smallwaiget();
        qDebug()<<"widget2的值是:"<<ui->widget_2->get_num();
    });
}

Widget::~Widget()
{
    delete ui;
}
