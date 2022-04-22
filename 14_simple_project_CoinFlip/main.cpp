#include "mainwindow.h"
#include <QApplication>
#include"dataconfig.h"
#include<QDebug>
#include<QImage>
#include<QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QString path=QString("D:/Qt/lcw/14_simple_project_CoinFlip/res");
//    QDir dir(path);
//    if(!dir.exists())
//    {
//        return 0;
//    }

//    QStringList filters;
//    filters << QString("*.png");
//    dir.setFilter(QDir::Files | QDir::NoSymLinks); //设置类型过滤器，只为文件格式
//    dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式（后缀为.jpeg等图片格式）

//    int dir_count = dir.count();
//    if(dir_count <= 0)
//    {
//        return 0 ;
//    }

//    QStringList string_list;
//    //获取分隔符
//    //QChar separator = QDir::separator();
//    QChar separator = QChar('/');
//    if(!path.contains(separator))
//    {
//        separator = QChar('\\');
//    }
//    QChar last_char = path.at(path.length()-1);
//    if(last_char == separator)
//    {
//        separator = QChar();
//    }

//    foreach(QFileInfo mfi ,dir.entryInfoList())
//    {
//        if(mfi.isFile())
//        {
//            QString file_path = path + separator +  mfi.fileName();
//            string_list.append(file_path);
//        }
//    }

//    for (int i=0; i< string_list.size(); ++i)
//    {
//        QImage im;
//        im.load(string_list.at(i));
//        im.save(string_list.at(i));
//        qDebug() << string_list.at(i);
//    }


    //测试关卡数据
    //    dataConfig config;
    //    for(int i=0;i<4;i++)
    //    {
    //        for(int j=0;j<4;j++)
    //        {
    //            qDebug()<<config.mData[1][i][j];
    //        }
    //        qDebug()<<"";
    //    }

    a.exec();
    return 0;
}
