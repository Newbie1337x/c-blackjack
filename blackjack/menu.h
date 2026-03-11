#ifndef menu_H
#define menu_H

// Declaraciones de las funciones de dibujo

#include <stdio.h> // Necesario para printf y otras funciones de entrada/salida
#include <windows.h> // Necesario para funciones de manipulación de la consola
#include <time.h>
void inic_menu (int primerInicio, int coins);
void inic_menuOpciones(int coins);
void inic_finalizarJuegoUI (int coins, int apuesta, int racha, int estado);
void song_Menu();
void song_inicioPartida();
void inic_menuPerfiles (int coins, char perfiles[7][15], int validos);
#endif /* menu_H */
