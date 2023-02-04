#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include <cmath>
#include <iomanip>
#include <vector>
#include <iostream>
#include "randomgen.h"

using namespace std;

int main(){
  
  integralMC integra(1);

  int nmax = 10000;

  seno s;

  TApplication app(0,0,0);

  vector <unsigned int> nextractions = {100,500,1000,5000,10000};
  vector <TH1F> AVE(nextractions.size());
  vector <TH1F> HOM(nextractions.size());
  vector <double> devstdave(nextractions.size());
  vector <double> devstdhom(nextractions.size());

  for(int i=0; i<nextractions.size(); i++){
    string AVEname = "IntegraleMC AVE" + to_string(nextractions[i]);
    AVE[i] = TH1F(AVEname.c_str(),AVEname.c_str(),100,0,0);
    for(int j=0; j<nmax; j++){
    AVE[i].Fill(integra.integraleave(0,M_PI,s,nextractions[i]));
    }
    AVE[i].StatOverflows(kTRUE);
    devstdave[i] = AVE[i].GetStdDev();
  }

  TCanvas c;
  c.Divide(2,3);
  for(int i=0; i<nextractions.size(); i++){
    c.cd(i+1);
    AVE[i].GetXaxis()->SetTitle("x [AU]");
    AVE[i].GetYaxis()->SetTitle("N");
    AVE[i].Draw();
  }

  for(int i=0; i<nextractions.size(); i++){
    string HOMname = "IntegraleMC HOM" + to_string(nextractions[i]);
    HOM[i] = TH1F(HOMname.c_str(),HOMname.c_str(),100,0,0);
    for(int j=0; j<nmax; j++){
    HOM[i].Fill(integra.integralehom(0,M_PI,1,s,nextractions[i]));
    }
    HOM[i].StatOverflows(kTRUE);
    devstdhom[i] = HOM[i].GetStdDev();
  }

  TCanvas c1;
  c1.Divide(2,3);
  for(int i=0; i<nextractions.size(); i++){
    c1.cd(i+1);
    HOM[i].GetXaxis()->SetTitle("x [AU]");
    HOM[i].GetYaxis()->SetTitle("N");
    HOM[i].Draw();
  }

  TGraph myGraph1;

  c.cd(6);

  for ( int k = 0 ; k < nextractions.size() ; k++ ) {
    double x = nextractions[k] ;
    double y =  devstdave[k];
    myGraph1.SetPoint(k, x, y);
  }

  myGraph1.SetTitle("Andamento dell'errore AVE");
  myGraph1.GetXaxis()->SetTitle("N");
  myGraph1.GetYaxis()->SetTitle("stddev");

  myGraph1.SetMarkerStyle(20);

  myGraph1.Draw("ALP");

  TGraph myGraph2;

  c1.cd(6);

  for ( int k = 0 ; k < nextractions.size() ; k++ ) {
    double x = nextractions[k] ;
    double y =  devstdhom[k];
    myGraph2.SetPoint(k, x, y);
  }

  myGraph2.SetTitle("Andamento dell'errore HOM");
  myGraph2.GetXaxis()->SetTitle("N");
  myGraph2.GetYaxis()->SetTitle("stddev");

  myGraph2.SetMarkerStyle(20);

  myGraph2.Draw("ALP");

  app.Run();

  return 0;
}