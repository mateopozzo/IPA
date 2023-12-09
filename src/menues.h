#ifndef MENUES_H
#define MENUES_H

#include <string>
using namespace std;

void logo();
void bienvenida();
void menuPpal();
bool cierre_app();
bool menu_valido(char c);
void lectorPalabras(string P[]);
void menu_juegos();
void menu_abecedarios();
void menu_procesador_texto();
bool verificar_si_o_no(string palabra);

#endif
