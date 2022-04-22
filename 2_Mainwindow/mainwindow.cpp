#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    QMenuBar* menub=new QMenuBar();//创建菜单栏，只能有一个
    setMenuBar(menub);
    //创建菜单,最多一个
    QMenu *filename = menub->addMenu("文件");
    QMenu *editname = menub->addMenu("编辑");
    //创建菜单项
    QAction * newaction= filename->addAction(QIcon(":/open.png"),"新建");
    filename->addSeparator();
    QAction * openaction=filename->addAction("打开");
    //工具栏,可以多个
    QToolBar *toolbar=new QToolBar();
    addToolBar(Qt::LeftToolBarArea,toolbar);
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//设置停靠区域
    toolbar->setFloatable(true);//设置浮动
    toolbar->setMovable(true);//设置是否可移动
    toolbar->addAction(QIcon(":/test.png"),"新建");
    //toolbar->addAction(newaction);
    toolbar->addSeparator();
    toolbar->addAction(QIcon(":/test2.png"),"新建");
    //toolbar->addAction(openaction);
    QPushButton * btn = new QPushButton("按钮",this);
    toolbar->addWidget(btn);//添加控件
    //设置底下状态栏，最多一个
    QStatusBar * stabar=statusBar();//不用new
    setStatusBar(stabar);
    //存放标签控件
    QLabel * qlab = new QLabel("提示标签",this);
    stabar->addWidget(qlab);
    QLabel * qlab2 = new QLabel("右侧标签",this);
    stabar->addPermanentWidget(qlab2);
    //铆接部件，可以有多个
    QDockWidget * dockWidget =new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置只允许上下浮动
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);
    //在窗口中央设置文本框
    QTextEdit * txte = new QTextEdit(this);
    setCentralWidget(txte);//设置核心部件，只能一个


}

MainWindow::~MainWindow()
{

}
