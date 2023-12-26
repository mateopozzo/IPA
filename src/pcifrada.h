#ifndef PCIFRADA_H
#define PCIFRADA_H

#include <string>
using namespace std;

void cifrado_cesar(string P[]);
void encriptadorCesar(string Prand, string & cesar, int offset);
void reemplazoCesar(const string Prand, string & cesar, string letra);
void resultadoCesar(string Prand, string cesar);

#endif
