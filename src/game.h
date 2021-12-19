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
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetTopScore() const;
  int GetSize() const;
  void SetTopScore(); 

 private:
  bool paused = false;
  Snake snake;
  std::unique_ptr<Food> food;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_int_distribution<int> random_poisoned_food;

  int score{0};
  int top_score{0};

  int poisened_food_score;

  void PlaceFood();
  void PlaceFood(bool is_poisoned);
  void Update();
};

#endif