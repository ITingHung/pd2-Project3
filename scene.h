#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>

#include "player.h"
#include "boss.h"
#include "attackbook.h"
#include "attackchalk.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    void gameGround();

public slots:
    //virtual void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);

signals:
    void attacksuccess(int role);

private:
    QTimer *timer;
    int screenW;
    int screenH;
    QGraphicsPixmapItem *Gamebackground, *playerScore, *bossScore;
    Player *player;
    Boss *boss;
    AttackBook *book;
    AttackChalk *chalk;
private slots:
    void check();
};

#endif // SCENE_H
