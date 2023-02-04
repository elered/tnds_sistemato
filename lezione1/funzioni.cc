#include <iostream>
#include <fstream>
#include <cmath>
#include "funzioni.h"

using namespace std;

double *read_load(int ntot, char *filename){

    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good())
        throw runtime_error("ERROR, failed to open file..."); //lancia un errore mentre il programma gira

    infile.clear(); infile.seekg(0);

    double *read = new double[ntot];
    for(int i = 0; i < ntot; i++){
        infile >> read[i];
    }
    infile.close();
    return read;
}

double media(double *m, int ntot){

    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    return sum/ntot;
}

double varianza(double *m, int ntot){

    double mean = media(m, ntot);
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i] - mean),2);
    }
    return (scarti/(ntot-1));
}

double dev_st (double *m, int ntot) {
    return sqrt(varianza(m, ntot));
}

void scambia_byvalue (double a, double b) {

    double c = a;
    a = b;
    b = c;

}

void scambia_bypointer (double *a, double *b) {
    
    double c = *a;
    *a = *b;
    *b = c;

}

void scambia_byref (double &a, double &b) {
    
    double c = a;
    a = b;
    b = c;

}

void sort_by (double *m, int ntot) {

    int minindex = 0;
    double min = 0;

    for(int j = 0; j<ntot-1; j++) {
        minindex = j;
        min = m[minindex];
        for(int i = j+1; i<ntot; i++) {
            if(m[i]<min) {
                min = m[i];
                minindex = i;
            }

        }

        scambia_byref(m[j], m[minindex]);
    }

}

double mediana(double *m, int ntot) {

    double *vcopy = new double[ntot];
    for(int k = 0; k<ntot; k++) {
    vcopy[k] = m[k];
    }

    sort_by(vcopy, ntot);

    double mediana = 0;
        if(ntot%2==0) {
            mediana = (vcopy[(ntot/2)-1] + vcopy[ntot/2])/2;
            } else {
               mediana = vcopy[ntot/2];
            }

    delete [] vcopy;
    return mediana;
}

void print(const char* filename,  double *m, int ntot) {

    fstream outfile(filename, ios::out);
    outfile << "Array riordinato:" << endl;
    for(int i=0; i<ntot; i++) {
        outfile << "Elemento " << i+1 << ": " << m[i] << endl;
    }
    outfile.close();
}

void print(double *m, int ntot) {

    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<ntot; i++) {
        cout << "Elemento " << i+1 << ": " << m[i] << endl;
    }
}

