#include "SnakeGame.h"

#include <iomanip>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    current_level = 0;
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

void SnakeGame::Intro(){
    stringstream ss;
    ss << "\n  ---> Welcome to the classic Snake Game! <---\n"
        << std::setfill('-') << std::setw(50) << "\n"
        << "Levels Loaded: " << levels.size() << " | " 
        << "Snake Lives: 5 | " 
        << "Apples to eat: " << levels[current_level].get_num_apples() << "\n"
        << "Clear all the levels to win the game!\n"
        << std::setfill('-') << std::setw(50) << "\n"
        << ">>> Press \x1b[94m<ENTER>\x1b[0m to start.\n";

    cout << ss.str() << endl;

    while(cin.get() != '\n'){
        continue;
    }
}

void SnakeGame::printInterface(){
    std::stringstream ss;
    ss << setfill('-') << std::setw(50) << "\n"
       << "Lives: XX"  << " | "
       << "Score: " << score << " | "
       << "Food Eaten: " << cobra.get_apples_eaten() << "of " 
       << levels[current_level].get_num_apples() << "\n" 
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

        if(aux.config_maze(cobra) == false){
            cerr << ">>> ERRO! Labirinto não possui posição inicial da cobra!\n";
            exit(1);
        }
        aux.print_maze();
        levels.push_back(aux); 
    }
    
    Intro();

    state = START;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;

        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"

    /* Um nível é completado quando a quantidade de comida chega a 0 e a 
    cobra come a última comida que foi colocada no mapa. Quando isso acontece, 
    a simulação deve exibir uma mensagem correspondente e perguntar ao usuário se ele 
    quer continuar para ir para o próximo nível (se houver), reiniciar aquele mesmo nível 
    ou reiniciar do nível 1. */
    
    switch(state){
        case START:
            levels[current_level].rand_apple();
            // FIND SOLUTION
            state = RUNNING;
            break;

        case RUNNING:
            /*
            if(frameCount>0 && frameCount%10 == 0) 
                state = WAITING_USER;
            */
            break;
        
        case LEVEL_UP:
            //change Level
            if(levels.size() > 2){
                current_level++;
                //avoid seg fault
                if(current_level >= levels.size()-1){
                     current_level = 0;
                }
            }
            state = START;
            break;

        case WAITING_USER: 
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else if(choice == "s"){
                state = LEVEL_UP;
            }
            /*
            else if(choice == "r"){
                reiniciar
            }
            else if(choice == "r1"){
                reiniciar tudo
            }
            */
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
            printInterface();
            break;
        case WAITING_USER:
            cout << "Você quer continuar com o jogo? (s/n)" << endl;
            break;
        case GAME_OVER:
            cout << "O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
    
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(500);
    }
}