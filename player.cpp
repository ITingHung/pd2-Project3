#include "player.h"

Player::Player()
{
    this->setPos(480,550);
}

void Player::move()
{
    switch(dir){
    case 1:
        this->setPos(x()-10, y());
        if (x()<=5)
            this->setPos(5, y());
        break;
    case 2:
        this->setPos(x()+10, y());
        if (x()>=950)
            this->setPos(950, y());
        break;
    }
}

void Player::setElement(int value)
{
    dir = value;
}
