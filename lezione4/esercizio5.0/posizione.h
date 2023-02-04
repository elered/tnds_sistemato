#ifndef __posizione_h_
#define __posizione_h_

class posizione {

    public:

    posizione();
    posizione(double x, double y, double z);
    ~posizione();

    double getx() const;
    double gety() const;
    double getz() const;
    double getr() const;
    double getphi() const;
    double gettheta() const;
    double getrho() const;
    double distanza(const posizione&) const;

    private:

    double m_x, m_y, m_z;
};

#endif 