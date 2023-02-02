#include "particella.h"
#include <iostream>
#include <cmath>

using namespace std;

particella::particella(double massa, double carica) {
    m_massa = massa;
    m_carica = carica;
}

particella::~particella() {
    //vuoto
}

void particella::print() const {
    cout << "Particella: m = " << m_massa << endl;
    cout << "Particella: carica = " << m_carica << endl;
}

elettrone::~elettrone() {
    //vuoto
}

void elettrone::print() const {
    cout << "elettrone: m = " << m_massa << endl;
    cout << "elettrone: carica= " << m_carica << endl;

}
