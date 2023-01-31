#include <iostream>
#include <fstream>
#include "funzioni.h"
#include <cstdlib> //mi serve per usare atoi

using namespace std;

int main(int argc, char** argv) {

    if(argc<4) {
        cout << "Uso del programma: " << argv[0] << " <n_data> <nome_file> <nome_outfile>" << endl;
        return -1;
    } //argv[0] e assegato al nome dell'eseguibile

    int ntot = atoi(argv[1]); //converto a int

    char *filename = argv[2];

    char *fileout = argv[3];
    
    double *v = read_load(ntot, filename);

    cout << "Media: " << media(v, ntot) << endl;

    cout << "Varianza: " << varianza(v, ntot) << endl;

    cout << "Mediana: " << mediana(v, ntot) << endl;

    double *vcopy = new double[ntot];
    for(int k = 0; k<ntot; k++) {
    vcopy[k] = v[k];
    }

    sort_by (vcopy, ntot);

    print(fileout, vcopy, ntot);

    print(vcopy, ntot);

    delete [] v;
    delete [] vcopy;

    return 0;

}