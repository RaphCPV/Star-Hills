#include "destroyer.h"

Destroyer::Destroyer(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Ressources/destroyer.png"));
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn_tie()));
    timer->start(2000);
}

void Destroyer::spawn_tie()
{
    Enemie * tie = new Enemie();
    tie->setPos(this->x(),this->y()+55);
    scene()->addItem(tie);
}
