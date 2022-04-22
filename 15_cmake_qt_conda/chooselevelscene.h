#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playsence.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    //游戏场景对象指针
    PlaySence * play=NULL;
    PlaySence * playsence;
signals:
    //写一个自定义信号，告诉主场景，点击返回
    void chooseSenceBack();
public slots:
};

#endif // CHOOSELEVELSCENE_H
