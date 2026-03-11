#include <time.h>
#include <stdio.h> // Necesario para printf y otras funciones de entrada/salida
#include <windows.h> // Necesario para funciones de manipulación de la consola
#include "cartas.h"



void inic_blackjackUI (int coins, int apuesta)
{

    srand(time(NULL));
    system("cls");


    dibujar_Casino(20,17);
    dibujar_mazo(70,5);


    dibujar_fichas(8,33,coins);
    dibujar_Marco(2,5);

    dibujar_texto(10,3,"Apuesta:",apuesta,35);
    dibujar_texto(10,5,"Ganancia:",apuesta*2,35);
    dibujar_Linea(28,6);

}


void dibujar_GananciaAps(int coins, int apuesta)
{
    dibujar_texto(10,3,"Apuesta:",apuesta,35);
    dibujar_texto(10,5,"Ganancia:",apuesta*2,35);
}
void inic_blackjackUI_Botones()
{

    dibujar_boton(12,29,"Pedir",1,35);
    dibujar_boton(36,29,"Pasar",2,35);
    dibujar_boton(60,29,"Doble",3,35);
}

void inic_blackjack(Carta maso[], int *posMaso, Carta mano[], Carta manoPC[], int *manoCant, int *manoCantPC)
{
    for (int i = 0; i < 2; i++)
    {
        repartirCarta(maso, mano, posMaso, manoCant, 1, 0);
        (*posMaso)++;

        repartirCarta(maso, manoPC, posMaso, manoCantPC, 2, 0);
        (*posMaso)++;
    }

    dibujar_texto(37, 12, "Crupier:", calcularPuntos(manoPC, 2) - manoPC[0].valor, 35);
    dibujar_texto(37, 15, "Jugador:", calcularPuntos(mano, 2), 35);
    usleep(600000);
    inic_blackjackUI_Botones();

    *manoCant = 2;
    *manoCantPC = 2;
}

int determinarResultado(Carta manoJ[], Carta manoPC[], int cantJ, int cantPC, int revelar)
{

    int flag = -3;
    int puntosPC;

    if (revelar == 1)
    {
        puntosPC = calcularPuntos(manoPC, cantPC) - calcularPuntos(manoPC,0);
    }
    else
    {
        puntosPC = calcularPuntos(manoPC, cantPC);
    }
    int puntosJugador = calcularPuntos(manoJ, cantJ);

    if (puntosJugador > 21 || puntosPC > puntosJugador && puntosPC <= 21)
    {
        flag = -1; // El jugador pierde
    }
    else if (puntosPC > 21 || puntosPC < puntosJugador)
    {
        flag = 1; // El jugador gana
    }
    else if (puntosJugador == puntosPC)
    {
        flag = 0; // Empate
    }
    else if (puntosPC < puntosJugador && puntosPC < 21)
    {
        flag = -2; // El juego continúa
    }
    return flag;
}
