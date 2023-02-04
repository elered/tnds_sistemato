#ifndef __campovettoriale_h__
#define __campovettoriale_h__

#include "posizione.h"
#include "campovettoriale.h"
#include <assert.h>
#include <cmath>
#include <iostream>

using namespace std;

class campovettoriale : public posizione {

public:
 campovettoriale(const posizione & v) : posizione(v) {
 double m_Fx = 0;
 double m_Fy = 0;
 double m_Fz = 0;
}
  campovettoriale(const posizione & v, double Fx, double Fy, double Fz) : posizione(v) {
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}
  campovettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : posizione(x,y,z) {
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}
  ~campovettoriale() {}

  campovettoriale &operator+=(const campovettoriale & v) {
    return (*this)=(*this)+v;
}
  campovettoriale operator+(const campovettoriale & v) const {
    campovettoriale sum(v);
    sum.m_Fx+=getFx();
    sum.m_Fy+=getFy();
    sum.m_Fz+=getFz();
    return sum;
}

  double getFx() const { return m_Fx; }
  double getFy() const { return m_Fy; }
  double getFz() const { return m_Fz; }

  double modulo() {
    return sqrt(pow(m_Fx, 2)+pow(m_Fy, 2)+pow(m_Fz, 2));
}

private:
  double m_Fx, m_Fy, m_Fz;
};

#endif // __campovettoriale_h__