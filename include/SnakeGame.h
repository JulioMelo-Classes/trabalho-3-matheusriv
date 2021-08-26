#ifndef SnakeGame_h
#define SnakeGame_h

#include <iostream>
#include <vector>
#include "Player.h"
#include "Snake.h"
#include "Level.h"

class SnakeGame{
    public:
        /**
        * @brief construtor padrão
        **/
        SnakeGame();

        Snake cobra; //objeto snake

        Player player; //objeto player

        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            START, RUNNING, WAITING, GAME_OVER 
        };

        /**
        * @brief realiza a inicialização geral do jogo
        **/
        void initialize_game(int argc, char *argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        int index_level; //índice do level
        int score; //<! score do jogo
        int frameCount;
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        std::vector<Level> levels; //<! vector de levels
        Level current_level;
        GameStates state; //<! guarda o estado do jogo

        /**
        * @brief imprime apresentação do jogo no início
        **/
        void print_intro();

        /**
        * @brief imprime número de vidas, score e maças comidas
        **/
        void print_informations();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h