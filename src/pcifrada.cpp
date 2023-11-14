#include "pcifrada.h"
#include "fgrales.h"
#include <iostream>
using namespace std;


void encriptadorCesar(string Prand, string & cesar, int offset) {
    char j;
    /* 
    Relleno arreglo cesar de letra de la palabra ingresada mas offset posicion
    por posicion
    */
    for (unsigned int i = 0; i < Prand.length(); i++) {
        j = Prand.at(i);
        // Casos desde o hasta letra i
        if (j < 'i' || j >= 'o')
            cesar += (j - 'a' + offset) % (('z' + 1) - 'a') + 'a';

        // Casos entre letra o e i
        else if (j < 'o'
            and j > 'i')
            cesar += (j - ('a' + 1) + offset) % (('z' + 1) - 'a') + 'a';

        //casos particulares para la ñ y la i
        else if (j == char(164))
            cesar += 't';
        else if (j == 'i')
            cesar += char(164);
    }
}

void reemplazoCesar(const string Prand, string & cesar, string letra) {

    unsigned int i = 0;

    /*
    Se fija en el arreglo de la palabra ganadora si esta la letra intentada
    por el usuario, y cuando la encuentra, la reemplaza en el arreglo auxiliar
    tantas veces como esta aparezca
    */

    while (i < Prand.length()) {
        if (Prand.at(i) == letra.at(0)) {
            cesar[i] = Prand.at(i);
        }
        i++;
    }
}

void resultadoCesar(string Prand, string aux) {

    // Cartel de victoria
    if (Prand == aux) {

        gotoxy((100 - aux.length()) / 2, 15);
        cout << Prand;
        gotoxy((100 - aux.length()) / 2, 17);
        cout << aux;

        gotoxy((100 - Prand.length()) / 2, 15);
        cout << Prand;
        gotoxy(42, 25);
        cout << "                             ";
        gotoxy(46, 25);
        cout << "GANASTE";
        for (int i = 0; i < 3; i++) {
            system("color F2");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }

    // Cartel de derrota
    else {

        gotoxy((100 - aux.length()) / 2, 15);
        cout << Prand;

        gotoxy(42, 25);
        cout << "                             ";
        gotoxy(46, 25);
        cout << "PERDISTE";
        for (int i = 0; i < 3; i++) {
            system("color F4");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }
}
