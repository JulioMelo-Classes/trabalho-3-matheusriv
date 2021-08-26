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

    int rand_row, rand_col;

    while(true){
        rand_row = generatorRow()%lrow;
        rand_col = generatorCol()%lcol;
        if(maze[rand_row][rand_col] == ' '){
            if(!cobra->check_body(rand_row, rand_col) &&
                check_sides_apple(rand_row, rand_col) )
                maze[rand_row][rand_col] = apple_maze;
            break;
        }
    }

    apple_pos = std::make_pair(rand_row, rand_col);
}

bool Level::check_sides_apple(int row, int col){
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

void Level::set_measures(int row, int col){
    lrow = row;
    lcol = col;

    string s;
    s.resize(lcol);
    maze.resize(lrow, s);
}

void Level::set_start_pos(int row, int col){
    start_pos = std::make_pair(row, col);
    snake_pos = start_pos;
}