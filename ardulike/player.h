#ifndef __ARDULIKE_PLAYER_H__
#define __ARDULIKE_PLAYER_H__

#include "constants.h"
#include "character.h"

class Player : public Character {
  uint32_t exp;
  uint32_t next_level_exp;
  uint8_t  character_level;
  public:

  Player(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, uint8_t _strength);
  virtual bool onInput(uint8_t input, World * w);

  uint32_t getExperience(void);
  uint32_t getNextLevelExperience(void);
  uint8_t getCharacterLevel(void);

  void levelUp(void);
  void gainExperience(Character * other);
};

#endif
