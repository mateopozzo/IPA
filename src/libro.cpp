#include "libro.h"
#include <iostream>
#include <cstring>
using namespace std;

ifstream libro_archivo;
ofstream archivo_out;

Libro
libro_declarar(string & libro_titulo, const char * libro_path)
{
	/*	Se instancia un libro y se le asigna a sus campos la informacion correspondiente	*/
	
	Libro libro;
	
	libro.titulo = libro_titulo;
	strcpy(libro.path, libro_path);
	
	return libro;
}

bool 
libro_iniciar_archivo(Libro & libro)
{
	/*	Recibe un libro con campos cargados y lo abre en el manejador de libro	*/
	
	bool exito=true;
	
	libro_archivo.open(libro.path);
	if(libro_archivo.fail()){
		exito = false;
		cout<<"Error al intentar abrir libro, revisar el path brindado."<<endl;
	}
	
	return exito;
}
	
bool
libro_finalizar_archivo()
{
	/*	Cierra el manejador si es tiene cargado algun libro	*/
	bool exito = true;
	
	libro_archivo.close();
	if(libro_archivo.fail()){
		cout << "Error al intentar cerrar archivo" << endl;
		exito = false;
	}
	
	return exito;
}

bool 
libro_leer_linea(string & linea)
{
	/*	Recibe string, guarda en ella una linea si algun libro esta cargado	*/
	
	bool ret = !libro_archivo.eof();
	
	if(ret)
		getline(libro_archivo, linea);
	
	return ret;
}

bool 
libro_leer_caracter(char * c)
{
	/*	Recibe string, guarda en ella una linea si algun libro esta cargado	*/
	
	bool ret = !libro_archivo.eof();
	
	if(ret)
		libro_archivo.get(c, 2, EOF);
	
	return ret;
}
	
void
libro_titulo_imprimir(Libro & libro)
{
	/*	Recibe un libro imprime el titulo	*/
	
	cout<<libro.titulo<<'\n';
}
	
string 
libro_titulo(Libro & libro)
{
	/*	Recibe un libro y devuelve su titulo	*/
	
	return libro.titulo;
}




