#ifndef FGRALES_H
#define FGRALES_H

#include <windows.h>
#include <string>
using namespace std;

void gotoxy(SHORT x, SHORT y);
void identificar_espacios_al_final (string& palabra);
void pasar_minusculas (string& palabra);
int pot(int b, int e); //se uso en algun momento??
void limpiarRenglon(int nRenglon);
void intercambiar(int & a, int & b);

#endif
