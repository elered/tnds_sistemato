#ifndef __puntomateriale_h__
#define __puntomateriale_h__

#include "particella.h"
#include "posizione.h"

#include "campovettoriale.h"

class puntomateriale : public particella, posizione {

public:

  puntomateriale(double massa, double carica, const posizione&);
  puntomateriale(double massa, double carica, double x, double y, double z);
  ~puntomateriale();

  campovettoriale campoelettrico(const posizione&) const ;
  campovettoriale campogravitazionale(const posizione&) const;

};

#endif // __puntomateriale_h__