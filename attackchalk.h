#ifndef ATTACKCHALK_H
#define ATTACKCHALK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class AttackChalk : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    AttackChalk();
    static const int chalksize = 50;

public slots:
    void fly();

signals:
    void attack();
    void deletechalk();
};

#endif // ATTACKCHALK_H
