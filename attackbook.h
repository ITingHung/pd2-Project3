#ifndef ATTACKBOOK_H
#define ATTACKBOOK_H

#include <QObject>
#include <QGraphicsPixmapItem>

class AttackBook : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AttackBook();
    static const int booksize = 50;

public slots:
    void fly();

signals:
    void attack();
};

#endif // ATTACKBOOK_H
