#include "attackchalk.h"

#include <QGraphicsScene>
#include <QDebug>

AttackChalk::AttackChalk(int mode)
{
    switch(mode) {
    case 0:
        this->setPixmap(QPixmap(":/image/bluechalk.png").scaled(chalksize,chalksize));
        break;
    case 1:
        this->setPixmap(QPixmap(":/image/yellowchalk.png").scaled(chalksize,chalksize));
        break;
    }
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
