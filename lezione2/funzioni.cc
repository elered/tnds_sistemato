#include <iostream>
#include <cmath>
#include <fstream>
#include "funzioni.h"
#include "vettore.h"


Vettore read(int ntot, const char* filename) {

    Vettore v(ntot);
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good()) {
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);
    }else {
        for(int i = 0; i < ntot; i++){

            double vector = 0;
            infile >> vector;
            v.SetComponent(i, vector);
            if(infile.eof()){
                break;
            }
        }
    }

    infile.close();
    return v;
}

double media (const Vettore &v)  {
    double sum = 0;
    for (int i = 0; i < v.GetN(); i++){
        sum += v.GetComponent(i);
    }
    return sum/(v.GetN());
}

double varianza (const Vettore &v) {
    double mean = media(v);
    return (mean/(v.GetN()-1));
}

double dev_std(Vettore v) {
    return sqrt(varianza(v));
}

void sort_by (Vettore &v) {
    double dep;              
    for (int i = 0; i < v.GetN() - 1; i++){
        for (int j = i + 1; j < v.GetN(); j++){
            if (v.GetComponent(i) > v.GetComponent(j)){
                v.scambia(i,j);
            }
        }   
    }
}

double mediana (Vettore v) {
    sort_by(v);
    double mediana;
        if(v.GetN()%2==0) {
            mediana = (v[(v.GetN()-1)/2] + v[v.GetN()/2])/2;
        } else {
            mediana = v[v.GetN()/2];
        }
    return mediana;
}

void print(const char* filename,  Vettore &v) {
    fstream outfile(filename, ios::out);
    outfile << "Array riordinato: " << endl;
    for(int i=0; i<v.GetN(); i++) {
        outfile << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
    outfile.close();
}

void print(Vettore &v) {
    cout << "Elementi dell'array:" << endl;
    for(int i=0; i<v.GetN(); i++) {
        cout << "Elemento " << i+1 << ": " << v.GetComponent(i) << endl;
    }
}