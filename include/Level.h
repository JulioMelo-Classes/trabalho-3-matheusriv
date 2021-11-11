/* Representa um nível do jogo
   Possui dimensões e personagens que representam elementos do jogo
*/

#ifndef Level_h
#define Level_h

#include <iostream>
#include <utility>
#include <random>
#include <chrono> 
#include "Position.h"
#include "Snake.h"

class Level{
   public:
      /**
      * @brief construtor padrão
      * @param row inteiro com número de linhas
      * @param col inteiro com número de colunas
      **/
      Level(int row, int col);

      /**
      * @brief construtor 
      **/
      Level();

      std::vector<std::string> maze; //vector contendo o labirinto atual, pode ser interpretado como uma matriz

      Snake * cobra; //cobra da classe Snake

      Position snake_pos; //posição da cobra

      /**
      * @brief adiciona cobra ao nível
      * @param cobra objeto da classe Snake
      **/
      void add_snake(Snake &cobra);

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
      bool config_maze(); 

      /**
       * @brief verifica se a comida tem um dos lados livres para que a snake chegue ate ela
       * @param pst posição a ser verificada
       * @return verdadeiro se um dos vizinhos da maça esta livre, falso caso contrario
       */
      bool check_sides_apple(Position pst);

      /**
      * @brief imprime o labirinto
      **/
      void print_maze();

      /**
      * @brief gera posição aleatória para a maçã no maze
      **/
      void rand_apple();


   private:
      int lrow; //número de linhas
      int lcol; //número de colunas
      int num_apples; //número de maçãs para comer
      char apple_maze; //maçã
      Position start_pos; //posição inicial da cobra
      Position apple_pos; //posição da maçã

      /**
      * @brief verifica se a posição passada esta ocupada pela cobra
      * @param pst Posição a ser verificada
      * @return true caso esteja na posição, false caso contrário
      **/
      bool check_body(Position pst);

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