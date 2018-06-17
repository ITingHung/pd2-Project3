#include "boss.h"

Boss::Boss() : dir(1)
{
    setPos(480,50);
}

void Boss::move()
{
    if(dir == 1)
    {
        this->setPos(this->x()+2, this->y());
        if (x()>=950)
           setElement(2);
    }
    if(dir == 2)
    {
        this->setPos(this->x()-2, this->y());
        if(x() <= 5)
            setElement(1);
    }
}

void Boss::setElement(int value)
{
    dir = value;
}

