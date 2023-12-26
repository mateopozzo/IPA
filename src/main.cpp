#include "menues.h"
#include "libro.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

int main() {
	system("mode con: cols=100 lines=30");
	system("chcp 850");	//	codepage de consola ASCII
	
	bienvenida();
	
	return 0;
}

