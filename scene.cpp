#include "scene.h"

#include <QDebug>

Scene::Scene() :
    timer(new QTimer), stimeinterval(5), gamemode(false), screenW(1500), screenH(800),
    btimeinterval(0), skillcount(0), playermode(0), bossmode(0), bossmodecount(0),
    secondtimer(new QTimer), player(new Player), boss(new Boss), skillavailable(true)
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

    player->setPixmap(QPixmap(":/image/girl.png").scaled(player->rolesize, player->rolesize));
    boss->setPixmap(QPixmap(":/image/teacher.png").scaled(boss->rolesize, boss->rolesize));
    playerScore = new QGraphicsPixmapItem(QPixmap(":/image/score-book.png"));
    bossScore = new QGraphicsPixmapItem(QPixmap(":/image/score-chalkbox.png"));
    playerskill1 = new QGraphicsPixmapItem(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));
    playerskill2 = new QGraphicsPixmapItem(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));
    playerskill3 = new QGraphicsPixmapItem(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));
    playerskill4 = new QGraphicsPixmapItem(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));
    playerskill5 = new QGraphicsPixmapItem(QPixmap(":/image/dictionary.png").scaled(book_tmp->booksize,book_tmp->booksize));

    addItem(player);
    addItem(boss);
    addItem(playerScore); playerScore->setPos(1100,600);
    addItem(bossScore); bossScore->setPos(1100,55);
    addItem(playerskill1); playerskill1->setPos(1105,500);
    addItem(playerskill2); playerskill2->setPos(1170,500);
    addItem(playerskill3); playerskill3->setPos(1235,500);
    addItem(playerskill4); playerskill4->setPos(1300,500);
    addItem(playerskill5); playerskill5->setPos(1365,500);

    this->connect(this, SIGNAL(bossattack(int)), this, SLOT(bossattack_slot(int)));
}

void Scene::setGamemode(bool mode)
{
    gamemode = mode;
}

void Scene::keyPressEvent(QKeyEvent *e)
{
    if (gamemode == true)
    {
        switch(e->key()) {
        case Qt::Key_Left:
            player->setElement(1);
            player->move();
            break;
        case Qt::Key_Right:
            player->setElement(2);
            player->move();
            break;
        case Qt::Key_Up:
            playerattack(playermode);
            break;
        case Qt::Key_Space:
            if(skillavailable == true)
            {
                if(playerskill1->QGraphicsItem::isVisible() || playerskill2->QGraphicsItem::isVisible() || playerskill3->QGraphicsItem::isVisible() || playerskill4->QGraphicsItem::isVisible() || playerskill5->QGraphicsItem::isVisible())
                {
                    playermode = 1;
                    skillavailable = false;
                    secondtimer->start(1000);
                    this->connect(secondtimer, SIGNAL(timeout()), this, SLOT(secondcount_slot()));
                    emit skilluse();
                    if(playerskill1->QGraphicsItem::isVisible() && playerskill2->QGraphicsItem::isVisible() && playerskill3->QGraphicsItem::isVisible() && playerskill4->QGraphicsItem::isVisible() && playerskill5->QGraphicsItem::isVisible())
                    {
                        playerskill5->setVisible(false);
                        break;
                    }
                    if(playerskill1->QGraphicsItem::isVisible() && playerskill2->QGraphicsItem::isVisible() && playerskill3->QGraphicsItem::isVisible() && playerskill4->QGraphicsItem::isVisible())
                    {
                        playerskill4->setVisible(false);
                        break;
                    }
                    if(playerskill1->QGraphicsItem::isVisible() && playerskill2->QGraphicsItem::isVisible() && playerskill3->QGraphicsItem::isVisible())
                    {
                        playerskill3->setVisible(false);
                        break;
                    }
                    if(playerskill1->QGraphicsItem::isVisible() && playerskill2->QGraphicsItem::isVisible())
                    {
                        playerskill2->setVisible(false);
                        break;
                    }
                    if(playerskill1->QGraphicsItem::isVisible())
                    {
                        playerskill1->setVisible(false);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void Scene::playerattack(int playermode)
{
    book_tmp = new AttackBook(playermode);
    addItem(book_tmp);
    book_tmp->setPos(player->x() + player->pixmap().width()/2 - book_tmp->pixmap().width()/2, player->y() - book_tmp->pixmap().height());
    book_tmp->connect(timer, SIGNAL(timeout()), book_tmp, SLOT(fly()));
    this->connect(book_tmp, SIGNAL(attack()), this, SLOT(checkbosshp_slot()));
    //Save all the book exist in scene to a vector
    book.push_back(book_tmp);
    this->connect(book_tmp, SIGNAL(deletebook()), this, SLOT(deletebook_slot()));
}

void Scene::secondcount_slot()
{
    stimeinterval -= 1;
    if (stimeinterval == -1)
    {
        playermode = 0;
        emit timeup();
        stimeinterval = 5;
        this->disconnect(secondtimer, SIGNAL(timeout()), this, SLOT(secondcount_slot()));
        skillavailable = true;
    }
}

void Scene::bossattack_slot(int bossmode)
{
    chalk_tmp = new AttackChalk(bossmode);
    addItem(chalk_tmp);
    chalk_tmp->setPos(boss->x() + boss->pixmap().width()/2 - chalk_tmp->pixmap().width()/2, boss->y() + boss->pixmap().height());
    chalk_tmp->connect(timer, SIGNAL(timeout()), chalk_tmp, SLOT(fly()));
    this->connect(chalk_tmp, SIGNAL(attack()), this, SLOT(checkplayerhp_slot()));
    //Save all the chalk exist in scene to a vector
    chalk.push_back(chalk_tmp);
    this->connect(chalk_tmp, SIGNAL(deletechalk()), this, SLOT(deletechalk_slot()));
}

void Scene::bosstime_slot()
{
    //Mode change with time
    bossmodecount += 1;
    if (bossmodecount == 1000)
        bossmode = 1;
    if (bossmodecount == 1501)
    {
        bossmode = 0;
        bossmodecount = 0;
    }
    switch(bossmode) {
    case 0:
        btimeinterval += 1;
        if(btimeinterval==101)
            btimeinterval = 1;
        if(btimeinterval==100)
            emit bossattack(0);
        break;
    case 1:
        if (btimeinterval>51)
            btimeinterval = 0;
        btimeinterval += 1;
        if(btimeinterval==11)
            btimeinterval = 1;
        if(btimeinterval==10)
            emit bossattack(1);
        break;
    }
}

void Scene::checkplayerhp_slot()
{
    for (unsigned int i=0; i<chalk.size(); ++i)
    {
        if(chalk.at(i)->y()==548 && chalk.at(i)->x()>=(player->x()-chalk_tmp->chalksize) && chalk.at(i)->x()<=(player->x()+player->rolesize))
        {
            chalk.at(i)->setVisible(false);
            emit attacksuccess(1);
        }
    }
}

void Scene::checkbosshp_slot()
{
    for (unsigned int i=0; i<book.size(); ++i)
    {
        if(book.at(i)->y()==122 || book.at(i)->y()==123)
        {
            if((book.at(i)->x())>=(boss->x()-book_tmp->booksize) && (book.at(i)->x())<=(boss->x()+boss->rolesize))
            {
                book.at(i)->setVisible(false);
                switch(playermode) {
                case 0:
                    emit attacksuccess(2);
                    break;
                case 1:
                    emit attacksuccess(3);
                    break;
                }
            }
        }
    }
}

void Scene::useplayerskill()
{
//    skillbook_tmp = new AttackBook;
//    skillbook_tmp->setPixmap(QPixmap(":/image/dictionary.png").scaled(skillbook_tmp->skillbooksize,skillbook_tmp->skillbooksize));
//    addItem(skillbook_tmp);
//    //skillbook_tmp->setPos(50+100*i,800);
//    skillbook_tmp->setPos(player->x() + player->pixmap().width()/2 - book->pixmap().width()/2, player->y() - book->pixmap().height());
//    skillbook_tmp->connect(timer, SIGNAL(timeout()), skillbook_tmp, SLOT(fly()));
//    this->connect(skillbook_tmp, SIGNAL(attack()), this, SLOT(checkbosshp_slot()));
//    skillbook.push_back(skillbook_tmp);
//    this->connect(skillbook_tmp,SIGNAL(deleteskillbook()),this,SLOT(deleteskillbook_slot()));
}

void Scene::deletebook_slot()
{
    book.erase(book.begin());
    //skillbook.erase(skillbook.begin(),skillbook.begin()+9);
}

void Scene::deletechalk_slot()
{
    chalk.erase(chalk.begin());
}
