#ifndef BASE_H
#define BASE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <QGraphicsTextItem>
#include <QTimer>

#include "base.h"


class Base : public QObject, public QGraphicsPixmapItem
       {
           Q_OBJECT
public:
    Base(QGraphicsItem *parent = 0);
    void decrease();
    int get_health();
    QGraphicsTextItem * Vie;
public slots:
    void detect();
private:
    int health;
};

#endif // BASE_H
