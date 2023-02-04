#include <iostream>
#include <fstream> 
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

template <typename T> vector<T> readall( const char* filename ) {

vector<T> v;    
    fstream infile;
    infile.open(filename,ios::in);
    T val = 0;
    if(!infile.good()) {
        throw runtime_error("ERROR, failed to open file...");

    infile.clear(); infile.seekg(0);
    } else {
        while(infile >> val) {
        v.push_back(val);
        }
    }

    infile.close();
    return v;
};

template <typename T> TH1F FillHisto(const vector<T> & v){
 
  TH1F h ("histo","histo", 100, -10, 100) ;
  h.StatOverflows( kTRUE );
  for ( int k = 0 ; k < v.size() ; k++ ) h.Fill( v[k] );
  return h;

}