#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer), secondtimer(new QTimer), counttime(60),
    playerscore(0), bossscore(0)
{
    ui->setupUi(this);
    scene = new Scene;
    ui->graphicsView->setScene(scene);
    timer->start(10);
    secondtimer->start(1000);
    scene->gameGround();

    QPalette HpBarColor, GameoverColor;
    HpBarColor.setColor(QPalette::Highlight, QColor(Qt::red));
    GameoverColor.setColor(QPalette::WindowText, QColor(Qt::yellow));
    ui->PlayerhpBar->setValue(scene->player->rolehp); ui->BosshpBar->setValue(scene->boss->rolehp);
    ui->PlayerhpBar->setPalette(HpBarColor); ui->BosshpBar->setPalette(HpBarColor);
    ui->GameOver->setPalette(GameoverColor); ui->GameOver->setVisible(false);
    ui->YouWin->setPalette(GameoverColor); ui->YouWin->setVisible(false);
    ui->GameTime->setVisible(false); ui->TimeLable->setVisible(false);

    this->connect(ui->Start, SIGNAL(clicked()), this, SLOT(startClick_slot()));
    this->connect(scene, SIGNAL(skilluse()), this, SLOT(connectSkillTime_slot()));
    this->connect(scene, SIGNAL(timeup()), this, SLOT(disconnectSkillTime_slot()));
    this->connect(scene, SIGNAL(attacksuccess(int)), this, SLOT(hpChange_slot(int)));
    this->connect(this, SIGNAL(gameover()), this, SLOT(Gameover_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hpChange_slot(int role)
{
    switch(role){
    case 1:
        ui->PlayerhpBar->setValue(scene->player->rolehp-1);
        scene->player->rolehp -= 1;
        ScoreChange(1);
        break;
    case 2:
        ui->BosshpBar->setValue(scene->boss->rolehp-1);
        scene->boss->rolehp -= 1;
        ScoreChange(2);
        break;
    case 3:
        ui->BosshpBar->setValue(scene->boss->rolehp-2);
        scene->boss->rolehp -= 2;
        if(ui->BosshpBar->value()==1)
        {
            ui->BosshpBar->setValue(scene->boss->rolehp-1);
            scene->boss->rolehp -= 1;
        }
        ScoreChange(3);
        break;
    }
}

void MainWindow::setGameTime_slot()
{
    counttime -= 1;
    QString time = QString::number(counttime);
    ui->GameTime->setText(time);
    if (counttime == 0)
    {
        emit gameover();
        this->disconnect(secondtimer, SIGNAL(timeout()), this, SLOT(setGameTime_slot()));
        scene->disconnect(scene->timer, SIGNAL(timeout()), scene, SLOT(bosstime_slot()));
        scene->boss->disconnect(scene->boss->timer, SIGNAL(timeout()), scene->boss, SLOT(move()));
    }
}

void MainWindow::startClick_slot()
{
    ui->Start->setVisible(false);
    ui->GameTime->setVisible(true); ui->TimeLable->setVisible(true);
    this->connect(secondtimer, SIGNAL(timeout()), this, SLOT(setGameTime_slot()));
    scene->connect(scene->timer, SIGNAL(timeout()), scene, SLOT(bosstime_slot()));
    scene->boss->connect(scene->boss->timer, SIGNAL(timeout()), scene->boss, SLOT(move()));
}

void MainWindow::connectSkillTime_slot()
{
    this->connect(timer, SIGNAL(timeout()), this, SLOT(skillTimeCount_slot()));
}

void MainWindow::disconnectSkillTime_slot()
{
    ui->SkillTime->setText("");
    this->disconnect(timer, SIGNAL(timeout()), this, SLOT(skillTimeCount_slot()));
}

void MainWindow::skillTimeCount_slot()
{
    QString time = QString::number(scene->stimeinterval);
    QPalette ScoreBarColor;
    ScoreBarColor.setColor(QPalette::WindowText, QColor(Qt::red));
    ui->SkillTime->setPalette(ScoreBarColor);
    ui->SkillTime->setText(time);
    ui->SkillTime->setGeometry(1410,510,150,120);
}

void MainWindow::ScoreChange(int casenum)
{
    switch(casenum){
    case 1:
        bossscore += 100;
        break;
    case 2:
        playerscore += 100;
        break;
    case 3:
        playerscore += 200;
        break;
    }
    ui->BossScoreBar->display(bossscore);
    ui->PlayerScoreBar->display(playerscore);
}

void MainWindow::Gameover_slot()
{
    if(playerscore>=bossscore)
        ui->YouWin->setVisible(true);
    if(bossscore>playerscore)
        ui->GameOver->setVisible(true);
}
