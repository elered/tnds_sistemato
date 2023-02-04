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

  double w0 = 10;

  double alpha = 1./30.;

  double w = 5;

  smorzforz p(w0, alpha, w);

  double h = atof(argv[1]);
  
  TApplication myApp("myApp",0,0); 
  
  TGraph myGraph1;
  TGraph myGraph2;

  TCanvas c;
  c.Divide(1,2);

  double tmax = 10 * (1./alpha);

  double A = 0.;

  double t = 0.;

  vector<double> x {A, 0.};

  c.cd(1);

  while (t<=tmax) {

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

  c.cd(2);

  int nstep = 40;

  for(int i = 0; i<nstep; i++) {

    w = 0.9*w0+(0.2*w0/nstep)*(i+1); //aumento la forzante

    t = 0.;

    x[0] = 0;

    x[1] = 0;

  smorzforz p(w0, alpha, w);

  while (t<=tmax) {

    x = myk.Passo(t,x,h,p);

    double w2 = pow(w0, 2)- pow(w, 2);

    A = 1/(sqrt(pow(w2, 2)+pow(w,2)*pow(alpha, 2)));

    t = t + h;

   }

  myGraph2.SetPoint(i, w, A);

  }

  /*int nstep = 40;

  for(int i = 0; i<nstep; i++) {

    w = 0.9*w0+(0.2*w0/nstep)*(i+1);

    t = 0.;

    x[0] = 0;

    x[1] = 0;

  smorzforz p(w0, alpha, w);

  double aprec = 0;

  double wprec = 0;

  while (t<=tmax) {

    if(x[1]>=0) {

      double wprec = x[1];

      double aprec = x[0];

      x = myk.Passo(t,x,h,p);

      t = t + h;

    }

   }

    A = (((wprec)*x[0]-x[1]*aprec)/(x[0]-aprec));

    myGraph2.SetPoint(i, w, A);

  }*/

  myGraph2.SetTitle("Lorentziana");
  myGraph2.GetXaxis()->SetTitle("Pulsazione [rad/s]");
  myGraph2.GetYaxis()->SetTitle("Ampiezza [...]");
  
  myGraph2.SetLineColor(2);
  myGraph2.SetMarkerStyle(20);   

  myGraph2.Draw("ALP");
  
  myApp.Run();

  return 0;
}