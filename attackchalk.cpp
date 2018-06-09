#include "attackchalk.h"

#include <QGraphicsScene>

AttackChalk::AttackChalk()
{

}

void AttackChalk::fly()
{
    setPos(x(), y() + 3);
    if(y() > 800 )
    {
        this->scene()->removeItem(this);
        delete this;
    }
}
