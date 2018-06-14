#include "boss.h"

Boss::Boss() : dir(true)
{
    setPos(480,50);
}

void Boss::move()
{
    if(dir == true)
    {
        this->setPos(this->x()+2, this->y());
        if (x()>=950)
           dir = false;
    }
    if(dir == false)
    {
        this->setPos(this->x()-2, this->y());
        if(x() <= 5)
            dir = true;
    }
}
