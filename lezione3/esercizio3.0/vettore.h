#ifndef __vettore_h__
#define __vettore_h__ 

#include <iostream>
#include <assert.h>

using namespace std;

template <typename T> class Vettore {

 public:

    Vettore() {
    m_N = 0;
    m_v = nullptr;
    };

	Vettore(unsigned int N) {
    cout << "Calling constructor with arguments" << endl;
    m_N = N;
    m_v = new double[N];
    for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
    };

	~Vettore() {
    cerr << "Calling distructor with arguments" << endl;
        delete[] m_v;
    };

    unsigned int GetN() const { return m_N; };

    void SetComponent(unsigned int i, T a) {
        if ( i<m_N ) {
        m_v[i]=a;
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit (-1);
    }
    }; 
    double GetComponent(unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
    };

    double& operator[] (unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
    };

    void scambia(unsigned int primo, unsigned int secondo) {
    double tmp = GetComponent(primo);
    SetComponent(primo, GetComponent(secondo));
    SetComponent(secondo, tmp);
    };


 private:

	unsigned int m_N;
	T *m_v;

};

#endif // __vettore_h__