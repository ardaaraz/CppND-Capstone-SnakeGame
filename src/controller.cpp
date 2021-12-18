#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, bool &paused, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          if (!paused)
            ChangeDirection(snake, Snake::Direction::kUp,
                            Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          if(!paused)
            ChangeDirection(snake, Snake::Direction::kDown,
                            Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          if(!paused)
            ChangeDirection(snake, Snake::Direction::kLeft,
                            Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          if(!paused)
            ChangeDirection(snake, Snake::Direction::kRight,
                            Snake::Direction::kLeft);
          break;
        // Quit game when "Esc" is pressed.
        case SDLK_ESCAPE:
          running = false;
          break;
        // Pause/Continue game when "Space" is pressed.
        case SDLK_SPACE:
          paused = !paused;
          break;
      }
    }
  }
}