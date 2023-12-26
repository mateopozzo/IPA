#ifndef MEMORIA_H
#define MEMORIA_H

#include <string>
using namespace std;

void juego_memoria(string tex[]);
void ordenBurbuja(int arreglo[], const int tl);
char mas_repetida(const string vec[], int t, int& sum); 
int frecuencia_letra(const string vec[], int t, char letra);
int cant_tot_vocales (const string& palabra);
float asignar_puntos (int valor_max, int valor_adivinado, int pts_max);
void ordenar_mayorAmenor(string vec[]);
bool validar_palabra (const string p_ingresada, string palabras[]);

#endif
