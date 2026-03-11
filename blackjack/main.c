#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "ui.h"
#include "menu.h"
#include "blackjack.h"
#include "pila.h"
#include "cartas.h"
// Función para dibujar una carta en la terminal con Unicode

int main()
{


    srand(time(NULL));
    //Consola Windows

    HWND hwnd = GetConsoleWindow();

    int width = 800;
    int height = 600;
    int x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

    MoveWindow(hwnd, x, y, width, height, TRUE);

    // Matriz para rastrear qué cartas han sido repartidas

    int mano_pc[100];
    int mano_Cant = 0;
    int mano_pcCant = 0;
    int mano_jugador[100];
    int key_Menu;
    int key_Opciones;
    int key_Blackjack;
    int key_fin;
    int primerInicio = 0;
    int posMaso = 0;


    //Archivo Iara
    int coins = 1000; //Por defecto
    int apuesta = 1000;
    int racha = 0;
    int estado = -2;
    int musica = 0;

    //Perfiles

    char perfiles [7][15] = {"Carlos","Jose","Alan","Tomas","Iara","Armando"};
    int perfVal = 6;



    inic_menuPerfiles(1000,perfiles,perfVal);
    scanf("%d");
    HANDLE HiloCancion_Menu = CreateThread(NULL, 0, song_Menu, NULL, 0, NULL);
    SuspendThread(HiloCancion_Menu);
    if (musica == 1)
    {
        ResumeThread(HiloCancion_Menu);
    }


//Mejorame los switch y el menu joacolol que me da sida.
    do
    {

        inic_menu(primerInicio,coins);

        scanf("%d", &key_Menu);

        switch (key_Menu)
        {
        case 1: //Inicia blackjack
            if (musica == 1)
            {
                SuspendThread(HiloCancion_Menu);
            }
            dibujar_boton_Normal(38,17,"Jugar",1,31);
            if (musica == 1)
            {
                song_inicioPartida();
            }
inicio:

            mano_Cant = 0;
            mano_pcCant = 0;
            MezclarCartas(cartas);
            primerInicio = 0;
            posMaso = 0;
            int salir = 0;
            inic_blackjackUI(coins,apuesta);
            inic_blackjack(cartas,&posMaso,mano_jugador,mano_pc,&mano_Cant,&mano_pcCant);

            while (salir == 0)
            {
                scanf("%d", &key_Blackjack);
                switch (key_Blackjack)
                {
                case 1: //Pedir carta
                    repartirCarta(cartas, mano_jugador, &posMaso, &mano_Cant, 1,0);
                    if (calcularPuntos(mano_jugador, mano_Cant) > 21) //Pasarse de 21.
                    {
                        salir = 1;
                    }
                    break;
                case 2: //Plantarse.
                    revelarCarta(mano_pc, mano_pcCant);
                    while (calcularPuntos(mano_pc, mano_pcCant) < calcularPuntos(mano_jugador, mano_Cant) + 1 && calcularPuntos(mano_pc, mano_pcCant) < 18 )
                    {
                        repartirCarta(cartas, mano_pc, &posMaso, &mano_pcCant, 0, 1);
                    }
                    salir = 1;
                    break;
                case 3:
                    if(coins>apuesta)
                    {
                        apuesta=apuesta*2;
                        dibujar_GananciaAps(coins,apuesta);
                        repartirCarta(cartas, mano_jugador, &posMaso, &mano_Cant, 1,0);
                        revelarCarta(mano_pc, mano_pcCant);

                        while (calcularPuntos(mano_pc, mano_pcCant) < calcularPuntos(mano_jugador, mano_Cant) + 1 && calcularPuntos(mano_pc, mano_pcCant) < 18)
                        {
                            repartirCarta(cartas, mano_pc, &posMaso, &mano_pcCant, 0, 1);
                        }
                        salir = 1;
                    }
                    else
                    {
                        printf("Coins Insuficientes!!!");
                    }
                    break;
                default:
                    printf("Opción no válida.\n");
                }
            }
            estado = determinarResultado(mano_jugador, mano_pc, mano_Cant, mano_pcCant, 1);
            inic_finalizarJuegoUI(coins, apuesta, racha, estado);
            scanf("%d",&key_fin);

            if (key_fin == 1)
            {
                goto inicio;

            }

            //fin_blackjack actualizarte los coins, pasar a nueva partida, guardar los coins en un archivo.

            if (musica == 1)
            {
                ResumeThread(HiloCancion_Menu);
            }
            break;
        case 2: //Menu de opciones
            do
            {
                inic_menuOpciones(coins);
                fflush(stdin);
                scanf("%d", &key_Opciones);

                switch (key_Opciones)
                {
                case 1:
                    if (musica == 1)
                    {
                        SuspendThread(HiloCancion_Menu);
                        musica = 0;
                    }
                    else
                    {
                        ResumeThread(HiloCancion_Menu);
                        musica = 1;
                    }
                    break;
                case 2:
                    coins = 1000;
                    break;
                case 3:
                    coins+= 1000;
                    break;
                case 4:
                    coins+= 10000;
                    break;
                case 5:
                    coins += 100000;
                    break;
                case 6:
                    coins=coins*coins;
                    break;
                case 0:
                    break;
                default:
                    printf("Opción no válida.\n");
                }
            }
            while (key_Opciones != 0);
            break;

        default:
            printf("Opción no válida.\n");
        }
    }
    while (key_Menu != 0);
    return 0;
}
