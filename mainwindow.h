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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void hpChange(int role);

private:
    Ui::MainWindow *ui;
    Scene *scene;
    QGraphicsPixmapItem *background, *player, *boss, *playerScore, *bossScore;
    QTimer *timer;
    int playerhp, bosshp;
};

#endif // MAINWINDOW_H
