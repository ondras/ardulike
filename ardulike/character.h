#ifndef __ARDULIKE_CHARACTER_H__
#define __ARDULIKE_CHARACTER_H__

#include <Arduino.h>
#include "entity.h"
#include "world.h"

class Character : public Entity {
protected:
  uint8_t hp, max_hp;
  uint8_t toughness;
  uint8_t strength;

  uint32_t exp;
  uint32_t next_level_exp;
  uint8_t character_level;

  void die(void);
  uint32_t experienceGained(Character * other);
  virtual void levelUp(void);
public:
  Character(uint8_t _level, uint8_t _position, uint8_t _max_hp, uint8_t _toughness, uint8_t _strength, char _representation, uint8_t _properties);
  uint8_t getToughness(void);
  uint8_t getStrength(void);
  uint8_t getHp(void);
  uint8_t getMaxHp(void);
  uint32_t getExperience(void);
  uint32_t getNextLevelExperience(void);
  uint8_t getCharacterLevel(void);
  void damage(uint8_t damage);
  bool  isAlive(void);
  bool attack(Character * other);
  void gainExperience(Character * other);
  void say(const char * message, ...);

  virtual bool onInput(uint8_t input, World * w);
};

#endif
