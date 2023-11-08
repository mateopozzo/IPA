#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cctype>
#include <iomanip>
#include <conio.h>
using namespace std;

void gotoxy(SHORT x, SHORT y);
int pot(int b, int e);
int strToInt(string n);

void bienvenida();
void login();
void menuPpal();
string volverMenuAnterior(int continuaPrograma);
void ValidacionID ();
void generarID (int legajo, int ID[]);
void convertirIDAchar(int ID[], char contrasenia[], int i);
void Ingresarcontrasenia( char Clave[] );
void ValidacionContrasenia (int ID[]);
bool esNroMenuValido(string & x);
void limpiarRenglon(int nRenglon);
void menuJuegos(void);
void menu_abecedarios();
void identificar_espacios_al_final (string& palabra);
void pasar_minusculas (string& palabra);
bool verificar_si_o_no(string palabra);

void lectorPalabras(string P[]);
int strToInt(string n);
void cartelesIntentos(int avisoIntento, string letra, string ultimoIntento, int fila);
bool esIntentoInval(string letra);

void ahorcado(string P[]);
int reemplazoAhorcado(const string Prand, string & aux, string letra);
void dibujarMonigote(string aux, int errores);
void resultadoAhorcado(int errores, string Prand);
void imprimirBase ();
void imprimirPiernaD();
void imprimirPiernaI();
void imprimirBrazoD();
void imprimirBrazoI();
void imprimirTorso();
void imprimirCabeza();

void palabraCifrada(string P[]);
void encriptadorCesar(string Prand, string & cesar, int offset);
void reemplazoCesar(const string Prand, string & cesar, string letra);
void resultadoCesar(string Prand, string cesar);

void juego_memoria();
void intercambiar(int & a, int & b);
void ordenBurbuja(int arreglo[], const int tl);

char letra_mas_repetida(const string palabra);
int cant_tot_vocales (const string& palabra);
float asignar_puntos (int valor_max, int valor_adivinado, int pts_max);
void ordenar_mayorAmenor (string vec[]);
bool validar_palabra (const string p_ingresada, string palabras[]);

void ValidacionDatosNroOtroIdioma ();
void NumerosEnOtroIdioma(string num, string Nroid, string aum);
void mostrarEspaniol (const int numero);
void mostrarIngles (const int numero);
void mostrarItaliano (const int numero);
void mostrarPortugues (const int numero);
void mostrarFrances (const int numero);
void mostrarEscrito (const int numero, const int Nroidioma );
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

void abecedario_espaniol();
void abecedario_ingles();
void abecedario_italiano();
void abecedario_portugues();
void abecedario_frances();
