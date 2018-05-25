#ifndef ENEMIE2_H
#define ENEMIE2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QTimer>
#include <QMediaPlayer>

#include "base.h"

class Enemie2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemie2(QGraphicsItem * parent=0);
    QMediaPlayer * blast;
public slots:
    void move();
    void decrease();
private:
    int health;
};




#endif // ENEMIE2_H
