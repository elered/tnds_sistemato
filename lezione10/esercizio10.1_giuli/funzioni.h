#ifndef __funzioni__
#define __funzioni__

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <algorithm> //Funzioni
#include <vector>    //Contenitore

using namespace std;

template <typename T> double media(const vector<T> &x) {

  double sum = 0;

  if (x.size() == 0) {
    return sum;
  }
  for (int i = 0; i < x.size(); i++) {
    sum = sum + x[i];
  }
  return sum / double(x.size());
}

template <typename T> double varianza(const vector<T> &x) {

  double med;
  double sum = 0;
  med = media(x);

  if (x.size() == 0) {
    return sum;
  }
  for (int i = 0; i < x.size(); i++) {
    sum = sum + pow((x[i]) - med, 2);
  }
  return sum / (double((x.size())) - 1);
}

template <typename T> double mediana(const vector<T> x) {

  vector<T> w = x;
  sort(w.begin(), w.end());
  double md = 0;

  if (w.size() % 2 == 0) {
    md = (w[(w.size() / 2) - 1] + w[w.size() / 2]) / 2;
  } else {
    md = w[w.size() / 2];
  }
  return md;
}

template <typename T> vector<T> read(const char *filename, int n) {

  vector<T> x;
  ifstream flusso_in;

  flusso_in.open(filename);

  if (flusso_in.fail()) {
    cout << endl << "Cannot open file " << filename << endl;
    exit(1);
  } else {
    for (int i = 0; i < n; i++) {
      T value = 0;
      flusso_in >> value;
      x.push_back(value);
      if (flusso_in.eof()) {
        cout << "End of file reached exiting" << endl;
        exit(1);
      }
    }
  }

  flusso_in.close();

  return x;
}

template <typename T> void print(const vector<T> &x) {
  for (int i = 0; i < x.size(); i++) {
    cout << endl << x[i];
  }
  cout << endl << endl;
}

template <typename T> void print(const char *filename, const vector<T> &x) {

  ofstream flusso_out;

  flusso_out.open(filename);

  flusso_out << endl << "Dati del file" << endl;
  for (int i = 0; i < x.size(); i++) {
    flusso_out << endl << x[i];
  }
  flusso_out << endl;

  flusso_out.close();
}

/*template <typename T> TH1F FillHisto(const vector<T> &x) {

  TH1F h("histo", "histo", 100, -10, 100);
  h.StatOverflows(kTRUE);
  for (int i = 0; i < x.size(); i++) {
    h.Fill(x[i]);
    return h;
  }
}*/

#endif