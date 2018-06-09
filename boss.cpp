#include "boss.h"

Boss::Boss()
{
    this->setPos(480,50);
}

void Boss::move()
{
    bool dir = true;
    if(x() <= 0)
        dir = true;
    else if(x() <= 800)
        dir = false;
    if(dir == true)
        this->setPos(this->x()-10, this->y());
    if(dir == false)
        this->setPos(this->x()+10, this->y());
}
