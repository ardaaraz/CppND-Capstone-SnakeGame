#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_poisoned_food(3, 10) {
  this->food = std::make_unique<std::vector<Food>> ();
  PlaceFood();
  poisened_food_score = random_poisoned_food(engine);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();
  
    // Check whether snake is reborn or not
    if(snake.reborn)
    {
      snake.reborn = false;
      score = 0;
      food.get()->clear();
      PlaceFood(false);
      poisened_food_score = random_poisoned_food(engine);
    }

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paused, snake);
    // Check whether game is paused or not
    if(!this->paused)
    {
      Update();
      renderer.Render(snake, food);
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, top_score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  auto f = Food();
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or another food item before placing
    // food.
    if(food.get()->size() == 0)
    {
      if (!snake.SnakeCell(x, y)) {
        f.SetPosition(x, y);
        food.get()->emplace_back(f);
        return;
      }
    }
    else
    {
      bool is_occupied = false;
      for(auto& f : *food)
      {
        auto food_pos = f.GetPosition();
        if(x == food_pos.x && y == food_pos.y)
          is_occupied = true;
          break;
      }
      if(!snake.SnakeCell(x, y) && !is_occupied)
      {
        f.SetPosition(x, y);
        food.get()->emplace_back(f);
        return;
      }
    }
  }
}

void Game::PlaceFood(bool is_poisoned)
{
  int x, y;
  auto f = Food();
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or another food item before placing
    // food.
    if(food.get()->size() == 0)
    {
      if (!snake.SnakeCell(x, y)) {
        f.SetPosition(x, y);
        f.SetToxicity(is_poisoned);
        food.get()->emplace_back(f);
        return;
      }
    }
    else
    {
      bool is_occupied = false;
      for(auto& f : *food)
      {
        auto food_pos = f.GetPosition();
        if(x == food_pos.x && y == food_pos.y)
          is_occupied = true;
          break;
      }
      if(!snake.SnakeCell(x, y) && !is_occupied)
      {
        f.SetPosition(x, y);
        f.SetToxicity(is_poisoned);
        food.get()->emplace_back(f);
        return;
      }
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  for(auto& f : *food)
  {
    // Check if there's food over here
    auto food_pos = f.GetPosition();
    if (food_pos.x == new_x && food_pos.y == new_y) {
      food.get()->clear();
      if(f.isPoisoned())
      {
        snake.alive = false;
        return;
      }
      else
      {
        score++;
        if(score == poisened_food_score)
        {
          poisened_food_score += random_poisoned_food(engine);
          PlaceFood(true);
        }
        SetTopScore();
        PlaceFood();
        // Grow snake and increase speed.
        snake.GrowBody();
        snake.speed += 0.02;
      }
      break; 
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetTopScore() const { return top_score; }
int Game::GetSize() const { return snake.size; }

void Game::SetTopScore() { top_score = (score > top_score) ? score : top_score; }