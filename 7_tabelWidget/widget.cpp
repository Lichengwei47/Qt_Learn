#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TabelWidget使用
    //设置列树
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
    ui->tableWidget->setItem(0 ,0,new QTableWidgetItem("盖伦"));
    QStringList nameList;
    nameList<<"盖伦"<<"流浪"<<"金克斯"<<"提莫"<<"蛮王";
    QList<QString> sexlist;
    sexlist<<"男"<<"男"<<"女"<<"女"<<"男";
    for(int i =0;i<5;i++)
    {
        int cols=0;
        ui->tableWidget->setItem(i,cols++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,cols++,new QTableWidgetItem(sexlist.at(i)));
        ui->tableWidget->setItem(i,cols++,new QTableWidgetItem(QString::number(18+i)));
    }

}

Widget::~Widget()
{
    delete ui;
}
