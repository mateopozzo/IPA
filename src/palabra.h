#ifndef PALABRA_H
#define PALABRA_H

#include <string>
using namespace std;

struct Palabra{
	string cadena;
	int apariciones;
};

struct NodoPalabra{
	Palabra palabra;
	NodoPalabra * ptr_nodo_palabra;
};

typedef NodoPalabra * PtrNodoPalabra;

Palabra palabra_crear(string);									//	Setea la cadena dada y una aparicion a una Palabra 
string palabra_cadena(Palabra &);								//	Devuelve la cadena que contiene la Palabra
int palabra_apariciones(Palabra &);								//	Devuelve las apariciones de una palabra dada
void palabra_aumentar_apariciones(Palabra *);					//	Aumenta la cantidad de apariciones de una Palabra

PtrNodoPalabra lista_palabra_crear();							//	Devuelve un puntero "maestro" al inicio de una nueva lista dinamica
void nodo_palabra_set(NodoPalabra * ptr_nodo, string cadena);	//	Devuelve un puntero a un nuevo nodo
void lista_palabra_enlace(NodoPalabra ** , NodoPalabra * );		//	Realiza un enlace
void lista_palabra_enlace_inicio(NodoPalabra **, NodoPalabra *);//	Realiza un enlace al inicio de la lista
void lista_palabra_enlace_final(NodoPalabra **, NodoPalabra * );	//	(REVISAR UTILIDAD) ???? Realiza un enlace al final de la lista
void lista_palabra_enlace_condicional(NodoPalabra **, string);	//	Enlaza una palabra unicamente no esta ya presente en la lista
void lista_palabra_ordenar(NodoPalabra *);						//	Ordena la lista dinamica en funcion de la cantidad de apariciones de cada palabra, de su longitud, o de su orden alfabetico
void lista_palabra_iniciar_ms(NodoPalabra *);
void lista_palabra_frecuencia(PtrNodoPalabra, char);			//	Muestra las 5 palabras de mayor apariciones que comienan con el caracter dado
string nodo_palabra_siguiente(PtrNodoPalabra &);				// 	Lectura destructiva de la palabra del primer nodo
	
void mostrar_todas_las_palabras(NodoPalabra * ptr_maestro);


#endif
