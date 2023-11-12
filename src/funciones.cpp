#include "funciones.h"
using namespace std;

// Funciones de menu
void logo() {

    system("color F0"); // Fondo negro y texto verde

    string bienvenidos = "BIENVENIDOS ;)";
    int tam = bienvenidos.size();

    // Logo
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

void bienvenida() {

    logo();

    if (cin.get() == '\n') {
        ValidacionID();
    }
}

void ValidacionID() {
	// Si se le ingresa un numero de legajo valido, esta genera una contraseña
    system("cls");

    bool flagNumero;
    int legajo;
    string legajoS;
    bool dentroDeRango = false;
    int ID[5];

    gotoxy((100 - 28) / 2, 5);
    cout << "Ingrese su numero de legajo: " << endl;
    do { // Validacion del numero de legajo.

        flagNumero = true;
		
        limpiarRenglon(7);
        gotoxy(47, 7);
        getline(cin, legajoS);
		
        int i = 0, tam = legajoS.size();
        while (flagNumero and i < tam) {
            if (!isdigit(legajoS.at(i))) {
                flagNumero = false;
            }
            i++;
        }

        if (flagNumero)
            legajo = stoi(legajoS);

        gotoxy((100 - 55) / 2, 8);
		
        if ((legajo >= 10000 and legajo <= 89999) and flagNumero) 
			dentroDeRango = true;
		
        else 
			cout << "Legajo incorrecto. Por favor ingrese de nuevo su legajo" << endl;
    } while (!dentroDeRango);

    if (dentroDeRango) {
        generarID(legajo, ID);
        ValidacionContrasenia(ID);
    }
}

void generarID(int legajo, int ID[]) {
    // Generacion de la contraseña
    int aux;

    for (int i = 4; i >= 0; i--) { 
		/*
		Genero arreglo con el numero de legajo 
		para luego trabajar cada posicion por si sola. 
        */
		ID[i] = legajo % 10;
		legajo /= 10;
    }
	
    aux = ID[0];
    ID[0] = ID[4]; //le asigno al primer digito el valor del ultimo
    ID[4] = (ID[0] + aux) % 10; // asigno al ultimo digito el valor correspondiente
    aux = ID[1];
    ID[1] = ID[3]; //invierto las posiciones 2 y 4
    ID[3] = aux;

}

void Ingresarcontrasenia(char Clave[]) {
    // Permite ingresar la contraseña y en pantalla se la muestra oculta (a traves de asteriscos)

    int i = 0;
	bool flag = true;

	do {
        
		Clave[i] = getch();
		
		if(Clave[i] == (char) 13)
			flag = false;
		
		
		else if (Clave[i] != 8){// no es retroceso
			
            cout << '*'; // muestra por pantalla
			
			i++;	
        } 
		
		else if (i > 0) {// es retroceso y hay caracteres
			
            cout << (char) 8 << (char) 32 << (char) 8;
			
            i--; //el caracter a borrar el backspace
        }
		
    } while (flag);
	
	Clave[5] = '\0';
}

void ValidacionContrasenia(int ID[]) { // Esta funcion valida la contraseña
	
    int intentos = 0, i = 4;
    bool esValida = false;
    char contrasenia[6], claveReal[6];
	
	// Convierte ID numerico a una cadena
    convertirIDAchar(ID, claveReal, i); 

	
    gotoxy((100 - 22) / 2, 10);
    cout << "Ingrese la contrase" << char(164) << "a: " << endl;
	
    do { 
		/* 
		Validacion de contraseña, 3 intentos
		*/
		
        limpiarRenglon(12);
		
        gotoxy(47, 12);
        Ingresarcontrasenia(contrasenia);
		
        if (strstr(claveReal, contrasenia) != NULL) 
           
			esValida = true;
        
		
		else {
			
            gotoxy((100 - 63) / 2, 13);
			
            if (intentos < 2) 
				cout << "Contrase" << char(164) << "a incorrecta. "
				<< "Por favor ingrese" << endl;
			
            intentos++;
        }

        if (intentos > 2) {
			
            limpiarRenglon(13);
            gotoxy((100 - 31) / 2, 13);
			
            cout << char(173) << "Cantidad de intentos excedida!" << endl;
        }

    } while (!esValida and intentos < 3);

    if (esValida) menuPpal(); 
	// si la contraseña es correcta llamamos al menu principal

}

void convertirIDAchar(int ID[], char contrasenia[], int i) { 
	// Esta funcion convierte un arreglo entero en un arreglo de caracteres
    if (i == 0) {
        contrasenia[0] = ('0' + ID[0]);
        return;
    }
    contrasenia[i] = ('0' + ID[i]);

    return convertirIDAchar(ID, contrasenia, i - 1);
}

void menuPpal() {
	
	char opcion_user;
	bool flag = true;

    do {
		
		system("cls");
		
        cout << "----------------\n" <<
            "|MENU PRINCIPAL|\n" <<
            "----------------\n" <<
            "1) Abecedarios\n" <<
            "2) Juegos\n" <<
            "X) Salir de App\n" << endl;
		
		
        do {
            opcion_user = getch();
			
            gotoxy(0, 9);
			
        } while (!menu_valido(opcion_user));

        switch (opcion_user) {

        case '1':
            system("cls");
            menu_abecedarios();
            break;

        case '2':
            system("cls");
            menuJuegos();
            break;

        case 'X':
            flag = cierre_app();
            break;
        }

    } while (flag);

    return;
}


bool cierre_app() {
    system("cls");

    string opcion;
    bool es_opcion, continuar;
	
	
	// Alerta previa cerrar app
	cout << char(168) 
		<< "ESTAS SEGURO DE ABANDONAR?" <<
		"Escribe 'SI' si estas seguro\n" <<
		"'NO' para volver al menu" << endl;
	

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

bool menu_valido(char c) {

    bool rep;

    if (isdigit(c) or toupper(c) == 'X') 
		
        rep = true;
		
    
	else{
		
		rep = false;
		cout << "Opcion no disponible";
	}
	
    return rep;
}

void limpiarRenglon(int nRenglon) {
    for (int i = 0; i < 100; i++) {
        gotoxy(0 + i, nRenglon);
        cout << " ";
    }
}

void menuJuegos() {
	
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
            palabraCifrada(P);
            break;
			
        case '3':
            ValidacionDatosNroOtroIdioma();
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

void menu_abecedarios() {

    char opcion;
	bool flag = true;

    do {
        system("cls");
		
        cout << "------------------\n" <<
            "|MENU ABECEDARIOS|\n" <<
            "------------------\n" <<
            "1) Espa" << char(164) << "ol\n" <<
            "2) Ingles\n" <<
            "3) Italiano\n" <<
            "4) Portugues\n" <<
            "5) Frances\n" <<
            "X) Para volver al menu\n" << endl;
		
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

void identificar_espacios_al_final(string & palabra) {

    int indice = palabra.find_first_of(" ");
    palabra = palabra.substr(0, indice);

    return;
}

void pasar_minusculas(string & palabra) {

    int tam = palabra.size();

    for (int i = 0; i < tam; i++) {

        palabra[i] = tolower(palabra[i]);
    }
    return;
}

bool verificar_si_o_no(string palabra) {

    bool valido = false;
    if (palabra == "si"
        or palabra == "no") valido = true;

    return valido;
}



// Funciones de Juegos
void lectorPalabras(string P[]) {

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
		} while (not final);
	}
}

int pot(int b, int e) {
    // Calcula potencia recursivamente
    if (e == 0) return 1;
    return b * pot(b, e - 1);
}

void gotoxy(SHORT x, SHORT y) {
    COORD cp = {
        x,
        y
    };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

bool esIntentoInval(string letra) {
    /*
    La funcion devuelve 1 (invalido) si la cadena ingresada es 
    nula, tiene una longitud mayor a un caracter, o no es una letra.
    */
    return (letra.empty() or(letra.length() > 1) or!isalpha(letra.at(0)));
}

void cartelesIntentos(int avisoIntento, string letra, string ultimoIntento, int fila) {
    //Limpiar mensaje previo
    limpiarRenglon(fila);

    // Si se ha ingresado una letra ya intentada, se avisa al usuario
    if (avisoIntento) {
        string x = "Ya se ha intentado la letra " + ultimoIntento;
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }

    // Si se ingreso mas de una letra, se avisa al usuario
    if (letra.length() > 1) {
        string x = "Por favor, no ingrese mas de una letra por vez";
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }

    // Si se ingreso algo que no es letra, se avisa al usuario
    else if (!letra.empty() and!isalpha(letra.at(0))) {
        string x = "Por favor, ingrese unicamente letras";
        gotoxy((100 - x.length()) / 2, fila);
        cout << x;
    }
}

//Ahorcado
void ahorcado(string P[]) {
    srand(time(NULL));

    // Declaracion Variables
    // El string Prand guarda una palabra aleatoria de las 100 del archivo txt
    string Prand = P[rand() % 100];
    string letra, aux, intentos, ultimoIntento;
    int errores = 0, avisoIntento = 0;

    // Crea cadena de guiones bajos
    for (int i = 0; unsigned(i) < Prand.length(); i++)
        aux += "_";

    do {

        /*
        Hacer mientras la cantidad de errores sea menor a la permitida
        y no se haya adivinado la palabra
        */
        do {

            dibujarMonigote(aux, errores);

            cartelesIntentos(avisoIntento, letra, ultimoIntento, 27);

            gotoxy(34, 25);
            cout << "Ingresa letra: ";
            // Se pide input para la variable letra
            getline(cin, letra);

            // El comentario de letra ya intentada se evita sobreescribir
            avisoIntento = 0;

        } while (esIntentoInval(letra));

        // Una vez la letra paso la validacion, se pasa la pasa a minuscula 
        letra[0] = tolower(letra[0]);

        /*
        Si se encuentra que la letra ya fue intentada, se activa bandera de
        aviso y se guarda dicha letra en una variable string auxiliar para 
        imprimirla, sino, se envia el intento del usuario a la funcion de 
        reemplazo y error, se concatena la letra del intento al final
        de la variable intentos, y se anula la bandera de aviso de intento
        */
        if (intentos.find(letra) != -1) {
            avisoIntento = 1;
            ultimoIntento = letra.at(0);
        } else {
            errores += reemplazoAhorcado(Prand, aux, letra);
            intentos += letra.at(0);
            avisoIntento = 0;
        }

    } while (errores < 6 and Prand != aux);

    // Se imprime una vez mas para mostrar la palabra completa en caso de derrota
    dibujarMonigote(aux, errores);

    // Anuncio de resultado
    resultadoAhorcado(errores, Prand);
}

int reemplazoAhorcado(const string Prand, string & aux, string letra) {

    int apariciones = 0, pos = -1;

    do {
        // Buesca si la letra esta en la palabra aleatoria
        pos = Prand.find(letra, pos + 1);

        if (pos != -1) {
            /*
            Si esta la agrega al arreglo de renglones tantas veces 
            como aparezca y suma por vez la cantidad de apariciones
            */
            apariciones++;
            aux[pos] = Prand.at(pos);
        }

    } while (pos != -1);

    // Si no hubo apariciones, hubo error
    return (apariciones == 0);
}

void resultadoAhorcado(int errores, string Prand) {

    // Si el programa termino con menos de seis errores, el jugador gano
    if (errores < 6) {
        gotoxy(34, 25);
        cout << endl;
        gotoxy(34, 25);
        cout << "GANASTE!" << endl;
        gotoxy(34, 26);

        // El puntaje se calcula como el total menos la cantidad de partes
        // del monigote descubiertas
        cout << "Puntos: " << 100 - errores * 10 << endl;
        for (int i = 0; i < 3; i++) {
            system("color F2");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }

    //Si el programa termino con mas de seis errores, el jugador perdio
    else {
        gotoxy(80, 10);
        cout << Prand;
        gotoxy(34, 25);
        cout << endl;
        gotoxy(34, 25);
        cout << "PERDISTE!" << endl;
        gotoxy(34, 26);
        cout << "Puntos: " << 0 << endl;
        for (int i = 0; i < 3; i++) {
            system("color F4");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }

    Sleep(2000);
}

void dibujarMonigote(string aux, int errores) {
    // Limpia consola 
    system("cls");

    // Se imprime titulo, letras adivinadas y la base del ahorcado
    gotoxy(40, 0);
    cout << "AHORACADO";
    gotoxy(80, 10);
    cout << aux << endl;
    imprimirBase();

    // Estructura dibuja extremidades en funcion de errores cometidos
    switch (errores) {
    case 6:
        imprimirPiernaD();
    case 5:
        imprimirPiernaI();
    case 4:
        imprimirBrazoD();
    case 3:
        imprimirBrazoI();
    case 2:
        imprimirTorso();
    case 1:
        imprimirCabeza();
    default:
        ;
    };
}
void imprimirBase() {
    for (int i = 0; i < 25; i++) {
        gotoxy(30 + i, 20);
        cout << '_';
    }
    for (int k = 0; k < 12; k++) {
        gotoxy(31 + k, 1);
        cout << '_';
    }
    for (int j = 19; j > 0; j--) {
        gotoxy(30, 1 + j);
        cout << '|';
    }
    gotoxy(43, 2l);
    cout << '\\';
}

void imprimirPiernaD() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 + i, 13 + i);
        cout << '\\';
    }
}

void imprimirPiernaI() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 - i, 13 + i);
        cout << '/';
    }
}

void imprimirBrazoD() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 + i, 8 + i);
        cout << '\\';
    }
}

void imprimirBrazoI() {
    for (int i = 0; i < 4; i++) {
        gotoxy(44 - i, 8 + i);
        cout << '/';
    }
}

void imprimirTorso() {
    for (int i = 0; i < 5; i++) {
        gotoxy(44, 8 + i);
        cout << '|';
    }
}

void imprimirCabeza() {
    gotoxy(42, 3);
    cout << "00000" << endl;
    for (int i = 1; i <= 3; i++) {
        gotoxy(41, 3 + i);
        cout << "0     0" << endl;
    }
    gotoxy(42, 7);
    cout << "00000" << endl;
}

// Palabra cifrada
void palabraCifrada(string P[]) {
    srand(time(NULL));
    /* 
    Se considera que a mayor sea la palabra, mas intentos necesitara el 
    jugador, entonces para el maximo largo de palabra (14) se necesitadan
    3*14 intentos, y para la menor palabra posible se brindara una cantidad
    de dos veces el largo de la palabra, de esta manera se balancean los 
    los casos mas dificiles a mayor sencilles y los mas faciles a mayor 
    dificultad
    */
    const float k = float(-1) / float(12),
        b = 3.25;

    // Declaracion de Variables 
    // El string Prand guarda una palabra aleatoria de las 100 del archivo txt
    string Prand = P[rand() % 100], cesar, letra = "x", lIntentadas;
    string ultimoIntento, aux;
    int offset = 6, intentos = 0, avisoIntento = 0;
    int intentosMax = (b + k * Prand.length()) * Prand.length();

    // Encripta y guarda en arreglo auxiliar(cesar)
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
        if (lIntentadas.find(letra) != -1) {
            avisoIntento = 1;
            ultimoIntento = letra.at(0);
        } else {
            lIntentadas += letra.at(0);
        }

        // Siempre se cuenta el intento 
        intentos++;

        // Reemplaza caracter ingresado en la palabra auxiliar
        reemplazoCesar(Prand, aux, letra);

    } while (intentos < intentosMax and Prand != aux);

    // Carteles de victoria y derrota
    resultadoCesar(Prand, aux);

}

void encriptadorCesar(string Prand, string & cesar, int offset) {
    char j;
    /* 
    Relleno arreglo cesar de letra de la palabra ingresada mas offset posicion
    por posicion
    */
    for (unsigned int i = 0; i < Prand.length(); i++) {
        j = Prand.at(i);
        // Casos desde o hasta letra i
        if (j < 'i' || j >= 'o')
            cesar += (j - 'a' + offset) % (('z' + 1) - 'a') + 'a';

        // Casos entre letra o e i
        else if (j < 'o'
            and j > 'i')
            cesar += (j - ('a' + 1) + offset) % (('z' + 1) - 'a') + 'a';

        //casos particulares para la ñ y la i
        else if (j == char(164))
            cesar += 't';
        else if (j == 'i')
            cesar += char(164);
    }
}

void reemplazoCesar(const string Prand, string & cesar, string letra) {

    unsigned int i = 0;

    /*
    Se fija en el arreglo de la palabra ganadora si esta la letra intentada
    por el usuario, y cuando la encuentra, la reemplaza en el arreglo auxiliar
    tantas veces como esta aparezca
    */

    while (i < Prand.length()) {
        if (Prand.at(i) == letra.at(0)) {
            cesar[i] = Prand.at(i);
        }
        i++;
    }
}

void resultadoCesar(string Prand, string aux) {

    // Cartel de victoria
    if (Prand == aux) {

        gotoxy((100 - aux.length()) / 2, 15);
        cout << Prand;
        gotoxy((100 - aux.length()) / 2, 17);
        cout << aux;

        gotoxy((100 - Prand.length()) / 2, 15);
        cout << Prand;
        gotoxy(42, 25);
        cout << "                             ";
        gotoxy(46, 25);
        cout << "GANASTE";
        for (int i = 0; i < 3; i++) {
            system("color F2");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }

    // Cartel de derrota
    else {

        gotoxy((100 - aux.length()) / 2, 15);
        cout << Prand;

        gotoxy(42, 25);
        cout << "                             ";
        gotoxy(46, 25);
        cout << "PERDISTE";
        for (int i = 0; i < 3; i++) {
            system("color F4");
            Sleep(1000);
            system("color F0");
            Sleep(1000);
        }
    }
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

    ordenar_mayorAmenor(p_selec); // ordena el vector de la palabra mas corta a la mas larga

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

void intercambiar(int & a, int & b) {

    int aux = a;
    a = b;
    b = aux;

    return;
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

char letra_mas_repetida(const string palabra) {

    /*Si la palabra tiene la misma cantidad de letras, se toma
    como correcta la primera letra de la palabra*/

    int tam = palabra.size();
    int cont, max = 0, pos_max;

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

// Numeros en otro idioma
void ValidacionDatosNroOtroIdioma() {
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
void mostrarEscrito(const int numero,
    const int Nroidioma) { // Esta funcion es llamada por la general y meustra el numero de manera escrita en el idioma que corresponde
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
    cout << (char) 160 << " " << (char) 130 << " " << (char) 161 << " " << (char) 162 << " " << (char) 163 << endl;

    do {
        cout << "\nPresione enter para volver al menu abecedarios";
    } while (cin.get() != '\n');

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

    do {
        cout << "\nPresione enter para volver al menu abecedarios";
    } while (cin.get() != '\n');

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

    do {
        cout << "\nPresione enter para volver al menu abecedarios";
    } while (cin.get() != '\n');

    return;
}

void abecedario_portugues() {

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
    cout << (char) 160 << " " << (char) 133 << " " << (char) 131 << " " << (char) 130 << " " << (char) 136 << " " << (char) 161 << " " << (char) 162 << " " << (char) 147 << " " << (char) 163 << " " << (char) 128 << endl;

    do {
        cout << "\nPresione enter para volver al menu abecedarios";
    } while (cin.get() != '\n');

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
    cout << (char) 133 << " " << (char) 131 << " " << (char) 130 << " " << (char) 138 << " " << (char) 136 << " " << (char) 137 << " " << (char) 140 << " " << (char) 139 << " " << (char) 147 << " " << (char) 148 << " " << (char) 151 << " " << (char) 150 << " " << (char) 152 << endl;

    do {
        cout << "\nPresione enter para volver al menu abecedarios";
    } while (cin.get() != '\n');

    return;
}
