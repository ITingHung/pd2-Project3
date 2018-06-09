#include "book.h"

#include <QGraphicsScene>

book::book()
{

}

void book::fly()
{
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
