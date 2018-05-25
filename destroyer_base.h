#ifndef DESTROYER_BASE_H
#define DESTROYER_BASE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "enemie2.h"

class Destroyer_base : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Destroyer_base(QGraphicsItem * parent=0);

public slots:
    void spawn_tie();
};

#endif // DESTROYER_BASE_H
