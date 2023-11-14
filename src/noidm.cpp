#include "noidm.h"
#include <iostream>
using namespace std;


void NumerosEnOtroIdioma(string imprimir, string lenguaje, string aum) { // Esta es la funcion general que segun el numero, idioma y aumento, 				muestra lo debido
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
	// Esta funcion es llamada por la general y meustra el numero de manera escrita en el idioma que corresponde
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

void mostrarGrafico(const int numero,
    const int aumento) { //Esta funcion es llamada por la funcon general y meusrra el numero  en el idioma que corresponde y el grafico del numero con el aumento pedido
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

    cin.ignore();
    do {
        cout << endl << "Ingrese enter para continuar" << endl;
    } while ((cin.get() != '\n'));
}

