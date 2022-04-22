#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QPicture>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QPixmap绘图设备，为不同平台做了显示优化
    /*QPixmap pix(300,300);//pix绘图设备
    //声明画家
    pix.fill(Qt::white);
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawRect(QRect(100,100,150,150));
    //保存
    pix.save("E:\\testQPainter.jpg");*/



    //QImage绘图设备，可以对像素进行访问
    /*QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::blue);
    QPainter painter(&img);
    painter.setPen(QPen(Qt::green));
    painter.drawRect(QRect(100,100,150,150));
    img.save("E:\\testQImage.jpg");*/

    //QPicture绘图设备，可以记录和重新绘图指令
    /*QPicture pic;
    QPainter painter;

    painter.begin(&pic);
    painter.setPen(QPen(Qt::cyan));
    painter.drawRect(QRect(100,100,150,150));
    painter.end();//结束绘画
    pic.save("E:\\pic.zt");*/
}

Widget::~Widget()
{

    delete ui;
}
//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    /*
    //利用QImage对像素进行修改
    QPainter painter(this);
    QImage img;
    img.load(":/open.png");

    //修改像素点
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        {
            QRgb value =qRgb(255,0,0);
            img.setPixel(i,j,value);
        }
    painter.drawImage(0,0,img);
    */
    //重现绘图指令
    QPicture pic;
    QPainter painter(this);
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);
}
