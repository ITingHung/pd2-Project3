#include "attackchalk.h"

#include <QGraphicsScene>
#include <QDebug>

AttackChalk::AttackChalk()
{

}

void AttackChalk::fly()
{
    setPos(x(), y()+3);
    if(y()==548)
    {
        emit attack();
    }
    if(y() > 800)
    {
        this->scene()->removeItem(this);
        emit deletechalk();
        delete this;
    }
}
