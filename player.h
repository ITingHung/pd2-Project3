#ifndef PLAYER_H
#define PLAYER_H

#include "attackbook.h"
#include <QGraphicsPixmapItem>
//#include <vector>
//using namespace std;

class Player : public QGraphicsPixmapItem
{
public:
    Player();
//    void attackmode(int mode);
    static const int playersize = 120;

public slots:

private:
//    AttackBook *book_tmp;
//    vector<AttackBook*> book;
};

#endif // PLAYER_H
