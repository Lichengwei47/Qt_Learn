#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include<QPushButton>
#include"studen.h"
#include"teacher.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
    1、信号槽重载：用到函数指针
    2、信号可连接信号
    3、一个信号可以连接多个槽函数
    4、多个信号可以连接同一个函数
    5、信号和槽函数的参数必须一一对应
    6、信号参数的个数可以多余槽函数的参数，举例：
    void(Teacher::* teacherSigna)(QString,int)=&Teacher::hungry;
    void(Studen::* studentSignal)(QString)=&Studen::Student_eat;这样也可以
    */
    ui->setupUi(this);
    mypushbutton * mybtn = new mypushbutton();
    mybtn->setText("关闭窗口");
    mybtn->move(360,20);
    mybtn->setFixedSize(150,30);
    mybtn->setParent(this);
    resize(800,600);
    setWindowTitle("下课案例");
    connect(mybtn,&mypushbutton::clicked,this,&MainWindow::close);
    student = new Studen();
    teacher = new Teacher();
    void(Teacher::* teacherSignal0)(void)=&Teacher::hungry;
    void(Teacher::* teacherSignal)(QString)=&Teacher::hungry;
    void(Studen::* studentSignal0)(void)=&Studen::Student_eat;
    void(Studen::* studentSignal)(QString)=&Studen::Student_eat;// 类型 （*指针变量名）（参数列表）；指向函数的指针
    //connect(teacher, &Teacher::hungry,student,&Studen::Student_eat);//无重载
    connect(teacher,SIGNAL(hungry()),student,SLOT(Student_eat()));//利用Qt4版本的信号槽，连接.缺点：类型不做检测
    //connect(teacher,teacherSignal0,student,studentSignal0);//这里使用studentSignal槽不可以
    connect(teacher,teacherSignal,student,studentSignal);//这里使用studentSignal0槽可以
    //connect(teacher,static_cast<void(Teacher::*)(const QString&)>(&Teacher::hungry),student,static_cast<void(Studen::*)(const QString&)>(&Studen::Student_eat));
    QPushButton * btn_class_over = new QPushButton("下课_信号连接槽",this);
    btn_class_over->move(360,200);;
    btn_class_over->setParent(this);
    btn_class_over->setFixedSize(150,30);
    connect(btn_class_over,&QPushButton::clicked,this,MainWindow::clss_over);//信号连接槽
    QPushButton * btn_class_over1 = new QPushButton("下课_连接另一信号",this);
    btn_class_over1->setFixedSize(150,30);
    btn_class_over1->move(360,300);;
    btn_class_over1->setParent(this);
    connect(btn_class_over1,&QPushButton::clicked,teacher,teacherSignal0);//信号连接信号,clicked一个bool参数，所有不能连接teacherSignal(带QString参数)
    //disconnect(btn_class_over1,&QPushButton::clicked,teacher,teacherSignal0);//断开信号
    //clss_over();//利用函数开启信号

    //Lambda表达式
    QPushButton * btn_L = new QPushButton("Lambda按钮",this);
    btn_L->setFixedSize(150,30);
    btn_L->move(360,400);;
    btn_L->setParent(this);
    int m =10;
    connect(btn_L,QPushButton::pressed,this,[m]()mutable{qDebug()<<"Lambda表达式中m="<<(m+100);});//mutable可修值传递进来的拷贝，修改的是拷贝，不是本体
    connect(btn_L,QPushButton::released,this,[=]()mutable{qDebug()<<"释放按钮时m="<<m;});
    int res;
    res =[]()->int{return 1000;}();//Lambda返回函数值
    qDebug()<<"res="<<res;
    connect(btn_L,QPushButton::clicked,this,[=](){this->close();teacher->hungry("宫保鸡丁");});//点击时连接槽函数

}
void MainWindow::clss_over()
{
    qDebug()<<"下课啦！";
    teacher->hungry("排骨");
}

MainWindow::~MainWindow()
{
    delete ui;
}
