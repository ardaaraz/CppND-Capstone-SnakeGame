#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, bool &paused, Snake &snake) const;

 private:
  void ChangeDirection(Snake &snake, const Snake::Direction &input,
                       const Snake::Direction &opposite) const;
};

#endif