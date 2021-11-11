/* Representa o motor de IA
   Esta classe deve armazenar uma sequência de direções para alimentar a simulação
   A sugestão é criar pelo menos dois métodos:
   bool find_solution() : dada a localização atual da cobra dentro do labirinto e a 
        localização da comida, ele retorna true se ele encontrou (e armazenou) uma sequência 
        de direções que leva à comida, ou false caso contrário. No caso da solução ser encontrada, 
        este método também armazena a solução internamente no objeto.
   Direction next_move() : retorna uma direção para a cobra com base na sequência de direções encontradas 
        e armazenadas pelo motor de IA ou em uma política aleatória
*/

#ifndef Player_h
#define Player_h

#include "Level.h"

class Player{
   public:
      Player();
      void set_level(Level & level);
      bool find_solution(Position snake, Position food);
      std::vector<Position> get_shortest_path(Position food);
      std::vector<Position> get_death_path();
   
   private:
      Level * level;
      unsigned distance;
      std::vector<Position> visited;
      std::vector<std::vector<Position>> shortest_path;
      std::queue<Position> fila;
      std::vector<Position> ghost_snake_body;
      std::vector<Position> death_path;
      unsigned find_path(Position pst);
      void simulate_snake(Position end_pst);
      Position update_position(Position snake, short next);
      bool is_body(Position pst);
      int count_visited(Position pst);
      void reset();

};

#endif //Player_h