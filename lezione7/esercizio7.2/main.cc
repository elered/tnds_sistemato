#include <iostream>
#include "integrali.h"
#include "funzione_base.h"
#include <iomanip>

using namespace std;

int main(int argc, char * argv[] ) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <precisione>" << endl;
    return -1;
  }

  double prec = atof(argv[1]);

  seno f;
  trapezoidi myint(0, M_PI);


  double I = myint.integra(prec, f);

  cout << setw(5) << "Prec: " << setw(5) << prec << endl
       << setw(5) << "I: " << setw(5) << I << endl;
  
  return 0;

}