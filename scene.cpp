#include "scene.h"

#include <QDebug>

Scene::Scene() :
    timer(new QTimer), screenW(1500), screenH(800),
    player(new Player), boss(new Boss)
{
    this->setSceneRect(0, 0, screenW, screenH);
    timer->start(10);
}

void Scene::gameGround()
{
    Gamebackground = new QGraphicsPixmapItem(QPixmap(":/image/blackboard.png"));
    Gamebackground->setScale(0.6);
    addItem(Gamebackground);
    Gamebackground->setPos(0,0);

    player->setPixmap(QPixmap(":/image/girl.png").scaled(player->playersize, player->playersize));
    boss->setPixmap(QPixmap(":/image/teacher.png").scaled(boss->bosssize, boss->bosssize));
    playerScore = new QGraphicsPixmapItem(QPixmap(":/image/score-book.png"));
    bossScore = new QGraphicsPixmapItem(QPixmap(":/image/score-chalkbox.png"));
    addItem(player);
    addItem(boss);
    addItem(playerScore); playerScore->setPos(1100,600);
    addItem(bossScore); bossScore->setPos(1100,50);

    //boss->connect(timer, SIGNAL(timeout()), boss, SLOT(move()));
}

void Scene::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Left:
        player->setPos(player->x() - 10, player->y());
//        player->setElement(0,player->x());
        break;
    case Qt::Key_Right:
        player->setPos(player->x() + 10, player->y());
//        player->setElement(0,player->x());
        break;
    case Qt::Key_Up:
        book = new AttackBook;
        if(qrand() % 2 == 0)
            book->setPixmap(QPixmap(":/image/orange-book.png").scaled(book->booksize,book->booksize));
        else
            book->setPixmap(QPixmap(":/image/blue-book.png").scaled(book->booksize,book->booksize));
        addItem(book);
        book->setPos(player->x() + player->pixmap().width()/2 - book->pixmap().width()/2, player->y() - book->pixmap().height());
        book->connect(timer, SIGNAL(timeout()), book, SLOT(fly()));
        this->connect(book, SIGNAL(attack()), this, SLOT(check()));
    }
}

void Scene::check()
{
    //    if(chalk->x()>=(player->x()-player->booksize) && chalk->x()<=(player->x()+player->bosssize))
    //        emit attacksuccess(1);
    if(book->x()>=(boss->x()-book->booksize) && book->x()<=(boss->x()+boss->bosssize))
        emit attacksuccess(2);
}


