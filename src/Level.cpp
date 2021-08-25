#include "Level.h"

using namespace std;

Level::Level(int row, int col){
    set_measures(row, col);
    apple_maze = "\x1b[31mQ\x1b[0m";
}

void Level::set_apples(int num_apples_){
    num_apples = num_apples_;
}

int Level::get_num_apples(){
    return num_apples;
}

bool Level::config_maze(Snake & cobra){
    for(int i=0; i<lrow; i++){
        for(int j=0; j<lcol; j++){
            if(maze[i][j] == '*'){
                set_start_pos(i, j);
                cobra.snake_body.push(line_col_toIndex(i, j));
                return true;
            }
        }
    }
    return false;
}

void Level::print_maze(){
    for(int i=0; i<lrow; i++){
        for(int j=0; j<lcol; j++){
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
            if((rand_row != start_pos.first) || (rand_col != start_pos.second))
            break;
        }
    }

    apple_pos = std::make_pair(rand_row, rand_col);
}

int Level::line_col_toIndex(int i, int j){
    return i*lcol+j;
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
}