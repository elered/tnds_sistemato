#include "RandomGen.h"
#include "FunzioneBase.h"
#include "funzioni.h"

#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TPad.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <nmax> <nsum>" << endl;
    return -1;
  }

  TApplication app(0,0,0);

  unsigned int nmax = atoi(argv[1]);
  unsigned int nsum = atoi(argv[2]);
  vector <double> v(nmax);
  double n;
  double var1, var2;

  if(nmax%nsum==0){
    n = nmax/nsum;
  }
  else{
    cout << "Errore: inserire nsum sottomultiplo di nmax" << endl;
    exit(-1);
  }
  
  vector <double> s(n); //vector somme
  
  RandomGen gen(1);

  TH1F unif("Uniforme","Uniforme",100,0,1);
  unif.StatOverflows(kTRUE);
  
  TH1F sum("Somme","Somme",100,0,0);
  sum.StatOverflows(kTRUE);

  for(int i=0; i<nmax; i++){
    v[i] = gen.Unif(0,1);
    unif.Fill(v[i]); 
  }

  for(int i=0; i<(n-nsum); i++){
    s[i] = 0;
    for(int k=0; k<nsum; k++){
      s[i] += v[i+k];
    }
    sum.Fill(s[i]);
  }

  /*Codice somme parziali, sp vector somme parziali
  for(int i=0; i<nsum; i++){
    for(int k=0; k<(i+1); k++){
      sp[i] += v[i-k];
      sparz.Fill(sp[i]);
    }
  }*/
  
  var1 = varianza(v);
  var2 = varianza(s);
  
  cout << "Varianza degli elementi = " << var1 << endl;
  cout << "Varianza delle somme = " << var2 << endl;
  
  TCanvas c("Uniforme","Uniforme");
  c.cd();
  unif.GetXaxis()->SetTitle("x [AU]");
  unif.GetYaxis()->SetTitle("N");
  unif.Draw();
  //c.Print("Grafici/Uniforme.png");

  TCanvas d("Somme","Somme");
  d.cd();
  sum.GetXaxis()->SetTitle("x [AU]");
  sum.GetYaxis()->SetTitle("N");
  sum.Draw();
  //d.Print("Grafici/Somme.png");
  app.Run();

  return 0;
}