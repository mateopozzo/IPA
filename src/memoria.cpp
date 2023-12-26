#include "memoria.h"
#include "fgrales.h"
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Memoria
void juego_memoria(string tex[]) {

    system("cls");

    srand(time(NULL)); // valor semilla para pasarle a la funcion y que busque una palabra en el archivo de texto 

    string p_selec[5]; // arreglo de 5 string que guardara las palabras 

    for (int i = 0; i < 5; i++) { // cargo las palabras seleccionadas

        p_selec[i] = tex[rand() % 100];
    }

    cout << "--------------------\n" <<
        "|PALABRAS ALEATORIAS|\n" <<
        "--------------------" << endl;

    for (int j = 0; j < 5; j++) { // muestro contedido del vector 

        cout << j + 1 << ")" << p_selec[j] << endl;
    }

    Sleep(2000); // hace una pausa de 2 seg
    system("cls"); // limpia la pantalla 

    cout << (char) 173 << "QUE COMIENCE EL JUEGO!" << endl;

    /*PARTE A: El usuario debe identificar la letra que mas se repite en cada palabra. 
    Puntos maximos a obtener = 30. Por cada letra acertada, se suman 6 puntos en esta primera
    parte. En el caso de que una palabra tenga 2 o mas letras con la misma cantidad, se considera
    correcta aquella que se encuentra en la posicion mas cercana al inicio de la palabra*/

	// modificado por franco el 18-11-23 
    cout << "\n----- PARTE A -----" << endl;

    float puntos_a = 0.0;
	int cant_mas_repet = 0, frecuencia_alter = 0;
    char letra_mas_repe, letra_usuario; // variable para que el usuario ingrese la letra que mas se repite
	string ingreso_letra;
	bool aviso_letra;
	
	cout << "Ingrese la Letra mas Repetida: "; 
	
	do{
		getline(cin, ingreso_letra); 
		
		if(ingreso_letra.size()!=1 or !isalpha(ingreso_letra.at(0))){
			
			aviso_letra = true;
			
			cout << "Ingrese unicamente una letra" << endl;
			
		}
		
		else aviso_letra = false;
		
	} while(aviso_letra);

	letra_usuario = ingreso_letra.at(0);
	
    letra_mas_repe = mas_repetida(p_selec , 5, cant_mas_repet); 
	
	if (letra_usuario == letra_mas_repe) puntos_a = 30.0; 
	else{
		
		frecuencia_alter = frecuencia_letra(p_selec, 5, letra_usuario); 
		puntos_a = ((float)frecuencia_alter*30.0)/(float)cant_mas_repet;
	}

    /*PARTE B: El usuario debe colocar la cantidad de vocales que hay entre las cinco palabras.
    Puntos maximos a obtener = 40. El criterio de puntaje adoptado por el grupo se divide en dos casos: 
    1- Si la cantidad ingresada es menor a la cantidad real de vocales que hay, el puntaque que se obtiene es 
    por medio de regla de 3.
    2- Si la cantidad que ingresa el usuario es mayor a la real, se calcula la diferencia y se le resta a la
    cantidad real de vocales para posteriormente calcular el puntaje por medio de regla de 3. Si la diferencia representa
    el doble o mas de la cantidad de vocales, al usuario se le asignan cero puntos. 
    Ejemplo, si la cantidad que ingreso el usuario es 18, y la cantidad de vocales es 15, se realiza 18-15 = 3 para
    calcular la diferencia y luego 15-3 = 12 para finalmente asignar el puntaje. Por lo que, en la logica del programa
    el usuario recibira el mismo puntaje tanto si ingresa 12 como 18. Por otro lado, si el usuario hubiese colocado 35, se 
    hubiese llevado cero puntos.*/

    cout << "\n----- PARTE B -----" << endl;

    int cant_tot = 0, cant;
    string adivinar_cant; // variable para ingresar la cant de vocales 
    float puntos_b;
    bool valido;

    for (int k = 0; k < 5; k++) {
        cant_tot += cant_tot_vocales(p_selec[k]);
    }
    cout << "Ingrese cantidad total de vocales: ";
	
    do { // valido que el numero ingresado NO sea negativo y sea un numero.
        cin >> ws;
        getline(cin, adivinar_cant);
        int h = 0, tam = adivinar_cant.size();
        valido = (tam < 8); // Solo puede ser valido si ingresa un numero almacenable en un int
		
        while (valido and h < tam) { // valido que el string represente numeros
			if ( isalpha(adivinar_cant.at(h)) ) 
				valido = false;
			
            h++;
        }
		
        if (valido == false) cout << "No se ingreso una cantidad valida, por favor reingresar: ";
		
        else {
            cant = stoi(adivinar_cant);
            if (cant < 0) cout << "No se permite el ingreso de cantidades negativas, por favor reingresar: ";
        }
		
    } while (!valido or cant < 0);

    puntos_b = asignar_puntos(cant_tot, cant, 40);

    /*PARTE C: El usuario debe advinar la palabra de mayor longitud.
    Puntos maximos a obtener = 30. Como en esta parte se ordena el arreglo de las 5 palabras de
    forma tal que la de menor longitud quede al inicio y la de mayor al final, al ingresar la
    palabra que el usuario cree que es la mas larga, comienza una busqueda secualcial la cual inicia al 
    final del vector. Si la funcion encuentra una coincidencia, multiplica por 6 las pos + 1, para obtener el 
    puntaje final.*/

    cout << "\n----- PARTE C -----" << endl;

    string palabra_usuario;
    bool palabra_valida = false, espos = false;
    float puntos_c = 6.0;

    ordenar_mayorAmenor(p_selec); // ordena el vector de la palabra mas corta a la mas larga

    cout << "Ingrese cual fue la palabra de mayor longitud: ";

	getline(cin, palabra_usuario);
	
	identificar_espacios_al_final(palabra_usuario); // por si el usuario ingreso espacios al final, para que no de error, los borra si hubiesen
	
	pasar_minusculas(palabra_usuario); // paso la palabra todas a minusculas en el caso de que se haya ingresado alguna mayuscula
	
	palabra_valida = validar_palabra(palabra_usuario, p_selec); // verfifico que la palabra ingresada sea una de las 5 aleatorias
	
	if (palabra_valida == false) cout << "La palabra no es igual a ninguna de las 5. ";
	
	//asignacion de puntos 
	
	int w = 4;
    while (!espos and w >= 0) {
        if (palabra_usuario == p_selec[w]) {
            puntos_c = 6.0 * (float)(w + 1);
            espos = true;
        }
        w--;
    }

    cout << "\n----- RESULTADOS -----\n" <<
        "PUNTOS EN A: " << fixed << setprecision(2) << puntos_a << "\n" <<
        "PUNTOS EN B: " << fixed << setprecision(2) << puntos_b << "\n" <<
        "PUNTOS EN C: " << puntos_c << "\n\n" <<
        "-------------------------\n" <<
        "|RESULTADO: " << fixed << setprecision(2) << puntos_a + puntos_b + puntos_c << " PUNTOS|\n" <<
        "-------------------------" << endl;

    Sleep(5000); // pausa de 5 segundos para visualizar el resultado antes de volver al menu principal 

    return;
}


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

void ordenar_mayorAmenor(string vec[]) {

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

char mas_repetida(const string vec[], int t, int& sum) {
	
	/*Si la palabra tiene la misma cantidad de letras, se toma
	como correcta la primera letra de la palabra*/
	
	string palabra; 
	int tam, cont, max = 0, pos_max;
	
	for (int j = 0 ; j < t ; j++){
		
		palabra += vec[j]; 
	}
	
	tam = palabra.size();
	
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
	sum = max; 
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

int frecuencia_letra(const string vec[], int t, char letra){
	
	string palabra; 
	int tam, cont = 0;
	
	for (int j = 0 ; j < t ; j++){
		
		palabra += vec[j]; 
	}
	tam = palabra.size(); 
	
	for (int pos = 0; pos < tam; pos++) if (palabra[pos] == letra) cont++;
	
	return cont; 
}
