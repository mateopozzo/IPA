#ifndef PERSONA_H
#define PERSONA_H

/*	Contiene las estructuras de datos que almacenan los datos de los usuarios	*/

#include <string>
using namespace std;

struct Fecha {
	int dia;
	int mes;
	int anio;
};

struct Persona {
	char nombre[30];
	char apellido[30];
    char rol[15];   //  Al usar strings, el guardado en archivo binario genero problemas
	char sexo;
	int numeroLegajo;
	int contrasenia[5];
	Fecha ultimoAcceso;
};

void persona_actualizar_fecha(Persona&);

#endif
