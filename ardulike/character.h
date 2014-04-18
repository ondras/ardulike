#ifndef __ARDULIKE_CHARACTER_H__
#define __ARDULIKE_CHARACTER_H__

#include <Arduino.h>
#include "entity.h"
#include "world.h"

class Character : public Entity {
protected:
  uint8_t hp;
  uint8_t toughness;

  void die(void);
public:
  Character(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, char _representation, uint8_t _properties);
  uint8_t getToughness(void);
  uint8_t getHp(void);
  void damage(uint8_t damage);
  bool  isAlive(void);
  bool attack(Character * other);
  void say(char * message);

  virtual bool onInput(uint8_t input, World * w);
};

#endif
