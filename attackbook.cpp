#include "attackbook.h"
#include <QGraphicsScene>
#include <QDebug>

AttackBook::AttackBook(int mode)
{
    switch(mode) {
    case 0:
        this->setPixmap(QPixmap(":/image/orange-book.png").scaled(booksize,booksize));
        break;
    case 1:
        this->setPixmap(QPixmap(":/image/dictionary.png").scaled(skillbooksize,skillbooksize));
        break;
    }
}

void AttackBook::fly()
{
    setPos(x(), y()-3);
    if(y()==122 || y()==123)
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

