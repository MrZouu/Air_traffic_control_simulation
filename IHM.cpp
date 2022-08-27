#include "IHM.h"


void IHM::initialisationAllegro()
{
    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

IHM::~IHM()
{

}

IHM::IHM(int debut, int fin)
{
    //Création d'une bitmap pour toutes les images
    BITMAP *image;
    BITMAP *page;
    BITMAP *bangui;
    BITMAP *bankok;
    BITMAP *cape;
    BITMAP *haiti;
    BITMAP *NY;
    BITMAP *paz;
    BITMAP *perth;
    BITMAP *paris;

    initialisationAllegro();

    show_mouse(screen); //la souris s'affiche à l'écran

    page = create_bitmap(SCREEN_W,SCREEN_H); //Page de 800x600
    clear_bitmap(page);
    //On charge les différentes images stockés
    image=load_bitmap("carte1.bmp",NULL);
    if (!image)
    {
        allegro_message("pas pu trouver/charger carte1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    bangui =load_bitmap("bangui.bmp",NULL);
    if (!bangui)
    {
        allegro_message("pas pu trouver/charger bangui.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    bankok =load_bitmap("bankok.bmp",NULL);
    if (!bankok)
    {
        allegro_message("pas pu trouver/charger bankok.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    cape =load_bitmap("cape.bmp",NULL);
    if (!cape)
    {
        allegro_message("pas pu trouver/charger cape.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    haiti =load_bitmap("haiti.bmp",NULL);
    if (!haiti)
    {
        allegro_message("pas pu trouver/charger haiti.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    NY =load_bitmap("NY.bmp",NULL);
    if (!NY)
    {
        allegro_message("pas pu trouver/charger NY.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    paris =load_bitmap("paris.bmp",NULL);
    if (!paris)
    {
        allegro_message("pas pu trouver/charger paris.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    paz =load_bitmap("paz.bmp",NULL);
    if (!paz)
    {
        allegro_message("pas pu trouver/charger paz.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    perth =load_bitmap("perth.bmp",NULL);
    if (!perth)
    {
        allegro_message("pas pu trouver/charger perth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    textout_ex(image, font, "VISUALISATION DE LA SIMULATION DU CONTROLE AERIEN", 200, 590, makecol(0, 0, 255), -1);


    for(int i=0; i<73; i++)
    {
        hline(image, 0, 0+8*i, 800, makecol(100,100,100));
    }

    for(int j=0; j<100; j++)
    {
        vline(image, 0+8*j, 0, 580, makecol(100,100,100));
    }
    //Points rouges correspondants à la position des aeroports
    circlefill(image, 380, 269, 5, makecol(255, 0, 0)); //Paris
    circlefill(image, 214, 296, 5, makecol(255, 0, 0)); //New York
    circlefill(image, 219, 347, 5, makecol(255, 0, 0)); //Haiti
    circlefill(image, 231, 429, 5, makecol(255, 0, 0)); //La Paz
    circlefill(image, 429, 461, 5, makecol(255, 0, 0)); //Cape Town
    circlefill(image, 644, 430, 5, makecol(255, 0, 0)); //Perth
    circlefill(image, 608, 358, 5, makecol(255, 0, 0)); //Bankok
    circlefill(image, 414, 373, 5, makecol(255, 0, 0)); //Bangui

    ///LIGNES SUR LA MAP EN FONCTION DU TRAJET SOUHAITÉ/////////////////////////////////
    if((debut ==1 && fin==2)||(debut ==2 && fin==1))
    {
        line(image, 380, 269, 414, 373, makecol(0,255,150)); //Paris-Bangui = 3400
        line(image, 608, 358, 414, 373, makecol(255,86,4)); //Bankok-Bangui = 6400
    }
    if((debut ==1 && fin==3)||(debut ==3 && fin==1))
    {
        line(image, 380, 269, 429, 461, makecol(255,255,0)); //Paris-Cape Town = 6000
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
    }
    if((debut ==1 && fin==4)||(debut ==4 && fin==1))
    {
        line(image, 380, 269, 429, 461, makecol(255,255,0)); //Paris-Cape Town = 6000
    }
    if((debut ==1 && fin==5)||(debut ==5 && fin==1))
    {
        line(image, 380, 269, 219, 347, makecol(0,255,150)); //Paris-Haiti = 4800
        line(image, 230, 428, 218, 346, makecol(0,255,150)); //La Paz-Haiti = 3000
    }
    if((debut ==1 && fin==6)||(debut ==6 && fin==1))
    {
        line(image, 380, 269, 219, 347, makecol(0,255,150)); //Paris-Haiti = 4800
    }
    if((debut ==1 && fin==7)||(debut ==7 && fin==1))
    {
        line(image, 380, 269, 214, 296, makecol(0,255,150)); //Paris-New York = 4000
    }
    if((debut ==1 && fin==8)||(debut ==8 && fin==1))
    {
        line(image, 380, 269, 414, 373, makecol(0,255,150)); //Paris-Bangui = 3400
    }
    if((debut ==2 && fin==3)||(debut ==3 && fin==2))
    {
        line(image, 608, 358, 644, 430, makecol(0,255,150)); //Bankok-Perth = 3200
    }
    if((debut ==2 && fin==4)||(debut ==4 && fin==2))
    {
        line(image, 608, 358, 429, 461, makecol(255,86,4)); //Bankok-Cape Town = 6800
    }
    if((debut ==2 && fin==5)||(debut ==5 && fin==2))
    {
        line(image, 608, 358, 429, 461, makecol(255,86,4)); //Bankok-Cape Town = 6800
        line(image, 231, 429, 429, 461, makecol(255,255,0)); //La Paz-Cape Town = 5500
    }
    if((debut ==2 && fin==6)||(debut ==6 && fin==2))
    {
        line(image, 608, 358, 414, 373, makecol(255,86,4)); //Bankok-Bangui = 6400
        line(image, 219, 347, 414, 373, makecol(255,255,0)); //Haiti-Bangui = 5500
    }
    if((debut ==2 && fin==7)||(debut ==7 && fin==2))
    {
        line(image, 608, 358, 414, 373, makecol(255,86,4)); //Bankok-Bangui = 6400
        line(image, 380, 269, 414, 373, makecol(0,255,150)); //Paris-Bangui = 3400
        line(image, 380, 269, 214, 296, makecol(0,255,150)); //Paris-New York = 4000
    }
    if((debut ==2 && fin==8)||(debut ==8 && fin==2))
    {
        line(image, 608, 358, 414, 373, makecol(255,86,4)); //Bankok-Bangui = 6400
    }
    if((debut ==3 && fin==4)||(debut ==4 && fin==3))
    {
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
    }
    if((debut ==3 && fin==5)||(debut ==5 && fin==3))
    {
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
        line(image, 231, 429, 429, 461, makecol(255,255,0)); //La Paz-Cape Town = 5500
    }
    if((debut ==3 && fin==6)||(debut ==6 && fin==3))
    {
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
        line(image, 219, 347, 429, 461, makecol(255,86,4)); //Haiti-Cape Town = 6700
    }
    if((debut ==3 && fin==7)||(debut ==7 && fin==3))
    {
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
        line(image, 219, 347, 429, 461, makecol(255,86,4)); //Haiti-Cape Town = 6700
        line(image, 218, 346, 213, 295, makecol(0,255,150)); //Haiti-New York = 2000
    }
    if((debut ==3 && fin==8)||(debut ==8 && fin==3))
    {
        line(image, 644, 430, 429, 461, makecol(255,255,0)); //Perth-Cape Town = 6000
        line(image, 429, 461, 414, 373, makecol(0,255,150)); //Cape Town-Bangui = 2600
    }
    if((debut ==4 && fin==5)||(debut ==5 && fin==4))
    {
        line(image, 231, 429, 429, 461, makecol(255,255,0)); //La Paz-Cape Town = 5500
    }
    if((debut ==4 && fin==6)||(debut ==6 && fin==4))
    {
        line(image, 219, 347, 429, 461, makecol(255,86,4)); //Haiti-Cape Town = 6700
    }
    if((debut ==4 && fin==7)||(debut ==7 && fin==4))
    {
        line(image, 219, 347, 429, 461, makecol(255,86,4)); //Haiti-Cape Town = 6700
        line(image, 218, 346, 213, 295, makecol(0,255,150)); //Haiti-New York = 2000
    }
    if((debut ==4 && fin==8)||(debut ==8 && fin==4))
    {
        line(image, 429, 461, 414, 373, makecol(0,255,150)); //Cape Town-Bangui = 2600
    }
    if((debut ==5 && fin==6)||(debut ==6 && fin==5))
    {
        line(image, 230, 428, 218, 346, makecol(0,255,150)); //La Paz-Haiti = 3000
    }
    if((debut ==5 && fin==7)||(debut ==7 && fin==5))
    {
        line(image, 230, 428, 218, 346, makecol(0,255,150)); //La Paz-Haiti = 3000
        line(image, 218, 346, 213, 295, makecol(0,255,150)); //Haiti-New York = 2000
    }
    if((debut ==5 && fin==8)||(debut ==8 && fin==5))
    {
        line(image, 231, 429, 429, 461, makecol(255,255,0)); //La Paz-Cape Town = 5500
        line(image, 429, 461, 414, 373, makecol(0,255,150)); //Cape Town-Bangui = 2600
    }
    if((debut ==6 && fin==7)||(debut ==7 && fin==6))
    {
        line(image, 218, 346, 213, 295, makecol(0,255,150)); //Haiti-New York = 2000
    }
    if((debut ==6 && fin==8)||(debut ==8 && fin==6))
    {
        line(image, 219, 347, 414, 373, makecol(255,255,0)); //Haiti-Bangui = 5500
    }
    if((debut ==7 && fin==8)||(debut ==8 && fin==7))
    {
        line(image, 380, 269, 214, 296, makecol(0,255,150)); //Paris-New York = 4000
        line(image, 380, 269, 414, 373, makecol(0,255,150)); //Paris-Bangui = 3400
    }

    //image de fond
    blit(image,page,0,0,0,0, image->w, image->h);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    while (!key[KEY_ESC]) //Boucle jusqu'à l'appui sur ECHAP
    {
        clear_bitmap(page);
        blit(image,page,0,0,0,0, image->w, image->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        textprintf_ex(screen,font,40,540,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);
        ///Affichage des pancartes des aeroports en fonction de la position de la souris
        if (mouse_x >= 411&&mouse_x<=420 && mouse_y >= 370&&mouse_y<=380)//Bangui
        {
            masked_blit(bangui, image, 0,0,0,0, bangui->w, bangui->h);
        }
        if (mouse_x >= 600&&mouse_x<=615 && mouse_y >= 350&&mouse_y<=360)//Bankok
        {
            masked_blit(bankok, image, 0,0,0,0, bankok->w, bankok->h);
        }
        if (mouse_x >= 425&&mouse_x<=437 && mouse_y >= 460&&mouse_y<=471)//Cape
        {
            masked_blit(cape, image, 0,0,0,0, cape->w, cape->h);
        }
        if (mouse_x >= 214&&mouse_x<=230 && mouse_y >= 343&&mouse_y<=355)//Haiti
        {
            masked_blit(haiti, image, 0,0,0,0, haiti->w, haiti->h);
        }
        if (mouse_x >= 210&&mouse_x<=225 && mouse_y >= 293&&mouse_y<=305)//New York
        {
            masked_blit(NY, image, 0,0,0,0, NY->w, NY->h);
        }
        if (mouse_x >= 376&&mouse_x<=390 && mouse_y >= 263&&mouse_y<=275)//Paris
        {
            masked_blit(paris, image, 0,0,0,0, paris->w, paris->h);
        }
        if (mouse_x >= 227&&mouse_x<=243 && mouse_y >= 425&&mouse_y<=440)//La Paz
        {
            masked_blit(paz, image, 0,0,0,0, paz->w, paz->h);
        }
        if (mouse_x >= 640&&mouse_x<=655 && mouse_y >= 426&&mouse_y<=441)//Perth
        {
            masked_blit(perth, image, 0,0,0,0, perth->w, perth->h);
        }
    }
    destroy_bitmap(image);
    destroy_bitmap(bangui);
    destroy_bitmap(bankok);
    destroy_bitmap(cape);
    destroy_bitmap(haiti);
    destroy_bitmap(NY);
    destroy_bitmap(paz);
    destroy_bitmap(paris);
    destroy_bitmap(perth);
    allegro_exit();
}
