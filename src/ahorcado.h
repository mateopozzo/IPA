#ifndef AHORCADO_H
#define AHORCADO_H

/*	Contiene las librerias y prototipos que hacen al funcionamiento del
 *  juego ahorcado	*/

#include <string>
using namespace std;

void ahorcado(string P[]);
int reemplazoAhorcado(const string Prand, string & aux, string letra);
void cartelesIntentos(int avisoIntento, string letra, string ultimoIntento, int fila);
void dibujarMonigote(string aux, int errores);
void resultadoAhorcado(int errores, string Prand);
void imprimirBase();
void imprimirPiernaD();
void imprimirPiernaI();
void imprimirBrazoD();
void imprimirBrazoI();
void imprimirTorso();
void imprimirCabeza();

#endif
