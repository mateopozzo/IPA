#ifndef ARCHIVO_H
#define ARCHIVO_H

/*	Contiene los prototipos y librerias brindados por la catedra
 *  y otros implementados por los integrantes del grupo	*/

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
char leerCaracter(archivo & x, bool & final);
int leidas(archivo x);
bool cierre(archivo x);

/*	Funciones que amplian el tda	*/
bool archivo_setup_escritura(const char * direccion);	//	Abre el flujo de escritura del archivo
void archivo_cargar_linea(string linea);				//	Escribe una linea de texto al archivo
void archivo_cerrar_escritura();						//	Cierra el flujo de escritura del archivo

#endif
