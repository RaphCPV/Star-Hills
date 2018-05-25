#ifndef XWING_H
#define XWING_H

#include <QObject>
#include <QGraphicsPixmapItem>

class XWing: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    XWing(QGraphicsItem * parent=0);
    void decrease();
    int x1,x2,y1,y2;
    bool aller;
    bool rempli;
public slots:
    void set_coord(int x4, int y4, int x5, int y5);
    void move();
private:
    int health;

};

#endif // XWING_H
