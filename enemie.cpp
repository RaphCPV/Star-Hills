#include "enemie.h"
#include "base.h"
#include "xwing.h"
#include "debris.h"

Enemie::Enemie(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    health = 50;
    setPixmap(QPixmap(":/images/Ressources/tie_fighter.png"));
    setTransformOriginPoint(30,23);
    blast = new QMediaPlayer();
    blast->setMedia(QUrl("qrc:/sounds/Ressources/blast.mp3"));
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void Enemie::move()
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
        else if(typeid(*(colliding_items[i])) == typeid(XWing) || typeid(*(colliding_items[i])) == typeid(Debris))
        {
            scene()->removeItem(this);
            blast->play();
            delete this;
            return;
        }
    }
    setPos(x(),y()+10);
    if(pos().y()+70 > 720)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Enemie::decrease()
{
    health = health - 10;
}
