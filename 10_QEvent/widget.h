#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void timerEvent(QTimerEvent *ev);
    ~Widget();
    bool eventFilter(QObject *obj,QEvent *e);
private:
    Ui::Widget *ui;
    int id1;
    int id2;
};

#endif // WIDGET_H
