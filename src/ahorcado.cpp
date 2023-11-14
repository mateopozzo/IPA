#include "ahorcado.h"
#include "fgrales.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int reemplazoAhorcado(const string Prand, string & aux, string letra) {

    int apariciones = 0, pos = -1;

    do {
		
        pos = Prand.find(letra, pos + 1);
		
        if (pos != -1) {
            /*
            Si se adivina una letra, se agrega al arreglo de renglones 
			tantas veces como aparezca y suma la cantidad de apariciones
            */
            apariciones++;
            aux[pos] = Prand.at(pos);
        }

    } while (pos != -1);

    // Si no hubo apariciones, es error
    return (apariciones == 0);
}

void resultadoAhorcado(int errores, string Prand) {

    // Si el programa termino con menos de seis errores, el jugador gano
    if (errores < 6) {
		
		limpiarRenglon(25);
        gotoxy(34, 25);
        cout << "GANASTE!\n";
        
        // Se calcula puntaje, total menos la cantidad de partes
        // del monigote descubiertas
		
		gotoxy(34, 26);
        cout << "Puntos: " << 100 - errores * 10 << endl;
		
        for (int i = 0; i < 3; i++) {
			
            system("color F2");
            Sleep(500);
            system("color F0");
            Sleep(500);
        }
    }

    //Si el programa termino con mas de seis errores, el jugador perdio
    else {
		// Muestra palabra ganadora
        gotoxy(80, 10);
        cout << Prand;
		
        limpiarRenglon(25);
        gotoxy(34, 25);
        cout << "PERDISTE!\n";
		
        gotoxy(34, 26);
        cout << "Puntos: 0\n";
		
        for (int i = 0; i < 3; i++) {
            system("color F4");
            Sleep(500);
            system("color F0");
            Sleep(500);
        }
    }

    Sleep(1000);
}

void dibujarMonigote(string aux, int errores) {

    // Se imprimen letras adivinadas     
    gotoxy(80, 10);
    cout << aux << endl;

    // Dibuja extremidades en funcion de errores cometidos
    switch (errores) {
    case 6:
        imprimirPiernaD();
		break;
    case 5:
        imprimirPiernaI();
		break;
    case 4:
        imprimirBrazoD();
		break;
    case 3:
        imprimirBrazoI();
		break;
    case 2:
        imprimirTorso();
		break;
    case 1:
        imprimirCabeza();
		break;
    };
}

void imprimirBase() {
    for (int i = 0; i < 25; i++) {
        gotoxy(30 + i, 20);
        cout << '_';
    }
    for (int k = 0; k < 12; k++) {
        gotoxy(31 + k, 1);
        cout << '_';
    }
    for (int j = 19; j > 0; j--) {
        gotoxy(30, 1 + j);
        cout << '|';
    }
    gotoxy(43, 2l);
    cout << '\\';
}

void imprimirPiernaD() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 + i, 13 + i);
        cout << '\\';
    }
}

void imprimirPiernaI() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 - i, 13 + i);
        cout << '/';
    }
}

void imprimirBrazoD() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 + i, 8 + i);
        cout << '\\';
    }
}

void imprimirBrazoI() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 - i, 8 + i);
        cout << '/';
    }
}

void imprimirTorso() {
    for (int i = 0; i < 5; i++) {
        gotoxy(44, 8 + i);
        cout << '|';
    }
}

void imprimirCabeza() {
    gotoxy(42, 3);
    cout << "00000" << endl;
    for (int i = 1; i <= 3; i++) {
        gotoxy(41, 3 + i);
        cout << "0     0" << endl;
    }
    gotoxy(42, 7);
    cout << "00000" << endl;
}


