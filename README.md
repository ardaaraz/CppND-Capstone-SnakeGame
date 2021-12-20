# CPPND: Capstone Snake Game

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). In this project, Snake++ game introduce in [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) StackOverflow post is extended by adding new features.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## New Features

* New user inputs are defined. While game is running, user can pause/continue game by pressing space bar. If snake dies, user can restart game by the same action. Finally, user can quit game by pressing Esc button.
* At some instances of the game, **red poisoned food** are formed. If the user eats those poisoned food, snake will die. In order to feed the snake, user should eat **green nontoxic food**.
* Window title is updated to show top score. At the end of the game, top score with current size of the snake are presented to the user in the terminal window.

## Code Structure

The files that contain definition and functionality of classes are introduced below:

* `controller.h` and `controller.cpp`: **Controller** class handles user input from keyboard. User can pause/continue, quit or restart game by keyboard inputs. Moreover, direction of snake can be changed by using arrow buttons.
* `game.h` and `game.cpp`: **Game** class updates current states of the snake according to user input. Moreover, location of the food is updated by using Game class methods. The game loop is defined using this class `Run()` method.  
* `renderer.h` and `renderer.cpp`: **Renderer** class draws state of the game to the screen.
* `snake.h` and `snake.cpp`: **Snake** class defines states and functionalities of the snake component of the game.
* `food.h` and `food.cpp`: **Food** class defines states and functionalities of the food component of the game.

Finally in `main.cpp` file, **Controller**, **Renderer** and **Game** objects are instantiated and then, the **Game Loop** is started by calling `Run()` method of game class.

## Rubric Points Addressed

### Loops, Functions, I/O
| Rubric Point | Explanation |
| ------------ | ----------- |
| The project demonstrates an understanding of C++ functions and control structures. | Functionalities of the each classes are implemented as C++ functions to clearly organized code structure. |
| The project accepts input from a user as part of the necessary operation of the program. | In [controller.h](https://github.com/ardaaraz/CppND-Capstone-SnakeGame/blob/f53e1e3889c4cd645f7cf82f1e5d77f89997d89d/src/controller.h#L15) `HandleInput()` method handles user input from keybord. |

### Object Oriented Programming
| Rubric Point | Explanation |
| ------------ | ----------- |
| The project uses Object Oriented Programming techniques. | The project code is organized into 5 different classes. |
| Classes use appropriate access specifiers for class members. | Data members of all classes are specified as public or private. |
| Classes abstract implementation details from their interfaces. | Class members and functions are introduced with their comments in header files of each classes. |
| Overloaded functions allow the same function to operate on different parameters. | `PlaceFood()` method in [game.h](https://github.com/ardaaraz/CppND-Capstone-SnakeGame/blob/master/src/game.h) is overloaded with two different signatures. |

## Memory Management
| Rubric Point | Explanation |
| ------------ | ----------- |
| The project makes use of references in function declarations. | Different methods in project like `ChangeDirection()` method in [controller.h](https://github.com/ardaaraz/CppND-Capstone-SnakeGame/blob/e3bb0fc5ee9feaedac17a40b5bd3bdeac1bf3fcb/src/controller.h#L25) and `Render()` method in [renderer.h](https://github.com/ardaaraz/CppND-Capstone-SnakeGame/blob/e3bb0fc5ee9feaedac17a40b5bd3bdeac1bf3fcb/src/renderer.h#L33) use pass-by-reference. |
| The project uses smart pointers instead of raw pointers. | `food` member of **Game** class defined as `unique_ptr` in [game.h](https://github.com/ardaaraz/CppND-Capstone-SnakeGame/blob/e3bb0fc5ee9feaedac17a40b5bd3bdeac1bf3fcb/src/game.h#L57). |
