#include "fgrales.h"
#include "ahorcado.h"
#include "memoria.h"
#include "pcifrada.h"
#include "noidm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

bool esIntentoInval(string letra) {
    /*
    Es una sola letra 
    */
    return (letra.length() != 1 or !isalpha(letra.at(0)));
}


//Ahorcado
void ahorcado(string P[]) {
	
	system("cls");
    srand(time(NULL));

    // Declaracion Variables
    // El string Prand guarda una palabra aleatoria de las 100 del archivo txt
    string Prand = P[rand() % 100];
    string letra, aux, intentos, ultimoIntento;
    int errores = 0, yaIntentada = 0;
	
	// Se imprime base y titulo por unica vez
	gotoxy(40, 0);
    cout << "AHORCADO";
	imprimirBase();

    // Crea cadena de guiones bajos
    for (int i = 0; unsigned(i) < Prand.length(); i++)
        aux += "_";

    do {

        /*
        Repetir mientras la cantidad de errores sea menor a 6
        y no se haya adivinado la palabra
        */
        do {
			// Validacion de entrada
			
            dibujarMonigote(aux, errores);
			
            cartelesIntentos(yaIntentada, letra, ultimoIntento, 27);
			
			limpiarRenglon(25);
            gotoxy(34, 25);
            cout << "Ingresa letra: ";
            getline(cin, letra);
			
            // El comentario de letra ya intentada se evita sobreescribir
            yaIntentada = 0;
			
        } while (esIntentoInval(letra));
		
		
        letra[0] = tolower(letra[0]);
		
        /*
        Si la letra ya fue intentada, se activa bandera de aviso y se guarda 
		para imprimirla, sino, se envia el intento del usuario a la funcion de 
        reemplazo, se concatena la letra del intento al final de la variable 
		intentos, y se anula la bandera de aviso
        */
		
        if (intentos.find(letra) != -1) {
			
            yaIntentada = 1;
            ultimoIntento = letra.at(0);
        } 
		else {
			
            errores += reemplazoAhorcado(Prand, aux, letra);
            intentos += letra.at(0);
            yaIntentada = 0;
        }
		
    } while (errores < 6 and Prand != aux);

    // Se imprime una vez mas para mostrar la palabra completa en caso de derrota
    dibujarMonigote(aux, errores);

    // Anuncio de resultado
    resultadoAhorcado(errores, Prand);
}


// Palabra cifrada
void cifrado_cesar(string P[]) {
    srand(time(NULL));
    /* 
    Se considera que a mayor sea la palabra, mas intentos necesitara el 
    jugador, entonces para el maximo largo de palabra (14) se necesitaran
    3*14 intentos, y para la menor palabra posible se brindara una cantidad
    de dos veces el largo de la palabra, de esta manera se balancean los 
    los casos mas dificiles a mayor sencilles y los mas faciles a mayor 
    dificultad
    */
    const float k = float(-1) / float(12),
        b = 3.25;

    // Declaracion de Variables 
    // El string Prand guarda una palabra aleatoria de las 100 del archivo txt
    string Prand = P[rand() % 100], cesar, letra = "x", l_intentadas;
    string ultimoIntento, aux;
    int offset = 6, intentos = 0, avisoIntento = 0;
	
	// Se calculan los intentos en funcion de la longitud de la palabra de adivinar
    int intentosMax = (b + k * Prand.length()) * Prand.length();

    // Encripta y guarda en string auxiliar(cesar)
    encriptadorCesar(Prand, cesar, offset);

    // Crea cadena de guiones bajos
    for (unsigned int i = 0; i < Prand.length(); i++)
        aux += "_";

    /*
    Mientras se tengan intentos y el string cesar sea distinto a la palabra
    a adivinar, pide al usuario ingresar una letra, y si pertenece a la palabra
    la descubre en el string cesar
    */

    do {
        // Limpia pantalla
        system("cls");

        gotoxy(43, 5);
        cout << "CIFRADO CESAR";

        // Calcula el medio de la pantalla e imprime la palabra cifrada
        // con los intentos acertados por el usuario
        gotoxy((100 - cesar.length()) / 2, 15);
        cout << cesar;

        gotoxy((100 - aux.length()) / 2, 17);
        cout << aux;
		
        do {
			
            cartelesIntentos(avisoIntento, letra, ultimoIntento, 27);
			
            limpiarRenglon(25);
            gotoxy(42, 25);
            cout << "Ingrese letra: ";
            getline(cin, letra);
            avisoIntento = 0;

        } while (esIntentoInval(letra));

        /*
        Si se encuentra el ultimo ingreso en las palabras ya intentadas
        se prende la bandera y se guarda este ultimo intento, sino, se 
        suma un intento y se concatena este ultimo a la string de intentos
        */
		letra = tolower(letra.at(0));
        if (l_intentadas.find(letra) != -1) {
            avisoIntento = 1;
            ultimoIntento = letra.at(0);
        } else {
            l_intentadas += letra.at(0);
        }

        // Siempre se cuenta el intento 
        intentos++;

        // Reemplaza caracter ingresado en la palabra auxiliar
        reemplazoCesar(Prand, aux, letra);

    } while (intentos < intentosMax and Prand != aux);

    // Carteles de victoria y derrota
    resultadoCesar(Prand, aux);
}

// Memoria
void juego_memoria(string tex[]) {

    system("cls");

    srand(time(NULL)); // valor semilla para pasarle a la funcion y que busque una palabra en el archivo de texto 

    string p_selec[5]; // arreglo de 100 string que guardara las palabras del texto y otro con las 5 seleccionadas 

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

    cout << "¡QUE COMIENCE EL JUEGO!" << endl;

    /*PARTE A: El usuario debe identificar la letra que mas se repite en cada palabra. 
    Puntos maximos a obtener = 30. Por cada letra acertada, se suman 6 puntos en esta primera
    parte. En el caso de que una palabra tenga 2 o mas letras con la misma cantidad, se considera
    correcta aquella que se encuentra en la posicion mas cercana al inicio de la palabra*/

    cout << "\n----- PARTE A -----" << endl;

    float puntos_a = 0.0;
    char letras_mas_repe[5];
    char letra_usuario; // variable para que el usuario ingrese la letra que mas se repite

    for (int m = 0; m < 5; m++) { // calculo las letras mas repetidas de cada palabra 

        letras_mas_repe[m] = letra_mas_repetida(p_selec[m]);
    }

    int k;
    for (k = 0; k < 5; k++) {

        cout << "Ingrese letra mas repetida de la palabra " << k + 1 << ": ";

        do {
            cin >> letra_usuario;
        } while (!isalpha(letra_usuario));

        if (letra_usuario == letras_mas_repe[k]) puntos_a += 6.0;
    }
    k = 0; // reciclo variable contador 

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

    for (; k < 5; k++) {

        cant_tot += cant_tot_vocales(p_selec[k]);
    }
    cout << "Ingrese cantidad total de vocales: ";

    do { // valido que el numero ingresado NO sea negativo y sea un numero.

        cin >> ws;
        getline(cin, adivinar_cant);
        int h = 0, tam = adivinar_cant.size();
        valido = true;

        while (valido and h < tam) {

            if ((adivinar_cant[h] >= 'a'
                    and adivinar_cant[h] <= 'z') or(adivinar_cant[h] >= 'A'
                    and adivinar_cant[h] <= 'Z')) valido = false;
            h++;
        }
        if (valido == false) cout << "No se ingreso una cantidad, por favor reingresar: ";
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

    ordenar_mayor_a_menor(p_selec); // ordena el vector de la palabra mas corta a la mas larga

    cout << "Ingrese cual fue la palabra de mayor longitud: ";

    do {
        getline(cin, palabra_usuario);

        identificar_espacios_al_final(palabra_usuario); // por si el usuario ingreso espacios al final, para que no error el programa esto los borra si hubiesen

        pasar_minusculas(palabra_usuario); // paso la palabra todas a minusculas en el caso de que se haya ingresado alguna mayuscula

        palabra_valida = validar_palabra(palabra_usuario, p_selec); // verfifico que la palabra ingresada sea una de las 5 aleatorias

        if (palabra_valida == false) cout << "La palabra no es igual a ninguna de las 5, reingresar: ";

    } while (!palabra_valida); // no sale del bucle hasta que la palabra no sea una de esas 5

    int w = 4;
    while (!espos or w >= 0) {

        if (palabra_usuario == p_selec[w]) {

            puntos_c = 6.0 * (float)(w + 1);
            espos = true;
        }
        w--;
    }

    cout << "\n----- RESULTADOS -----\n" <<
        "PUNTOS EN A: " << puntos_a << "\n" <<
        "PUNTOS EN B: " << fixed << setprecision(2) << puntos_b << "\n" <<
        "PUNTOS EN C: " << puntos_c << "\n\n" <<
        "-------------------------\n" <<
        "|RESULTADO: " << fixed << setprecision(2) << puntos_a + puntos_b + puntos_c << " PUNTOS|\n" <<
        "-------------------------" << endl;

    do {
        cout << endl << "Ingrese enter para volver al menu principal" << endl;
    } while ((cin.get() != '\n'));

    return;
}


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
		
    } while (aumento.size() != 1 and (Nroidioma < "1" or Nroidioma > "5"));
	
	
    gotoxy(0, 15);
    cout << "Ingrese el aumento  del gr" << (char) 160 
		<< "fico (Debe estar en el rango [1;4]): " << endl;
	
	
    do {// Validacion de aumento
        
        limpiarRenglon(17);
        gotoxy(0, 17);
        getline(cin, aumento);
		
    } while (aumento.size() != 1 and (Nroidioma < "1" or Nroidioma > "4"));

    NumerosEnOtroIdioma(numero, Nroidioma, aumento);
}
