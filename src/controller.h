#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "racket.h"

class Controller {
 public:
  void HandleInput(bool &running, Racket &racketLeft, Racket &racketRight) const;

 private:
};

#endif