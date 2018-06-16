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
    void move(int dir);
    int playerhp;
    static const int playersize = 120;

public slots:

private:

};

#endif // PLAYER_H
