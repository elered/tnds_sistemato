#ifndef __funzionebase__
#define __funzionebase__
#include <cmath>

class funzionebase {

  public:

  virtual double eval (double) const = 0;

  virtual ~funzionebase () {}

};

class segno {

  public: 

  double eval(double x) const {
  if(x<0)
    return -1;
  else 
    return 1;
  }

};

class funz : public funzionebase {
    
    public:

    double eval(double x) const {

        return sin(x)-x*cos(x);
    }
};

#endif // __funzionebase__