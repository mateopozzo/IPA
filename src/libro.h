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

struct Palabra{
	string cadena;
	int apariciones;
};

struct NodoPalabra{
	Palabra palabra;
	NodoPalabra * ptr_nodo_palabra;
};
typedef NodoPalabra * PtrNodoPalabra;

/*	Funciones para el manejo de archivo libro
 *	Se considero que un libro solo se puede leer
 *	Pero no escribir	*/
Libro libro_declarar(string &, const char * );		//	Se instancia un libro y se le asigna a sus campos la informacion correspondiente
bool libro_iniciar_archivo(Libro &);				//	Recibe un libro con campos cargados y lo abre en el manejador de libro
bool libro_finalizar_archivo();						//	Cierra el flujo de entrada del libro
bool libro_leer_linea(string &);					//	Recupera una linea de texto del libro
bool libro_leer_caracter(char *);					//	Recupera un carater de texto del libro
string libro_titulo(Libro &);						//	Devuelve una cadena con el titulo del libro


/*	Funciones de la estructura "Palabra"	*/
Palabra palabra_crear(string);
string palabra_cadena(Palabra &);
int palabra_apariciones(Palabra &);
void palabra_aumentar_apariciones(Palabra *);


/*	Funciones de creacion y destruccion de lista	*/
PtrNodoPalabra lista_palabra_crear();								//	Devuelve el puntero "maestro" a una lista vacia						
void lista_palabra_destruir(NodoPalabra ** ptr_maestro);			//	Libera la memoria que contiene los nodos de la lista
void nodo_palabra_set(NodoPalabra * ptr_nodo, string cadena);		//	Recibe la direccion de un nuevo nodo y setea sus campos


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
void lista_imprimir_completa(NodoPalabra * ptr_maestro);			//	Funcion de testeo, imprime todas los nodos de la lista

#endif
