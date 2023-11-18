#include "fgrales.h"
#include "login.h"
#include "menues.h"
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

void ValidacionID() {
	// Si se le ingresa un numero de legajo valido, esta genera una contraseņa
	system("cls");

    bool flagNumero;
    int legajo;
    string legajoS;
    bool dentroDeRango = false;
    int ID[5];

    gotoxy((100 - 28) / 2, 5);
    cout << "Ingrese su numero de legajo: " << endl;
	
    do { // Validacion del numero de legajo.

        flagNumero = false;
		
        limpiarRenglon(7);
        gotoxy(47, 7);
        getline(cin, legajoS);
		
		
        int i = 0, tam;
		
		if(!legajoS.empty()){
			tam = legajoS.size();
			
			if(tam == 5)
				flagNumero = true;
		}
		
        while (flagNumero and i < tam) {
			
            if (!isdigit(legajoS.at(i))) {
                flagNumero = false;
            }
			
            i++;
			
        }

        if (flagNumero)
            legajo = stoi(legajoS);
		
		
        gotoxy((100 - 55) / 2, 8);
		
		
        if (legajo >= 10000 and legajo <= 89999 and flagNumero) 
			dentroDeRango = true;
		
		
        else 
			cout << "Legajo incorrecto. Por favor ingrese de nuevo su legajo" << endl;
		
		
	} while (!dentroDeRango);
	
	limpiarRenglon(8);
    
	generarID(legajo, ID);
    ValidacionContrasenia(ID);

}

void generarID(int legajo, int ID[]) {
	
    // Generacion de la contraseņa
    int aux;

    for (int i = 4; i >= 0; i--) { 
		
		ID[i] = legajo % 10;
		legajo /= 10;
		
    }
	
	//le asigno al primer digito el valor del ultimo
    aux = ID[0];
    ID[0] = ID[4]; 
	
	// asigno al ultimo digito el valor correspondiente
    ID[4] = (ID[0] + aux) % 10; 
    
	//invierto las posiciones 2 y 4
	intercambiar(ID[1], ID[3]);

}

void Ingresarcontrasenia(char Clave[]) {
	
    // Permite ingresar la contraseņa y en pantalla se la muestra oculta (a traves de asteriscos)
    int i = 0;
	bool flag = true;
	char aux = '\0';

	do {
        
		aux = getch();
		
		if(aux == 13)
			flag = false;
		
		
		else if (aux != 8){// no es retroceso
			
            cout << '*'; // muestra por pantalla
			
			if(i<10)
				Clave[i] = aux;
			
			i++;
			
			
        } 
		
		else if (i > 0) {// es retroceso y hay caracteres
			
            cout << (char) 8 << (char) 32 << (char) 8;
			
            i--; //el caracter a borrar el backspace
        }
		
    } while (flag);
	
	if(i<10)
		Clave[i] = '\0';
	else 
		Clave[10] = '\0';
}

void ValidacionContrasenia(int ID[]) { // Esta funcion valida la contraseņa
	
    int intentos = 0, i = 4;
    bool esValida = false;
    char contrasenia[10], claveReal[6];
	
	// Convierte ID numerico a una cadena
    convertirIDAchar(ID, claveReal, i); 

	
    gotoxy((100 - 22) / 2, 10);
    cout << "Ingrese la contrase" << char(164) << "a: " << endl;
	
    do { 
		/* 
		Validacion de contraseņa, 3 intentos
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
	// si la contraseņa es correcta llamamos al menu principal

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
