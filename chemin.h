#ifndef CHEMIN_H
#define CHEMIN_H

#include <QGraphicsLineItem>
#include <QObject>
#include <QPen>

#include "xwing.h"

class Chemin :public QObject ,public QGraphicsLineItem
{
    Q_OBJECT
public:
    Chemin(QGraphicsItem * parent=0);
    Chemin(int x1, int y1, int x2, int y2, QPen pen);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    int x_depart,x_arrive,y_depart, y_arrive;
public slots:
    void spawn_xwing();
};

#endif // CHEMIN_H
