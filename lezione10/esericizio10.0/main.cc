#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TAxis.h"
#include <cmath>
#include <vector>
#include <iostream>
#include "randomgen.h"

using namespace std;

int main(){
  
  RandomGen gen(1);

  int nmax = 10000;
  
  TApplication myApp("myApp",0,0); 

  TCanvas c;

  c.Divide(2,2);

  TH1F unif("uniforme", "uniforme", 100, 5, 10);
  
  for (int i = 0; i<nmax; i++) {

    unif.Fill(gen.Unif(5,10));

  }

  c.cd(1);

  unif.SetTitle("LCG");
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  
  unif.SetLineColor(2);
  unif.SetMarkerStyle(1);   

  unif.Draw(); 

  TH1F exp("exp", "exp", 100, 0, 20);
  
  for (int i = 0; i<nmax; i++) {

    exp.Fill(gen.Exp(1));

  }

  c.cd(2);

  exp.SetTitle("Esponenziale");
  exp.GetXaxis()->SetTitle("x [AU]");
  exp.GetYaxis()->SetTitle("N");
  
  exp.SetLineColor(2);
  exp.SetMarkerStyle(1);   

  exp.Draw(); 

  TH1F gaus("gauss", "gauss", 100, -4, 6);
  
  for (int i = 0; i<nmax; i++) {

    gaus.Fill(gen.Gaus(1,1));

  }

  c.cd(3);

  gaus.SetTitle("Gaussiana");
  gaus.GetXaxis()->SetTitle("x [AU]");
  gaus.GetYaxis()->SetTitle("N");
  
  gaus.SetLineColor(2);
  gaus.SetMarkerStyle(1);   

  gaus.Draw(); 

  TH1F gausAR("gaussar", "gaussar", 100, -4, 6);
  
  for (int i = 0; i<nmax; i++) {

    gausAR.Fill(gen.GausAR(1,1));

  }

  c.cd(4);

  gausAR.SetTitle("GaussianaAR");
  gausAR.GetXaxis()->SetTitle("x [AU]");
  gausAR.GetYaxis()->SetTitle("N");
  
  gausAR.SetLineColor(2);
  gausAR.SetMarkerStyle(1);   

  gausAR.Draw(); 

  myApp.Run();

  return 0;
}