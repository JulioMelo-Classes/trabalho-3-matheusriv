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

std::queue<std::pair<int,int>> & Snake::get_snake_body(){
    return snake_body;
}

bool Snake::check_body(int prow, int pcol){
    std::pair<int,int> pst = std::make_pair(prow, pcol);
    auto aux = snake_body;
    
    while(!aux.empty()){
        if(pst == aux.front()){
            return true;
        }
        aux.pop();
    }

    return false;
}

void Snake::reset(){
    //reiniciar todos os atributos
    while(!snake_body.empty()){
        snake_body.pop();
    }

    snake_size = 1;
    apples_eaten = 0;
}