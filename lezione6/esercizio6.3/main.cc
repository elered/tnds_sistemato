#include <iostream>
#include <cmath>
#include <iomanip>
#include "bisezione.h"

using namespace std;

int main(int argc, char** argv) {


    if(argc!=2) {
        cerr << "Utilizzo del programma: " << argv[0] << " <precisione (maggiore di 10^-6)>" << endl;
        exit(-1);
    }

    double prec = atof(argv[1]);
 
    int cifre_significative = -log10(prec);

    bisezione bis;
    funz f;

    if(prec > 10E-6) {
        cout << "Aumentare la precisione" << endl;
    } else {

     for(int n=1; n<21; n++) {

        double min = n*M_PI;
        double max = (n*M_PI)+(M_PI/2);

        cout << "Lo zero numero " << n << " è: " << setprecision(cifre_significative) << bis.cercazeri(min, max, f, prec) << endl;

        }
    }

    return 0;
}