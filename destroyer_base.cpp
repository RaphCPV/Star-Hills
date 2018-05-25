#include "destroyer_base.h"

Destroyer_base::Destroyer_base(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Ressources/destroyer.png"));
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn_tie()));
    timer->start(1000);
}

void Destroyer_base::spawn_tie()
{
    Enemie2 * tie = new Enemie2();
    tie->setPos(this->x()+20,this->y()-20);
    scene()->addItem(tie);
}
