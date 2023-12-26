#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <fstream>
using namespace std;

//TDA LIBRO
struct Libro{
	string titulo;
	char path[100];
};

Libro libro_declarar(string & libro_titulo, const char * libro_path);
bool libro_iniciar_archivo(Libro & libro);
bool libro_finalizar_archivo();
bool libro_leer_linea(string & linea);
void libro_titulo_imprimir(Libro & libro);
string libro_titulo(Libro & libro);


/* FUNCIONES QUE HICE QUE CREO QUE NO VAMOS A USAR PERO POR LAS DUDAS LAS DEJO AHI


struct NodoLibro{
	wstring linea;
	NodoLibro * linea_sig;
};

typedef NodoLibro * PtrNodoLibro;
NodoLibro * libro_nodo_crear();
NodoLibro * libro_leer_completo(wifstream & libro_archivo);
void libro_nodo_linea_cambiar(PtrNodoLibro & libro_nodo, wstring & linea);
void libro_nodo_apuntador_cambiar(NodoLibro & libro_nodo_previo, NodoLibro & libro_nodo_posterior);
void libro_nodo_enlace_final(NodoLibro & libro_nodo);
void libro_nodo_enlace_principio(PtrNodoLibro * libro_ptr_maestro, PtrNodoLibro & libro_ptr_nodo_nuevo);
void libro_imprimir_entero(NodoLibro * libro_ptr_maestro);
void libro_reescribir_entero(NodoLibro * libro_ptr_maestro);
*/

#endif
