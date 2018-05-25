#include "base.h"
#include "enemie2.h"
#include "menu.h"

extern Menu * menu;

Base::Base(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    health = 100; // on fixe la vie de la base
    setPixmap(QPixmap(":/images/Ressources/base.png"));
    Vie = new QGraphicsTextItem(); // affichage de la vie sur la scene
    Vie->setPlainText(QString("HP : " + QString::number(health)));
    Vie->setFont(QFont("times",16));
    Vie->setDefaultTextColor(Qt::white);
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(detect()));
    timer->start(100);

}

void Base::decrease() // on fait perdre des HP à la base, et on update l'affichage
{
    health = health - 3;
    Vie->setPlainText(QString("HP : " + QString::number(health)));
}

int Base::get_health() // un getter, rien de foufou
{
    return health;
}

void Base::detect()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); // on détecte si dans les object qui touche la base on a des enemies
    for(int i =0, n= colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemie2))
        {
            this->decrease();
            if(health <= 0)
            {
                scene()->removeItem(this);
                menu->lose();
                delete this;
                return;
            }
        }
    }
}
