#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"

/**
 * @brief Food class
 */
class Food {
 public:
  /**
   * @brief Set the Position of food
   * 
   * @param x x position of the food
   * @param y y position of the food
   */
  void SetPosition(int& x, int& y);
  /**
   * @brief Get the Position of food
   * 
   * @return SDL_Point current x-y position of food
   */
  SDL_Point GetPosition() const;
  /**
   * @brief Whether food is poisoned or not
   * 
   * @return true if food is poisoned
   * @return false if food is not poisoned
   */
  bool isPoisoned() const;
  /**
   * @brief Set the toxicity of food
   * 
   * @param is_poisoned true if the food is toxic
   */
  void SetToxicity(bool is_poisoned); 

 private:
  SDL_Point position;    // Position of food in a 2-D grid
  bool poisoned = false; // Whether food is poisoned or not
};

#endif