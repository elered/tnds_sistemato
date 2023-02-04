#ifndef __posizione_h_
#define __posizione_h_

#include<cmath>
#include <assert.h>

using namespace std;

class posizione {

    public:

    posizione(){
    m_x = 0;
    m_y = 0;
    m_z = 0;
};
    posizione(double x, double y, double z) {
    m_x = x;
    m_y = y;
    m_z = z;
};
    ~posizione() {};

    double getx() const {
    return m_x;
};
    double gety() const{
    return m_y;
};
    double getz() const {
    return m_z;
};
    double getr() const {
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
};
    double getphi() const {
    return atan2(m_y,m_x);
};
    double gettheta() const {
    return acos(m_z/getr());
};
    double getrho() const {
    return sqrt(m_x*m_x+m_y*m_y);
};
    double distanza(const posizione& b) const {
    return sqrt(pow(getx()-b.getx(),2)+pow(gety()-b.gety(),2)+pow(getz()-b.getz(),2));
};

    void setz (double a) {
        m_z = a;
};

    protected:

    double m_x, m_y, m_z;
};

#endif 