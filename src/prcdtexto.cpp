#include "prcdtexto.h"
#include "fgrales.h"
#include "palabra.h"
#include "archivo.h"
#include <conio.h>
#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#define ALFABETO_ITALIANO "aäbcdefghijklmnoöpqrstuvwxyzAÄBCDEFGHIJKLMNOÖPQRSTUVWXYZ"
#define NO_ES_LIBRO_VALIDO 	!(opcion_libro == "1" || opcion_libro == "2" \
							|| opcion_libro == "x" || opcion_libro == "X")

#define HAY_PALABRA (plb_inicio != -1)
#define ES_VALIDA ((plb_inicio < plb_final) || (!plb_inicio and plb_final == -1))

typedef int* arreglo;
typedef int** matriz;

//	Arreglo de libros disponibles
Libro arreglo_libros[2];

//  Prototipos de funciones internas
void estadisticas_nivel_caracteres(Libro &);
void arreglo_agrandar(arreglo &, int &, int);
void arreglo_set_nulo(int *, int *);
void conteo_caracteres(char *, string &, arreglo &, int &, int &);
void tabla_frecuencias_salida(string, int *, int);


void estadisticas_nivel_palabras(Libro &);
void matriz_iniciales_imprimir(int **, int);
int ** matriz_iniciales_creacion();
string aminusq(string);
void matriz_resize(matriz &, int &, int &);
bool analisis(	int ** ptr_mtrz, int plb_mayor, float & promedio, float & vocales_prc, float & consonantes_prc);
void palabras_mayor_frecuencia_salida(PtrNodoPalabra , Libro &);


//	Implementacion de funciones
void
seleccion_libro(int opcion)
{
	/*	Permite elegir al usuario entre los dos libros disponibles	*/
	
	bool seguir = true;
	int i, nlibro;
	string opcion_libro;
	
	//	Parametros de los libros de catedra
	string titulo1 = "Divina commedia";
	string titulo2 = "Le aventure di Pinocchio";
	const char path1[] = "..\\doc\\libros\\Divina commedia.txt";
	const char path2[] = "..\\doc\\libros\\Le aventure di pinocchio.txt";
	
	arreglo_libros[0] = libro_declarar(titulo1, path1);
	arreglo_libros[1] = libro_declarar(titulo2, path2);
	
	//  Validacion de input de usuario
	do{
		system("cls");
		cout << "Que libro en italiano desea analizar: \n\n";
		
		for(i=0; i<2; i++)
			printf("%d: %s\n", i+1, libro_titulo(arreglo_libros[i]).c_str());
		cout << "X para salir\n";
		
		do{
			limpiarRenglon(5);
			gotoxy(0,5);
			cin >> opcion_libro;
		}while( NO_ES_LIBRO_VALIDO );
		
		char opcion_c = opcion_libro.at(0);
		
		switch(opcion_c){
		case '1':
		case '2':
			//  Conversion de seleccion al indice de arreglo del libro
			nlibro = int(opcion_c - '1');
			
			system("chcp 1252"); // Asegura que la consola del usuario tenga codepage latina
			libro_iniciar_archivo(arreglo_libros[nlibro]);
			
			if(opcion == 1)
				estadisticas_nivel_caracteres(arreglo_libros[nlibro]);
			
			else 
				estadisticas_nivel_palabras(arreglo_libros[nlibro]);
			
			system("chcp 850");	//	Devuelve la consola a codepage ASCII
			
			break;
		case 'x':
		case 'X':
			seguir = false;
		}
	}while( seguir );
	
	return; 
}


/*	Implementaciones estadisticas nivel caracteres	*/
void
estadisticas_nivel_caracteres(Libro & libro)
{
	system("cls");
	cout << libro_titulo(libro) << endl;
	
	/*========================================================================*/
	//	Cadena utilizada para extraer lineas del libro
	//string libro_linea;
	/*========================================================================*/
	
	//	Variable para leer caracter del libro
	char libro_caracter;
	
	//	Cadena utilizada para almacenar caracteres extraidos
	string caracteres_libro;
	caracteres_libro.clear();
	
	//	Variables de tamaños fisico y logico
	int tf = 50, tl=0; 
	//	Arreglo dinamico
	int * ptr_arreglo_apariciones = (int*) malloc(sizeof(int) * tf);

	if(ptr_arreglo_apariciones == NULL){
		printf("Error al ejecutar el proceso\n");
		Sleep(2000);
		return;
	}
	
	else{
		//	Seteo todas las apariciones a 0
		arreglo_set_nulo(ptr_arreglo_apariciones, ptr_arreglo_apariciones + tf);
		
		while( libro_leer_caracter(&libro_caracter) && ptr_arreglo_apariciones != NULL )
			conteo_caracteres(&libro_caracter, caracteres_libro, ptr_arreglo_apariciones, tl, tf);
		
		/*========================================================================*/
		/*while(libro_leer_linea(libro_linea))
			conteo_caracteres(libro_linea, caracteres_libro, ptr_arreglo_apariciones, tl, tamanho_fisico);*/
		/*========================================================================*/
		
		// 	Salida consola y grabado en archivo de texto simultaneo
		string archivo_estadistica_direccion = "..\\doc\\estadisticas\\" + libro_titulo(libro) + "\\frecuencia.txt";
		
		//	Setup de archivo
		if( archivo_setup_escritura(archivo_estadistica_direccion.c_str()) ) 	
			tabla_frecuencias_salida(caracteres_libro, ptr_arreglo_apariciones, tl);
		
		else	
			printf("No se pudo abrir el archivo %s\n", archivo_estadistica_direccion.c_str());
	}
	
	//	Limpieza de memoria utilizada
	archivo_cerrar_escritura();
	libro_finalizar_archivo();
	free(ptr_arreglo_apariciones);
	ptr_arreglo_apariciones = NULL;
	
	return ;
}


void
arreglo_agrandar(arreglo & ptr_arreglo, int & tf, int incremento)
{
	/*	Agranda el tamaño fisico del arreglo y rellena los nuevos espacios
	 *  nuevos con 0	*/
	
	tf += incremento;
	
	ptr_arreglo = (int*) realloc( ptr_arreglo, sizeof(int) * (tf));
	
	if( ptr_arreglo == NULL ){
		printf("No se pudo relocalizar el arreglo\n");
		free(ptr_arreglo);
		abort();
	}
	
	arreglo_set_nulo(ptr_arreglo+tf-10, ptr_arreglo+tf);
	
	return;
}


void
arreglo_set_nulo(int * array, int * array_end)
{
	/*	Setea todos los valores entre un inicio y un fin dado al valor nulo	*/
	
	for( ; array != array_end; array++ )
		(*array) = 0;
	
	return;
}


void
conteo_caracteres(char * libro_caracter, string & caracteres_libro, arreglo & ptr_arreglo_apariciones, int & tl, int & tf)
{
	/*	Recibe un caracter extraido del libro y lo anota	*/
	
	int indice;
	
	indice = caracteres_libro.find( *libro_caracter );
	
	if( indice != -1 )
		/*	Si el caracter ya fue encontrado, aumento la posicion 
		 *	ocupa en el contador*/
		ptr_arreglo_apariciones[indice]++;
	
	
	else{
		/*	Si el caracter de la linea no estaba previamente en la
		 *	cadena, se suma al final	*/
		ptr_arreglo_apariciones[tl]++;
		tl++;
		
		caracteres_libro += *libro_caracter;
	}
	
	if(tf == tl){
		/*	Si el tamaño fisico del arreglo es alcanzado por el logico, 
		 *  se realiza una operacion de agrandado del arreglo usando
		 *  realloc  */
		arreglo_agrandar(ptr_arreglo_apariciones, tf, 10);
		
	}
}





void
tabla_frecuencias_salida(string caracteres_libro, int * ptr_arreglo_apariciones, int tl)
{
	system("mode con cols=100 lines=80");
	system("color F0");
	
	int i, j, pos_mayor;
	string linea_cargar;
	
	archivo_cargar_linea("TABLA DE FRECUENCIAS\n\nApariciones\tCaracter\n\n");
	printf("TABLA DE FRECUENCIAS\n\nApariciones\tCaracter\n\n");
	
	for( i = 0; i < tl; i++ ){
		pos_mayor = 0;
		for(j = 0; j < tl; j++ ){
			/*	Busco el mayor elemento del arreglo	*/
			if( *(ptr_arreglo_apariciones + j) > *(ptr_arreglo_apariciones + pos_mayor) ){
				pos_mayor = j;
			}
		}
		
		printf("%d\t\t%c\t\t\n", *(ptr_arreglo_apariciones + pos_mayor), caracteres_libro.at(pos_mayor));
		
		linea_cargar = to_string(*(ptr_arreglo_apariciones + pos_mayor));
		linea_cargar += "\t\t";
		linea_cargar +=	caracteres_libro.at(pos_mayor);
		linea_cargar += "\n";
		
		archivo_cargar_linea(linea_cargar);
		
		*(ptr_arreglo_apariciones + pos_mayor) = 0;
	}
	cout<< "Puedes revisar cualquier estadistica realizada por IPA en "
		<< "la carpeta de estadisticas del proyecto\n(IPA/doc/estaditicas)\n";
	
	char caux = 1;
	while( caux != 13)	caux = getch();
	
	system("mode con cols=100 lines=30");
	
	return;
}


/*	Implementaciones estadisticas nivel palabras	*/
void
estadisticas_nivel_palabras(Libro & libro)
{
	system("cls");
	
	/*	Creacion de matriz de [largo; caracter incial], el analisis de 
	 *  frecuencia de letras nos permitio descubrir que no existe palabra en 
	 *  los libros que comience con un caracter acentuado o especial, esto 
	 *  se tuvo en cuenta al desarrollar el tamaño de la matriz	*/
	
	cout << libro_titulo(libro) << "\nLeyendo...";
	
	string linea, palabra;
	int plb_inicio, plb_final, plb_mayor = 10, plb_tam;
	PtrNodoPalabra lista_dinamica_palabras = NULL;
	
	//	Creacion de matriz (arreglo de arreglo de enteros)
	int ** ptr_mtrz = matriz_iniciales_creacion();
	
	if(ptr_mtrz == NULL)
		return;
	
	else {
		lista_dinamica_palabras = lista_palabra_crear();
		
		while( libro_leer_linea(linea) ){
			
			while( plb_final != -1 ){
				
				plb_inicio = linea.find_first_of(ALFABETO_ITALIANO);
				plb_final = linea.find_first_not_of(ALFABETO_ITALIANO);
				
				if( HAY_PALABRA && ES_VALIDA ){
					
					//	Es la ultima palabra del renglon/linea
					if( plb_final == -1 )
						plb_tam = linea.length();
					
					//	Caso contrario
					else	
						plb_tam = plb_final - plb_inicio;
					
					
					/*	Si la palabra leida es mas larga que la mayor 
					 *  anterior se pide mas memoria en tiempo de ejecucion	*/
					if( plb_tam > plb_mayor )
						matriz_resize(ptr_mtrz, plb_tam, plb_mayor);
					
					
					//	Conteo de matriz[largo; caracter inicial]
					ptr_mtrz[plb_tam-1][tolower(linea.at(plb_inicio))-'a']++;
					
					/*	Se extrae la palabra de la cadena leida y se la agrega
					 *  a la lista enlazada	*/
					palabra = aminusq(linea.substr(plb_inicio, plb_tam));
					lista_palabra_enlace_condicional(& lista_dinamica_palabras, palabra);
					
				}
				//  "Corte" de la linea leida
				linea = linea.substr(plb_final+1);
				
			}
			plb_final = plb_inicio = 0;
			
		}
		
		/*	Impresion de matriz	*/
		matriz_iniciales_imprimir(ptr_mtrz, plb_mayor);
		
		cout << libro_titulo(libro) << "\n";
		
		/*	Ordenamiento de la lista enlazada	*/
		printf("\nOrdenando apariciones...\n");
		lista_palabra_iniciar_ms(lista_dinamica_palabras);
		limpiarRenglon(2);
		gotoxy(0, 2);
		
		float promedio, vocales_prc, consonantes_prc;
		string cargar_palabra;
		
		/*	Se llama a la funcion de calculo de porcentajes y se muestran estadisticas en pantalla	*/
		if(analisis(ptr_mtrz, plb_mayor, promedio, vocales_prc, consonantes_prc)){
			cout << endl << fixed << setprecision(0) << "Promedio de longitud: " << promedio << "\n\n";
			
			//	Impresion de las palabras segun aparicion
			palabras_mayor_frecuencia_salida(lista_dinamica_palabras, libro);
			
			cout<< fixed << setprecision(2) << endl 
				<< "Porcentaje de vocales: " << vocales_prc << "%" << endl
				<< "Porcentaje de consonantes: " << consonantes_prc << "%" << endl;
		}
	}
	
	char c;
	printf("\n\nPresione enter para volver al menu\n");
	do{
		c = getch();
	} while( c != 13);
	
	//	Liberacion de memoria
	printf("Borrando archivos basura...\n");
	
	archivo_cerrar_escritura();
	libro_finalizar_archivo();
	
	//	Liberacion de matriz
	for( int i = 0; i<plb_mayor; i++ )
		delete[] ptr_mtrz[i];
	delete[] ptr_mtrz;
	ptr_mtrz = NULL;
	
	lista_dinamica_palabras = NULL;
	libro_finalizar_archivo();
	
	cout<< "Puedes revisar cualquier estadistica realizada por IPA en "
		<< "la carpeta de estadisticas del proyecto\n(IPA/doc/estaditicas)\n";
	
	return;
}


void
matriz_iniciales_imprimir(int **ptr_mtrz, int largo_max)
{	
	system("cls");
	system("mode con: cols=300 lines=30");
	
	gotoxy(0, 0);
	int i, j;
	
	printf("Matriz de inciales\n");
	
	for( i=0; i<26; i++ ){
		gotoxy(4+i*6, 2);
		printf("%c", ('a'+i));
	}
	printf("\n");
	
	for( i=0; i<largo_max; i++ ){
		gotoxy(0, i+3);
		printf("%d", i+1);
		for(j=0; j<26; j++){
			gotoxy(4+j*6, 3+i);
			printf("%d", ptr_mtrz[i][j]);
		}
		printf("\n");
	}	
	
	printf("Presione enter para continuar el analisis\n");
	
	char c;
	while( (c=getch()) != 13 );
	
	for(i=0; i<largo_max; i++)
		limpiarRenglon(i);
	
	system("mode con: cols=100 lines=30");
}


int **
matriz_iniciales_creacion()
{
	int ** ptr_mtrz = new arreglo[10];
	
	if(ptr_mtrz == NULL){
		cout << "Fallo" << endl;
		Sleep(2000);
		return 0;
	}
	
	for( int i = 0; i < 10; i++){
		ptr_mtrz[i] = new int[26];
		arreglo_set_nulo(ptr_mtrz[i], ptr_mtrz[i] + 26);
	}
	
	return ptr_mtrz;
}


string
aminusq(string palabra)
{	
	/*	Convierte una cadena entera a minuscula	*/
	
	for( int i=0; i<palabra.length(); i++ ){
		if(isalpha(palabra.at(i)))
			palabra[i] = tolower(palabra.at(i));
	}
	
	return palabra;
}


void
matriz_resize(matriz & ptr_mtrz, int & plb_tam, int & plb_mayor)
{
	/*	Amplia la cantidad de filas (arreglos) que contiene la matriz	*/
	
	ptr_mtrz = ( int ** ) realloc( ptr_mtrz, (sizeof( int * ) * plb_tam) );
	
	if(ptr_mtrz == NULL){
		cout << "No se puedo relocalizar la matriz" << endl;
		Sleep(2000);
		return;	
	}
	
	for( int i = plb_mayor; i < plb_tam; i++){
		ptr_mtrz[i] = (int *) malloc( sizeof(int) * 26 );
		arreglo_set_nulo(ptr_mtrz[i], ptr_mtrz[i]+26);
	}
	
	plb_mayor = plb_tam;	
}


bool
analisis
(int ** ptr_mtrz, int plb_mayor, float & promedio, float & vocales_prc, float & consonantes_prc){
	
	/*	Calculo de longitud promedio, porcentaje de vocales y consonantes del libro elegido	*/
	
	int i, j, vocales_tot, consonantes_tot;
	
	promedio = vocales_tot = consonantes_tot = 0;
	
	/*	Seguridad de puntero a matriz	*/
	if(ptr_mtrz != NULL)
	{
		for( i=0; i<plb_mayor; i++)
		{
			for( j=0; j<26; j++ )
			{
				if( !i || i == 4 || i == 8 || i == 14 || i == 20 )
					vocales_tot += ptr_mtrz[i][j];
				
				else 
					consonantes_tot += ptr_mtrz[i][j];
				
				promedio += ptr_mtrz[i][j] * i;
			}
		}
		vocales_prc = (float) vocales_tot / (consonantes_tot + vocales_tot) * 100.0;
		consonantes_prc = (float) consonantes_tot / (consonantes_tot + vocales_tot) * 100.0;
		
		promedio = ceil( promedio / (float)(vocales_tot + consonantes_tot));
	}

	else printf("No se puede calcular el promedio\n");
	
	return (ptr_mtrz != NULL);
}
	
	
void
palabras_mayor_frecuencia_salida(PtrNodoPalabra lista_dinamica_palabras, Libro & libro)
{
	/*	Salida de 5 palabras de mayor aparicion por consola y ordenadas de 
	 *  de forma descendente en archivo	*/
	
	string c;
	bool validacion;
	
	do{
		limpiarRenglon(6);
		gotoxy(0,6);
		cout << "Mostrar 5 mas comunes que empiezan con: ";
		
		gotoxy(42,6);
		cin >> c;
		validacion = c.length() != 1 or !isalpha(c.at(0));
		
		if(validacion){
		cout << "Letra no valida\n";
		gotoxy(42,6);
		cout << " ";
		}
		
	}while( validacion );
	
	//	Impresion en consola
	lista_palabra_frecuencia(lista_dinamica_palabras, c.at(0));
	
	string aux;
	string cargar_palabra;
	aux = toupper(c.at(0));
	string path = "..\\doc\\estadisticas\\" + libro_titulo(libro) + "\\palabras" + aux +".txt";
	
	//	Escritura de archivo
	if(archivo_setup_escritura(path.c_str())){
		while( lista_dinamica_palabras != NULL ){
			cargar_palabra = nodo_palabra_siguiente(lista_dinamica_palabras);
			if( tolower(cargar_palabra.at(0)) == tolower(c.at(0)) )
				archivo_cargar_linea(cargar_palabra + "\n");
		}
	}
	
	else
		cout << "No se pudo abrir el path: " + path << endl;
}
