#ifndef __bisezione__
#define __bisezione__

#include "solutore.h"
#include "funzione_base.h"

using namespace std;

class bisezione : public solutore {

public:

  bisezione () : solutore() {;} ;
  bisezione (double a, double b, double prec) : solutore (a,b,prec) {;} ;
  ~bisezione () {;};

  double cercazeri (double a, double b, const funzionebase &f, double prec = 0.001, unsigned int nmax = 100 ) override {

    segno sign;

    m_prec = prec;
    m_nmax = nmax;
    m_iterations = 0;

    if(a<b) {
      m_a = a;
      m_b = b;
    } else {
      m_a = b;
      m_b = a;
    }

    double c = 0.5 * (m_b+m_a);
    double fa = f.eval(m_a);
    double fb = f.eval(m_b);
    double fc = f.eval(c);

    while(abs(m_b-m_a)>m_prec && m_iterations<m_nmax) {

    m_iterations++;

    if (sign.eval(fa)*sign.eval(fc)<0) {

      return cercazeri(a, c, f);

    } else if (sign.eval(fc)*sign.eval(fb)<0) {

      return cercazeri(c, b, f);


    }

  }

  return c;

}



double cercazeri (double a, double b, const funzionebase *f, double prec = 0.001, unsigned int nmax = 100 ) {

    segno sign;

    m_prec = prec;
    m_nmax = nmax;
    m_iterations = 0;

    if(a<b) {
      m_a = a;
      m_b = b;
    } else {
      m_a = b;
      m_b = a;
    }

    double c = 0.5 * (m_b+m_a);
    double fa = f->eval(a);
    double fb = f->eval(b);
    double fc = f->eval(c);

    while(abs(m_b-m_a)>m_prec && m_iterations<m_nmax) {

    m_iterations ++;

    if (sign.eval(fa)*sign.eval(fc)<0) {

      return cercazeri(a, c, f);

    } else if (sign.eval(fc)*sign.eval(fb)<0) {

      return cercazeri(c, b, f);

    }

  }

  return c;
}

};

#endif