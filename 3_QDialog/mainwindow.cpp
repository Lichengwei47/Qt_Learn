#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actiondakai,QAction::triggered,[=](){//控件触发
        //模态对话框,不可以对其他窗口进行操作
       /* QDialog * qd =new QDialog(this);//可能造成内存泄漏
        qd->resize(400,300);
        qd->exec();
        qDebug()<<"模态对话框弹出了";*/
        //QDialog * qd2 = new QDialog(this);
        //非模态对话框，不会一闪而过
        /*qd2->setWindowTitle("这是弹窗");
        qd2->resize(400,300);
        qd2->show();
        qd2->setAttribute(Qt::WA_DeleteOnClose);
        qDebug()<<"模态对话框弹出了";*/
        //消息对话框
        //QMessageBox::critical(this,"窗口标题","错误对话框");
        //QMessageBox::information(this,"窗口标题","消息对话框");

        //参数1:父类 参数2 =：标题 参数3：文字 参数4：按键类型 参数5：关联回车的按键
        /*if(QMessageBox::Close== QMessageBox::question(this,"窗口标题","请进行选择",QMessageBox::Apply|QMessageBox::Close,QMessageBox::Apply))
        {
            qDebug()<<"这是退出选择";
        }
        else
        {
            qDebug()<<"这是应用选择";
        }*/
        //QColor qlor = QColorDialog::getColor(QColor(255,0,0,255));
        //qDebug()<<"r="<<qlor.red()<<"g="<<qlor.green()<<"b="<<qlor.blue()<<"透明度="<<qlor.alpha();
        /*QString res = QFileDialog::getOpenFileName(this,"选择文件","D:\\","(*.txt)");
        qDebug()<<"文件名字为:"<<res;*/
        bool * flag;
        QFont qft = QFontDialog::getFont(flag,QFont("华文彩云",24),this);
        qDebug()<<"字体:"<<qft.family()<<"是否加粗:"<<qft.bold()<<"是否倾斜:"<<qft.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
