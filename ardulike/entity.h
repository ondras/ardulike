#ifndef __ARDULIKE_ENTITY_H__
#define __ARDULIKE_ENTITY_H__

#include <Arduino.h>
#include "msgqueue.h"

#define ENTITY_NONE             0
#define ENTITY_HOSTILE          1
#define ENTITY_ALIVE            2
#define ENTITY_ITEM             4
#define ENTITY_TERRAIN          8
#define ENTITY_NPC             16
#define ENTITY_PLAYER          32
#define ENTITY_BLOCKS_MOVEMENT 64

class World;

class Entity {
protected:
  MsgQueue * output;

  char representation;
  uint8_t position;
  uint8_t level;
  uint8_t properties;
  uint8_t display_depth;

public:
  Entity(uint8_t _level, uint8_t _position, char _representation, uint8_t _properties);

  void    setOutput(MsgQueue * q);

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
