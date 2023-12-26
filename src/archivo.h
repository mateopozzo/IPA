#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct archivo{
	string nombre;
	string nombrefisico;
	int cantidad;
};

archivo setup(string nombre, string nombreF);
bool apertura(archivo x);
string leerLinea(archivo & x, bool & final);
int leidas(archivo x);
bool cierre(archivo x);

void archivo_cargar_linea(string linea);
bool archivo_setup_escritura(const char * direccion);
void archivo_cerrar_escritura();

#endif
