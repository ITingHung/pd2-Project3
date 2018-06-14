#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Boss : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Boss();
    int getElement(int index);
    void setElement(int index,int value);
    static const int bosssize = 120;

public slots:
    void move();

private:
    bool dir;
//    int bossPo[4];

};

#endif // BOSS_H
