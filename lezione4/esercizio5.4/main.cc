#include "puntomateriale.h"
#include "campovettoriale.h"
#include "posizione.h"
#include "particella.h"
#include<cmath>
#include<iostream>
#include<cstdlib>
#define _USE_MATH_DEFINES

using namespace std;

int main(int argc, char** argv) {

    if(argc!=2) {
        cerr << "Utilizzo del programma: " << argv[0] << " numero pari di cariche" << endl;
        exit(-1);
    }

    int n = atoi(argv[1]);

    if((n%2)!=0) {
        cout << "Inserire un numero pari" << endl;
        exit(1);
    }

    const double R = 1E-8;
    const double r0 = 0.5E-10;

    posizione r(R,0,0);
    campovettoriale E(r);

    const double e = 1.60217653E-19;
    const double me = 9.1093826E-31;

    for(int i=0; i<n; i++) {
        double theta = (2*M_PI*i)/n;
        posizione a (r0*cos(theta), r0*sin(theta), 0);
        puntomateriale party (me, pow(-1, i)*e, a);
        E += party.campoelettrico(r);
    }

    cout << "E = (" << E.getFx() << ", " << E.getFy() << ", " << E.getFz() << ")" << endl;
    cout << "Modulo di E: " << E.modulo() << endl;

    return 0;
}