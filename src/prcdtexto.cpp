#include "prcdtexto.h"
#include "fgrales.h"
#include "palabra.h"
#include "archivo.h"
#include <wchar.h>
#include <conio.h>
#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

Libro arreglo_libros[2];

void estadisticas_tabla_frecuencia(Libro &);
void estadisticas_nivel_palabras(Libro &);
bool analisis(int ** ptr_mtrz, int plb_mayor, float & promedio, float & vocales_prc, float & consonantes_prc);
string aminusq(string);

void seleccion_libro(int opcion){
	
	/*	El usuario setea que libro quiere estudiar estadisticamente entre un maximo de diez	*/
	
	bool seguir = true;
	int i, nlibro;
	string opcion_libro;
	
	string titulo1 = "Divina commedia", titulo2 = "Le aventure di Pinocchio";
	char path1[] = "..\\doc\\libros\\Divina commedia.txt", path2[] = "..\\doc\\libros\\Le aventure di pinocchio.txt";
	arreglo_libros[0] = libro_declarar(titulo1, path1);
	arreglo_libros[1] = libro_declarar(titulo2, path2);
	
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
		}while(!(opcion_libro == "1" || opcion_libro == "2" || opcion_libro == "x" || opcion_libro == "X"));
		
		char SWITCH = opcion_libro.at(0);
		switch(SWITCH){
			
		case '1':
		case '2':
			nlibro = int(SWITCH - '1');
			system("cls");
			libro_iniciar_archivo(arreglo_libros[nlibro]);
			if(opcion == 1)
				estadisticas_tabla_frecuencia(arreglo_libros[nlibro]);
			else 
				estadisticas_nivel_palabras(arreglo_libros[nlibro]);
			break;
		case 'x':
		case 'X':
			seguir = false;
		}
	}while( seguir );
	
	return; 
}

void estadisticas_tabla_frecuencia(Libro & libro){
	
	/*	Calcula la cantidad de apariciones de cada caracter presente en el libro y finalmente muestra por pantalla la cantidad en forma descendente*/
	cout << libro_titulo(libro) << endl;
	
	
	string libro_linea, caracteres_libro;
	int tamanho_fisico = 50, i, j, tl=0; 
	int * ptr_arreglo_apariciones = (int*) malloc(sizeof(int) * tamanho_fisico);
		
	if(ptr_arreglo_apariciones == NULL)
		printf("Error al ejecutar el proceso\n");
	
	else{
		
		for(i = 0; i<tamanho_fisico; i++)
			*(ptr_arreglo_apariciones + i) = 0;
		
		while(libro_leer_linea(libro_linea)){
			for(i = 0; i < libro_linea.length(); i++){
				j = caracteres_libro.find(libro_linea.at(i));
				
				if( j != -1){
					/*	Si el caracter de la linea esta en la cadena, calculo la posicion que ocupa en ella y sumo uno en la misma posicion del arreglo que cuenta apariciones	*/
					(*(ptr_arreglo_apariciones + j))++;
				}
				
				else{
					/*	Si el caracter de la linea no esta en la cadena, sumo uno en el extremo del tamaño físico del arreglo de cantidad de apariciones, aumento el tl, y concateno el caracter al final de la cadena	*/
					(*(ptr_arreglo_apariciones + tl))++;
					tl++;
					caracteres_libro += libro_linea.at(i);
				}
				
				if(tamanho_fisico == tl){
					/*	Si el tamaño fisico del arreglo es alcanzado por el logico, se realiza una operacion de agrandado del arreglo, en donde un auxiliar guarda sus valores
						temporalmente hasta borrar el anterior, crear uno de 10 posiciones mas grande y volver a volcar los datos a este*/
					tamanho_fisico += 10;
					int * ptr_arreglo_aux = (int*) realloc(ptr_arreglo_apariciones, sizeof(int)*tamanho_fisico);
					
					if(ptr_arreglo_aux == NULL){
						printf("No se pudo relocalizar el arreglo\n");
						free(ptr_arreglo_apariciones);
						return ;
					}
					
					ptr_arreglo_apariciones = ptr_arreglo_aux;
					ptr_arreglo_aux = NULL;
					
					for(int k=tamanho_fisico-10; k<tamanho_fisico; k++){
						*(ptr_arreglo_apariciones+k) = 0;
					}
				}
			}
		}
		
		/* Salida consola y grabado en archivo de texto simultaneo	*/
		
		string linea_cargar;
		
		int pos_mayor;
		string archivo_estadistica_direccion = "..\\doc\\estadisticas\\" + libro_titulo(libro) + " frecuencias.txt";
		
		if(archivo_setup_escritura(archivo_estadistica_direccion.c_str()))	archivo_cargar_linea("TABLA DE FRECUENCIAS\n\nApariciones\tCaracter\n\n");
		
		else	printf("No se pudo abrir el archivo %s\n", archivo_estadistica_direccion.c_str());
		
		printf("TABLA DE FRECUENCIAS\n\nApariciones\tCaracter\n\n");
		
		for( i = 0; i < tl; i++ ){
			pos_mayor = 0;
			for(j = 0; j < tl; j++ ){
				/*	Busco el mayor elemento del arreglo	*/
				if( *(ptr_arreglo_apariciones + j) > *(ptr_arreglo_apariciones + pos_mayor) ){
					pos_mayor = j;
				}
			}
			
			printf("%d\t\t%c\n", *(ptr_arreglo_apariciones + pos_mayor), caracteres_libro.at(pos_mayor));
			
			linea_cargar = to_string(*(ptr_arreglo_apariciones + pos_mayor));
			linea_cargar += "\t\t";
			linea_cargar +=	caracteres_libro.at(pos_mayor);
			linea_cargar += "\n";
			
			archivo_cargar_linea(linea_cargar);
			
			*(ptr_arreglo_apariciones + pos_mayor) = 0;
		}	
	}
	
	archivo_cerrar_escritura();
	libro_finalizar_archivo();
	
	free(ptr_arreglo_apariciones);
	
	ptr_arreglo_apariciones = NULL;
	
	printf("Puedes revisar cualquier estadistica realizada por IPA en la carpeta de estadisticas del proyecto (IPA/doc/estaditicas)\n");
	
	char caux;
	do{
		caux = getch();
	} while( caux != 13);
	
	return ;
}




void estadisticas_nivel_palabras(Libro & libro){
	
	/*	Creacion de matriz de [largo, caracter incial], el analisis de frecuencia de letras nos permitio descubrir que no existe palabra en los libros que comience
		con un caracter acentuado o especial, esto se tuvo en cuenta al desarrollar el tamaño de la matriz	*/
	
	cout << libro_titulo(libro) << "\nLeyendo...";
	
	const string alfabeto_italiano = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string linea, palabra;
	int plb_inicio, plb_final, plb_mayor = 10, plb_tam, i, j;
	int ** ptr_mtrz = ( int ** ) malloc( sizeof ( int* ) * 10 );    //	puntero "maestro" a la matriz, apunta a un arreglo de punteros que apuntan a arreglo de 26 enteros, lo incializo en 10 filas pero esta cantidad puede aumantar
	
	if(ptr_mtrz == NULL){
		cout << "Fallo" << endl;
		cin>>i;
	}
	
	else {
		PtrNodoPalabra lista_dinamica_palabras = lista_palabra_crear();
		
		for( i = 0; i < 10; i++){
			ptr_mtrz[i] = (int*) malloc( sizeof(int) * 26 );
			for( j = 0; j < 26; j++)
				ptr_mtrz[i][j] = 0;
		}
		
		while( libro_leer_linea(linea) ){
			
			while( plb_final != -1 ){
				
				plb_inicio = linea.find_first_of(alfabeto_italiano);
				plb_final = linea.find_first_not_of(alfabeto_italiano);
				
				if( plb_inicio != -1 and ( (plb_inicio < plb_final) || (!plb_inicio and plb_final == -1) ) ){
					
					
					if( plb_final == -1 )    plb_tam = linea.length();
					else	plb_tam = plb_final - plb_inicio;
					
					
					if( plb_tam > plb_mayor ){	
						
						/*	Si la palabra leida es mas larga que la mayor ya leida se pide mas memoria al compilador	*/
						
						int ** ptr_aux_mtrz = ( int ** ) realloc( ptr_mtrz, (sizeof( int * ) * plb_tam) );
						
						if(ptr_aux_mtrz == NULL){
							cout << "No se puedo relocalizar la matriz" << endl;
							cin>>i;
							return;	
						}
						
						else{						
							ptr_mtrz = ptr_aux_mtrz;
							
							for( i = plb_mayor; i < plb_tam; i++){
								ptr_aux_mtrz[i] = (int *) malloc( sizeof(int) * 26 );
								for( j = 0; j < 26; j++)	ptr_mtrz[i][j] = 0;
							}
						}
						
						ptr_aux_mtrz = NULL;
						plb_mayor = plb_tam;	
					}
					
					ptr_mtrz[plb_tam-1][tolower(linea.at(plb_inicio))-'a']++;
					
					palabra = aminusq(linea.substr(plb_inicio, plb_tam));
					lista_palabra_enlace_condicional(& lista_dinamica_palabras, palabra);
					
				}
				linea = linea.substr(plb_final+1);
				
			}
			plb_final = plb_inicio = 0;
			
		}
		
		/*	Ordenamiento de la lista enlazada	*/
		printf("\nOrdenando apariciones...\n");
		lista_palabra_iniciar_ms(lista_dinamica_palabras);
		
		float promedio, vocales_prc, consonantes_prc;
		string cargar_palabra;
		
		/*	Se llama a la funcion de calculo de porcentajes y se muestran estadisticas en pantalla	*/
		if(analisis(ptr_mtrz, plb_mayor, promedio, vocales_prc, consonantes_prc)){
			cout << endl << fixed << setprecision(2) << "Promedio de longitud: " << promedio << "\n\n";
			
			string c;
			
			cout << "Mostrar 5 mas comunes que empiezan con: ";
			do{
				cin >> c;
			}while( c.length() != 1 or !isalpha(c.at(0)) );
			lista_palabra_frecuencia(lista_dinamica_palabras, c.at(0));
			
			cout << endl << "Porcentaje de vocales: " << vocales_prc << endl
				 << "Porcentaje de consonantes: " << consonantes_prc << endl;
			
			string aux;
			aux = toupper(c.at(0));
			string archivo_palabrax = "..\\doc\\estadisticas\\" + libro_titulo(libro) + " palabra" + aux +".txt";
			
			archivo_setup_escritura(archivo_palabrax.c_str());
			
			while( lista_dinamica_palabras != NULL ){
				cargar_palabra = nodo_palabra_siguiente(lista_dinamica_palabras);
				if( tolower(cargar_palabra.at(0)) == tolower(c.at(0)) )
					archivo_cargar_linea(cargar_palabra + "\n");
			}
			
		}
	
	}
	
	char c;
	printf("Presione enter para volver al menu\n");
	do{
		c = getch();
	} while( c != 13);
	
	return;
}
	
bool analisis(int ** ptr_mtrz, int plb_mayor, float & promedio, float & vocales_prc, float & consonantes_prc){
	
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
		
		promedio = promedio / (float)(vocales_tot + consonantes_tot);
	}

	else printf("No se puede calcular el promedio\n");
	
	return (ptr_mtrz != NULL);
}
	
	
string aminusq(string palabra){
	
	/*	Del estudio de frecuencia de caracteres se concluyo que la cantidad de caracteres especiales como Ä en mayuscula es nulo, esta funcion convierte
		una cadena con mayusculas en una completamente minusculas salteandose los caracteres que no se pueden transformar utilizando tolower()	*/
	
	/*	La aplicacion de esta funcion es esencial al trabajar la lista enlazada de palabras, ya que se buscan asociar palabras iguales indiferenctemente
		del casing de cada caracter particular*/
	
	int i;
	
	for( i=0; i<palabra.length(); i++ ){
		if(isalpha(palabra.at(i)))
			palabra[i] = tolower(palabra.at(i));
	}
	
	return palabra;
	
}

	
/*
void prueba(){
	
	wstring a;
	
	while(libro_leer_linea(a)){
		wprintf(L"%s\n", a.c_str());
	}
	
}
*/
