#include "puntomateriale.h"
#include "campovettoriale.h"
#include "posizione.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TF1.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {


    if(argc!=4) {
        cerr << "Utilizzo del programma: " << argv[0] << " <x> <y> <z>" << endl;
        exit(-1);
    }

    double x = atof(argv[1]);
    double y = atof(argv[2]);
    double z = atof(argv[3]);
    posizione r(x,y,z);
    posizione b(4, 9, 5);
    posizione o(0,0,0);

    const double e = 1.60217653E-19;
    const double me = 9.1093826E-31;
    const double mp = 1.6726217E-27;
    const double d = 1E-10;

    puntomateriale elettrone (me, -e, 0, 0, d/2);
    puntomateriale protone (mp, e, 0, 0, -d/2);

    campovettoriale E = elettrone.campoelettrico(r) + protone.campoelettrico(r);
    campovettoriale EE = elettrone.campoelettrico(b) + protone.campoelettrico(b);
    campovettoriale Eo = elettrone.campoelettrico(o) + protone.campoelettrico(o);

    double alpha = 0;

    alpha = (log(E.modulo()/EE.modulo()))/(log(Eo.distanza(r)/Eo.distanza(b)));

    cout << "E = (" << E.getFx() << ", " << E.getFy() << ", " << E.getFz() << ")" << endl;
    cout << "Modulo di E: " << E.modulo() << endl;
    cout << "Alpha: " << alpha << endl;

    TApplication myApp("app",0,0);
    TGraph field;
    posizione P(0,0,0);
    double E1 = 0;
    double E2 = 0;

    for(int i=100; i <= 1000; i++) {

        P.setz(i*d) ; //mi allontano per vedere l'andamento
        campovettoriale Ed = elettrone.campoelettrico(P) + protone.campoelettrico(P);

        if (i==100) E1 = Ed.modulo();
        if (i==1000) E2 = Ed.modulo();

        field.SetPoint(i-100, i*d, Ed.modulo()); //i-100 perchè funziona così addpoint
    }

	field.SetTitle("Andamento campo elettrico");
	field.GetXaxis()->SetTitle("Distanza sull'asse del dipolo (m)");
	field.GetYaxis()->SetTitle("Campo elettrico E (N/C))");

    field.Draw("ALP");

    myApp.Run();

    return 0;
}