#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  /**
   * @brief Handle keybord inputs
   * 
   * @param running whether game is running or not
   * @param paused whether game is paused or not
   * @param snake snake object
   */
  void HandleInput(bool &running, bool &paused, Snake &snake) const;

 private:
  /**
   * @brief Change snake direction according to user input
   * 
   * @param snake snake object
   * @param input keybord input
   * @param opposite opposite direction of current snake movement
   */
  void ChangeDirection(Snake &snake, const Snake::Direction &input,
                       const Snake::Direction &opposite) const;
};

#endif