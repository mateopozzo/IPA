#ifndef FGRALES_H
#define FGRALES_H

/*	Contiene librerias y prototipos de funciones utiles se presentan en 
 *	diversos contextos	*/

#include <windows.h>
#include <string>
using namespace std;

void gotoxy(SHORT x, SHORT y);
void identificar_espacios_al_final (string& palabra);
void pasar_minusculas (string& palabra);
void limpiarRenglon(int nRenglon);
void intercambiar(int & a, int & b);
bool esIntentoInval(string letra);

#endif
