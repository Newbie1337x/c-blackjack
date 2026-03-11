#include <stdio.h> // Necesario para printf y otras funciones de entrada/salida
#include <windows.h> // Necesario para funciones de manipulación de la consola
#include <time.h>
#include "menu.h"
#include "ui.h"
void inic_menu (int primerInicio, int coins)
{

    system("cls");

    if (primerInicio == 1)
    {
        dibujar_logo_anim(12,27);
    }

    else
    {
        dibujar_logo(12,7);
    }

    dibujar_boton(38,17,"Jugar",1,35);
    dibujar_boton_opciones(38,22,2,35);
    dibujar_boton(38,27,"Salir",0,35);
    dibujar_fichas(8,33,coins);
    dibujar_decoracion();

}

void inic_menuPerfiles(int coins, char perfiles[7][15], int validos)
{
    usleep(2000000);
    system("cls");
    dibujar_logoPerfiles(20, 4);
    dibujar_decoracion();
    dibujar_boton_volver(27, 30, 0, 35);
    dibujar_boton_continuar(52, 30, 1, 35);

    for (int i = 0; i < 6; i++)
    {
        int x = 12 + 3 * i;
        printf("\033[35m");
        printf("\033[%d;%dH──────────────────\n", x, 40);
        printf("\033[0m");
        printf("\033[%d;%dHCrear Usuario", x + 1, 46);
        printf("\033[%d;%dH──────────────────\n", x + 2, 40);
    }


    for (int i = 0; i < validos; i++)
    {
        int x = 12 + 3 * i;
        printf("\033[%d;%dH                     ", x + 1, 40);
        printf("\033[%d;%dH%s", x + 1, 46, perfiles[i]);
    }
}

void inic_menuOpciones(int coins)
{
    system("cls");
    dibujar_opciones(17,7);
    dibujar_decoracion();

    dibujar_texto(34,15,"Juego",-1,37);
    dibujar_boton_musica(27,17,1,35);
    dibujar_boton_reiniciar(27,22,2,35);
    dibujar_boton_volver(27,27,0,35);
    dibujar_fichas(8,33,coins);

    dibujar_boton(52,17,"+1000",3,35);
    dibujar_boton_dinero(52,22,4,35);
    dibujar_boton_masdinero(52,27,5,35);
    dibujar_texto(58,15,"Trampas",-1,37);
}

void inic_finalizarJuegoUI (int coins, int apuesta, int racha, int estado)
{
    usleep(2000000);
    system("cls");
    if (estado == -1)
    {
        dibujar_PerdisteAnim(20,1);
        dibujar_decoracion();
        dibujar_boton_volver(27,27,0,35);
        dibujar_boton_continuar(52,27,1,35);
        dibujar_texto(38,17,"Fichas restantes:",coins,37);
        dibujar_texto(38,20,"Fichas perdidas:",apuesta,37);
        dibujar_texto(38,23,"Racha de victorias:",racha,37);
        printf("\033[%d;%dH──────────────────────────────────────────\n", 26,27 );

    }

    if (estado == 1)
    {
        dibujar_GanasteAnim(20,1);
        dibujar_decoracion();
        dibujar_boton_volver(27,27,0,35);
        dibujar_boton_continuar(52,27,1,35);
        dibujar_texto(38,17,"Fichas restantes:",coins,37);
        dibujar_texto(38,20,"Fichas ganadas:",apuesta,37);
        dibujar_texto(38,23,"Racha de victorias:",racha,37);
        printf("\033[%d;%dH──────────────────────────────────────────\n", 26,27 );

    }

    if(estado == 0)
    {
        dibujar_EmpateAnim(20,1);
        dibujar_decoracion();
        dibujar_boton_volver(27,27,0,35);
        dibujar_boton_continuar(52,27,1,35);
        dibujar_texto(38,17,"Fichas restantes:",coins,37);
        dibujar_texto(38,20,"Fichas ganadas:",apuesta,37);
        dibujar_texto(38,23,"Racha de victorias:",racha,37);
        printf("\033[%d;%dH──────────────────────────────────────────\n", 26,27 );
    }
}

void song_Menu()
{
    while(1)
    {


        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(83.99,200);

        Beep(880,200);

        Beep(830.61,200);

        Beep(880,200);

        Beep(987.77,400);


        Beep(880,200);

        Beep(783.99,200);

        Beep(698.46,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(880,200);

        Beep(830.61,200);

        Beep(880,200);

        Beep(987.77,400);



        Sleep(200);
        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(783.99,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(880,200);

        Beep(830.61,200);

        Beep(880,200);

        Beep(987.77,400);


        Beep(880,200);

        Beep(783.99,200);

        Beep(698.46,200);


        Beep(659.25,200);

        Beep(698.46,200);

        Beep(784,200);

        Beep(880,400);

        Beep(784,200);

        Beep(698.46,200);

        Beep(659.25,200);



        Beep(587.33,200);

        Beep(659.25,200);

        Beep(698.46,200);

        Beep(784,400);

        Beep(698.46,200);

        Beep(659.25,200);

        Beep(587.33,200);



        Beep(523.25,200);

        Beep(587.33,200);

        Beep(659.25,200);

        Beep(698.46,400);

        Beep(659.25,200);

        Beep(587.33,200);

        Beep(493.88,200);

        Beep(523.25,200);


        Sleep(400);
        Beep(349.23,400);

        Beep(392,200);

        Beep(329.63,200);

        Beep(523.25,200);

        Beep(493.88,200);

        Beep(466.16,200);



        Beep(440,200);

        Beep(493.88,200);

        Beep(523.25,200);

        Beep(880,200);

        Beep(493.88,200);

        Beep(880,200);

        Beep(1760,200);

        Beep(440,200);



        Beep(392,200);

        Beep(440,200);

        Beep(493.88,200);

        Beep(783.99,200);

        Beep(440, 200);

        Beep(783.99,200);

        Beep(1568,200);

        Beep(392,200);



        Beep(349.23,200);

        Beep(392,200);

        Beep(440,200);

        Beep(698.46,200);

        Beep(415.2,200);

        Beep(698.46,200);

        Beep(1396.92,200);

        Beep(349.23,200);



        Beep(329.63,200);

        Beep(311.13,200);

        Beep(329.63,200);

        Beep(659.25,200);

        Beep(698.46,400);

        Beep(783.99,400);



        Beep(440,200);

        Beep(493.88,200);

        Beep(523.25,200);

        Beep(880,200);

        Beep(493.88,200);

        Beep(880,200);

        Beep(1760,200);

        Beep(440,200);



        Beep(392,200);

        Beep(440,200);

        Beep(493.88,200);

        Beep(783.99,200);

        Beep(440,200);

        Beep(783.99,200);

        Beep(1568,200);

        Beep(392,200);



        Beep(349.23,200);

        Beep(392,200);

        Beep(440,00);

        Beep(698.46,200);

        Beep(659.25,200);

        Beep(698.46,200);

        Beep(739.99,200);

        Beep(783.99,200);

        Beep(392,200);

        Beep(392,200);

        Beep(392,200);

        Beep(392,200);

        Beep(196,200);

        Beep(196,200);

        Beep(196,200);



        Beep(185,200);

        Beep(196,200);

        Beep(185,200);

        Beep(196,200);

        Beep(207.65,200);

        Beep(220,200);

        Beep(233.08,200);

        Beep(246.94,200);
    }
}
void song_inicioPartida()
{

    Beep(329.628, 187);
    Beep(329.628, 375);
    Beep(329.628, 375);
    Beep(261.626, 187);
    Beep(329.628, 375);
    Beep(391.995, 375);
    Beep(8.176, 375);
    Beep(195.998, 375);
    Beep(8.176, 375);
}
