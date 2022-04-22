#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TreeWdiget树控件的使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");
    QTreeWidgetItem * qtwiget = new QTreeWidgetItem(QStringList()<<"名称");
    QTreeWidgetItem * qtwiget2 = new QTreeWidgetItem(QStringList()<<"属性");
    QTreeWidgetItem * qtwiget3 = new QTreeWidgetItem(QStringList()<<"技能");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(qtwiget);
    ui->treeWidget->addTopLevelItem(qtwiget2);
    ui->treeWidget->addTopLevelItem(qtwiget3);
    //追加子节点
    QStringList yx1;
    yx1<<"瑞兹(Ryze)"<<"流浪法师";
    QTreeWidgetItem* qtwidget4 = new QTreeWidgetItem(yx1);
    qtwiget->addChild(qtwidget4);
    QStringList yx2;
    yx2<<"生命值"<<"360"<<"魔法值"<<"250";
    QTreeWidgetItem* qtwidget5 = new QTreeWidgetItem(yx2);
    qtwiget2->addChild(qtwidget5);
    QStringList yx3;
    yx3<<"技能Q"<<"超负荷";
    QTreeWidgetItem* qtwidget6 = new QTreeWidgetItem(yx3);
    qtwiget3->addChild(qtwidget6);

}

Widget::~Widget()
{
    delete ui;
}
