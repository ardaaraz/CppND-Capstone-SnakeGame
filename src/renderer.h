#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "snake.h"
#include "food.h"

class Renderer {
 public:
  /**
   * @brief Construct a new Renderer object
   * 
   * @param screen_width screen width
   * @param screen_height screen height
   * @param grid_width grid width
   * @param grid_height gird height
   */
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  /**
   * @brief Destroy the Renderer object
   * 
   */
  ~Renderer();
  /**
   * @brief Render snake and foods
   * 
   * @param snake snake object
   * @param food vector of foods
   */
  void Render(Snake const &snake, std::unique_ptr<std::vector<Food>> const &food);
  /**
   * @brief Update title of the window
   * 
   * @param score current score
   * @param top_score top score
   * @param fps frame per second
   */
  void UpdateWindowTitle(const int &score, const int &top_score, const int &fps);

 private:
  SDL_Window *sdl_window;          // SDL Window object
  SDL_Renderer *sdl_renderer;      // SDL Renderer object

  const std::size_t screen_width;  // Screen width
  const std::size_t screen_height; // Screen height
  const std::size_t grid_width;    // Grid width
  const std::size_t grid_height;   // Grid height
};

#endif