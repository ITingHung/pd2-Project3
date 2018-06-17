#include "role.h"

Role::Role() : rolehp(100), timer(new QTimer)
{
    timer->start(10);
}
