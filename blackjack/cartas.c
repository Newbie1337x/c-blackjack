#include <stdio.h>
#include "cartas.h"



// Declaración del mazo de cartas
;
Carta cartas[52] =
{

    // Corazones (♥)
    {"2", "♥", 2},
    {"3", "♥", 3},
    {"4", "♥", 4},
    {"5", "♥", 5},
    {"6", "♥", 6},
    {"7", "♥", 7},
    {"8", "♥", 8},
    {"9", "♥", 9},
    {"10", "♥", 10},
    {"J", "♥", 10},
    {"Q", "♥", 10},
    {"K", "♥", 10},
    {"A", "♥", 11},

    // Diamantes (♦)
    {"2", "♦", 2},
    {"3", "♦", 3},
    {"4", "♦", 4},
    {"5", "♦", 5},
    {"6", "♦", 6},
    {"7", "♦", 7},
    {"8", "♦", 8},
    {"9", "♦", 9},
    {"10", "♦", 10},
    {"J", "♦", 10},
    {"Q", "♦", 10},
    {"K", "♦", 10},
    {"A", "♦", 11},

    // Tréboles (♣)
    {"2", "♣", 2},
    {"3", "♣", 3},
    {"4", "♣", 4},
    {"5", "♣", 5},
    {"6", "♣", 6},
    {"7", "♣", 7},
    {"8", "♣", 8},
    {"9", "♣", 9},
    {"10", "♣", 10},
    {"J", "♣", 10},
    {"Q", "♣", 10},
    {"K", "♣", 10},
    {"A", "♣", 11},

    // Picas (♠)
    {"2", "♠", 2},
    {"3", "♠", 3},
    {"4", "♠", 4},
    {"5", "♠", 5},
    {"6", "♠", 6},
    {"7", "♠", 7},
    {"8", "♠", 8},
    {"9", "♠", 9},
    {"10", "♠", 10},
    {"J", "♠", 10},
    {"Q", "♠", 10},
    {"K", "♠", 10},
    {"A", "♠", 11},

    // Carta NULL
    {"-1", "X", -1},
};

void MezclarCartas(Carta cartas[])    //Quite los validos porque en el juego son siempre 52. (Tom)
{
    srand(time(NULL));
    for (int i = 52 - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Carta temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }
}
//Test (Se puede borrar)
void mostrarMaso (Carta cartas[], int validos)
{

    int x = 0;
    for (int i = 0; i < validos; i++)
    {
        system("cls");
        dibujar_carta(cartas[i].numero,cartas[i].palo,40,10,0);
        usleep(900000);

    }
}

void repartir_UI(Carta mano[], int jugador, int posMano)
{

    int x = posMano * 7;
    if (jugador == 1)
    {
        dibujar_carta(mano[posMano].numero, mano[posMano].palo, x + 30, 19,0);
    }
    else
    {
        if (posMano == 0)
        {
            dibujar_carta_reverso(x + 30, 3);

        }
        else
        {
            dibujar_carta(mano[posMano].numero, mano[posMano].palo, x + 30, 3,1);

        }
    }
}

void repartirCarta(Carta maso[], Carta mano[], int *posMaso, int *posMano, int jugador, int revelar)
{
    mano[*posMano] = maso[*posMaso];
    usleep(700000);

    if (jugador == 1)
    {
        dibujar_texto(37, 15, "Jugador:", calcularPuntos(mano, *posMano + 1), 35);
    }
    else
    {
        if (calcularPuntos(mano, 0) != 0)
        {
            dibujar_texto(37, 12, "Crupier:", calcularPuntos(mano, 2) - mano[0].valor, 35);
        }
        if (revelar == 1)
        {

            dibujar_texto(37, 12, "Crupier:", calcularPuntos(mano, *posMano + 1), 35);


        }
    }

    repartir_UI(mano, jugador, *posMano);
    (*posMano)++;
    (*posMaso)++;

}

int calcularPuntos(Carta mano[], int posMano)
{
    int puntos = 0;
    for (int i = 0; i < posMano; i++)
    {
        puntos += mano[i].valor;
    }
    return puntos;
}

void revelarCarta(Carta mano[], int posMano)
{

    for (int i = 0; i < posMano; i++)
    {
        dibujar_carta(mano[i].numero, mano[i].palo, (i * 7) + 30, 3,1);
        dibujar_texto(37, 12, "Crupier:", calcularPuntos(mano, 2), 35);

    }
}
