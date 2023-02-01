#include "vettore.h"
#include <iostream>

using namespace std;

Vettore read(int ntot, const char* filename);
double media (const Vettore &v);
double varianza(const Vettore &v);
double dev_std(Vettore v);
void sort_by (Vettore &v);
double mediana (Vettore v);
void print(const char* filename,  Vettore &v);
void print(Vettore &v);

