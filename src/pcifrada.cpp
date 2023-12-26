#include "pcifrada.h"
#include "fgrales.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ahorcado.h"
using namespace std;

// Palabra cifrada
void cifrado_cesar(string P[]) {
    srand(time(NULL));
    /* 
    Se considera que a mayor sea la palabra, mas intentos necesitara el 
    jugador, entonces para el maximo largo de palabra (14) se necesitaran
    3*14 intentos, y para la menor palabra posible se brindara una cantidad
    de dos veces el largo de la palabra, de esta manera se balancean los 
    los casos mas dificiles a mayor sencilles y los mas faciles a mayor 
    dificultad
    */
    const float k = float(-1) / float(12),
        b = 3.25;

    // Declaracion de Variables 
    // El string Prand guarda una palabra aleatoria de las 100 del archivo txt
    string Prand = P[rand() % 100], cesar, letra = "x", l_intentadas;
    string ultimoIntento, aux;
    int offset = 6, intentos = 0, avisoIntento = 0;
	
	// Se calculan los intentos en funcion de la longitud de la palabra de adivinar
    int intentosMax = (b + k * Prand.length()) * Prand.length();

    // Encripta y guarda en string auxiliar(cesar)
    encriptadorCesar(Prand, cesar, offset);

    // Crea cadena de guiones bajos
    for (unsigned int i = 0; i < Prand.length(); i++)
        aux += "_";

    /*
    Mientras se tengan intentos y el string cesar sea distinto a la palabra
    a adivinar, pide al usuario ingresar una letra, y si pertenece a la palabra
    la descubre en el string cesar
    */

    do {
        // Limpia pantalla
        system("cls");

        gotoxy(43, 5);
        cout << "CIFRADO CESAR";

        // Calcula el medio de la pantalla e imprime la palabra cifrada
        // con los intentos acertados por el usuario
        gotoxy((100 - cesar.length()) / 2, 15);
        cout << cesar;

        gotoxy((100 - aux.length()) / 2, 17);
        cout << aux;
		
        do {
			
            cartelesIntentos(avisoIntento, letra, ultimoIntento, 27);
			
            limpiarRenglon(25);
            gotoxy(42, 25);
            cout << "Ingrese letra: ";
            getline(cin, letra);
            avisoIntento = 0;

        } while (esIntentoInval(letra));

        /*
        Si se encuentra el ultimo ingreso en las palabras ya intentadas
        se prende la bandera y se guarda este ultimo intento, sino, se 
        suma un intento y se concatena este ultimo a la string de intentos
        */
		letra = tolower(letra.at(0));
        if (l_intentadas.find(letra) != -1) {
            avisoIntento = 1;
            ultimoIntento = letra.at(0);
        } else {
            l_intentadas += letra.at(0);
        }

        // Siempre se cuenta el intento 
        intentos++;

        // Reemplaza caracter ingresado en la palabra auxiliar
        reemplazoCesar(Prand, aux, letra);

    } while (intentos < intentosMax and Prand != aux);

    // Carteles de victoria y derrota
    resultadoCesar(Prand, aux);
	
	return;
}

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
