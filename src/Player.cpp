#include "Player.h"

using namespace std;

Player::Player(){}

void Player::set_level(Level & level){
    this->level = &level;
}

bool Player::find_solution(Position snake, Position food){
    Position position_aux{snake.i, snake.j}, position_aux1;
    vector<Position> aux_vector;
    unsigned count = 0;
    distance = 0;

    for(auto i=0; i<4; i++){
        vector<Position> aux;
        aux.push_back(snake);
        shortest_path.push_back(aux);
    }

    fila.push(snake);

    while(!fila.empty()){
        count = 0;
        position_aux = fila.front();
        fila.pop();
        unsigned current_path = find_path(position_aux);
        simulate_snake(position_aux);

        for(auto i=0; i<4;i++){
            position_aux1 = position_aux;
            position_aux1 = update_position(position_aux1, i);

            if(!is_body(position_aux1)){
                if((level->maze[position_aux1.i][position_aux1.j] != '#') && (count_visited(position_aux1) == 0)){
                    visited.push_back(position_aux1);
                    fila.push(position_aux1);
                    if(count > 0){
                        aux_vector = shortest_path[current_path];
                        aux_vector[aux_vector.size()-1] = position_aux1;
                        shortest_path.push_back(aux_vector);
                    }
                    else{
                        shortest_path[current_path].push_back(position_aux1);
                    }
                    count+=1;
                }
            }
        }

        distance++;
        if(level->check_sides_apple(position_aux)){ 
            return true; 
        }    
    }

    return false;
}

unsigned Player::find_path(Position pst){
    Position shpath;
    for(auto i=0; i<shortest_path.size(); i++){
        shpath.i = shortest_path[i][shortest_path[i].size()-1].i;
        shpath.j = shortest_path[i][shortest_path[i].size()-1].j;
        if(shpath.i == pst.i && shpath.j == pst.j){
            return i;
        }
    }

    return 0;
}

void Player::simulate_snake(Position end_pst){
    unsigned path = 0, snake_body = 0;

    for(auto i=0; i<shortest_path.size(); i++){
        if(shortest_path[i][shortest_path[i].size()-1].i == end_pst.i && 
        shortest_path[i][shortest_path[i].size()-1].j == end_pst.j){
            path = i;
            break;
        }
    }

    if(shortest_path[path].size() >= level->cobra->get_snake_size()){
        if(distance == 0){
            auto aux_body = level->cobra->snake_body;
            ghost_snake_body.clear();

            while(!aux_body.empty()){
                ghost_snake_body.push_back(aux_body.front());
                aux_body.pop();
            }
        }
        else{
            snake_body = shortest_path[path].size() - level->cobra->get_snake_size();
            ghost_snake_body.clear();

            for(auto i=snake_body; i<shortest_path[path].size(); i++){
                ghost_snake_body.push_back(shortest_path[path][i]);
            }
        }

    }
    else{
        ghost_snake_body.clear();
        auto aux_body = level->cobra->snake_body;

        for(auto i{level->cobra->get_snake_size()-shortest_path[path].size()}; 
        i<shortest_path[path].size(); i++){
            aux_body.pop();
        }

        while(!aux_body.empty()){
            ghost_snake_body.push_back(aux_body.front());
            aux_body.pop();
        }

        for(auto i=0; i<shortest_path[path].size(); i++){
            ghost_snake_body.push_back(shortest_path[path][i]);
        }
    }

}

Position Player::update_position(Position snake, short next){
    Position aux{snake.i, snake.j};
    switch(next){
        case 0: //para cima
            aux.i -= 1; 
            return aux;
            break;
        case 1: //para direita
            aux.j += 1;
            return aux;
            break;
        case 2: //para baixo
            aux.i += 1;
            return aux;
            break;
        case 3: //para a esquerda
            aux.j -= 1;
            return aux;
            break;
        default:
            std::cerr << "Erro!\n";
    }

    return aux;
}

bool Player::is_body(Position pst){
    for(auto i=0; i<ghost_snake_body.size(); i++){
        if(pst.i == ghost_snake_body[i].i && 
        pst.j == ghost_snake_body[i].j){
            return true;
        }
    }

    return false;
}

int Player::count_visited(Position pst){
    int count=0;
    for(auto i=0; i<visited.size(); i++){
        if(pst.i == visited[i].i && pst.j == visited[i].j)
            count+=1;
    }

    return count;
}

vector<Position> Player::get_death_path(){
     return death_path;
}


vector<Position> Player::get_shortest_path(Position food){
    unsigned path = 0;

    for(auto i=0; i<shortest_path.size(); i++){
        if(shortest_path[i][shortest_path[i].size()-1].i == food.i && 
        shortest_path[i][shortest_path[i].size()-1].j == food.j){
            path = i;
            break;
        }
    }

    return shortest_path[path];
}

void Player::reset(){
    visited.clear();
    
    for(auto i{0}; i < shortest_path.size(); i++){
        shortest_path[i].clear();
    }
    shortest_path.clear();

    while(!fila.empty()){
        fila.pop();
    }
}