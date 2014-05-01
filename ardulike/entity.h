#ifndef __ARDULIKE_ENTITY_H__
#define __ARDULIKE_ENTITY_H__

#include <Arduino.h>
#include "msgqueue.h"

class World;

class Entity {
protected:
  MsgQueue * output;

  uint8_t position;
  uint8_t level;

public:
  Entity(uint8_t _level, uint8_t _position) { position = _position; level = _level; };

  void    setOutput(MsgQueue * q) { output = q; };

  void    setLevel(uint8_t _level) { level = _level; };
  uint8_t getLevel(void) { return level; };

  void    setPosition(uint8_t _position) { position = _position; };
  uint8_t getPosition(void) { return position; };

  virtual uint8_t getDisplayDepth(void) { return DISPLAY_DEPTH_TERRAIN; };
  virtual char    getRepresentation(void) { return CHAR_FLOOR; };
  virtual bool    onInput(uint8_t input, World * w) { return false; };
  virtual bool    blocksMovement(void) { return true; };
};
#endif
