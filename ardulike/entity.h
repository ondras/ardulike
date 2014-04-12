#ifndef __ARDULIKE_ENTITY_H__
#define __ARDULIKE_ENTITY_H__

#include <Arduino.h>

class World;

class Entity {
protected:
  uint8_t display_depth;
  uint8_t position;
  uint8_t level;
  uint8_t properties;
  char representation;

public:
  Entity(uint8_t _level, uint8_t _position, char _representation);

  uint8_t getProperties(void);
  void    setProperties(uint8_t _properties);

  char getRepresentation(void);
  void setRepresentation(char _representation);

  void setLevel(uint8_t level);
  uint8_t getLevel(void);

  void setPosition(uint8_t _position);
  uint8_t getPosition(void);

  void setDisplayDepth(uint8_t _display_depth);
  uint8_t getDisplayDepth(void);

  virtual bool onInput(uint8_t input, World * w);
};
#endif
