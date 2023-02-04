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
  
  if(argc != 2)
  {
    cerr << "Uso: " << argv[0]  << " <passo_di_integrazione> " << endl;
    return -1;
  }

  rungekutta myk;

  double l = 1;

  pendolo p (l);

  double h = atof(argv[1]);
  
  TApplication myApp("myApp",0,0); 
  
  TGraph myGraph1;
  TGraph myGraph2;

  TCanvas * myCanvas = new TCanvas();
  myCanvas->cd();

  int nstep = 30;

  for (int step = 0; step < nstep; step++){

  double A = 0.1*(step + 1); //è un angolo

  double t = 0.0;

  double w = 0.;

  vector<double> x {-A,w};

  while ( x[1] >=0 ) {

    w = x[1];
    x = myk.Passo(t,x,h,p);
    t = t + h;

  };

  double T = (((t-h)*x[1]-t*w)/(x[1]-w))*2;

  myGraph1.SetPoint(step, A, T);

  }  

  myGraph1.SetTitle("Pendolo");
  myGraph1.GetXaxis()->SetTitle("Ampiezza [rad]");
  myGraph1.GetYaxis()->SetTitle("Periodo [s]");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(20);   

  myGraph1.Draw("ALP"); 

  myApp.Run();

  return 0;
}