#ifndef BLACKJACK_H
#define BLACKJACK_H

// Declaraciones de las funciones de dibujo
#include <time.h>
#include <stdio.h> // Necesario para printf y otras funciones de entrada/salida
#include <windows.h> // Necesario para funciones de manipulación de la consola
#include "cartas.h"

// Declaraciones de las funciones de dibujo
void inic_blackjackUI (int coins, int apuesta);
void dibujar_GananciaAps(int coins, int apuesta);
void inic_blackjackUI_Botones();
void inic_blackjack(Carta maso[], int *posMaso, Carta mano[], Carta manoPC[], int *manoCant, int *manoCantPC);
int determinarResultado(Carta manoJ[], Carta manoPC[], int cantJ, int cantPC, int revelar);




#endif /* truco_H */

