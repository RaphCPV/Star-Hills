#ifndef ENEMIE_H
#define ENEMIE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QTimer>
#include <QMediaPlayer>

#include "base.h"

class Enemie : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemie(QGraphicsItem * parent=0);
    QMediaPlayer * blast;
public slots:
    void move();
    void decrease();
private:
    int health;
};

#endif // ENEMIE_H

