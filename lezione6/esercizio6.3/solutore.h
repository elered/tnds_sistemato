#ifndef __solutore__
#define __solutore__

#include "funzione_base.h"

class solutore {

public:

  solutore () {;} ;

  solutore(double a, double b, double prec){m_a=a; m_b=b; m_prec=prec;};

  virtual ~solutore() {;} ;

  virtual double cercazeri (double xmin, double xmax, const funzionebase& f, double prec = 0.001, unsigned int nmax = 100 ) = 0 ;

  virtual double cercazeri (double xmin, double xmax, const funzionebase *f, double prec = 0.001, unsigned int nmax = 100 ) = 0 ;

  void setprecisione (double epsilon) { m_prec=epsilon; }
  void setnmaxiterations (unsigned int n) { m_iterations = n; }

  unsigned int getnmaxiterations () { return m_nmax; }
  unsigned int getniterations () { return m_iterations; }
  double getprecisione () { return m_prec; }

protected:

  double m_a, m_b;
  double m_prec;
  unsigned int m_nmax, m_iterations;
	
};

#endif // __solutore__