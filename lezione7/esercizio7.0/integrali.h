#ifndef __integrali_h__
#define __integrali_h__

#include <iostream>
#include "funzione_base.h"

using namespace std;

// Base class : generic integrator

class integral {

 public:
  
  integral (double a, double b){
    checkinterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral = 0;
  }

  virtual double integra(unsigned int nstep, funzionebase& f) = 0;

 protected:

  void checkinterval (double a, double b){

    m_a = min(a,b);
    m_b = max(a,b);

    if(a>b) {
      m_sign = -1;
    } else {
      m_sign =1;
    };

  }

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;
};

// derived class : Midpoint integrator

class midpoint : public integral {

 public:

  midpoint (double a, double b) : integral (a, b){;};

  double integra(unsigned int nstep, funzionebase& f) override {

    m_nstep = nstep;

    double m_h = (m_b-m_a)/m_nstep;

    for (int k = 0; k<(m_nstep); k++) {

    double xk = m_a + (k+0.5)*m_h;

    m_sum += f.eval(xk);

    m_integral = m_sign*m_sum*m_h;

    }

    return m_integral;

  };

};

#endif 