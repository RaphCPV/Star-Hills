#include "menu.h"

extern Score * score;

Menu::Menu()
{
    /*Constructeur du menu, on commence par initialiser
    la page du menu principal, puis on initialise celle
    des autres pages*/
    //--------------------- reglages de notre fenêtre-----------------------
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    setWindowTitle("Star Hill -- What is this ? A cross-over episode ??"); // Mr. PeanutButter <3
    // creation de la bande son
    musique = new QMediaPlayer();
    musique->setMedia(QUrl("qrc:/sounds/Ressources/bg.mp3"));
    musique->play();
    no = new QMediaPlayer();
    no->setMedia(QUrl("qrc:/sounds/Ressources/noo.mp3"));
    winner = new QMediaPlayer();
    winner->setMedia(QUrl("qrc:/sounds/Ressources/win.mp3"));
    //creation d'une scene qui va gérer l'interface graphique du menu
    scene_menu = new QGraphicsScene();
    scene_menu->setSceneRect(0,0,1280,720);
    scene_menu->setBackgroundBrush(QBrush(QImage(":/images/Ressources/fond_etoile.jpg")));
    //on créé des boutons que l'on ajoute à la scene
    jouer = new QPushButton("Jouer");
    jouer->setGeometry(320,415,640,50);
    connect(jouer,SIGNAL(clicked()),this,SLOT(play()));
    scene_menu->addWidget(jouer);
    //creation des autres scenes
    tuto_1B = new QPushButton("Comment jouer ?");
    tuto_1B->setGeometry(320,515,640,50);
    connect(tuto_1B,SIGNAL(clicked()),this,SLOT(tuto_1()));
    scene_menu->addWidget(tuto_1B);
    quitter = new QPushButton("Quitter");
    quitter->setGeometry(320,615,640,50);
    connect(quitter,SIGNAL(clicked()),this,SLOT(close()));
    scene_menu->addWidget(quitter);
    scene_lose = new QGraphicsScene();
    scene_lose->setSceneRect(0,0,1280,720);
    scene_lose->setBackgroundBrush(QBrush(QImage(":/images/Ressources/lose.png")));
    scene_win = new QGraphicsScene();
    scene_win->setSceneRect(0,0,1280,720);
    scene_win->setBackgroundBrush(QBrush(QImage(":/images/Ressources/win.png")));
    //ajout du logo
    logo = new QGraphicsPixmapItem();
    logo->setPixmap(QPixmap(":/images/Ressources/star_hill.png"));
    logo->setPos(480,50);
    scene_menu->addItem(logo);
    // ici on fait les scenes des tutos pour le plus grand plaisir des noobs
    scene_tuto_1 = new QGraphicsScene();
    scene_tuto_1->setSceneRect(0,0,1280,720);
    scene_tuto_1->setBackgroundBrush(QBrush(QImage(":/images/Ressources/fond_etoile.jpg")));
    tuto_1_p1 = new QGraphicsPixmapItem();
    tuto_1_p1->setPixmap(QPixmap(":/images/Ressources/tuto_1.png"));
    scene_tuto_1->addItem(tuto_1_p1);
    tuto_1_p1->setPos(50,100);
    tuto_1_text1 = new QGraphicsTextItem();
    tuto_1_text1->setPlainText(QString("Bienvenue sur Star Hill jeune padawan !\n"
                                      "Tu veux savoir comment jouer, tu ne t'es pas trompé de chemin..\n"
                                      "Sur l'image de gauche tu peux voir ta base au centre, tu dois la protéger !\n"
                                      "Surtout si tu veux te faire la princesse .. Ton score est toujours afficher\n"
                                      "en bas à droite, pour gagner tu dois atteindre 100 points"));
    tuto_1_text1->setFont(QFont("times",14));
    tuto_1_text1->setDefaultTextColor(Qt::white);
    scene_tuto_1->addItem(tuto_1_text1);
    tuto_1_text1->setPos(50,400);
    tuto_1_p2 = new QGraphicsPixmapItem();
    tuto_1_p2->setPixmap(QPixmap(":/images/Ressources/tuto_2.png"));
    scene_tuto_1->addItem(tuto_1_p2);
    tuto_1_p2->setPos(690,100);
    tuto_1_text2 = new QGraphicsTextItem();
    tuto_1_text2->setPlainText(QString("Sur l'image de droite tu peux voir les gros débris,\n"
                                       "c'est en les ramassant que tu vas te faire des points, cependant attention\n"
                                       "aux Tie Fighters qui vont tenter des les détruires, ainsi que ta base"));
    tuto_1_text2->setFont(QFont("times",14));
    tuto_1_text2->setDefaultTextColor(Qt::white);
    scene_tuto_1->addItem(tuto_1_text2);
    tuto_1_text2->setPos(690,400);
    Vers_tuto_2 = new QPushButton("Suite");
    Vers_tuto_2->setGeometry(320,615,640,50);
    connect(Vers_tuto_2,SIGNAL(clicked()),this,SLOT(tuto_2()));
    scene_tuto_1->addWidget(Vers_tuto_2);

    scene_tuto_2 = new QGraphicsScene();
    scene_tuto_2->setSceneRect(0,0,1280,720);
    scene_tuto_2->setBackgroundBrush(QBrush(QImage(":/images/Ressources/fond_etoile.jpg")));
    tuto_2_p1 = new QGraphicsPixmapItem();
    tuto_2_p1->setPixmap(QPixmap(":/images/Ressources/tuto_3.png"));
    scene_tuto_2->addItem(tuto_2_p1);
    tuto_2_p1->setPos(50,100);
    tuto_2_text1 = new QGraphicsTextItem();
    tuto_2_text1->setPlainText(QString("Comment se défendre me direz-vous! et bien les X-Wings c'est pas que\n"
                                       "casser la belle étoile noire de papa [SPOILER ALERT BTW],\n "
                                       "pour appeler vos X-Wings rien de plus simple, cliquez une \n"
                                       "fois sur votre base, et une fois là où vous voulez les envoyer,\n"
                                       "cela va tracer une route pour eux attention cependant\n"
                                       "chaque nouvelle route coute 5 points"));
    tuto_2_text1->setFont(QFont("times",14));
    tuto_2_text1->setDefaultTextColor(Qt::white);
    scene_tuto_2->addItem(tuto_2_text1);
    tuto_2_text1->setPos(50,400);
    tuto_2_p2 = new QGraphicsPixmapItem();
    tuto_2_p2->setPixmap(QPixmap(":/images/Ressources/tuto_4.png"));
    scene_tuto_2->addItem(tuto_2_p2);
    tuto_2_p2->setPos(690,100);
    tuto_2_text2 = new QGraphicsTextItem();
    tuto_2_text2->setPlainText(QString("Vos X-Wings en plus d'être vos lignes de défense en détruisant\n"
                                       "les Tie-Fighters ( qui ripostent hein faut pas trop faire les chauds\n"
                                       "ils collectent aussi les ressource ! Envoyez les dans les débris pour\n"
                                       " les collecter. Si jamais vous avez construit une route par erreur,\n"
                                       "on voulez juste vous en débarrasser, faites un SHIFT Doucle clic sur \n"
                                       "votre chemin, et PIOUF, elle disparait et les X-Wings ne s'y rendent plus."));
    tuto_2_text2->setFont(QFont("times",14));
    tuto_2_text2->setDefaultTextColor(Qt::white);
    scene_tuto_2->addItem(tuto_2_text2);
    tuto_2_text2->setPos(690,400);
    Vers_fin_tuto = new QPushButton("Suite et fin");
    Vers_fin_tuto->setGeometry(320,615,640,50);
    connect(Vers_fin_tuto,SIGNAL(clicked()),this,SLOT(tuto_fin()));
    scene_tuto_2->addWidget(Vers_fin_tuto);

    scene_fin_tuto = new QGraphicsScene();
    scene_fin_tuto->setSceneRect(0,0,1280,720);
    scene_fin_tuto->setBackgroundBrush(QBrush(QImage(":/images/Ressources/fond_etoile.jpg")));
    tuto_fin_p = new QGraphicsPixmapItem();
    tuto_fin_p->setPixmap(QPixmap(":/images/Ressources/tuto_5.png"));
    scene_fin_tuto->addItem(tuto_fin_p);
    tuto_fin_p->setPos(370,100);
    tuto_fin_t = new QGraphicsTextItem();
    tuto_fin_t->setPlainText(QString("Ca y est ! Tu sais tout ce qu'il faut savoir pour jouer !\n"
                                     "Maintenant arrêtes de faire des câlins à Chewie et lance toi!"));
    tuto_fin_t->setFont(QFont("times",14));
    tuto_fin_t->setDefaultTextColor(Qt::white);
    scene_fin_tuto->addItem(tuto_fin_t);
    tuto_fin_t->setPos(370,400);

    retour_acceuil = new QPushButton("Acceuil");
    retour_acceuil->setGeometry(320,615,640,50);
    connect(retour_acceuil,SIGNAL(clicked()),this,SLOT(acceuil()));
    scene_fin_tuto->addWidget(retour_acceuil);
   // on lance l'acceuil
   this->acceuil();
}

void Menu::acceuil()
{
    //on ajoute la scene à la View afin de pouvoir la visualisé
    setScene(scene_menu);
}

void Menu::tuto_1()
{
    //meme chose qu'avant
    setScene(scene_tuto_1);
}


void Menu::tuto_2()
{
    //je penses que tout le monde à compris à ce point là ..
    setScene(scene_tuto_2);
}

void Menu::tuto_fin()
{
    setScene(scene_fin_tuto);
}

void Menu::play()
{
    // On creer une partie
    jeu = new Game();
    setScene(jeu);
}

void Menu::lose()
{
    setScene(scene_lose);
    musique->stop();
    no->play();
}

void Menu::win()
{
    setScene(scene_win);
    musique->stop();
    winner->play();
}
