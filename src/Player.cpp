#include "Player.h"

using namespace std;

Player::Player(){}

void Player::set_player(Level & level){
    this->level = &level;
}