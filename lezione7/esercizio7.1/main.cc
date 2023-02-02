#include <cmath>
#include <iostream>
#include "integrali.h"
#include "funzione_base.h"
#include <iomanip>
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"

using namespace std;

int main(int argc, char * argv[] ) {
  
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <nstep pari>" << endl;
    return -1;
  }

  unsigned int nstep = atoi(argv[1]);

  seno f;
  simpson myint(0, M_PI);


  double I = myint.integra(nstep, f);


  cout << setw(5) << "Passi: " << setw(5) << nstep << endl
       << setw(5) << "I: " << setw(5) << I << endl;

  TApplication myApp("myApp",0,0);
  
  TGraph myGraph1;
  TCanvas mycanvas;

  for ( int k = 2 ; k < nstep; k+=2 ) {
    double x = k;
    double y =  fabs(myint.integra(k,f) - 2);
    myGraph1.AddPoint(x, y);
  }

  mycanvas.SetLogy();
  mycanvas.SetLogx();

  myGraph1.SetTitle("Andamento dell'errore tramite lunghezza del passo");
  myGraph1.GetXaxis()->SetTitle("Passo");
  myGraph1.GetYaxis()->SetTitle("Scarto valore noto e integrale nel punto");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(20);   

  myGraph1.Draw("ALP"); 
  
  myApp.Run();
  
  return 0;

}