#ifndef ATTACKCHALK_H
#define ATTACKCHALK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class AttackChalk : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    AttackChalk();

public slots:
    void fly();

};

#endif // ATTACKCHALK_H
