#include "player.h"

Player::Player()
{
    this->setPos(480,550);
}

//void Player::attackmode(int mode)
//{
//    book_tmp = new AttackBook;
//    switch(mode) {
//    case 0:
//        book_tmp->setPixmap(QPixmap(":/image/orange-book.png").scaled(book_tmp->booksize,book_tmp->booksize));
//        break;
//    case 1:
//        book_tmp->setPixmap(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));
//        break;
//    }
//    addItem(book_tmp);
//    book_tmp->setPos(this->x() + this->pixmap().width()/2 - book_tmp->pixmap().width()/2, this->y() - book_tmp->pixmap().height());
//    book_tmp->connect(timer, SIGNAL(timeout()), book_tmp, SLOT(fly()));
//    this->connect(book_tmp, SIGNAL(attack()), this, SLOT(checkbosshp_slot()));
//    //Save all the book exist in scene to a vector
//    book.push_back(book_tmp);
//    this->connect(book_tmp,SIGNAL(deletebook()),this,SLOT(deletebook_slot()));
//}
