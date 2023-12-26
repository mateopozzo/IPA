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


/*	Funciones de la estructura "Palabra"	*/

Palabra palabra_crear(string);										
string palabra_cadena(Palabra &);
int palabra_apariciones(Palabra &);
void palabra_aumentar_apariciones(Palabra *);


/*	Funciones de creacion y destruccion de lista	*/

PtrNodoPalabra lista_palabra_crear();								
void lista_palabra_destruir(NodoPalabra ** ptr_maestro);			
void nodo_palabra_set(NodoPalabra * ptr_nodo, string cadena);


/*	Funciones de enlace de nodos	*/

void lista_palabra_enlace(NodoPalabra ** , NodoPalabra * );			//	Realiza un enlace de acceso aleatorio
void lista_palabra_enlace_inicio(NodoPalabra **, NodoPalabra *);	//	Realiza un enlace al inicio de la lista
void lista_palabra_enlace_final(NodoPalabra **, NodoPalabra * );	//	Realiza un enlace al final de la lista (necesita puntero de cola)
void lista_palabra_enlace_condicional(NodoPalabra **, string);		//	Enlaza una palabra unicamente no esta ya presente en la lista


/*	Funciones de ordenamiento de lista	*/

void lista_palabra_ordenar(NodoPalabra *);							//	Ordena la lista dinamica en funcion de la cantidad de apariciones de cada palabra, de su longitud, o de su orden alfabetico
void lista_palabra_iniciar_ms(NodoPalabra *);						//  Funcion de arranque ordenamiento mergesort


/*	Funciones de muestra por consola de la lista	*/

void lista_palabra_frecuencia(PtrNodoPalabra, char);				//	Muestra las 5 palabras de mayor apariciones que comienan con el caracter dado
string nodo_palabra_siguiente(PtrNodoPalabra &);					// 	Lectura destructiva de la palabra del primer nodo
	
void lista_imprimir_completa(NodoPalabra * ptr_maestro);


#endif
