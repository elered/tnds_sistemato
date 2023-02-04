#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"
#include <cmath>
#include <vector>

#include <iostream>
#include "equazionidifferenziali.h"

using namespace std;

int main(int argc, char** argv){
  
  if(argc != 3)
  {
    cerr << "Uso: " << argv[0]  << " <passo_di_integrazione> <anni>" << endl;
    return -1;
  }

  rungekutta myk;

  double massasole = 1.98844E30;

  double distanza = 147098074;

  double velocità = 30.287;

  double t = 0;

  grav p (massasole, distanza);

  double h = atof(argv[1]);

  double anni = atof(argv[2]);
  
  TApplication myApp("myApp",0,0); 
  
  TGraph myGraph1;

  TCanvas * myCanvas = new TCanvas();
  myCanvas->cd();

  vector<double> x {distanza, velocità};

  while (t<=anni) {

    x = myk.Passo(t,x,h,p);

    myGraph1.AddPoint(t, x[0]);

    t = t + h;

  }

  myGraph1.SetTitle("Oscillatore armonico smorzato forzato");
  myGraph1.GetXaxis()->SetTitle("tempo [s]");
  myGraph1.GetYaxis()->SetTitle("x [rad]");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(1);   

  myGraph1.Draw("ALP"); 

  myApp.Run();

  return 0;
}