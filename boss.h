#ifndef BOSS_H
#define BOSS_H

#include <QTimer>

#include "role.h"

class Boss : public Role
{
    Q_OBJECT

public:
    Boss();

public slots:
    virtual void move();

private:
    virtual void setElement(int value);
    int dir;

};

#endif // BOSS_H
