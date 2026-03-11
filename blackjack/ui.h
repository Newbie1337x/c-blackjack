#ifndef UI_H
#define UI_H

// Declaraciones de las funciones de dibujo
#include <time.h>
#include <stdio.h> // Necesario para printf y otras funciones de entrada/salida
#include <windows.h> // Necesario para funciones de manipulación de la consola

void dibujar_mensaje(const char *texto, int segundos, int color);
void dibujar_decoracion();
void dibujar_fichas(int x, int y, int coins);
void dibujar_texto(int x, int y, char texto[], int dato, int color);
void dibujar_boton(int x, int y, char texto[], int boton, int color);
void dibujar_boton_Normal(int x, int y, char texto[], int boton, int color);
void dibujar_boton_opciones(int x, int y, int boton, int color);
void dibujar_boton_musica(int x, int y, int boton, int color);
void dibujar_boton_reiniciar(int x, int y, int boton, int color);
void dibujar_boton_volver(int x, int y, int boton, int color);
void dibujar_boton_dinero(int x, int y, int boton, int color);
void dibujar_boton_masdinero(int x, int y, int boton, int color);
void dibujar_boton_continuar(int x, int y, int boton, int color);
void dibujar_diamante (int x, int y);
void dibujar_logo(int x, int y);
void dibujar_logo_anim(int x, int y);
void dibujar_opciones(int x, int y);
void dibujar_carta(int numero, char palo[], int x, int y, char pc);
void dibujar_Linea (int x, int y);
void dibujar_Marco(int x, int y);
void dibujar_Casino(int x, int y);
void dibujar_Perdiste(int x, int y);
void dibujar_PerdisteAnim (int x, int y);
void dibujar_Ganaste(int x, int y);
void dibujar_Empate (int x, int y);
void dibujar_EmpateAnim (int x, int y);
void dibujar_GanasteAnim (int x, int y);
void dibujar_carta_reverso(int x, int y);
void dibujar_mazo(int x, int y);
void dibujar_barajarmazo(int x, int y);
void dibujar_cpu(int x, int y);
void borrar_carta_jugador(int x, int y);
void borrar_mazo(int x, int y);
void borrar_todo(int x, int y);
void dibujar_logoPerfiles (int x, int y);



#endif /* DIBUJAR_H */
