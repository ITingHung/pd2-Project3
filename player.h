#ifndef PLAYER_H
#define PLAYER_H

#include "attackbook.h"
#include "role.h"

class Player : public Role
{
public:
    Player();
    virtual void move();
    void setElement(int value);

public slots:

private:
    int dir;

};

#endif // PLAYER_H
