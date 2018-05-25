#ifndef DESTROYER_H
#define DESTROYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "enemie.h"

class Destroyer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Destroyer(QGraphicsItem * parent=0);

public slots:
    void spawn_tie();
};

#endif // DESTROYER_H
