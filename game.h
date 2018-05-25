#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QPen>

#include "base.h"
#include "enemie.h"
#include "xwing.h"
#include "destroyer.h"
#include "destroyer_base.h"
#include "debris.h"
#include "chemin.h"
#include "score.h"

class Game : public QGraphicsScene
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    Base  * base;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    int nb_destro;
    int nb_debris;
    int test;
    int x1,x2,y1,y2;
    QPen pen;
    Chemin *chemin;
    QTimer * timer;

public slots:
    void spawn_des();
    void spawn_debris();
    void check_win();


};

#endif // GAME_H
