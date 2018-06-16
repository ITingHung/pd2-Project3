#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>


#include <QDebug>

#include "scene.h"
#include "attackbook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class scene;
    bool gamestart;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void hpChange_slot(int role);
    void setGameTime_slot();
    void startClick_slot();
    void connectSkillTime_slot();
    void disconnectSkillTime_slot();
    void skillTimeCount_slot();
    void Gameover_slot();

signals:
    void gameover();

private:
    Ui::MainWindow *ui;
    Scene *scene;
    QTimer *timer, *secondtimer;
    QGraphicsPixmapItem *background, *player, *boss, *playerScore, *bossScore;
    int  counttime, playerhp, bosshp, playerscore, bossscore;
    void ScoreChange(int casenum);
};

#endif // MAINWINDOW_H
