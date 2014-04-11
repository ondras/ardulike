#ifndef __ARDULIKE_ENTITY_H__
#define __ARDULIKE_ENTITY_H__

#include <Arduino.h>

class World;

class Entity {
protected:
  uint8_t display_depth;
  uint8_t position;
  uint8_t level;
  char representation;

public:
  Entity(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position);
  void setLevel(uint8_t level);
  void setPosition(uint8_t _position);

  char getRepresentation(void);
  uint8_t getDisplayDepth(void);
  uint8_t getPosition(void);
  uint8_t getLevel(void);

  bool onInput(uint8_t input, World * w);
};
#endif
