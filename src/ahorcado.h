#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
using namespace std;

int reemplazoAhorcado(const string Prand, string & aux, string letra);
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
