#ifndef LIBRO_H
#define LIBRO_H

/*	Contiene las librerias y prototipos que hacen al TDA Libro, usado para
 * 	manipular la ubicacion y lectura del archivo	*/

#include <string>
#include <fstream>
using namespace std;

struct Libro{
	string titulo;
	char path[100];
};

Libro libro_declarar(string & libro_titulo, const char * libro_path);
bool libro_iniciar_archivo(Libro & libro);
bool libro_finalizar_archivo();
bool libro_leer_linea(string & linea);
bool libro_leer_caracter(char * c);
void libro_titulo_imprimir(Libro & libro);
string libro_titulo(Libro & libro);

#endif
