#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    playerhp(100),bosshp(100)
{
    ui->setupUi(this);
    scene = new Scene;
    ui->graphicsView->setScene(scene);

    QPalette ScoreBarColor;
    ScoreBarColor.setColor(QPalette::Highlight, QColor(Qt::red));
    ui->PlayerScoreBar->setValue(playerhp); ui->BossScoreBar->setValue(bosshp);
    ui->PlayerScoreBar->setPalette(ScoreBarColor); ui->BossScoreBar->setPalette(ScoreBarColor);

    scene->gameGround();
    this->connect(scene, SIGNAL(attacksuccess(int)), this, SLOT(hpChange(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hpChange(int role)
{
    switch(role){
    case 1:
        ui->PlayerScoreBar->setValue(playerhp-1);
        playerhp -= 1;
        break;
    case 2:
        ui->BossScoreBar->setValue(bosshp-1);
        bosshp -= 1;
        break;
    }
}




