#include "attackbook.h"
#include <QGraphicsScene>
#include <QDebug>

AttackBook::AttackBook()
{

}

void AttackBook::fly()
{
    setPos(x(), y()-3);
    if(y()==122)
    {
        emit attack();
    }
    if(y()<0)
    {
        this->scene()->removeItem(this);
        emit deletebook();
        delete this;
    }
}

