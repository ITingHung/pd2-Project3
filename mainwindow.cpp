#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer), secondtimer(new QTimer), counttime(60),
    playerhp(100),bosshp(100), playerscore(0), bossscore(0)
{
    ui->setupUi(this);
    scene = new Scene;
    ui->graphicsView->setScene(scene);
    timer->start(10);
    secondtimer->start(1000);
    scene->gameGround();

    QPalette HpBarColor;
    HpBarColor.setColor(QPalette::Highlight, QColor(Qt::red));
    ui->PlayerhpBar->setValue(playerhp); ui->BosshpBar->setValue(bosshp);
    ui->PlayerhpBar->setPalette(HpBarColor); ui->BosshpBar->setPalette(HpBarColor);

    this->connect(secondtimer, SIGNAL(timeout()), this, SLOT(setGameTime_slot()));
    this->connect(scene, SIGNAL(skilluse()), this, SLOT(connectSkillTime_slot()));
    this->connect(scene, SIGNAL(timeup()), this, SLOT(disconnectSkillTime_slot()));
    this->connect(scene, SIGNAL(attacksuccess(int)), this, SLOT(hpChange_slot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hpChange_slot(int role)
{
    switch(role){
    case 1:
        ui->PlayerhpBar->setValue(playerhp-1);
        playerhp -= 1;
        ScoreChange(1);
        break;
    case 2:
        ui->BosshpBar->setValue(bosshp-1);
        bosshp -= 1;
        ScoreChange(2);
        break;
    case 3:
        ui->BosshpBar->setValue(bosshp-2);
        bosshp -= 2;
        if(ui->BosshpBar->value()==1)
        {
            ui->BosshpBar->setValue(bosshp-1);
            bosshp -= 1;
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
