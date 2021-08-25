#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>

#include "Level.h"

class SnakeGame{
    public:
        /**
        * @brief construtor padrão
        **/
        SnakeGame();

        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            START, RUNNING, LEVEL_UP, GAME_OVER, WAITING_USER 
        };

        Snake cobra; //objeto snake

        /**
        * @brief realiza a inicialização geral do jogo
        **/
        void initialize_game(int argc, char *argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        int frameCount; //<! contador de frames, usado apenas como exemplo
        int current_level; //<! número de níveis do jogo
        int score; //<! score do jogo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        std::vector<Level> levels; //<! vector de levels
        GameStates state; //<! guarda o estado do jogo

        /**
        * @brief imprime apresentação do jogo no início
        **/
        void Intro();

        /**
        * @brief imprime número de vidas, score e maças comidas
        **/
        void printInterface();

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