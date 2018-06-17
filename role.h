#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Role : public QObject, public QGraphicsPixmapItem
{
public:
    Role();
    int rolehp;
    QTimer *timer;
    static const int rolesize = 120;
    virtual void move() = 0;
    virtual void setElement(int value)=0;

private:

};

#endif // ROLE_H
