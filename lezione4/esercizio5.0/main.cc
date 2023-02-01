#include <iostream>
#include <cstdlib>
#include "posizione.h"

using namespace std;

int main(int argc, char** argv) {

  if ( argc!=4 ) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    return -1;
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  posizione P(x,y,z);

  cout << "Coordinate cartesiane: (" 
       << P.getx() << ", " << P.gety() << ", " << P.getz() << ")" << endl;
  cout << "Coordinate cilindriche: (" 
       << P.getrho() << ", " << P.getphi() << ", " << P.getz() << ")" << endl;
  cout << "Coordinate sferiche: (" 
       << P.getr() << ", " << P.getphi() << ", " << P.gettheta() << ")" << endl;
  cout << "Distanza: " << P.distanza(posizione()) << endl;

  return 0;
}