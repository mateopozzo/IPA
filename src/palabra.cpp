#include "palabra.h"
#include "fgrales.h"

void nodo_palabra_swap(NodoPalabra *, NodoPalabra *);
void lista_palabra_mergesort(NodoPalabra *, NodoPalabra *);
void lista_palabra_merge(NodoPalabra *, NodoPalabra *, NodoPalabra *, NodoPalabra *);

Palabra
palabra_crear(string cadena)
{

	/*	Crea una Palabra y le asigna una cadena	*/
	
	Palabra palabra_nueva;
	
	palabra_nueva.cadena = cadena;
	palabra_nueva.apariciones = 1;
	
	return palabra_nueva;
	
}


string
palabra_cadena(Palabra & palabra)
{
	
	/*	Devuelve la Palabra per se	*/
	
	return palabra.cadena;
	
}

int
palabra_apariciones(Palabra & palabra)
{
	
	/*	Devuelve las apariciones de la palabra	*/
	
	return palabra.apariciones;
	
}

void
palabra_aumentar_apariciones(Palabra & palabra)
{

	/*	Aumenta la cantidad de apariciones de una Palabra	*/
	
	palabra.apariciones++;
	
}
	
PtrNodoPalabra
lista_palabra_crear()
{
	/*	Crea el puntero "maestro" de la lista	*/
	
	PtrNodoPalabra ptr_maestro = NULL;
	
	return ptr_maestro;
}

void
lista_palabra_destruir(NodoPalabra ** ptr_maestro)
{
	/*	Libera recursivamente la memoria que ocupa la lista	
	*	Utilizar al cerrar el programa	
	*	Reutilizar matriz y lista dinamica al reabrir estadisticas	*/
	
	if( *ptr_maestro == NULL )
		return;
	
	if( (*ptr_maestro)->ptr_nodo_palabra != NULL){
		printf("k\n");
		lista_palabra_destruir(&((*ptr_maestro)->ptr_nodo_palabra));
	}
	
	printf("k\n");
	delete (*ptr_maestro);
	printf("e\n");
	*ptr_maestro = NULL;
	return;
}

void
nodo_palabra_set(NodoPalabra * ptr_nodo, string cadena)
{
	
	/*	Recibe la direccion de un nuevo nodo y setea sus campos	*/
	
	ptr_nodo -> palabra = palabra_crear(cadena);
	ptr_nodo -> ptr_nodo_palabra = NULL;
	
}

void
lista_palabra_enlace_condicional( PtrNodoPalabra * ptr_maestro, string cadena )
{
	
	/*	Esta funcion recibe una cadena, la incluye a la lista enlazada no esta 
		ya enlazada sino aumenta la cantidad de apariciones	*/
	
	//	Creo un puntero a nodo iterador y auxiliar para facilitar linkeo final
	
	PtrNodoPalabra ptr = * ptr_maestro;
	bool esta = false;
	
	while( ptr != NULL and !esta ){
		
		if( palabra_cadena(ptr->palabra) == cadena ){
			esta = true;
			palabra_aumentar_apariciones(ptr -> palabra);
		}
		
		else	ptr = ptr -> ptr_nodo_palabra;
	}
	
	if(!esta){
		PtrNodoPalabra ptr_nodo_nuevo = new NodoPalabra;
		nodo_palabra_set(ptr_nodo_nuevo, cadena);
		if(ptr_nodo_nuevo != NULL)
			lista_palabra_enlace_inicio( ptr_maestro, ptr_nodo_nuevo );
	}
	return;
	
}

void
lista_palabra_enlace_inicio(NodoPalabra ** ptr_maestro, NodoPalabra * ptr_primer_nodo)
{
	/*	Recibe el puntero maestro y lo modifica para que apunte al primer nodo de la lista	*/
	
	if(ptr_primer_nodo != NULL){
	   ptr_primer_nodo -> ptr_nodo_palabra = (* ptr_maestro);
		(* ptr_maestro) = ptr_primer_nodo;
	}
	
	return;
}
	
void
lista_palabra_enlace_final(NodoPalabra ** ptr_fnl, NodoPalabra * nodo_palabra_nuevo)
{
	/*	Funcion NO ITERA, se debe pasar el nodo que apunta a final de lista y linkea	*/
	
	(* ptr_fnl) -> ptr_nodo_palabra = nodo_palabra_nuevo;
	(* ptr_fnl) = nodo_palabra_nuevo;
}

void
lista_palabra_ordenar(NodoPalabra * ptr_mtr)
{
	
	/*	Esta lista debe estar ordenada de mayor a menor por cantidad de apariciones,
		y en caso de empate, de mayor a menor por longitud, y en caso de empate, 
		alfabéticamente por letra de inicio.	*/
	/*	Recibe el puntero "maestro" de una lista dinamica de Palabra y las 
		ordena segun sus apariciones de manera descendente	*/
	
	bool APARICIONES, LONGITUD, ALFABETO;
	NodoPalabra *ptr_itr, *ptr_swp;
	
	while(ptr_mtr != NULL){
		
		ptr_swp = ptr_mtr;
		ptr_itr = ptr_mtr -> ptr_nodo_palabra;
		
		while(ptr_itr != NULL){
			
			APARICIONES = ptr_swp -> palabra.apariciones < ptr_itr -> palabra.apariciones;
			
			LONGITUD = (ptr_swp -> palabra.apariciones == ptr_itr -> palabra.apariciones)
						and ptr_swp -> palabra.cadena.size() < ptr_itr -> palabra.cadena.size(); 
			
			ALFABETO = (ptr_swp -> palabra.apariciones == ptr_itr -> palabra.apariciones)
						and ptr_swp -> palabra.cadena.size() == ptr_itr -> palabra.cadena.size()
						and ptr_swp -> palabra.cadena > ptr_itr -> palabra.cadena;
			
			if( APARICIONES || LONGITUD || ALFABETO )	ptr_swp = ptr_itr;
			
			ptr_itr = ptr_itr -> ptr_nodo_palabra;
		}
		
		if(ptr_swp != ptr_mtr)	nodo_palabra_swap(ptr_mtr, ptr_swp);
		
		ptr_mtr = ptr_mtr -> ptr_nodo_palabra;
		
	}
	
	
	return;
	
}

void
lista_imprimir_completa(NodoPalabra * ptr_maestro)
{
	PtrNodoPalabra ptr_aux = ptr_maestro;
	
	while(ptr_aux != NULL){
		
		printf("%s, aparece: %d\n", palabra_cadena(ptr_aux -> palabra).c_str(), palabra_apariciones(ptr_aux -> palabra));
		
		ptr_aux = ptr_aux -> ptr_nodo_palabra;
	}
}


	
void
nodo_palabra_swap(NodoPalabra *anterior, NodoPalabra *posterior)
{
	Palabra aux = anterior -> palabra;
	anterior -> palabra = posterior -> palabra;
	posterior -> palabra = aux;
}


void
lista_palabra_frecuencia(PtrNodoPalabra ptr_mtr, char c)
{
	
	/*	Dada una letra X, informar las 5 palabras con X como letra inicial,
		con mayor frecuencia (ordenadas de mayor a menor), y la cantidad
		de ocurrencias correspondientes.	*/
	
	int i=0;
	c = tolower(c);
	
	limpiarRenglon(7);
	gotoxy(2,7);
	printf("Palabra       -       Apariciones\n");
	
	while(ptr_mtr != NULL and i<5){
		if(tolower(ptr_mtr -> palabra.cadena.at(0)) == c){
			gotoxy(2,8+i);
			printf("%s", ptr_mtr -> palabra.cadena.c_str());
			gotoxy(28,8+i);
			printf("%d\n", ptr_mtr -> palabra.apariciones);
			i++;
		}
		ptr_mtr = ptr_mtr -> ptr_nodo_palabra;
	}
}

string
nodo_palabra_siguiente(PtrNodoPalabra & ptr_plb)
{
	/*	Devuelve la palabra del nodo y adelanta el puntero en la lista, borrando el nodo anterior
		tener cuidado con modificar el puntero maestro	*/
	
	NodoPalabra * ptr_aux = ptr_plb;
	
	string ret = ptr_plb -> palabra.cadena;
	
	ptr_plb = ptr_plb -> ptr_nodo_palabra;
	delete ptr_aux;
	return ret;
}

void
lista_palabra_iniciar_ms(NodoPalabra * ptr_mtr)
{
	
	//	Conclusion, en esta aplicacion mergesort agilizo el ordenamiento pero no fue una cantidad sustancial
	//	Agregar palabras a la lista controlando sin repetidos es la mayor fuente de retraso en el programa
	
	/*	Itera por la lista hasta obtener la direccion del ultimo elemento
		luego ingresa al merge sort	
		Paso necesario para encontrar mitad de la lista sin intentar acceder a campos de un puntero NULL	*/
	
	if( ptr_mtr == NULL ){
		printf("panic ms\n");
		return;
	}
	
	NodoPalabra * ptr_fnl = ptr_mtr;
	
	while(ptr_fnl -> ptr_nodo_palabra != NULL)
		ptr_fnl = ptr_fnl -> ptr_nodo_palabra;
	
	lista_palabra_mergesort(ptr_mtr, ptr_fnl);
	
	return;
}

void
lista_palabra_mergesort(NodoPalabra * ptr_ini, NodoPalabra * ptr_fnl)
{
	
	if(ptr_ini == ptr_fnl)	return;
	
	// Buscar mitad de la lista
	NodoPalabra *ptr_mtd = ptr_ini, *ptr_itr = ptr_ini -> ptr_nodo_palabra;
	while( ptr_itr != ptr_fnl ){
		ptr_itr = ptr_itr -> ptr_nodo_palabra;
		if(ptr_itr != ptr_fnl){
			ptr_mtd = ptr_mtd -> ptr_nodo_palabra;
			ptr_itr = ptr_itr -> ptr_nodo_palabra;
		}
	}
	
	lista_palabra_mergesort(ptr_ini, ptr_mtd);
	lista_palabra_mergesort(ptr_mtd -> ptr_nodo_palabra, ptr_fnl);
	
	lista_palabra_merge(ptr_ini, ptr_mtd, ptr_mtd ->ptr_nodo_palabra , ptr_fnl);
	
}

void 
lista_palabra_merge
(NodoPalabra *ptr_ini1, NodoPalabra *ptr_fnl1, NodoPalabra *ptr_ini2, NodoPalabra *ptr_fnl2)
{
	/*	Esta lista debe estar ordenada de mayor a menor por cantidad de apariciones,
		y en caso de empate, de mayor a menor por longitud, y en caso de empate, 
		alfabéticamente por letra de inicio.	*/
	
	NodoPalabra * ptr_aux = ptr_ini1, *ptr_dlt = NULL;
	NodoPalabra * lista_nueva = lista_palabra_crear();
	NodoPalabra * ptr_append;	//	Puntero guarda direccion de nodo final
	bool APARICIONES, LONGITUD, ALFABETO;
	
	//	Ordenamiento condicional
	while( ptr_ini1 != ptr_fnl1 -> ptr_nodo_palabra and ptr_ini2 != ptr_fnl2 -> ptr_nodo_palabra )
	{
		NodoPalabra * nodo_nuevo = new NodoPalabra;
		nodo_nuevo ->ptr_nodo_palabra = NULL;
		
		/*================================CONDICIONES====================================*/
		APARICIONES = ptr_ini1 -> palabra.apariciones > ptr_ini2 -> palabra.apariciones;
		
		LONGITUD = 	ptr_ini1 -> palabra.apariciones == ptr_ini2 -> palabra.apariciones
					and ptr_ini1 -> palabra.cadena.size() > ptr_ini2 -> palabra.cadena.size(); 
		
		ALFABETO = 	ptr_ini1 -> palabra.apariciones == ptr_ini2 -> palabra.apariciones
					and ptr_ini1 -> palabra.cadena.size() == ptr_ini2 -> palabra.cadena.size()
					and ptr_ini1 -> palabra.cadena < ptr_ini2 -> palabra.cadena;
		/*================================================================================*/
		
		
		if(APARICIONES || LONGITUD || ALFABETO ){
			nodo_nuevo -> palabra = ptr_ini1 -> palabra;
			
			if( lista_nueva == NULL ){
				lista_palabra_enlace_inicio(&lista_nueva, nodo_nuevo);
				ptr_append = lista_nueva;
			}
			
			else lista_palabra_enlace_final(&ptr_append, nodo_nuevo);
			ptr_ini1 = ptr_ini1 -> ptr_nodo_palabra;
		}
		else{
			nodo_nuevo -> palabra = ptr_ini2 -> palabra;
			
			if( lista_nueva == NULL ){
				lista_palabra_enlace_inicio(&lista_nueva, nodo_nuevo);
				ptr_append = lista_nueva;
			}
			
			else lista_palabra_enlace_final(&ptr_append, nodo_nuevo);	
			ptr_ini2 = ptr_ini2 -> ptr_nodo_palabra;
		}
		//printf("dentro de condicion\n");
	}
	
	//	Ordenamiento de elementos restantes
	while( ptr_ini1 != ptr_fnl1 -> ptr_nodo_palabra ){
		NodoPalabra * nodo_nuevo = new NodoPalabra;
		nodo_nuevo ->ptr_nodo_palabra = NULL;
		nodo_nuevo -> palabra = ptr_ini1 -> palabra;
		
		if( lista_nueva == NULL ){
			lista_palabra_enlace_inicio(&lista_nueva, nodo_nuevo);
			ptr_append = lista_nueva;
		}
		
		else lista_palabra_enlace_final(&ptr_append, nodo_nuevo);
		ptr_ini1 = ptr_ini1 -> ptr_nodo_palabra;
		//printf("dentro de condicion1\n");
	}
	
	while( ptr_ini2 != ptr_fnl2 -> ptr_nodo_palabra ){
		NodoPalabra * nodo_nuevo = new NodoPalabra;
		nodo_nuevo ->ptr_nodo_palabra = NULL;
		nodo_nuevo -> palabra = ptr_ini2 -> palabra;
		
		if( lista_nueva == NULL ){
			lista_palabra_enlace_inicio(&lista_nueva, nodo_nuevo);
			ptr_append = lista_nueva;
		}
		
		else lista_palabra_enlace_final(&ptr_append, nodo_nuevo);
		ptr_ini2 = ptr_ini2 -> ptr_nodo_palabra;
		//printf("dentro de condicion2\n");
	}
	
	//	Copiar ordenado en lista original
	while( ptr_aux != ptr_fnl2 -> ptr_nodo_palabra ){
		
		ptr_aux -> palabra = lista_nueva -> palabra;
		
		ptr_dlt = lista_nueva;
		lista_nueva = lista_nueva -> ptr_nodo_palabra;
		
		delete ptr_dlt;
		
		ptr_aux = ptr_aux -> ptr_nodo_palabra;
		
	}
}
	





