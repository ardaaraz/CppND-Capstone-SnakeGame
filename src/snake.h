#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
 /**
  * @brief Enumaration for snake direction
  * 
  */
  enum class Direction { kUp, kDown, kLeft, kRight };
  /**
   * @brief Construct a new Snake object
   * 
   * @param grid_width grid width
   * @param grid_height grid height
   */
  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}
  /**
   * @brief Update states of snake object
   * 
   */
  void Update();
  /**
   * @brief Reintialize snake object with its initial states
   * 
   */
  void Reborn();
  /**
   * @brief Grow snake body when it eats nontoxic food
   * 
   */
  void GrowBody();
  /**
   * @brief Decide whether any part of snake occupies given location or not
   * 
   * @param x x-position of a 2-D grid
   * @param y y-position of a 2-D grid
   * @return true if any part of snake occupies given location
   * @return false any part of snake does not occupies given location
   */
  bool SnakeCell(int &x, int &y);

  Direction direction = Direction::kUp; // Current direction of snake object. Default = kUp.

  float speed{0.1f};                    // Current speed of snake object. Default = 0.1.
  int size{1};                          // Current size of snake object. Default = 1.
  bool alive{true};                     // Whether snake object is alive or not. Default = true.
  bool reborn{false};                   // Whether snake object is reborn or not. Default = false.    
  float head_x;                         // x-position of head of snake object in a 2-D grid.
  float head_y;                         // y-position of head of snake object in a 2-D grid.
  std::vector<SDL_Point> body;          // Positions of body of snake object

 private:
  /**
   * @brief Update position of head of snake object 
   * 
   */
  void UpdateHead();
  /**
   * @brief Update position of body of snake object
   * 
   * @param current_cell location of head of snake object in current frame
   * @param prev_cell location of head of snake object in previous frame
   */
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false}; // Whether snake is growing or not by eating nontoxic food. Default = false.
  int grid_width;      // Grid width
  int grid_height;     // Grid height
};

#endif