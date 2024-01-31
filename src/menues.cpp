#include "menues.h"
#include "fgrales.h"
#include "login.h"
#include "archivo.h"
#include "abecedarios.h"
#include "ahorcado.h"
#include "pcifrada.h"
#include "noidm.h"
#include "memoria.h"
#include "prcdtexto.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <cctype>
using namespace std;

// Funciones de menu

void
bienvenida()
{
	
    /*  Espera a que el usuario aprete el enter */

    logo();
	char c;
	
    while((c = getch()) != 13){};
	
	login();
	
	return;
}

void
logo()
{
	
	system("cls");	//	Limpia consola

    string bienvenidos = "BIENVENIDOS ;)";
    int tam = bienvenidos.size();

    //  Impresion logo
    gotoxy(30, 2);
    cout << "      :+:::+::+:        :+:::+:::           :+:  \n";
    gotoxy(30, 3);
    cout << "         :+:           :+:    :+:        :+: :+: \n";
    gotoxy(30, 4);
    cout << "        +:+           +:+    +:+       +:+   +:+ \n";
    gotoxy(30, 5);
    cout << "       +#+           +#++:++#+       +#++:++#++: \n";
    gotoxy(30, 6);
    cout << "      +#+           +#+             +#+     +#+  \n";
    gotoxy(30, 7);
    cout << "     #+#           #+#             #+#     #+#   \n";
    gotoxy(30, 8);
    cout << "###########       ###             ###     ###    \n";

    // Retraso antes de mostrar "BIENVENIDO"
    Sleep(1000);

    gotoxy((100 - tam) / 2, 10);

    // Dibujo de la palabra "BIENVENIDO" en el espacio designado
    for (int i = 0; i < tam; i++) {
        printf("%c", bienvenidos.at(i));
        Sleep(50);
    }

    gotoxy((100 - 22) / 2, 13);
    cout << "Presione ENTER iniciar";

    return;
}

bool
verificar_si_o_no(string palabra)
{
    /*  Verifica que el usuario ingrese si o no  al salir de la aplicacion  */

    bool valido = false;
    if (palabra == "si"
        or palabra == "no") valido = true;

    return valido;
}

bool
cierre_app() 
{
    system("cls");

    string opcion;
    bool es_opcion, continuar;
	
	
	// Alerta previa cerrar app
	cout << char(168) 
		<< "ESTAS SEGURO DE ABANDONAR?\n" <<
		"Escribe 'SI' si estas seguro\n" <<
		"Escribe 'NO' para volver al menu" << endl;
	

    do {
        getline(cin, opcion);
		
		
		// Correccion de entrada de usuario
        identificar_espacios_al_final(opcion);
        pasar_minusculas(opcion);
        es_opcion = verificar_si_o_no(opcion);
		
        if (es_opcion) {
            system("cls");
            
            if (opcion == "si"){
				cout << char(173) << "HASTA LUEGO!" << endl;
				continuar = false;
			}
			
            else if (opcion == "no")
				continuar = true;
        }
		
		else cout << "Ingresar unicamente si o no: ";
		
    } while (es_opcion == false);
	
    return continuar;
}

bool
menu_valido(char c) 
{
    /*  Evalua que el usuario haya ingresado un numero o una x  */
    bool rep;

    if (isdigit(c) or toupper(c) == 'X') 
        rep = true;
    
	else{
		rep = false;
		cout << "Opcion no disponible\n";
	}
	
    return rep;
}


void
menuPpal()
{
	
	char opcion_user;
	bool flag = true;

    do {
		
		system("cls");
		
        cout << "----------------\n" <<
            "|MENU PRINCIPAL|\n" <<
            "----------------\n" <<
            "1) Abecedarios\n" <<
            "2) Juegos\n" <<
			"3) Procesador de texto\n"
            "X) Salir de App\n" << endl;
		
		
        do opcion_user = getch();
        while (!menu_valido(opcion_user));
		
        switch (toupper(opcion_user)) {
		
        case '1':
            system("cls");
            menu_abecedarios();
            break;
		
        case '2':
            system("cls");
            menu_juegos();
            break;
			
		case '3':
            system("cls");
            menu_procesador_texto();
            break;
		
        case 'X':
            flag = cierre_app();
            break;
        }

    } while (flag);

    return;
}

void
lectorPalabras(string P[]) 
{
    // Ubicacion de archivo de texto
    string nombre_archivo = "..\\..\\IPA\\doc\\palabras-1.txt";
	
	int i=0;
	archivo entrada;
	
    // Abre lectura de la ubicacion del archivo txt
    entrada = setup("Arreglo de palabras", nombre_archivo);

    if(!apertura(entrada))
		cout << "Error en apertura de archivo" << endl;
		
	else{
		bool final=false;
		do {
			P[i] = leerLinea(entrada, final);
			i++;
		} while (!final);
	}
}

void
menu_juegos()
{
	
    string P[110], opcion = "no";
	char juego;
	bool flag = true;
	
	/*
	Lectura de archivo
	almacenamiento en arreglo P
	*/
	lectorPalabras(P);

    do {
        system("cls");
        gotoxy(0, 0);
        cout << "----------------\n" <<
            "|MENU DE JUEGOS|\n" <<
            "----------------\n" <<
            "1) Ahorcado\n" <<
            "2) Palabra cifrada\n" <<
            "3) Numeros en otro idioma\n" <<
            "4) Juego de memoria\n" <<
            "X) A menu principal\n";
		
        do { // Validacion de input
            juego = getch();
			
            // Aviso ingreso invalido
            limpiarRenglon(12);
            gotoxy(0, 12);
        } while (!menu_valido(juego) );
		
        // Abre juego segun lista
        switch (toupper(juego)) {
			
        case '1':
            ahorcado(P);
            break;
			
        case '2':
            cifrado_cesar(P);
            break;
			
        case '3':
            numeros_otro_idioma();
            break;
			
        case '4':
            juego_memoria(P);
            break;
			
        case 'X':
			// salida
			flag = false;
            break;

		// nro de juego inexistente
        default:
            gotoxy(0, 12);
            cout << juego << " no es una opcion disponible";
        }

    } while (flag);

    return;
}

void
menu_abecedarios() 
{

    char opcion;
	bool flag = true;
	system("cls");

    do {
		gotoxy(0,0);
        cout << "------------------\n" <<
            "|MENU ABECEDARIOS|\n" <<
            "------------------\n" <<
            "1) Espa" << char(164) << "ol\n" <<
            "2) Ingles\n" <<
            "3) Italiano\n" <<
            "4) Portugues\n" <<
            "5) Frances\n" <<
            "X) Para volver al menu" << endl;
		
        do {
			
            opcion = getch();
			
            gotoxy(0, 12);
			
        } while (!menu_valido(opcion));
		
        switch (toupper(opcion)) {
		
        case '1':
            system("cls");
            abecedario_espaniol();
            break;
		
        case '2':
            system("cls");
            abecedario_ingles();
            break;
		
        case '3':
            system("cls");
            abecedario_italiano();
            break;
		
        case '4':
            system("cls");
            abecedario_portugues();
            break;
		
        case '5':
            system("cls");
            abecedario_frances();
            break;
		
        case 'X':
			flag = false;
			break;
			
		default:
            gotoxy(0, 12);
            cout << opcion << " no es una opcion disponible";
		}
        
    } while (flag);

    return;
}

void
menu_procesador_texto()
{
	char opcion;
	bool flag = true;
	
	do{
		system("cls");
		cout << "--------------------------\n" <<
			"|MENU PROCESADOR DE TEXTO|\n" <<
			"--------------------------\n" <<
			"1) Estadisticas a nivel de caracteres\n" <<
			"2) Estadisticas a nivel de palabras\n" <<
			"X) Volver al menu principal\n" << endl;
		
		do {
			opcion = getch();
			gotoxy(0, 12);
		} while (!menu_valido(opcion));
		
		switch (toupper(opcion)) {
		case '1':
			system("cls");
			seleccion_libro(1);
			break;
		case '2':
			system("cls");
			seleccion_libro(2);
			break;
		case 'X':
			flag = false;
			break;
		default:
			gotoxy(0, 12);
			cout << opcion << " no es una opcion disponible";
		}
		
    } while (flag);

    return;
}

