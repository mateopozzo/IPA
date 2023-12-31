#include "fgrales.h"
#include "login.h"
#include "menues.h"
#include "persona.h"
#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

//MODIFICADO POR FRANCO 23:12
void cargaUsuarios(){
	// Crear un arreglo de 100 elementos de la estructura Persona
	Persona personas[100];
	ifstream arch_salida; 
	
	arch_salida.open("Info_Definitiva_Usuarios.txt");
	
	if(!arch_salida){
		cout << "No se pudo abrir el archivo" << endl; 
		Sleep(5000);
	}
	else{
		
		// Llenar el arreglo con los datos de las 100 personas
		for (int i = 0; i < 100; i++) {
			//cout << "Persona " << i+1 << ":" << endl;
			//Nombre
			arch_salida >> personas[i].nombre;
			//Apellido
			arch_salida >> personas[i].apellido;
			//Sexo (M o F)
			arch_salida >> personas[i].sexo;
			//Numero de Legajo (entre 10000 y 89999)
			arch_salida >> personas[i].numeroLegajo;
			//Contra
			arch_salida >> personas[i].contrasenia[0] >> personas[i].contrasenia[1] >> personas[i].contrasenia[2] >> personas[i].contrasenia[3] >> personas[i].contrasenia[4];
			//Rol (Profesor o Estudiante)
			arch_salida >> personas[i].rol;
			//Fecha de ultimo acceso (dia mes anio)
			arch_salida >> personas[i].ultimoAcceso.dia >> personas[i].ultimoAcceso.mes >> personas[i].ultimoAcceso.anio;
		}
		// Crear y abrir el archivo binario en modo de escritura
		ofstream archivo("usuarios.bin", ios::binary);
		
		// Escribir los datos de las 100 personas en el archivo binario
		archivo.write(reinterpret_cast<const char*>(&personas), sizeof(personas));
		
		// Cerrar el archivos
		archivo.close();
		arch_salida.close();
		
		cout << personas[7].numeroLegajo << endl;
		Sleep(2000);
		//cout << "Se escribio con exito" << endl;
		
	}
}
void Ingresarcontrasenia(char Clave[]) {
	
	// Permite ingresar la contraseña y en pantalla se la muestra oculta (a traves de asteriscos)
	int i = 0;
	bool flag = true;
	char aux = '\0';
	
	do {
		
		aux = getch();
		
		if(aux == 13) flag = false;
		else if (aux != 8){// no es retroceso
			
			cout << '*'; // muestra por pantalla
			
			if(i<10) Clave[i] = aux;
			
			i++;
		} 
		else if (i > 0) {// es retroceso y hay caracteres
			
			cout << (char) 8 << (char) 32 << (char) 8;
			
			i--; //el caracter a borrar el backspace
		}
		
	} while (flag);
	
	if(i<10) Clave[i] = '\0';
	else Clave[10] = '\0';
}

void convertirClaveInt(char clave[], int ID[], const int tam){
	
	for (int i = 0; i < tam ; i++) ID[i] = clave[i] - '0';
}

bool validarContra(int ingresada[], int extraida[], const int tam){
	
	bool esValida = true; 
	int pos = 0; 
	
	while (esValida and pos < tam){
		
		if(ingresada[pos] != extraida[pos]) esValida = false; 
		pos++; 
	}
	
	return esValida; 
}

int IngresarLegajo(){
	
	// Si se le ingresa un numero de legajo valido, esta genera una contraseña
	
	system("chcp 850");	//	setea consola a ANSI latin
	system("cls");

    bool flagNumero;
    int legajo;
    string legajoS;
    bool dentroDeRango = false;
	
    gotoxy((100 - 28) / 2, 5);
    cout << "Ingrese su numero de legajo: " << endl;
	
    do{ // Validacion del numero de legajo.
		
        flagNumero = false;
		
        limpiarRenglon(7);
        gotoxy(47, 7);
        getline(cin, legajoS);
		
		
        int i = 0, tam;
		
		if(!legajoS.empty()){
			
			tam = legajoS.size();
			
			if(tam == 5) flagNumero = true;
		}
		
        while (flagNumero and i < tam) {
			
            if (!isdigit(legajoS.at(i))) flagNumero = false;
			
            i++;
			
        }
		
        if (flagNumero) legajo = stoi(legajoS);
		
		
        gotoxy((100 - 55) / 2, 8);
		
		
        if (legajo >= 10000 and legajo <= 89999 and flagNumero) dentroDeRango = true;
        else cout << "Legajo incorrecto. Por favor ingrese de nuevo su legajo" << endl;
		
		
	} while (!dentroDeRango);
	
	limpiarRenglon(8);
	
	//generarID(legajo, ID);
    //ValidacionContrasenia(ID);

	return legajo; 
}

void login(){

	ifstream arch_usuarios;
	arch_usuarios.open("..\\doc\\usuarios.bin", ios::binary);
	
	bool estaLegajo;
	int ID[5];
	char clave[6]; // fijarse el tamanio correcto
	int legajo, intentos = 0; 
	
	// se crea la variable de flujo y se abre el archivo
	Persona persona[100]; 
	bool contraCorrecta = false; 
	
	//variables para almacenar los datos de la persona
	string nombre, apellido, rol; 
	char sexo;
	int dia, mes, anio; 
	int contra[5];
	int i, pos;
	
	if(arch_usuarios.fail()){ // Verificacion de apertura
		cout << "No se pudo abrir el registro de usuarios." << endl; 
	}
	else{ // si hubo una apertura exitosa
		
		i=pos=0;
		
		//INGRESO DE LEGAJO
		do{
			estaLegajo = false; 
			
			legajo = IngresarLegajo(); 
			
			while( !arch_usuarios.eof() ){
				
				arch_usuarios.read((char*)(&persona[i]), sizeof(Persona));
				
				if(!estaLegajo){
					if(persona[i].numeroLegajo == legajo)
						estaLegajo = true;					
					else pos++;
					intentos = 0;
				}
				i++;
				
				
			}
			
			if( !estaLegajo ){
				printf("Legajo inexistente, volver a ingresar");
				arch_usuarios.seekg(0, ios::beg);
				intentos++;
			}
			
		} while( !estaLegajo and intentos < 3 );
		
		
		
		while(intentos < 3 and !contraCorrecta and estaLegajo){
			
			// copiados de valores del archivo hacia las varibles 
			for(i = 0 ; i < 5 ; i++)
				contra[i] = persona[pos].contrasenia[i]; // paso los valores de la contra a aca
			
			//solicitacion de ingreso de contra
			limpiarRenglon(8);
			gotoxy((100 - 22) / 2, 10);
			cout << "Ingresar contrase"<<char(164)<<"a\n";
			limpiarRenglon(12);
			gotoxy(47, 12);
			Ingresarcontrasenia(clave);
			convertirClaveInt(clave, ID, 5); // paso de arreglo de caacteres a arreglo de enteros 
			
			if(validarContra(ID, contra, 5))	contraCorrecta = true; // si la contra es igual a la ingresada, se permite el acceso
			else {
				intentos++; 
				gotoxy((100 - 28) / 2, 10);
				printf("Contrase%ca incorrecta, reingresar\n", 164); 
				Sleep(2000);
				limpiarRenglon(10);
			}
		}
		if (contraCorrecta){
			
			system("cls");
			
			nombre = (string)persona[pos].nombre; 
			sexo = persona[pos].sexo;
			dia = persona[pos].ultimoAcceso.dia;
			mes = persona[pos].ultimoAcceso.mes;
			anio = persona[pos].ultimoAcceso.anio;
			
			if (sexo == 'M') cout << "Bienvenido " << nombre << "!" << endl;
			else if (sexo == 'F') cout << "Bienvenida " << nombre << "!" << endl;
			
			cout << "Ultimo acceso a la aplicacion: " << dia << "/" << mes << "/" << anio << endl; 
			Sleep(1000); 
			
			persona_actualizar_fecha(persona[pos]); // actualizo el ultimo acceso al del dia actual 
			
			arch_usuarios.close();
				
			ofstream arch_salida;
			arch_salida.open("..\\doc\\usuarios.bin", ios::binary); //vinculamos nueva variable de flujo con el fichero para escribir
			
			if(arch_salida.fail()){
				cout <<"No se ha podido abrir el fichero" << endl; 
				exit(0); 
			}
			else { // apertura para escritura exitosa
				for(i=0; i<99; i++)
					arch_salida.write((char*)(&persona[i]), sizeof(Persona)); // actualizamos su informacion 

				Sleep(2000); 
				
			}
			
			menuPpal();
		}
	}
}
void ValidacionContrasenia(int ID[]) { // Esta funcion valida la contraseña
	
    int intentos = 0, i = 4;
    bool esValida = false;
    char contrasenia[10], claveReal[6];
	
	// Convierte ID numerico a una cadena
    convertirIDAchar(ID, claveReal, i); 

	
    gotoxy((100 - 22) / 2, 10);
    cout << "Ingrese la contrase" << char(164) << "a: " << endl;
	
    do { 
		/* 
		Validacion de contraseña, 3 intentos
		*/
		
        limpiarRenglon(12);
		
        gotoxy(47, 12);
		
        Ingresarcontrasenia(contrasenia);
		
        if(!strcmp(claveReal, contrasenia)) 
           
			esValida = true;
        
		
		else {
			
            gotoxy(25, 13);
			
            if (intentos < 2) 
				cout << "Contrase" << char(164) << "a incorrecta. "
				<< "Por favor ingresar nuevamente" << endl;
			
            intentos++;
        }
		
        if (intentos > 2) {
			
            limpiarRenglon(13);
            gotoxy((100 - 31) / 2, 13);
			
            cout << char(173) << "Cantidad de intentos excedida!" << endl;
        }
		
    } while (!esValida and intentos < 3);

    if (esValida) menuPpal(); 
	// si la contraseña es correcta llamamos al menu principal

}

void convertirIDAchar(int ID[], char contrasenia[], int i) { 
	// Esta funcion convierte un arreglo entero en un arreglo de caracteres
    if (i == 0) {
        contrasenia[0] = ('0' + ID[0]);
        return;
    }
    contrasenia[i] = ('0' + ID[i]);

    return convertirIDAchar(ID, contrasenia, i - 1);
}
