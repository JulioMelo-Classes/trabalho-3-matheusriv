/* Representa um nível do jogo
   Possui dimensões e personagens que representam elementos do jogo
*/

#ifndef Level_h
#define Level_h

#include <iostream>
#include <utility>
#include <random>
#include <chrono> 
#include "Snake.h"

class Level{
   public:
      /**
      * @brief construtor
      * @param row inteiro com número de linhas
      * @param col inteiro com número de colunas
      **/
      Level(int row, int col);

      std::vector<std::string> maze; //vector contendo o labirinto atual, pode ser interpretado como uma matriz

      /**
      * @brief definir o número de maçãs para comer
      * @param num_apples_ inteiro com número de maçãs
      **/
      void set_apples(int num_apples_);

      /**
      * @brief retornar número de maçãs
      **/
      int get_num_apples();

      /**
      * @brief configurar labirinto
      **/
      bool config_maze(Snake & cobra); 

      /**
      * @brief imprime o labirinto
      **/
      void print_maze();

      /**
      * @brief posição aleatória para a maçã
      **/
      void rand_apple();

   private:
      int lrow; //número de linhas
      int lcol; //número de colunas
      int num_apples; //número de maçãs
      std::string apple_maze; //maçã
      std::pair<int,int> start_pos; //posição inicial da cobra
      std::pair<int,int> apple_pos; //posição da maçã

      /**
       * @brief transforma um indice de matriz i e j em um unico indice para um vetor
       * @param i linha da matriz
       * @param j coluna da matriz
       * @return indice do elemento no vetor
       */
      int line_col_toIndex(int i, int j);

      /**
      * @brief definir o valor das linhas e colunas de maze
      * @param row inteiro com número de linhas
      * @param col inteiro com número de colunas
      **/
      void set_measures(int row, int col);

      /**
      * @brief definir a posição inicial da cobra
      * @param row inteiro com linha inicial da cobra
      * @param col inteiro com coluna inicial da cobra
      **/
      void set_start_pos(int row, int col);

};

#endif //Level_h