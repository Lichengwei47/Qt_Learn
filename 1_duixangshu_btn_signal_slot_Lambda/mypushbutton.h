#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QWidget>

class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mypushbutton(QPushButton *parent = nullptr);
    ~mypushbutton();
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
