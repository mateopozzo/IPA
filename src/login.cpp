#include "fgrales.h"
#include "login.h"
#include "menues.h"
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

void ValidacionID() {
	// Si se le ingresa un numero de legajo valido, esta genera una contraseña
    system("cls");

    bool flagNumero;
    int legajo;
    string legajoS;
    bool dentroDeRango = false;
    int ID[5];

    gotoxy((100 - 28) / 2, 5);
    cout << "Ingrese su numero de legajo: " << endl;
	
    do { // Validacion del numero de legajo.

        flagNumero = true;
		
        limpiarRenglon(7);
        gotoxy(47, 7);
        getline(cin, legajoS);
		
        int i = 0, tam = legajoS.size();
		
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
    
	generarID(legajo, ID);
    ValidacionContrasenia(ID);

}

void generarID(int legajo, int ID[]) {
	
    // Generacion de la contraseña
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
	
    // Permite ingresar la contraseña y en pantalla se la muestra oculta (a traves de asteriscos)
    int i = 0;
	bool flag = true;

	do {
        
		Clave[i] = getch();
		
		if(Clave[i] == (char) 13)
			flag = false;
		
		
		else if (Clave[i] != 8){// no es retroceso
			
            cout << '*'; // muestra por pantalla
			
			i++;	
        } 
		
		else if (i > 0) {// es retroceso y hay caracteres
			
            cout << (char) 8 << (char) 32 << (char) 8;
			
            i--; //el caracter a borrar el backspace
        }
		
    } while (flag);
	
	Clave[5] = '\0';
}

void ValidacionContrasenia(int ID[]) { // Esta funcion valida la contraseña
	
    int intentos = 0, i = 4;
    bool esValida = false;
    char contrasenia[6], claveReal[6];
	
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
		
        if (strstr(claveReal, contrasenia) != NULL) 
           
			esValida = true;
        
		
		else {
			
            gotoxy((100 - 63) / 2, 13);
			
            if (intentos < 2) 
				cout << "Contrase" << char(164) << "a incorrecta. "
				<< "Por favor ingrese" << endl;
			
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
