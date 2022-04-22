#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include"chooselevelscene.h"
#include<QTimer>
#include<QSound>//多媒体模块，在.pro中设置QT       += core gui multimedia
#include<QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置场景
    //设置固定大小
    setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻转金币主场景");
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,this,this->close);
    //paintEvent函数设置背景图片

    qDebug()<<"ok!";
    //准备开始按钮的音效
    QSound * startQSound=new QSound(":/res/TapButtonSound.wav",this);

    //循环开始的音效
    /*startQSound->setLoops(10);//-1表示无限循环
    startQSound->play();*/
    //开始按钮
    myPushButton * startButton =new myPushButton(QString(":/res/MenuSceneStartButton.png"));
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5,this->height()*0.7);
    //实例化选择关卡的场景
    chooseScene =new ChooseLevelScene();
    //监听选择关卡的返回按钮信号
    connect(chooseScene,&ChooseLevelScene::chooseSenceBack,this,[=](){
        QTimer::singleShot(250,this,[=](){
            this->setGeometry(chooseScene->geometry());
            chooseScene->close();
            this->show();
        });//重写singleShot函数

    });
    connect(startButton,&myPushButton::clicked,this,[=](){
        qDebug()<<"点击开始按钮";

        //播放开始的音效资源
        startQSound->play();

        //做弹起特效
        startButton->zoom1();
        startButton->zoom2();
        //延时0.25秒进入选择关卡的场景
        QTimer::singleShot(250,this,[=](){
            //设置chooseSence场景的位置
            chooseScene->setGeometry(this->geometry());//自身隐藏
            this->close();
            //显示选择关卡的场景
            chooseScene->show();
        });//重写singleShot函数

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//创建画家，指定绘画设备
    //创建QPixmap对象
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    QFile file(":/res/PlayLevelSceneBg.png");
    file.open(QIODevice::WriteOnly);
    pix.save(&file, "PNG");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    QFile file1(":/res/Title.png");
        file1.open(QIODevice::WriteOnly);
        pix.save(&file1, "PNG");
    //缩放图片
    pix =pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
