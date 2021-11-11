#include "Snake.h"

using namespace std;

Snake::Snake(){
    lives = 5;
    apples_eaten = 0;
    snake_size = 1;
}

int Snake::get_lives(){
    return lives;
}

int Snake::get_apples_eaten(){
    return apples_eaten;
}

int Snake::get_snake_size(){
    return snake_size;
}

void Snake::reset_lives(){
    lives = 5;
}

void Snake::reset(){
    //reiniciar todos os atributos
    while(!snake_body.empty()){
        snake_body.pop();
    }

    snake_size = 1;
    apples_eaten = 0;
}