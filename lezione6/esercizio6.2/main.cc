#include <iostream>
#include <cmath>
#include <float.h>
#include <iomanip>
#include "bisezione.h"
#include "parabola.h"

using namespace std;

int main(int argc, char** argv) {

    parabola p(3,5,-2);

    if(argc!=4) {
        cerr << "Utilizzo del programma: " << argv[0] << " <estremo a intervallo> <estremo b intervallo> <precisione>" << endl;
        exit(-1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double prec = atof(argv[3]);

    int cifre_significative = -log10(prec);

    bisezione bis;
    segno sign;

    double fa = p.eval(a);
    double fb = p.eval(b);

    if (sign.eval(fa)*sign.eval(fb)>0) {

    cout << "Non ci sono zeri o c'è più di uno zero nel'intervallo richiesto" << endl;
       
    } else {

    cout << "Lo zero è: " << setprecision(cifre_significative) << bis.cercazeri(a, b, p, prec) << endl;

    }

    return 0;
}