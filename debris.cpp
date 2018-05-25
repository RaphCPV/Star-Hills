#include <QTimer>

#include "debris.h"
#include "enemie.h"
#include "enemie2.h"
#include "xwing.h"

Debris::Debris(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Ressources/debris.png"));
    health = 10000;
    Vie = new QGraphicsTextItem();
    Vie->setPlainText(QString("HP : " + QString::number(health)));
    Vie->setFont(QFont("times",16));
    Vie->setDefaultTextColor(Qt::white);
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));
    // toutes les 100 ms on verifient si le débris perd de la durabilité
    timer->start(100);
}

void Debris::decrease()
{
    /*Le principe reste le même, on detecte si il y a des enemie ou un X-Wing dans les débris
    pour lui enlever des HP*/
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0, n= colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemie) || typeid(*(colliding_items[i])) == typeid(Enemie2))
        {
            health = health - 50;
            Vie->setPlainText(QString("HP : " + QString::number(health)));
            if(health <= 0) // si plus de HP, on le retire de la scene et on le détruit
            {
                scene()->removeItem(this->Vie);
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        else if(typeid(*(colliding_items[i])) == typeid(XWing))
        {
            health = health - 5;
            Vie->setPlainText(QString("HP : " + QString::number(health)));
            if(health <= 0)
            {
                scene()->removeItem(this->Vie);
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
}
