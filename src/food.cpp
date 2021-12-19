#include "food.h"

void Food::SetPosition(int& x, int& y) {
    this->position.x = x;
    this->position.y = y;
}

SDL_Point Food::GetPosition() const {
    return this->position;
}

bool Food::isPoisoned() const {
    return this->poisoned;
}

void Food::SetToxicity(bool& is_poisoned) {
    this->poisoned = is_poisoned;
}