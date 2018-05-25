#include "game.h"
#include "menu.h"

extern Menu * menu;

Score * score;

Game::Game(QWidget *parent)
{   
    setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/images/Ressources/fond_game.jpg")));
    base = new Base();
    addItem(base);
    base->setPos(580,320);
    base->Vie->setPos(base->x(),base->y()+80);
    addItem((base->Vie));
    //on compte le nombre de destroyers qui ont déja spawner pour ne pas en spawn 2 au meme endroit
    nb_destro = 0;
    nb_debris = 0;
    QTimer::singleShot(5000,this,SLOT(spawn_des())); // pensez a changer les temps
    QTimer::singleShot(10000,this,SLOT(spawn_des()));
    QTimer::singleShot(26000,this,SLOT(spawn_des()));
    QTimer::singleShot(5000,this,SLOT(spawn_debris()));
    QTimer::singleShot(25000,this,SLOT(spawn_debris()));
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(check_win()));
    timer->start(1000);
    test = 1;
    pen.setBrush(Qt::white);
    pen.setWidth(5);
    pen.setCapStyle(Qt::RoundCap);
    pen.setStyle(Qt::DashLine);
    score = new Score();
    addItem(score);
    score->setPos(1150,680);
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton && event->modifiers()==Qt::NoModifier)
    {
        if (test == 1 && event->scenePos().x() >600 && event->scenePos().x()<755 && event->scenePos().y()>335 && event->scenePos().y() < 400)
        {
            x1 = event->scenePos().x();
            y1 = event->scenePos().y();
            test =2;
        }
        else if (test == 2 && (event->scenePos().x() <580 || event->scenePos().x()>755 || event->scenePos().y()<330 || event->scenePos().y() > 400))
        {

            qDebug() << "clic en dehors";
            x2 = event->scenePos().x();
            y2 = event->scenePos().y();
            score->decrease();
            chemin = new Chemin(x1,y1,x2,y2,pen);
            addItem(chemin);
            test = 1;
        }
    }
    else if(event->button()==Qt::LeftButton && event->modifiers()==Qt::ShiftModifier)
    {
        qDebug()<<"shift clic";
    }
}

void Game::spawn_des()
{
    if(nb_destro == 1)
    {
        Destroyer * destro = new Destroyer();
        destro->setPos(300,100);
        addItem(destro);
    }
    else if(nb_destro == 2)
    {
        Destroyer * destro = new Destroyer();
        destro->setPos(1000,100);
        addItem(destro);
    }
    else if (nb_destro == 0)
    {
        Destroyer_base * destro = new Destroyer_base();
        destro->setPos(100,600);
        addItem(destro);
    }
    nb_destro++;
}

void Game::spawn_debris()
{
    Debris * debris = new Debris();
    if(nb_debris==0)
    {
        debris->setPos(300,300);
    }
    else
    {
        debris->setPos(1000,300);
    }
    addItem(debris);
    debris->Vie->setPos(debris->x(),debris->y()+100);
    addItem(debris->Vie);
    nb_debris++;
}

void Game::check_win()
{
    if (score->getScore() >= 100)
    {
        menu->win();
    }
}
