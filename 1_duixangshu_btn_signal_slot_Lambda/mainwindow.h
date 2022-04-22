#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"studen.h"
#include"teacher.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void clss_over();

private:
    Ui::MainWindow *ui;
    Studen * student;
    Teacher * teacher;
};

#endif // MAINWINDOW_H
