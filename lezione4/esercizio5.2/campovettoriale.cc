#include "campovettoriale.h"
#include <assert.h>
#include <cmath>
#include<iostream>
using namespace std;

campovettoriale::campovettoriale(const posizione&v) : posizione(v) {
 double m_Fx = 0;
 double m_Fy = 0;
 double m_Fz = 0;
}  

campovettoriale::~campovettoriale() {}

campovettoriale campovettoriale::operator+(const campovettoriale & v) const {
    campovettoriale sum(v);
    sum.m_Fx+=getFx();
    sum.m_Fy+=getFy();
    sum.m_Fz+=getFz();
    return sum;
}

campovettoriale & campovettoriale::operator+=( const campovettoriale & v ) {
    return (*this)=(*this)+v;
}

campovettoriale::campovettoriale(double x, double y, double z, double Fx, double Fy, double Fz) {
    m_x = x;
    m_y = y;
    m_z = z;
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}

campovettoriale::campovettoriale(const posizione& v, double Fx, double Fy, double Fz) : posizione(v) {
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}

double campovettoriale::modulo() {
    return sqrt(pow(m_Fx, 2)+pow(m_Fy, 2)+pow(m_Fz, 2));
}

int main(){

    return 0;
}