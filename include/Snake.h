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

class Snake{
   public:
      Snake();
      std::queue<unsigned> snake_body; //corpo da cobra
      int get_apples_eaten();

   private:
      int lifes; //número de vidas
      int apples_eaten; //número de maçãs comidas
      int snake_size; //tamanho da cobra

};

#endif //Snake_h