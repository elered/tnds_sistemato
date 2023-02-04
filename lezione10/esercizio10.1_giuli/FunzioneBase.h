#ifndef __FunzioneBase__
#define __FunzioneBase__

#include <cmath>
#include <iostream>

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase () {}

};

class Parabola : public FunzioneBase {

public:

  Parabola () {m_a=0.; m_b=0.; m_c=0.;}

  Parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}

  ~Parabola () {}

  double Eval (double x) const override {return m_a*x*x + m_b*x + m_c;}

  void SetA (double a) {m_a=a;}
  double GetA () const {return m_a;}
  void SetB (double b) {m_b=b;}
  double GetB () const {return m_b;}
  void SetC (double c) {m_c=c;};
  double GetC () const {return m_c;}

private:

  double m_a, m_b, m_c;

};

class Seno: public FunzioneBase {

  public:

  Seno() {}
  ~Seno() {}

  double Eval (double x) const override {return sin(x);}
};

class Gauss: public FunzioneBase {

  public:

  Gauss(double sigma, double miu) {
    m_miu = miu;
    m_sigma = sigma;
  }
  ~Gauss() {}

  double Eval (double x) const override {
    return (1/(sqrt(2*M_PI)*m_sigma))*pow(M_E,(-pow((x-m_miu),2)/(2*pow(m_sigma,2))));
  }

  private:
    double m_miu;
    double m_sigma;
};

#endif