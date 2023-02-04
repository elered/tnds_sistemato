#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"
#include <cmath>

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

  OscillatoreArmonico osc(1.0);

  double tmax = 70.0;
  double h = atof(argv[1]);
  vector<double> x {0.0, 1.0};
  double t = 0.0;

  int nstep = static_cast<int>(tmax/h+0.5);
  
  TApplication myApp("myApp",0,0); 
  
  TGraph myGraph1;
  TGraph myGraph2;

  TCanvas c;
  c.Divide(1,2);

  c.cd(1);

  for (int step = 0; step < nstep; step++){
    x = myk.Passo(t,x,h,osc);
    myGraph1.SetPoint(step, t, x[0]);
    t = t+h;
  }
  

  myGraph1.SetTitle("Oscillatore armonico");
  myGraph1.GetXaxis()->SetTitle("Posizione [m]");
  myGraph1.GetYaxis()->SetTitle("Tempo [s]");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(1);   

  myGraph1.Draw("ALP"); 

  c.cd(2);

  for(double i=0; i<10; i++) {
    double h = 0.1*pow(0.5,i);
    vector<double> x {0.,1.};
    double t = 0.;
    int nstep = int(tmax/h+0.5);
    for(int step = 0; step<nstep; step++) {
      x = myk.Passo(t,x,h,osc);
      t = t+h;
    }
    myGraph2.SetPoint(i,h,fabs(x[0]-sin(t)));

  }

  gPad->SetLogx();
  gPad->SetLogy();

  myGraph2.SetTitle("Andamento errore");
  myGraph2.GetXaxis()->SetTitle("Passo");
  myGraph2.GetYaxis()->SetTitle("Errore [m]");
  
  myGraph2.SetLineColor(2);
  myGraph2.SetMarkerStyle(20);   

  myGraph2.Draw("ALP");

  myApp.Run();

  return 0;
}

 

