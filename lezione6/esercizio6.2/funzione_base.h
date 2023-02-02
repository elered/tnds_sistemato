#ifndef __funzionebase__
#define __funzionebase__

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

#endif // __funzionebase__