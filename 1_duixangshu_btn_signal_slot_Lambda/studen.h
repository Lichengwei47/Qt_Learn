#ifndef STUDEN_H
#define STUDEN_H

#include <QObject>

class Studen : public QObject
{
    Q_OBJECT
public:
    explicit Studen(QObject *parent = nullptr);

signals:

public slots:
    void Student_eat();
    void Student_eat(QString foodname);
};

#endif // STUDEN_H
