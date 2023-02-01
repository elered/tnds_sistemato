#ifndef __particella_h__
#define __particella_h__

#include<iostream>
#include <assert.h>
#include<cmath>

using namespace std;

class particella {

public:
  particella();
  particella(double massa, double carica) {
    m_massa = massa;
    m_carica = carica;
}
  ~particella() {};

  double getmassa() const { return m_massa; }

  double getcarica() const { return m_carica; }

  void print() const {
    cout << "Particella: m = " << m_massa << endl;
    cout << "Particella: carica = " << m_carica << endl;
}

protected:
  double m_massa;
  double m_carica;
};

class elettrone : public particella {

public:
  elettrone() : particella(9.1093826E-31, -1.60217653E-19){};
  ~elettrone() {};
  void print() const {
    cout << "elettrone: m = " << m_massa << endl;
    cout << "elettrone: carica= " << m_carica << endl;

}

};

#endif // __particella_h__