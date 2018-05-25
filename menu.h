#ifndef MENU_H
#define MENU_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QObject>
#include <QGraphicsItem>
#include<QGraphicsPixmapItem>
#include <QWidget>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include "game.h"
#include "base.h"

class Menu : public QGraphicsView
{
    Q_OBJECT
public:
    Menu();
    QGraphicsScene * scene_menu;
    QGraphicsScene * scene_lose;
    QGraphicsScene * scene_win;
    QPushButton * jouer;
    QPushButton * tuto_1B;
    QPushButton * quitter;
    QPushButton * Vers_tuto_2;
    QGraphicsPixmapItem * logo;
    QGraphicsScene * scene_tuto_1;
    QGraphicsTextItem * tuto_1_text1;
    QGraphicsPixmapItem * tuto_1_p1;
    QGraphicsTextItem * tuto_1_text2;
    QGraphicsPixmapItem * tuto_1_p2;
    QGraphicsScene * scene_tuto_2;
    QGraphicsTextItem * tuto_2_text1;
    QGraphicsPixmapItem * tuto_2_p1;
    QGraphicsTextItem * tuto_2_text2;
    QGraphicsPixmapItem * tuto_2_p2;
    QPushButton * Vers_fin_tuto;
    QGraphicsScene * scene_fin_tuto;
    QGraphicsPixmapItem * tuto_fin_p;
    QGraphicsTextItem * tuto_fin_t;
    QPushButton * retour_acceuil;
    QMediaPlayer * musique;
    Game * jeu;
    QMediaPlayer * no;
    QMediaPlayer * winner;
public slots:
    void acceuil();
    void play();
    void tuto_1();
    void tuto_2();
    void tuto_fin();
    void lose();
    void win();
};
#endif // MENU_H
