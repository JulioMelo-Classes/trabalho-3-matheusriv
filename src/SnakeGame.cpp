#include "SnakeGame.h"

#include <iomanip>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    index_level = 0;
    score = 0;
    frameCount = 0;
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
    //some C++ voodoo here ;D
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void SnakeGame::print_intro(){
    stringstream ss;
    ss << "\n  ---> Welcome to the classic Snake Game! <---\n"
        << std::setfill('-') << std::setw(50) << "\n"
        << "Levels Loaded: " << levels.size() << " | " 
        << "Snake Lives: 5 | " 
        << "Apples to eat: " << levels[index_level].get_num_apples() << "\n"
        << "Clear all the levels to win the game!\n"
        << std::setfill('-') << std::setw(50) << "\n"
        << ">>> Press \x1b[94m<ENTER>\x1b[0m to start.\n";

    cout << ss.str() << endl;

    while(cin.get() != '\n'){
        continue;
    }
}

void SnakeGame::print_informations(){
    std::stringstream ss;
    ss << setfill('-') << std::setw(50) << "\n"
       << "Lives: " << cobra.get_lives() << " | "
       << "Score: " << score << " | "
       << "Food Eaten: " << cobra.get_apples_eaten() << " of " 
       << current_level.get_num_apples() << "\n" 
       << setfill('-') << std::setw(50) << "\n";
       
    cout << ss.str() << endl;
}

void SnakeGame::initialize_game(int argc, char *argv[]){
    if(argc < 2){
        cerr << ">>> Sem arquivo, jogo Snaze precisa de um arquivo para inicializar!\n" <<
                ">>> Simulação Falhou!" << endl;
        exit(1);
    }

    string filename = argv[1];
    ifstream levelFile(filename); //abrir arquivo
    if(!levelFile){
        cerr << ">>> ERRO, o arquivo não foi aberto!" << endl;
        exit(1);
    } 

    int linhas, colunas, num_apples, lvl = 0; 
    string line; 
    stringstream ss; //criar uma stringstream

    ss << levelFile.rdbuf(); //ler o arquivo

    levelFile.close();

    while(!ss.eof()){
        ss >> linhas >> colunas >> num_apples;
        
        if(linhas <= 0 || linhas > 100 || 
           colunas <= 0 || colunas > 100 || num_apples <= 0){
            cerr << ">>> ERRO, valores do labirinto inválidos!\n";
            exit(1);
        }

        Level aux(linhas, colunas);
        aux.set_apples(num_apples);

        //countering blank space and endlines
        while(ss.peek() == ' ' || ss.peek() == '\n'){
            ss.get();
        }

        for(int i=0; i<linhas; i++){
            getline(ss, line);
            aux.maze[i] = line;
        } 

        if(aux.config_maze() == false){
            cerr << ">>> ERRO! Labirinto não possui posição inicial da cobra!\n";
            exit(1);
        }
        levels.push_back(aux); 
    }

    print_intro();

    state = START;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;

        /*
        case RUNNING
            if(player.find_solution())
                level.snake_movement
            else
                level.snake_death_movement
        */

        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case START:
            current_level = levels[index_level];
            current_level.add_snake(cobra);
            player.set_player(current_level);
            state = RUNNING;
            break;

        case RUNNING:
            if(cobra.get_lives() == 0 || 
            cobra.get_apples_eaten() == current_level.get_num_apples())
                state = WAITING; //subir de nivel ou encerrar 
            if(frameCount>0 && frameCount%10 == 0)
                state = WAITING; 
            current_level.rand_apple();
            break;
        
        case WAITING:
            if(levels.size() > 2){
                if(index_level+1 == levels.size()){
                    //chegou no ultimo level
                    state = GAME_OVER;
                } 
                else{
                    if(choice == "n"){
                        state = GAME_OVER;
                        game_over();
                    }
                    else if(choice == "r"){
                        //reiniciar
                        cobra.reset();
                        state = START;
                    }
                    else if(choice == "rr"){
                        //reiniciar tudo
                        index_level = 0;
                        cobra.reset();
                        state = START;
                    }
                    else if(choice == "s"){
                        //mudar de nivel
                        index_level++;
                        cobra.reset();
                        state = START;
                    }
                }
            }
            else{
                state = GAME_OVER;
            }
            break;

        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            print_informations();
            current_level.print_maze();
            frameCount++;
            break;

        case WAITING:
            if(cobra.get_apples_eaten() == current_level.get_num_apples()){
                cout << "A cobra venceu o level " << index_level+1 << endl;
            }
            if(cobra.get_lives() == 0){
                cout << "A cobra perdeu!" << endl;
            }
            if(levels.size() > 2){
                cout << "A snake completou o level " << index_level+1 << endl;
                cout << "Você quer continuar com o jogo? \n" 
                     << "  Digite 's' para continuar | 'n' para parar\n" 
                     << "  'r' para reiniciar level  | 'rr' para reiniciar tudo" << endl;
            }
            break;

        case GAME_OVER:
            cout << "O jogo terminou!"<<endl;
            break;
    }
}

void SnakeGame::game_over(){
    
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);
    }
}