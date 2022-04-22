#ifndef MYLABEL_H
#define MYLABEL_H

//#include <QWidget>
#include<QLabel>
class mylabel : public QLabel //要改为QLabel,继承自QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);//继承自QLabel，但是父亲是QWidget
    void enterEvent(QEvent *event);//鼠标进入事件
    void leaveEvent(QEvent *);//鼠标离开事件

    virtual void mouseMoveEvent(QMouseEvent *ev);

    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    bool event(QEvent *e);//事件分发器，拦截。帮助文档[virtual protected] bool QWidget::event(QEvent *event)


signals:

public slots:
};

#endif // MYLABEL_H
