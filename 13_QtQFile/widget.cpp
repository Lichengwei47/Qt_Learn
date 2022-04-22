#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QTextCodec>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击按钮选择文件对话框
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString qs=QFileDialog::getOpenFileName(this,"打开文件");
        ui->lineEdit->setText(qs);//文件路径和名字放到lineEdit
        QFile file(qs);//读取文件,QFile默认支持utf-8的格式
        file.open(QIODevice::ReadOnly);
        /*QByteArray array=file.readAll();
         ui->textEdit->setText(array);*/
        //编码格式类
        //QTextCodec *codec = QTextCodec::codecForName("gbk");
        //ui->textEdit->setText(codec->toUnicode(array));

        QByteArray array;
        while(!file.atEnd())//判断是否读完
        {
            array+=file.readLine();//按照行读

        }
        ui->textEdit->setText(array);
        file.close();
        //进行写文件
        file.open(QIODevice::Append);
        file.write("添加新内容");

        ////QFileInfo文件信息类
         QFileInfo qinfo(qs);
        qDebug()<<"大小："<<qinfo.size()<<"后缀名"<<qinfo.suffix()<<"文件名称"<<qinfo.fileName()<<"文件路径"<<qinfo.filePath();
        qDebug()<<"创建日期"<<qinfo.created().toString("yyyy/MM//dd hh::mm::ss");
        qDebug()<<"最后修改日期"<<qinfo.lastModified().toString("yyy-MM-dd hh::mm::ss");
    });
}

Widget::~Widget()
{
    delete ui;
}
