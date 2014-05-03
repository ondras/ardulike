#ifndef __ARDULIKE_PLAYER_H__
#define __ARDULIKE_PLAYER_H__

#include "constants.h"
#include "character.h"

class World;
class Npc;

class Player : public Character {
  uint32_t exp;
  uint32_t next_level_exp;
  uint8_t  character_level;

  uint8_t  toughness;
  uint8_t  strength;
  uint8_t  max_hp;

  public:

  Player(uint8_t _level, uint8_t _position);

  uint8_t getStrength(void) { return strength; };
  uint8_t getToughness(void) { return toughness; };
  uint8_t getMaxHp(void) { return max_hp; };

  uint32_t getExperience(void) { return exp; };
  uint32_t getNextLevelExperience(void) { return next_level_exp; };
  uint8_t  getCharacterLevel(void) { return character_level; };

  char     getRepresentation(void) { return CHAR_PLAYER; };

  void levelUp(void);
  void gainExperience(Npc * other);
  virtual bool onInput(uint8_t input, World * w);
};

#endif
