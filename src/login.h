#ifndef LOGIN_H
#define LOGIN_H
#include "persona.h"

int IngresarLegajo();
void generarID (int legajo, int ID[]);
void convertirIDAchar(int ID[], char contrasenia[], int i);
void Ingresarcontrasenia( char Clave[] );
void ValidacionContrasenia (int ID[]);
bool esNroMenuValido(char x);
void login();

#endif
