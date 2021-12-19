#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"

class Game {
 public:
  /**
   * @brief Construct a new Game object
   * 
   * @param grid_width grid width
   * @param grid_height grid height
   */
  Game(std::size_t grid_width, std::size_t grid_height);
  /**
   * @brief Update method of the game loop
   * 
   * @param controller controller object 
   * @param renderer renderer object
   * @param target_frame_duration target duration in between two frames
   */
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  /**
   * @brief Get the current score 
   * 
   * @return int current score
   */
  int GetScore() const;
  /**
   * @brief Get the top score
   * 
   * @return int top score
   */
  int GetTopScore() const;
  /**
   * @brief Get the size of the snake
   * 
   * @return int snake size
   */
  int GetSize() const;
  /**
   * @brief Set the top score
   * 
   */
  void SetTopScore(); 

 private:
  bool paused = false;                                     // Whether game is paused or not
  Snake snake;                                             // Snake object
  std::unique_ptr<std::vector<Food>> food;                 // Vector of foods

  std::random_device dev;                                  // Uniformly-distributed integer random number generator
  std::mt19937 engine;                                     // Mersenne Twister pseudo-random generator
  std::uniform_int_distribution<int> random_w;             // Generate random integer value for x-localition of food
  std::uniform_int_distribution<int> random_h;             // Generate random integer value for y-localition of food
  std::uniform_int_distribution<int> random_poisoned_food; // Generate random integer value for score calue that poisoned food is formed

  int score{0};                                            // Score
  int top_score{0};                                        // Top score

  int poisened_food_score;                                 // Score value that poisoned food is formed

  /**
   * @brief Place food in a 2-D grid
   * 
   */
  void PlaceFood();
  /**
   * @brief Place food in a 2-D grid
   * 
   * @param is_poisoned whether placed food is poisoned or not
   */
  void PlaceFood(bool is_poisoned);
  /**
   * @brief Game update method
   * 
   */
  void Update();
};

#endif