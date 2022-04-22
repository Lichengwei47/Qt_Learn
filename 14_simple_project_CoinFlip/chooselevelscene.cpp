#include "chooselevelscene.h"
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QLabel>
#include"playsence.h"
#include<QSound>
#include<QTimer>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置关卡场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡的场景");
    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    QAction * quiteAction = startMenu->addAction("退出");
    //点击退出，实现退出游戏
    connect(quiteAction,&QAction::triggered,[=](){
        this->close();
    });

    //创建选择关卡的音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    QSound *backSound=new QSound(":/res/BackButtonSound.wav",this);//返回按钮音效
    //返回按钮
    myPushButton * backbtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    connect(backbtn,&myPushButton::clicked,this,[=](){
        backSound->play();
        QTimer::singleShot(300,this,[=](){
            this->chooseSenceBack();
        });

    });
    //创建选择关卡的按钮
    for(int i=0;i<20;i++){
        myPushButton * menuBtn = new myPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+(i%4) *70,130+(i/4) *70);
        connect(menuBtn,&myPushButton::clicked,this,[=](){
             qDebug()<<"您选择的是第"<<i+1<<"关";

             //添加音效果
             chooseSound->play();

             //进入游戏场景
             this->hide();//将选关卡场景关闭
             play = new PlaySence(i+1);//创建游戏场景
             play->setGeometry(this->geometry());//设置游戏场景的初始位置
             play->show();//显示游戏场景
             connect(play,&PlaySence::PlayeSenceBack,this,[=](){
                 this->setGeometry(play->geometry());
                 qDebug()<<"从游戏界面退出，返回选择关卡界面";
                 this->show();
                 play->close();
                 delete play;
                 play = NULL;
             });

        });
        QLabel *label = new QLabel();
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+(i%4) *70,130+(i/4) *70);

        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标穿透，不点击到QLabel
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    //painter.drawPixmap(this->width()-pix.width()*0.5,30,pix.width(),pix.height(),pix);//好像写错了
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);

}
