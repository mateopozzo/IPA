#include "menues.h"

using namespace std;

int main() {
	system("echo off");
	system("color F0");						//	Fondo blanco texto negro
	system("mode con: cols=100 lines=30");	//	Buffer de terminal
	system("chcp 850");						//	codepage de consola ASCII
	
	bienvenida();
	
	return 0;
}

