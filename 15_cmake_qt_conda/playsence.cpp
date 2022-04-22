#include "playsence.h"
#include<QDebug>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include"mypushbutton.h"
#include<QLabel>
#include"mycoin.h"
#include"dataconfig.h"
#include<QLabel>
#include<QPropertyAnimation>//动画事件
#include<QSound>
/*PlaySence::PlaySence(QWidget *parent) : QMainWindow(parent)
{

}*/
PlaySence:: PlaySence(int levelNum){
    QString str=QString("进入第%1关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex=levelNum;
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle(QString("翻金币场景"));
    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    QAction * quiteAction = startMenu->addAction("退出");
  
    //connect(quiteAction,&QAction::triggered, &QWidget::close);
    connect(quiteAction, SIGNAL(triggered()), SLOT(close()));

    //添加音效
    QSound *backSound=new QSound(":/res/BackButtonSound.wav",this);//返回按钮音效
    QSound *flipSound=new QSound(":/res/ConFlipSound.wav",this);//翻转金币音效
    QSound *winSound=new QSound(":/res/LevelWinSound.wav",this);//胜利音效

    //返回按钮
    myPushButton * backbtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    connect(backbtn,&myPushButton::clicked,this,[=](){
        backSound->play();//返回按钮音效
        QTimer::singleShot(300,this,[=](){
            this->PlayeSenceBack();
        });

    });

    //显示关卡数
    QLabel *qlabel = new QLabel();
    qlabel->setParent(this);
    QString qs = QString("Level:%1").arg(this->levelIndex);
    qlabel->setText(qs);
    qlabel->setGeometry(30,this->height()-50,120,50);
    QFont qfont;
    qfont.setFamily("华文新魏");
    qfont.setPointSize(20);
    qlabel->setFont(qfont);


    //初始化每个关卡的二维数据
    dataConfig dataconfig;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->ImageArray[i][j]=dataconfig.mData[this->levelIndex][i][j];

    //胜利图片的显示
    QLabel* winLabel=new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());//位置-是在窗口上面
    //显示金币背景图案
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){
            //绘制背景图片
            QLabel * label= new QLabel();
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建金币
            myCoin *coin;
            if(this->ImageArray[i][j]==1)
            {
                coin=new myCoin(":/res/Coin0001.png");
                coin->setParent(this);
                coin->move(59+i*50,204+j*50);
            }
            else
            {
                coin=new myCoin(":/res/Coin0008.png");
                coin->setParent(this);
                coin->move(59+i*50,204+j*50);
            }
            coin->posX=i;
            coin->posY=j;
            coin->flag=ImageArray[i][j];

            //给把金币放到 金币的二维数组 以便后期维护
            coinbtn[i][j]=coin;
            //点击金币，实现翻转
            connect(coin,&myCoin::clicked,[=](){
                //播放金币翻转音效
                flipSound->play();
                //解决Bug，点击瞬间，将所有按钮禁用

                for(int i=0;i<4;i++)
                    for(int j=0;j<4;j++)
                    {
                        coinbtn[i][j]->isWin=true;
                    }

                coin->changeFlag();
                this->ImageArray[i][j]=this->ImageArray[i][j]==0?1:0;
                QTimer::singleShot(300,this,[=](){//翻转周围金币时设置300毫秒延迟
                    //翻转周围硬币
                    if(coin->posX+1<=3)//翻转右侧的硬币
                    {
                        coinbtn[coin->posX+1][coin->posY]->changeFlag();
                        this->ImageArray[coin->posX+1][coin->posY]=this->ImageArray[coin->posX+1][coin->posY]==0?1:0;
                    }
                    if(coin->posX-1>=0)//翻转左侧的金币
                    {
                        coinbtn[coin->posX-1][coin->posY]->changeFlag();
                        this->ImageArray[coin->posX-1][coin->posY]=this->ImageArray[coin->posX-1][coin->posY]==0?1:0;
                    }
                    if(coin->posY+1<=3)//翻转下侧的金币
                    {
                        coinbtn[coin->posX][coin->posY+1]->changeFlag();
                        this->ImageArray[coin->posX][coin->posY+1]=this->ImageArray[coin->posX][coin->posY+1]==0?1:0;
                    }
                    if(coin->posY-1>=0)
                    {
                        coinbtn[coin->posX][coin->posY-1]->changeFlag();
                        this->ImageArray[coin->posX][coin->posY-1]=this->ImageArray[coin->posX][coin->posY-1]==0?1:0;
                    }


                    //周围按钮翻完了，将为了解决Bug而将isWin设置为的true还原为false
                    for(int i=0;i<4;i++)
                        for(int j=0;j<4;j++)
                        {
                            coinbtn[i][j]->isWin=false;
                        }


                    //判断是否胜利
                    this->isWin=true;
                    for(int i=0;i<4;i++)
                        for(int j=0;j<4;j++)
                        {
                            if(coinbtn[i][j]->flag==false)
                            {
                                this->isWin=false;
                                break;
                            }
                        }
                    if(this->isWin==true)
                    {
                        //添加胜利音效
                        winSound->play();
                        qDebug()<<"胜利了";
                        for(int i=0;i<4;i++)
                            for(int j=0;j<4;j++)
                            {
                                coinbtn[i][j]->isWin=true;//将所有按钮设置为true，如果再次点击按钮，直接return，不做翻转响应
                            }
                        //将胜利图标砸下
                        QPropertyAnimation * animation=new QPropertyAnimation(winLabel,"geometry");
                        //设置实践间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        //设置动画曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();//开始
                    }
                });

            });
        }
    }


}
void PlaySence::paintEvent(QPaintEvent *){
    //创建背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix =pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
