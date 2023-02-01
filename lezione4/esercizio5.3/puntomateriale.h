#ifndef __puntomateriale_h__
#define __puntomateriale_h__

#include "particella.h"
#include "posizione.h"
#include "puntomateriale.h"
#include "campovettoriale.h"
#include <cmath>
#define _USE_MATH_DEFINES

class puntomateriale : public particella, posizione {

public:

  puntomateriale(double massa, double carica, const posizione& v) : particella (massa, carica), posizione(v) {

}
  puntomateriale(double massa, double carica, double x, double y, double z) : particella (massa,carica), posizione(x,y,z) {

}
  ~puntomateriale() {};

  campovettoriale campoelettrico(const posizione& r) const {
    campovettoriale E(r);
    const double e0 = 8.854187818E-12;
    double Ex = (getcarica()/(4*M_PI*e0))*((r.getx()-getx())/(pow(distanza(r), 3)));
    double Ey = (getcarica()/(4*M_PI*e0))*((r.gety()-gety())/(pow(distanza(r), 3)));
    double Ez = (getcarica()/(4*M_PI*e0))*((r.getz()-getz())/(pow(distanza(r), 3)));
    return campovettoriale(r, Ex, Ey, Ez);
}
  campovettoriale campogravitazionale(const posizione& r) const {
    campovettoriale E(r);
    const double G = 6.67430E-11;
    double Gx = (G*getmassa())*(pow((r.getx()-getx()),2));
    double Gy = (G*getmassa())*(pow((r.gety()-gety()),2));
    double Gz = (G*getmassa())*(pow((r.getz()-getz()),2));
    return campovettoriale(r, Gx, Gy, Gz);
}

};

#endif // __puntomateriale_h__