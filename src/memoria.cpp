#include "memoria.h"
#include "fgrales.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


void cartelesIntentos(int avisoIntento, string letra, string ultimoIntento, int fila) {

    limpiarRenglon(fila);

    // Si se ha ingresado una letra ya intentada
    if (avisoIntento) {
        string x = "Ya se ha intentado la letra " + ultimoIntento;
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }

    // Si se ingreso mas de una letra
    if (letra.length() > 1) {
        string x = "Por favor, no ingrese mas de una letra por vez";
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }

    // Si se ingreso algo que no es letra
    else if (!letra.empty() and !isalpha(letra.at(0))) {
        string x = "Por favor, ingrese unicamente letras";
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }
}

void ordenBurbuja(int arreglo[],
    const int tl) {

    int pasada = 1, intercambios = 1, k;

    while (pasada < tl and intercambios) {

        intercambios = 0;

        for (k = 0; k < tl - pasada; k++) {

            if (arreglo[k] > arreglo[k + 1]) {

                intercambiar(arreglo[k], arreglo[k + 1]);
                intercambios = 1;
            }
        }
        pasada += 1;
    }
    return;
}

void ordenar_mayor_a_menor(string vec[]) {

    string copia_vec[5];
    int N[5], i = 0;

    for (; i < 5; i++) copia_vec[i] = vec[i]; // hago una copia del arreglo original

    i = 0; // reciclo y reinicio la variable de control 

    for (; i < 5; i++) N[i] = (int) vec[i].size(); // genero un vector de enteros con los tamaños de las palabras 

    i = 0;

    ordenBurbuja(N, 5); // ordeno el vector de enteros 
    /* 9 2 7 8 10 - 2 7 8 9 10*/

    for (; i < 5; i++) {

        for (int k = 0; k < 5; k++) {

            if (N[i] == (int) vec[k].size()) {
                vec[i].swap(vec[k]);
            }
        }
    }

    return;
}

int num_aleatorio() {

    return rand() % 100;
}

char letra_mas_repetida(const string palabra) {

    /*Si la palabra tiene la misma cantidad de letras, se toma
    como correcta la primera letra de la palabra*/

    int tam = palabra.size();
    int cont, max = 0, pos_max;

    for (int pos = 0; pos < tam; pos++) {

        cont = 0;

        for (int i = pos; i < tam; i++) {

            if (palabra[pos] == palabra[i]) cont++;
        }

        if (cont > max) {
            max = cont;
            pos_max = pos;
        }
    }

    return palabra[pos_max];
}

bool validar_palabra(const string p_ingresada, string palabras[]) {

    bool esvalida = false;
    int i = 0;

    while (!esvalida and i < 5) {

        if (p_ingresada == palabras[i]) esvalida = true;
        i++;
    }

    return esvalida;
}

int cant_tot_vocales(const string & palabra) {
    // calculo la cantidad total de vocales (sin diferenciarlas) de la palabra que paso como argumento

    int tam = int(palabra.size()); // calculo la longitud de la palabra 
    int cont = 0;

    for (int i = 0; i < tam; i++) {

        if (tolower(palabra[i]) == 'a'
            or tolower(palabra[i]) == 'e'
            or tolower(palabra[i]) == 'i'
            or tolower(palabra[i]) == 'o'
            or tolower(palabra[i]) == 'u') cont++;
    }

    return cont;
}

float asignar_puntos(int valor_max, int valor_adivinado, int pts_max) {

    float puntos;

    if (valor_adivinado >= 0 and valor_adivinado <= valor_max) puntos = (float)(valor_adivinado * pts_max) / (float) valor_max;
    else if (valor_adivinado > valor_max) {

        int diferencia = valor_adivinado - valor_max;

        if (diferencia > valor_max) puntos = 0.0;
        else puntos = (float)((valor_max - diferencia) * pts_max) / (float) valor_max;
    }

    return puntos;
}
