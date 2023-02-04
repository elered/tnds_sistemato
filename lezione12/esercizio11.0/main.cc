#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include "randomgen.h"
#include "prisma.h"

using namespace std;

int main(){

    TApplication app("app",0,0);

    TCanvas c;
    c.Divide(3,4);

    int n = 10000;

    EsperimentoPrisma p;

    c.cd(1);

    TH1F hA("A","A",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        hA.Fill(p.getAmis());
    }

    hA.StatOverflows(kTRUE);

    hA.SetTitle("A");
    hA.GetXaxis()->SetTitle("valori di A");
    hA.GetYaxis()->SetTitle("occorrenze");

    hA.Draw();

    c.cd(2);

    TH1F hB("B","B",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        hB.Fill(p.getBmis());
    }

    hB.StatOverflows(kTRUE);

    hB.SetTitle("B");
    hB.GetXaxis()->SetTitle("valori di B");
    hB.GetYaxis()->SetTitle("occorrenze");

    hB.Draw();

    c.cd(3);

    TH1F th0("th0","th0",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        th0.Fill(p.getth0mis());
    }

    th0.StatOverflows(kTRUE);

    th0.SetTitle("theta 0");
    th0.GetXaxis()->SetTitle("valori di theta 0");
    th0.GetYaxis()->SetTitle("occorrenze");

    th0.Draw();

    c.cd(4);

    TH1F th1("th1","th1",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        th1.Fill(p.getth1mis());
    }

    th1.StatOverflows(kTRUE);

    th1.SetTitle("theta 1");
    th1.GetXaxis()->SetTitle("valori di theta 1");
    th1.GetYaxis()->SetTitle("occorrenze");

    th1.Draw();

    c.cd(5);

    TH1F th2("th2","th2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        th2.Fill(p.getth2mis());
    }

    th2.StatOverflows(kTRUE);

    th2.SetTitle("theta 2");
    th2.GetXaxis()->SetTitle("valori di theta 2");
    th2.GetYaxis()->SetTitle("occorrenze");

    th2.Draw();

    c.cd(6);

    TH1F d1m("d1m","d1m",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        d1m.Fill(p.getdm1mis());
    }

    d1m.StatOverflows(kTRUE);

    d1m.SetTitle("delta minimo 1");
    d1m.GetXaxis()->SetTitle("valori di delta min 1");
    d1m.GetYaxis()->SetTitle("occorrenze");

    d1m.Draw();

    c.cd(7);

    TH1F dm2("dm2","dm2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        dm2.Fill(p.getdm2mis());
    }

    dm2.StatOverflows(kTRUE);

    dm2.SetTitle("delta minimo 2");
    dm2.GetXaxis()->SetTitle("valori di delta min 2");
    dm2.GetYaxis()->SetTitle("occorrenze");

    dm2.Draw();

    c.cd(8);

    TH1F n1("n1","n1",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        n1.Fill(p.getn1mis());
    }

    n1.StatOverflows(kTRUE);

    n1.SetTitle("n1");
    n1.GetXaxis()->SetTitle("valori di n1");
    n1.GetYaxis()->SetTitle("occorrenze");

    n1.Draw();

    c.cd(9);

    TH1F n2("n2","n2",100,0,0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();
        n2.Fill(p.getn2mis());
    }

    n2.StatOverflows(kTRUE);

    n2.SetTitle("n2");
    n2.GetXaxis()->SetTitle("valori di n2");
    n2.GetYaxis()->SetTitle("occorrenze");

    n2.Draw();


    double AB, A, B, N2, N1, D1, D2, N1N2, D1D2;

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        AB += p.getAmis()*p.getBmis();
        A += p.getAmis();
        B += p.getBmis();

        N1N2 += p.getn1mis()*p.getn2mis();
        N1 += p.getn1mis();
        N2 += p.getn2mis();

        D1D2 += p.getdm1mis()*p.getdm2mis();
        D1 += p.getdm1mis();
        D2 += p.getdm2mis();
        
    }

    double corrAB = (((AB/n) - (A/n)*(B/n))/(hA.GetStdDev()*hB.GetStdDev()))*100;
    double corrN1N2 = (((N1N2/n) - (N1/n)*(N2/n))/(n1.GetStdDev()*n2.GetStdDev()))*100;
    double corrD1D2 = (((D1D2/n) - (D1/n)*(D2/n))/(d1m.GetStdDev()*dm2.GetStdDev()))*100;

    c.cd(10);

    TH2F HAB("correlazione AB", "Correlazione AB", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        HAB.Fill(p.getAmis(), p.getBmis());

    }

    HAB.StatOverflows(kTRUE);

    HAB.GetXaxis()->SetTitle("valori di A");
    HAB.GetYaxis()->SetTitle("valori di B");
    HAB.Draw();

    c.cd(11);

    TH2F HAN("correlazione N1N2", "Correlazione N1N2", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        HAN.Fill(p.getn1mis(), p.getn2mis());

    }

    HAN.StatOverflows(kTRUE);

    HAN.GetXaxis()->SetTitle("valori di N1");
    HAN.GetYaxis()->SetTitle("valori di N2");
    HAN.Draw();

    c.cd(12);

    TH2F HAD("correlazione D1D2", "Correlazione D1D2", 100, 0, 0, 100, 0, 0);

    for(int i = 0; i<n; i++) {

        p.Esegui();
        p.Analizza();

        HAD.Fill(p.getdm1mis(), p.getdm2mis());

    }

    HAD.StatOverflows(kTRUE);

    HAD.GetXaxis()->SetTitle("valori di D1");
    HAD.GetYaxis()->SetTitle("valori di D2");
    HAD.Draw();

    cout << "Valore di A: " << hA.GetMean() << " +- " << hA.GetStdDev() << endl;
    cout << "Valore di B: " << hB.GetMean() << " +- "<< hB.GetStdDev() << endl;
    cout << "Valore di theta 0: " << th0.GetMean() << " +- "<< th0.GetStdDev() << endl;
    cout << "Valore di theta 1: " << th1.GetMean() << " +- "<< th1.GetStdDev() << endl;
    cout << "Valore di theta 2: " << th2.GetMean() << " +- "<< th2.GetStdDev() << endl;
    cout << "Valore di delta minimo 1: " << d1m.GetMean() << " +- "<< d1m.GetStdDev() << endl;
    cout << "Valore di delta minimo 2: " << dm2.GetMean() << " +- "<< dm2.GetStdDev() << endl;
    cout << "Valore di n1: " << n1.GetMean() << " +- "<< n1.GetStdDev() << endl;
    cout << "Valore di n2: " << n2.GetMean() << " +- "<< n2.GetStdDev() << endl;
    cout << "Correlazione AB: " << corrAB << endl;
    cout << "Correlazione N1N2: " << corrN1N2 << endl;
    cout << "Correlazione D1D2: " << corrD1D2 << endl;

    app.Run();

    return 0;

}