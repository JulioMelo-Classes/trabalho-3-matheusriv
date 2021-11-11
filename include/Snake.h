/* Representa a cobra e seus atributos  
   A simulação do jogo deve possuir apenas uma cobra
*/

#ifndef Snake_h
#define Snake_h

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include "Position.h"

class Snake{
   public:
      /**
      * @brief construtor 
      **/
      Snake();

      std::queue<Position> snake_body; //corpo da Snake

      /**
      * @brief retorna número de vidas da Snake 
      **/
      int get_lives();

      /**
      * @brief retorna número de maçãs comidas da Snake 
      **/
      int get_apples_eaten();

      /**
      * @brief retorna tamanho da Snake 
      **/
      int get_snake_size();

      /**
      * @brief faz reset do número de vidas da Snake 
      **/
      void reset_lives();

      /**
      * @brief faz reset dos parâmetros da Snake 
      **/
      void reset();

   private:
      int lives; //número de vidas
      int apples_eaten; //número de maçãs comidas
      int snake_size; //tamanho da cobra

};

#endif //Snake_h