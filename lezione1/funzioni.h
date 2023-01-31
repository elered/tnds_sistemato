#include <string>

using namespace std;

double *read_load(int ntot, char *filename);

double media(double *m, int ntot);

double varianza(double *m, int ntot);

double mediana(double *m, int ntot);

void print(const char* filename, double *m, int ntot);

void print(double *m, int ntot);

void sort_by (double *m, int ntot);

void scambia_byvalue (double a, double b);

void scambia_bypointer (double *a, double *b);

void scambia_byref (double &a, double &b);