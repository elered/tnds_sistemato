#ifndef __parabola__
#define __parabola__

#include "funzione_base.h"
#include <cmath>
#include <iostream>

using namespace std;

class parabola : public funzionebase {

public:

  parabola () {m_a=0.; m_b=0.; m_c=0.;}
  parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
  ~parabola () {}
  double eval (double x) const override {return m_a*x*x + m_b*x + m_c;} 
  void seta (double a) {m_a=a;}
  double geta () const {return m_a;}
  void setb (double b) {m_b=b;}
  double getb () const {return m_b;}
  void setc (double c) {m_c=c;};
  double getc () const {return m_c;}
  void vertice () {

    double vertx = (-m_b/(2*m_a));
    cout << "Valore x nel vertice: " << vertx << endl;
    double verty = eval(vertx);
    cout << "Valore y nel vertice: " << verty << endl;

  }


private:

  double m_a, m_b, m_c;

};

#endif // __Parabola__Richiami