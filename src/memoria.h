#ifndef MEMORIA_H
#define MEMORIA_H

#include <string>
using namespace std;

void ordenBurbuja(int arreglo[], const int tl);
char letra_mas_repetida(const string palabra);
int cant_tot_vocales (const string& palabra);
float asignar_puntos (int valor_max, int valor_adivinado, int pts_max);
void ordenar_mayor_a_menor (string vec[]);
bool validar_palabra (const string p_ingresada, string palabras[]);
void cartelesIntentos(int avisoIntento, string letra, string ultimoIntento, int fila);

#endif
