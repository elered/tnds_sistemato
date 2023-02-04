#include <vector>
#include <iostream>
#include <cmath>

#include "vectoroperations.h"

using namespace std;

int main() {

   vector<double> v1 { 3.,4.,6.} ;
   vector<double> v2 { 4.,5.,6.} ;

   double para = 2.;

   vector<double> vtot = v1 + v2;

   Print(vtot);

   vector<double> v3 = para*v1;

   Print(v3);

   vector<double> vnormalizzato = v1/(sqrt(v1*v1));

   Print(vnormalizzato);

   return 0;

}