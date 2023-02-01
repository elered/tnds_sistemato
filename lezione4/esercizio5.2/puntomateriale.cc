#include "puntomateriale.h"
#include "particella.h"
#include "campovettoriale.h"
#include <cmath>

using namespace std;

puntomateriale::puntomateriale(double massa, double carica, double x, double y, double z) : particella (massa,carica), posizione(x,y,z) {

}

puntomateriale::~puntomateriale() {}

puntomateriale::puntomateriale(double massa, double carica, const posizione&v) : particella(massa,carica), posizione(v) {

}

campovettoriale puntomateriale::campoelettrico(const posizione& r) const {
    campovettoriale E(r);
    const double e0 = 8.854187818E-12;
    double Ex = (getcarica()/(4*M_PI*e0))*(1/(pow((r.getx()-getx()),2)));
    double Ey = (getcarica()/(4*M_PI*e0))*(1/(pow((r.gety()-gety()),2)));
    double Ez = (getcarica()/(4*M_PI*e0))*(1/(pow((r.getz()-getz()),2)));
    return campovettoriale(r, Ex, Ey, Ez);
}

campovettoriale puntomateriale::campogravitazionale(const posizione& r) const {
    campovettoriale E(r);
    const double G = 6.67430E-11;
    double Gx = (G*getmassa())*(pow((r.getx()-getx()),2));
    double Gy = (G*getmassa())*(pow((r.gety()-gety()),2));
    double Gz = (G*getmassa())*(pow((r.getz()-getz()),2));
    return campovettoriale(r, Gx, Gy, Gz);
}


