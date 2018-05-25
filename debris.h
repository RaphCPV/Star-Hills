#ifndef DEBRIS_H
#define DEBRIS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class Debris: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Debris(QGraphicsItem * parent=0);
    QGraphicsTextItem * Vie;
public slots:
    void decrease();
private:
    int health;
};

#endif // DEBRIS_H
