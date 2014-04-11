#ifndef __ARDULIKE_PLAYER_H__
#define __ARDULIKE_PLAYER_H__

#include "constants.h"
#include "character.h"

class Player : public Character {
  public:
  Player(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness);
  virtual bool onInput(uint8_t input, World * w);
};

#endif
