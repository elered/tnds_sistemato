#include "vettore.h"

// costruttore senza argomenti

Vettore::Vettore()  {
  cout << "Calling default constructor" << endl;
  m_N = 0;
  m_v = NULL;
}

// costruttore con dimensione

Vettore::Vettore(unsigned int N) {
  cout << "Calling constructor with arguments" << endl;
  m_N = N;
  m_v = new double[N];
  for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
  
}

void Vettore::SetComponent(unsigned int i, double a) {
  if ( i<m_N ) {
    m_v[i]=a;
  } else {
    cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
    exit (-1);
  }
}

// distruttore

Vettore::~Vettore() {
    cout << "Calling destructor" <<endl;
    delete[] m_v;
}

double Vettore::GetComponent(unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}

double& Vettore::operator[] (unsigned int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}

void Vettore::scambia(unsigned int primo, unsigned int secondo) {
    double tmp = GetComponent(primo);
    SetComponent(primo, GetComponent(secondo));
    SetComponent(secondo, tmp);
}

//copy constructor

Vettore::Vettore(const Vettore& V) {
    m_N = V.GetN();
    m_v = new double[m_N];
    for (int i=0; i<m_N; i++) m_v[i]=V.GetComponent(i);
}

Vettore& Vettore::operator=(const Vettore& V) {
    m_N = V.GetN();
    if (m_v) delete[] m_v;
    m_v = new double[m_N];
    for (int i=0; i<m_N; i++) m_v[i]=V.GetComponent(i);
    return *this;

}