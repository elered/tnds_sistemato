#ifndef __funzionebase__
#define __funzionebase__

class funzionebase {

  public:

  virtual double eval (double) const = 0;
  virtual ~funzionebase () {}

};

#endif // __funzionebase__