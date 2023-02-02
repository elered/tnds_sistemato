#ifndef __campovettoriale_h__
#define __campovettoriale_h__

#include "posizione.h"

class campovettoriale : public posizione {

public:

  campovettoriale(const posizione&);
  campovettoriale(const posizione&, double Fx, double Fy, double Fz);
  campovettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
  ~campovettoriale();

  campovettoriale & operator+=( const campovettoriale & ) ;
  campovettoriale operator+( const campovettoriale & ) const;
  
  double getFx() const {return m_Fx;}
  double getFy() const {return m_Fy;}
  double getFz() const {return m_Fz;}

  double modulo();

private:

  double m_Fx, m_Fy, m_Fz;

};

#endif // __campovettoriale_h__