#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>
#include <mycoin.h>
class PlaySence : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlaySence(QWidget *parent = nullptr);
    explicit PlaySence(int levelNum);
    int levelIndex;//内部成员属性，记录所选关卡
    //重写绘图事件
    void paintEvent(QPaintEvent *);

    int ImageArray[4][4];//二维数组，维护每个关卡的数据

    myCoin *coinbtn[4][4];

    //判断是否胜利的标识
     bool isWin;
signals:
    //写一个自定义信号，返回选择关卡按钮
    void PlayeSenceBack();
public slots:
};

#endif // PLAYSENCE_H
