#ifndef HEADER_54434FA06C5110E2
#define HEADER_54434FA06C5110E2

#ifndef alg_mezclar.h
#define alg_mezclar.h


typedef struct
{
    char numero[3];
    char palo[3];
    int valor;
} Carta;

void MezclarCartas(Carta cartas[]);
Carta cartas[52];
void mostrarMaso (Carta cartas[], int validos);
void revelarCarta(Carta mano[], int posMano);
void repartirCarta(Carta maso[], Carta mano[], int *posMaso, int *posMano, int jugador, int revelar);
void repartir_UI(Carta mano[], int jugador, int posMano);
int calcularPuntos (Carta mano[],int posMano);

//Con este codigo deberia funcar
/*
 int arregloNumerosAzar[52]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
    int validosAzar=52;
    Pila almacenarNum;
    inicpila(&almacenarNum);
    MezclarCartas(arregloNumerosAzar,validosAzar);
    pasarMaso(arregloNumerosAzar,validosAzar,&almacenarNum);
    mostrar(&almacenarNum);
*/
\
#endif // alg_mezclar.h


#endif // header guard

