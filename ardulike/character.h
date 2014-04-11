#ifndef __ARDULIKE_CHARACTER_H__
#define __ARDULIKE_CHARACTER_H__

#include <Arduino.h>
#include "entity.h"
#include "world.h"

class Character : public Entity {
private:
  uint8_t hp;
  uint8_t toughness;
  bool alive;

  void die(void);
public:
  Character(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness);
  uint8_t getToughness(void);
  uint8_t getHp(void);
  void damage(uint8_t damage);
  bool  isAlive(void);
  bool attack(Character * other);

  virtual bool onInput(uint8_t input, World * w);
};

#endif
