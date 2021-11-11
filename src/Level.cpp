#include "Level.h"

using namespace std;

Level::Level(int row, int col){
    set_measures(row, col);
    apple_maze = 'Q';
}

Level::Level(){}

void Level::add_snake(Snake &cobra){
    this->cobra = &cobra;
    cobra.snake_body.push(start_pos);
}

void Level::set_apples(int num_apples_){
    num_apples = num_apples_;
}

int Level::get_num_apples(){
    return num_apples;
}

bool Level::config_maze(){
    for(int i=0; i<lrow; i++){
        for(int j=0; j<lcol; j++){
            if(maze[i][j] == '*'){
                set_start_pos(i, j);
                return true;
            }
        }
    }
    return false;
}

void Level::print_maze(){
    for(int i=0; i<lrow; i++){
        for(int j=0; j<lcol; j++){
            if(maze[i][j] == '.')
                cout << " ";
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}

void Level::rand_apple(){
    unsigned seedRow = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seedCol = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 generatorRow(seedRow);
    std::mt19937 generatorCol(seedCol);

    Position random;

    while(true){
        random.i = generatorRow()%lrow;
        random.j = generatorCol()%lcol;
        if(maze[random.i][random.j] == ' '){
            if(!check_body(random) && check_sides_apple(random))
                maze[random.i][random.j] = apple_maze;
            break;
        }
    }

    apple_pos.i = random.i;
    apple_pos.j = random.j;
}

bool Level::check_sides_apple(Position pst){
    int row = pst.i;
    int col = pst.j;
    if(maze[row+1][col] == ' '){
        return true;
    }
    else if(maze[row][col+1] == ' '){
        return true;
    }
    else if(maze[row-1][col] == ' '){
        return true;
    }
    else if(maze[row][col-1] == ' '){
        return true;
    }

    return false;
}

bool Level::check_body(Position pst){
    auto aux = cobra->snake_body;
    
    while(!aux.empty()){
        if(pst.i == aux.front().i && pst.j == aux.front().j){
            return true;
        }
        aux.pop();
    }

    return false;
}

void Level::set_measures(int row, int col){
    lrow = row;
    lcol = col;

    string s;
    s.resize(lcol);
    maze.resize(lrow, s);
}

void Level::set_start_pos(int row, int col){
    start_pos.i = row;
    start_pos.i = col;
    snake_pos = start_pos;
}