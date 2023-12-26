#include "noidm.h"
#include "fgrales.h"
#include <conio.h>
#include <iostream>
using namespace std;

// Numeros en otro idioma
void numeros_otro_idioma() {
    system("cls");

	string numero, Nroidioma, aumento;
	
	gotoxy(0, 0);
    cout << "Ingrese un numero de 0 a 9 con el que desee jugar: ";

    do { // Validacion de numero
		
		limpiarRenglon(2);
		gotoxy(0, 2);
		
		getline(cin, numero);
		
    } while (numero.size()!=1 or !isdigit(numero.at(0)));

	
    gotoxy(0, 5);
    cout << "Ingrese el idioma en el que quiere ver su numero: " 
		<< endl << "1.- Espa" << char(164) << "ol" 
		<< endl <<"2.- Ingles" 
		<< endl << "3.- Italiano" 
		<< endl << "4.- Portuges" 
		<< endl << "5.- Frances" << endl;

    do { // Mientras nro no corresponda a idioma
		
        limpiarRenglon(12);
        gotoxy(0, 12);
        getline(cin, Nroidioma);
		
    } while (Nroidioma.size() != 1 || Nroidioma < "1" || Nroidioma > "5");
	
	
    gotoxy(0, 15);
    cout << "Ingrese el aumento  del gr" << (char) 160 
		<< "fico (Debe estar en el rango [1;4]): " << endl;
	
	
    do {// Validacion de aumento
        
        limpiarRenglon(17);
        gotoxy(0, 17);
        getline(cin, aumento);
		
    } while (aumento.size() != 1 || aumento.at(0) < '1' || aumento.at(0) > '4');

    derivador_noidm(numero, Nroidioma, aumento);
	
	return ;
}


void derivador_noidm(string imprimir, string lenguaje, string aum) { 
	
	// ingreso de numero, idioma y aumento
    char n = 164;
    string idioma;

    int numero = stoi(imprimir), Nroidioma = stoi(lenguaje);
	int aumento = stoi(aum);

    if (Nroidioma == 1) {
        idioma = "Espa ol";
        idioma[4] = n;
    } else if (Nroidioma == 2) idioma = "Ingles";
    else if (Nroidioma == 3) idioma = "Italiano";
    else if (Nroidioma == 4) idioma = "Portugues";
    else if (Nroidioma == 5) idioma = "Frances";

    system("cls");
    cout << "Forma escrita en " << idioma << " : " << endl;
    mostrarEscrito(numero, Nroidioma);
    cout << "Gr" << (char) 160 << "fico: " << endl;
    mostrarGrafico(numero, aumento);
	
	cout << "\n\nPresione enter para salir" << endl;
	
    char c;
	do{
		c = getch();
	} while(c != 13);
	
    return;

}

void mostrarEspaniol(int numero) {
    switch (numero) {
    case 0:
        cout << "Cero" << endl;
        break;
    case 1:
        cout << "Uno" << endl;
        break;
    case 2:
        cout << "Dos" << endl;
        break;
    case 3:
        cout << "Tres" << endl;
        break;
    case 4:
        cout << "Cuatro" << endl;
        break;
    case 5:
        cout << "Cinco" << endl;
        break;
    case 6:
        cout << "Seis" << endl;
        break;
    case 7:
        cout << "Siete" << endl;
        break;
    case 8:
        cout << "Ocho" << endl;
        break;
    case 9:
        cout << "Nueve" << endl;
    }
}
void mostrarIngles(const int numero) {
    switch (numero) {
    case 0:
        cout << "Zero" << endl;
        break;
    case 1:
        cout << "One" << endl;
        break;
    case 2:
        cout << "Two" << endl;
        break;
    case 3:
        cout << "Three" << endl;
        break;
    case 4:
        cout << "Four" << endl;
        break;
    case 5:
        cout << "Five" << endl;
        break;
    case 6:
        cout << "Six" << endl;
        break;
    case 7:
        cout << "Seven" << endl;
        break;
    case 8:
        cout << "Eigth" << endl;
        break;
    case 9:
        cout << "Nine" << endl;
    }
}
void mostrarItaliano(const int numero) {
    switch (numero) {
    case 0:
        cout << "Zero" << endl;
        break;
    case 1:
        cout << "Uno" << endl;
        break;
    case 2:
        cout << "Due" << endl;
        break;
    case 3:
        cout << "Tre" << endl;
        break;
    case 4:
        cout << "Quattro" << endl;
        break;
    case 5:
        cout << "Cinque" << endl;
        break;
    case 6:
        cout << "Sei" << endl;
        break;
    case 7:
        cout << "Sette" << endl;
        break;
    case 8:
        cout << "Otto" << endl;
        break;
    case 9:
        cout << "Nove" << endl;
    }
}
void mostrarPortugues(const int numero) {
    switch (numero) {
    case 0:
        cout << "Zero" << endl;
        break;
    case 1:
        cout << "Um" << endl;
        break;
    case 2:
        cout << "Dois" << endl;
        break;
    case 3:
        cout << "Tr" << (char) 136 << "s" << endl;
        break;
    case 4:
        cout << "Quatro" << endl;
        break;
    case 5:
        cout << "Cinco" << endl;
        break;
    case 6:
        cout << "Seis" << endl;
        break;
    case 7:
        cout << "Sete" << endl;
        break;
    case 8:
        cout << "Oito" << endl;
        break;
    case 9:
        cout << "Nove" << endl;
    }
}

void mostrarFrances(const int numero) {
    switch (numero) {
    case 0:
        cout << "Zéro" << endl;
        break;
    case 1:
        cout << "Un" << endl;
        break;
    case 2:
        cout << "Deux" << endl;
        break;
    case 3:
        cout << "Trois" << endl;
        break;
    case 4:
        cout << "Quatre" << endl;
        break;
    case 5:
        cout << "Cinq" << endl;
        break;
    case 6:
        cout << "Six" << endl;
        break;
    case 7:
        cout << "Sept" << endl;
        break;
    case 8:
        cout << "Huit" << endl;
        break;
    case 9:
        cout << "Neuf" << endl;
    }
}

void mostrarEscrito(const int numero, const int Nroidioma) { 
	// funcion es llamada por la derivadora escribe nro en el idioma correspondiente
    if (Nroidioma == 1) mostrarEspaniol(numero);
    else if (Nroidioma == 2) mostrarIngles(numero);
    else if (Nroidioma == 3) mostrarItaliano(numero);
    else if (Nroidioma == 4) mostrarPortugues(numero);
    else if (Nroidioma == 5) mostrarFrances(numero);
}

void graficoCero(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }

}
void graficoUno(int aumento) {
    for (int i = 0; i < aumento * 2; i++) {
        cout << " |" << endl;
    }
}

void graficoDos(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        for (int i = 0; i < aumento * 2; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void graficoTres(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        for (int i = 0; i < aumento * 2; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        for (int i = 0; i < aumento * 2; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void graficoCuatro(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int j = 0; j < aumento * 2; j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << " ";
    for (int i = 0; i < aumento * 2; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        for (int j = 0; j < (aumento * 2) + 1; j++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
}

void graficoCinco(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        for (int i = 0; i < aumento * 2; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void graficoSeis(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void graficoSiete(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << "-";
    }
    cout << endl;
    for (int j = 0; j < aumento * 2; j++) {
        for (int i = 0; i < aumento; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }

}

void graficoOcho(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void graficoNueve(int aumento) {
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
    for (int i = 0; i < aumento; i++) {
        cout << "|";
        for (int i = 0; i < (aumento * 2) - 1; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
    cout << endl;
	
    for (int i = 0; i < aumento; i++) {
        //cout<<" ";
        for (int i = 0; i < aumento * 2; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < aumento; i++) {
        cout << " -";
    }
}

void mostrarGrafico(const int numero, const int aumento) { 
	//Esta funcion es llamada por la derivadora y muestra el numero en el
	// idioma que corresponde y el grafico del numero con el aumento pedido
    if (numero == 0) graficoCero(aumento);
    else if (numero == 1) graficoUno(aumento);
    else if (numero == 2) graficoDos(aumento);
    else if (numero == 3) graficoTres(aumento);
    else if (numero == 4) graficoCuatro(aumento);
    else if (numero == 5) graficoCinco(aumento);
    else if (numero == 6) graficoSeis(aumento);
    else if (numero == 7) graficoSiete(aumento);
    else if (numero == 8) graficoOcho(aumento);
    else if (numero == 9) graficoNueve(aumento);
	
	return ;
}

