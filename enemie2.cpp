#include "enemie2.h"
#include "xwing.h"
#include "base.h"

Enemie2::Enemie2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    health = 50;
    setPixmap(QPixmap(":/images/Ressources/tie_fighter.png"));
    blast = new QMediaPlayer();
    blast->setMedia(QUrl("qrc:/sounds/Ressources/blast.mp3"));
    setTransformOriginPoint(30,23);
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Enemie2::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0, n= colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Base))
        {
            this->decrease();
            if(health <= 0)
            {
                scene()->removeItem(this);
                blast->play();
                delete this;
                return;
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(XWing))
        {
            scene()->removeItem(this);
            blast->play();
            delete this;
            return;
        }
    }
    setPos(x()+20,y()-10);
    if(pos().y() <0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Enemie2::decrease()
{
    health = health - 10;
}
