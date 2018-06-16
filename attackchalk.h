#ifndef ATTACKCHALK_H
#define ATTACKCHALK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class AttackChalk : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    AttackChalk(int mode);
    static const int chalksize = 50;

public slots:
    void fly();

signals:
    void attack();
    void deletechalk();

private:

};

#endif // ATTACKCHALK_H
