#include <QTimer>

#include "xwing.h"
#include "enemie2.h"
#include "enemie.h"
#include "base.h"
#include "debris.h"
#include "score.h"

extern Score * score;

XWing::XWing(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    health = 50;
    setPixmap(QPixmap(":/images/Ressources/xwing_2.png"));
    setTransformOriginPoint(30,23);
    aller = true; // nous sert à savoir si on est sur l'aller ou le retour du chemin
    rempli = false; // savoir si on a loot le débris
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}

void XWing::decrease()
{
    health = health - 20;
}

void XWing::set_coord(int x4, int y4, int x5, int y5)
{
    this->x1 = x4;
    this->y1 = y4;
    this->x2 = x5;
    this->y2 = y5;
}

void XWing::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0, n= colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemie) || typeid(*(colliding_items[i])) == typeid(Enemie2))
        {
            this->decrease();
            if(health <= 0)
            {
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        else if (typeid(*(colliding_items[i])) == typeid(Base) && !aller)
        {
                score->increase();
                scene()->removeItem(this);
                delete this;
                return;

        }
        else if (typeid(*(colliding_items[i])) == typeid(Debris))
        {
            if(!rempli)
            {
                rempli = true;
            }
        }
    }
    // on calcule le pas de déplacement sur la ligne en fonction du chemin
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    float a = dx/8;
    float b = dy / a;
    if (a < 2) // on fait ceci afin d'éviter les bugs sur les chemins verticaux
    {
        b = 5;
        a = 0;
    }
    a = 8;
    if (x1 < x2 && y1 < y2) // on se deplace en bas à droite
    {
        if(pos().x() >= x2)
        {
            aller = false;
        }
        else if(pos().x() <= x1)
        {
            aller = true;
        }

        if(aller)
        {
            setPos(x()+a,y()+b);
        }
        else
        {
            setPos(x()-a,y()-b);
        }
    }
    else if(x1 <= x2 && y1 >= y2) // on se deplace en haut à droite
    {
        if(pos().x() >= x2)
        {
            aller = false;
        }
        else if(pos().x() <= x1)
        {
            aller = true;
        }
        if(aller)
        {
            setPos(x()+a,y()-b);
        }
        else
        {
            setPos(x()-a,y()+b);
        }
    }
    else if(x1 > x2 && y1 < y2) // on se déplace en bas à gauche
    {
        if(pos().x() <= x2)
        {
            aller = false;
        }
        else if(pos().x() >= x1)
        {
            aller = true;
        }
        if(aller)
        {
            setPos(x()-a,y()+b);
        }
        else
        {
            setPos(x()+a,y()-b);
        }
    }
    else // on se déplace en haut à gauche
    {
        if(pos().x() <= x2)
        {
            aller = false;
        }
        else if(pos().x() >= x1)
        {
            aller = true;
        }
        if(aller)
        {
            setPos(x()-a,y()-b);
        }
        else
        {
            setPos(x()+a,y()+b);
        }
    }
}
