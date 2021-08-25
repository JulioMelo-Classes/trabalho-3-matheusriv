#include "Snake.h"

using namespace std;

Snake::Snake(){
    lifes = 5;
    apples_eaten = 0;
    snake_size = 1;
}

int Snake::get_apples_eaten(){
    return apples_eaten;
}