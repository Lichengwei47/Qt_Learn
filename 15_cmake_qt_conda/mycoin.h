#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include<QPushButton>
#include<QTimer>
class myCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit myCoin(QWidget *parent = nullptr);
    explicit myCoin(QString btnImg);

    //金币的属性
    int posX;//X坐标位置
    int posY;//Y坐标位置
    bool flag;//金币正反面标识

    //改变标识方法
    void changeFlag();
    QTimer *timer1;//正面翻反正的定时器
    QTimer *timer2;//反面翻正面的定时器
    int min =1;
    int max =8;

    //执行动画的标志
    bool isAnimation=false;

    //重写按下，释放事件
    void mousePressEvent(QMouseEvent *e);

    bool isWin=false;//是否胜利标识
signals:

public slots:
};

#endif // MYCOIN_H
