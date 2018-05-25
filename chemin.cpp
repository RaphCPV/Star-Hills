#include "chemin.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QTimer>

Chemin::Chemin(QGraphicsItem *parent) : QObject(), QGraphicsLineItem(parent)
{

}

Chemin::Chemin(int x1, int y1, int x2, int y2, QPen pen)
{
    this->setLine(x1,y1,x2,y2);
    this->setPen(pen);
    x_depart = x1; // ces coordonnées nous servent pour déplacer les X-Wings
    x_arrive = x2;
    y_depart = y1;
    y_arrive = y2;
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn_xwing()));
    timer->start(4000); // toutes les 4 secondes, on fait spawn un X-Wing
}

void Chemin::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && event->modifiers()==Qt::ShiftModifier)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Chemin::spawn_xwing()
{
    XWing * xwing = new XWing();
    xwing->setPos(x_depart-15,y_depart-15);
    xwing->set_coord(x_depart,y_depart,x_arrive,y_arrive);
    scene()->addItem(xwing);
}
