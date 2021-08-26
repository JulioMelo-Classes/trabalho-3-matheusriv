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
      std::queue<std::pair<int,int>> snake_body;
      int get_lives();
      int get_apples_eaten();
      bool check_body(int prow, int pcol);
      void reset();
      std::queue<std::pair<int,int>> & get_snake_body();

   private:
      int lives; //número de vidas
      int apples_eaten; //número de maçãs comidas
      int snake_size; //tamanho da cobra
      std::unordered_set<int> visited; //armazena as posicoes visitadas
      std::vector<std::vector<int>> shortest_path;
      std::vector<int> death_path;

};

#endif //Snake_h