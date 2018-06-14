#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <vector>
using namespace std;

#include "player.h"
#include "boss.h"
#include "attackbook.h"
#include "attackchalk.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    int stimeinterval;
    void gameGround();
    void useplayerskill();
    void attackmode(int playermode);

public slots:
    //virtual void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void bossattack_slot(int bossmode);
    void bosstime_slot();
    void checkplayerhp_slot();
    void checkbosshp_slot();
    void secondcount_slot();
    void deletebook_slot();
    void deletechalk_slot();

signals:
    void attacksuccess(int role);
    void bossattack(int bossmode);
    void skilluse();
    void timeup();

private:
    const int screenW;
    const int screenH;
    int btimeinterval;
    int skillcount;
    int playermode, bossmode, bossmodecount;
    QTimer *timer, *secondtimer;
    QGraphicsPixmapItem *Gamebackground, *playerScore, *bossScore;
    QGraphicsPixmapItem *playerskill1, *playerskill2, *playerskill3, *playerskill4, *playerskill5;
    Player *player;
    Boss *boss;
    bool skillavailable;
    AttackBook *book_tmp, *skillbook_tmp;
    vector<AttackBook*> book;
    vector<AttackChalk*> chalk;
    AttackChalk *chalk_tmp;

};

#endif // SCENE_H
