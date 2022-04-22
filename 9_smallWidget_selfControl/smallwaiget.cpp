#include "smallwaiget.h"
#include "ui_smallwaiget.h"

smallWaiget::smallWaiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWaiget)
{
    ui->setupUi(this);
    //QSpinBox移动,QSlider跟着移动
    void(QSpinBox:: *boxsignal)(int)=QSpinBox::valueChanged;//函数指针定义信号重载
    //connect(ui->spinBox,boxsignal,ui->horizontalSlider,&QSlider::setValue);//QSlider::setValue没有重载,QSpinBox::valueChanged有重载
    //connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
    connect(ui->spinBox,boxsignal,this,[=](int value){ui->horizontalSlider->setValue(value);});
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,[this](int value){ui->spinBox->setValue(value);});

}

smallWaiget::~smallWaiget()
{
    delete ui;
}
int smallWaiget::get_num()
{
    return ui->spinBox->value();
}
void smallWaiget::set_num(int num )
{
    ui->spinBox->setValue(num);
}
