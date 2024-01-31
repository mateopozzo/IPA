#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

ifstream manejador;
ofstream escritor;


archivo setup(string nombre, string nombreF){
	archivo aux;
	aux.nombre = nombre;
	aux.nombrefisico = nombreF;
	aux.cantidad=0;
	return aux;
}
	
bool apertura(archivo X){
	manejador.open(X.nombrefisico.c_str());
	if (manejador.fail())
		return false;
	else
		return true;
}
	
string leerLinea(archivo &X, bool &final){
	string linea;
	final=false;
	if (manejador.eof()==false){
		getline(manejador, linea);
		X.cantidad++;
    }
	else
		final=true;
	return linea;
}
	
char leerCaracter(archivo & x, bool & final){
	char c;
	manejador.get(&c, 2, EOF);
	final=(!manejador.eof());
	return c;
}

bool cierre(archivo X){
	manejador.close();
	if (manejador.fail())
		return false;
	else
		return true;
}
	
int leidas(archivo X){
	return X.cantidad;
}
	
	
/*====Funciones que amplian el TDA original====*/
	
bool archivo_setup_escritura(const char * direccion){
	
	/*	Abre el archivo si es que no esta abierto ya	*/
	
	if(!escritor.is_open())	escritor.open(direccion);
	
	return escritor.is_open();
}
	
void archivo_cerrar_escritura(){
	
	/*	Cierra el archivo si es que esta abierto */
	
	if( escritor.is_open() )	escritor.close();
	
}

void archivo_cargar_linea(string linea){
	
	/*	Escibre una cadena que recibe si el archivo esta abierto	*/
	
	if( escritor.is_open() )	escritor << linea;
	
}

