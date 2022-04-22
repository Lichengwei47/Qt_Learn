#ifndef SMALLWAIGET_H
#define SMALLWAIGET_H

#include <QWidget>

namespace Ui {
class smallWaiget;
}

class smallWaiget : public QWidget
{
    Q_OBJECT

public:
    explicit smallWaiget(QWidget *parent = 0);
    ~smallWaiget();
    int get_num();
    void set_num(int num );

private:
    Ui::smallWaiget *ui;
};

#endif // SMALLWAIGET_H
