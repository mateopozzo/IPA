#include "persona.h"
#include <time.h>

void persona_actualizar_fecha(Persona & persona_actualizar){
	
	struct tm *aux;
	time_t ptr_aux;
	
	time(&ptr_aux);
	
	aux = localtime(&ptr_aux);
	
	persona_actualizar.ultimoAcceso.anio = aux->tm_year+1900;
	persona_actualizar.ultimoAcceso.mes = aux->tm_mon+1;
	persona_actualizar.ultimoAcceso.dia = aux->tm_mday;
		
};
