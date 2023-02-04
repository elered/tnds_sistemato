#include "parabola.h"
#include "funzione_base.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {


    if(argc!=4) {
        cerr << "Utilizzo del programma: " << argv[0] << " <coeff a> <coeff b> <coeff c>" << endl;
        exit(-1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    parabola p(a,b,c);

    p.vertice ();


return 0;
}