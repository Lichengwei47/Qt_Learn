#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置按钮默认选择男
    ui->radioMan->setChecked(true);
    //设置选中女打印输出
    connect(ui->radioWoman,&QRadioButton::clicked,this,[=](){
        qDebug()<<"选中女";
    });
    connect(ui->service,&QCheckBox::stateChanged,this,[](int state){//stateChanged信号中有一个int参数，所有槽中可以接受int参数
        qDebug()<<state;//2是选中，0是未选中，在ui中选中CheckBox tristate表示开启1状态，默认只要0和2状态
    });
    //往ListWidget中添加文字
    QListWidgetItem * itm = new QListWidgetItem("中午好");
    //添加到ListWidget控件中
    ui->listWidget->addItem(itm);
    itm->setTextAlignment(Qt::AlignCenter);//设置文字垂直居中

    QStringList qlist;//链表，在堆中
    qlist<<"早上好"<<"小李！"<<"好久不见！";
    ui->listWidget->addItems(qlist);//无法设置对齐方式
}

Widget::~Widget()
{
    delete ui;
}
