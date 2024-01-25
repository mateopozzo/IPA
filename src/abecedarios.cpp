#include "abecedarios.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Funciones abecedarios
void abecedario_espaniol() {
	
    // Alfabeto en minusculas
    cout << "------------------------\n" <<
        "|Alfabeto en minusculas|\n" <<
        "------------------------" << endl;

    cout << "a b c d e f g h i j\n" <<
        "k l m n " << (char) 164 << " o p q r s \n" <<
        "t u v w x y z" << endl << endl;

    // Alfabeto en mayusculas
    cout << "------------------------\n" <<
        "|Alfabeto en mayusculas|\n" <<
        "------------------------" << endl;

    cout << "A B C D E F G H I J\n" <<
        "K L M N " << (char) 165 << " O P Q R S\n" <<
        "T U V W X Y Z" << endl << endl;

    // Minusculas acentuadas 
    cout << "-----------------------\n" <<
        "|Minusculas Acentuadas|\n" <<
        "-----------------------" << endl;
    cout << (char) 160 << " " << (char) 130 << " " 
		<< (char) 161 << " " << (char) 162 << " "
		<< (char) 163 << " " << (char)129 << endl;

    cout << "\nPresione enter para volver al menu abecedarios";
	
	char c;
	do{
		c = getch();
	} while(c != 13);
	
	system("cls");
	
    return;
}

void abecedario_ingles() {

    // Alfabeto en minusculas
    cout << "------------------------\n" <<
        "|Alfabeto en minusculas|\n" <<
        "------------------------" << endl;

    cout << "a b c d e f g h i j\n" <<
        "k l m n o p q r s t\n" <<
        "u v w x y z" << endl << endl;

    // Alfabeto en mayusculas
    cout << "------------------------\n" <<
        "|Alfabeto en mayusculas|\n" <<
        "------------------------" << endl;

    cout << "A B C D E F G H I J\n" <<
        "K L M N O P Q R S T\n" <<
        "U V W X Y Z" << endl << endl;

    // Minusculas acentuadas 
    cout << "-----------------------\n" <<
        "|Minusculas Acentuadas|\n" <<
        "-----------------------" << endl;
    cout << "Este idioma no posee acentos" << endl;

    cout << "\nPresione enter para volver al menu abecedarios";
	
	char c;
	do{
		c = getch();
	} while(c != 13);
	
	system("cls");
	
    return;
}

void abecedario_italiano() {
	
    // Alfabeto en minusculas
    cout << "------------------------\n" <<
        "|Alfabeto en minusculas|\n" <<
        "------------------------" << endl;

    cout << "a b c d e f g h i j\n" <<
        "k l m n o p q r s t\n" <<
        "u v w x y z" << endl << endl;

    // Alfabeto en mayusculas
    cout << "------------------------\n" <<
        "|Alfabeto en mayusculas|\n" <<
        "------------------------" << endl;

    cout << "A B C D E F G H I J\n" <<
        "K L M N O P Q R S T\n" <<
        "U V W X Y Z" << endl << endl;

    // Minusculas acentuadas 
    cout << "-----------------------\n" <<
        "|Minusculas Acentuadas|\n" <<
        "-----------------------" << endl;
    cout << (char) 133 << " " << (char) 130 << " " << (char) 138 << " " << (char) 141 << " " << (char) 149 << " " << (char) 151 << endl;

    cout << "\nPresione enter para volver al menu abecedarios";
	
	char c;
	do{
		c = getch();
	} while(c != 13);
	
	system("cls");
	
    return;
}

void abecedario_portugues() {

	system("chcp 860");	//	codepage adecuada para el portugues
	system("cls");
	
    // Alfabeto en minusculas
    cout << "------------------------\n" <<
        "|Alfabeto en minusculas|\n" <<
        "------------------------" << endl;

    cout << "a b c d e f g h i j\n" <<
        "k l m n o p q r s t\n" <<
        "u v w x y z" << endl << endl;

    // Alfabeto en mayusculas
    cout << "------------------------\n" <<
        "|Alfabeto en mayusculas|\n" <<
        "------------------------" << endl;

    cout << "A B C D E F G H I J\n" <<
        "K L M N O P Q R S T\n" <<
        "U V W X Y Z" << endl << endl;

    // Minusculas acentuadas 
    cout << "-----------------------\n" <<
        "|Minusculas Acentuadas|\n" <<
        "-----------------------" << endl;
    cout << (char) 160 << " " << (char) 133 << " " 
		<< (char) 131 << " " << (char) 132 << " " 
		<<(char) 135 << " " << (char) 130 << " " 
		<< (char) 136 << " " << (char) 161 << " " 
		<< (char) 162 << " " << (char) 147 << " " 
		<< (char) 148 << " " << (char) 163 << " " 
		<<  endl;

    cout << "\nPresione enter para volver al menu abecedarios";
	
	char c;
	do{
		c = getch();
	} while(c != 13);
	
	system("chcp 850");
	system("cls");
	
	system("cls");
	
    return;
}

void abecedario_frances() {

    // Alfabeto en minusculas
    cout << "------------------------\n" <<
        "|Alfabeto en minusculas|\n" <<
        "------------------------" << endl;

    cout << "a b c d e f g h i j\n" <<
        "k l m n o p q r s t\n" <<
        "u v w x y z" << endl << endl;

    // Alfabeto en mayusculas
    cout << "------------------------\n" <<
        "|Alfabeto en mayusculas|\n" <<
        "------------------------" << endl;

    cout << "A B C D E F G H I J\n" <<
        "K L M N O P Q R S T\n" <<
        "U V W X Y Z" << endl << endl;

    // Minusculas acentuadas 
    cout << "-----------------------\n" <<
        "|Minusculas Acentuadas|\n" <<
        "-----------------------" << endl;
    cout << (char) 133 << " " << (char) 131 << " "
		<< (char) 145 << " " << (char) 135 << " "
		<< (char) 130 << " " << (char) 138 << " "
		<< (char) 136 << " " << (char) 137 << " " 
		<< (char) 140 << " " << (char) 139 << endl
		<< (char) 147 << " " << (char) 148 << " " 
		<< (char) 151 << " " << (char) 150 << " " 
		<< (char) 129 << " " << (char) 152 << endl;

    
	cout << "\nPresione enter para volver al menu abecedarios";
	
	char c;
	do{
		c = getch();
	} while(c != 13);
	
	system("cls");
	
    return;
}

