#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class myPushButton : public QPushButton
{
    Q_OBJECT
public:
   // explicit myPushButton(QWidget *parent = nullptr);
    //重写myPushButton构造函数
    myPushButton(QString normlImage,QString pressImage="");
    //构造函数参数一 正常显示图片，参数二按下显示的图片
    QString normImgPath;
    QString preeImgPath;
    //弹跳特效
    void zoom1();//向下跳
    void zoom2();//向上跳
    //重写鼠标按下事件和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
