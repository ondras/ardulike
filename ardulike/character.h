#ifndef __ARDULIKE_CHARACTER_H__
#define __ARDULIKE_CHARACTER_H__

#include <Arduino.h>
#include "entity.h"
#include "world.h"

class Character : public Entity {
protected:
  uint8_t hp;
public:
  Character(uint8_t _level, uint8_t _position, uint8_t _hp);

  bool attack(Character * other);
  void damage(uint8_t damage);
  void say(const char * message, ...);

  bool isAlive(void) { return hp > 0; };

  virtual uint8_t getToughness(void);
  virtual uint8_t getStrength(void);
  virtual uint8_t getHp(void);
  virtual uint8_t getMaxHp(void);

  virtual bool blocksMovement(void)  { return isAlive(); };
  virtual char getRepresentation(void) { return CHAR_SPACE; };
  virtual bool onInput(uint8_t input, World * w) { return false; };
};

#endif
