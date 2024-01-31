#ifndef NOIDM_H
#define NOIDM_H

/*	Contiene los prototipos de las funciones que realizan los graficos
 * 	de los numeros con su respectivo aumento	*/

#include <string>
using namespace std;

void numeros_otro_idioma();
void derivador_noidm(string num, string Nroid, string aum);

/*  Funciones que escriben el numero en su respectivo idioma    */
void mostrarEspaniol (const int numero);
void mostrarIngles (const int numero);
void mostrarItaliano (const int numero);
void mostrarPortugues (const int numero);
void mostrarFrances (const int numero);
void mostrarEscrito (const int numero, const int Nroidioma);

/*  Funnciones que grafican los numeros */
void graficoCero (int aumento);
void graficoUno (int aumento);
void graficoDos (int aumento);
void graficoTres (int aumento);
void graficoCuatro (int aumento);
void graficoCinco (int aumento);
void graficoSeis (int aumento);
void graficoSiete (int aumento);
void graficoOcho (int aumento);
void graficoNueve(int aumento);

void mostrarGrafico (const int numero, const int aumento);

#endif
