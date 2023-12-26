#ifndef PERSONA_H
#define PERSONA_H
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
	char sexo;
	int numeroLegajo;
	int contrasenia[5];
	string rol;
	Fecha ultimoAcceso;
};

void persona_actualizar_fecha(Persona& );
#endif
