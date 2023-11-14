#include "fgrales.h"
#include <iostream>
using namespace std;

void limpiarRenglon(int nRenglon) {
    for (int i = 0; i < 100; i++) {
        gotoxy(0 + i, nRenglon);
        cout << " ";
    }
}

int pot(int b, int e) {
    // Calcula potencia recursivamente
    if (e == 0) return 1;
    return b * pot(b, e - 1);
}

void gotoxy(SHORT x, SHORT y) {
    COORD cp = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void intercambiar(int & a, int & b) {

    int aux = a;
    a = b;
    b = aux;

    return;
}

void identificar_espacios_al_final(string & palabra) {

    int indice = palabra.find_first_of(" ");
    palabra = palabra.substr(0, indice);

    return;
}

void pasar_minusculas(string & palabra) {

    int tam = palabra.size();

    for (int i = 0; i < tam; i++) {

        palabra[i] = tolower(palabra[i]);
    }
    return;
}
