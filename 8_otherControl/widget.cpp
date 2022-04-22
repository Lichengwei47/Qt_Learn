#include "widget.h"
#include "ui_widget.h"
#include<QMovie>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//设置默认页
    //栈控件使用
    connect(ui->page1,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->page2,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //下拉框
    ui->comboBox->addItems(QStringList()<<"奔驰"<<"宝马"<<"特斯拉");
    connect(ui->tesila,&QPushButton::clicked,this,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("特斯拉");
    });
    //QLabel显示图片
    ui->label_image->setPixmap(QPixmap(":/test.png"));
    QMovie *qm = new QMovie(":/dongtu.jfif");
    ui->labelmovie->setMovie(qm);
    ui->labelmovie->setScaledContents(true);//设置自适应大小
    //开始播放
    qm->start();
}

Widget::~Widget()
{
    delete ui;
}
