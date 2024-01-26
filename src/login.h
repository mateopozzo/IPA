#ifndef LOGIN_H
#define LOGIN_H

/*	Contiene los prototipos de funciones que hacen al funcionamiento del
 * 	login del usuario a la aplicacion	*/

#include "persona.h"

int IngresarLegajo(int &);
void generarID (int legajo, int ID[]);
void convertirIDAchar(int ID[], char contrasenia[], int i);
void Ingresarcontrasenia( char Clave[] );
void ValidacionContrasenia (int ID[]);
bool esNroMenuValido(char x);
void login();
void actualizar_ultima_fecha_acceso(fstream& archivo, Persona& per, int pos);

#endif
