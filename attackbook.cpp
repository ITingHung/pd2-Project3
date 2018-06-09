#include "attackbook.h"

#include <QGraphicsScene>
#include <QDebug>
AttackBook::AttackBook()
{

}

void AttackBook::fly()
{
    setPos(x(), y()-3);
    if(y()<0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
    if(y()>160 && y()<180)
        emit attack();

}

