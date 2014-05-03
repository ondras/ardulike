#ifndef __ARDULIKE_ENTITY_H__
#define __ARDULIKE_ENTITY_H__

#include <inttypes.h>
#include "constants.h"

class MsgQueue;
class World;

class Entity {
protected:
  MsgQueue * output;

  uint8_t position;
  uint8_t level;

public:
  Entity(uint8_t _level, uint8_t _position) { position = _position; level = _level; };

  void    setOutput(MsgQueue * _output) { output = _output; };

  void    setLevel(uint8_t _level) { level = _level; };
  uint8_t getLevel(void) { return level; };

  void    setPosition(uint8_t _position) { position = _position; };
  uint8_t getPosition(void) { return position; };

  virtual char    getRepresentation(void) { return CHAR_FLOOR; };
  virtual bool    onInput(uint8_t input, World * w) { return false; };
  virtual bool    blocksMovement(void) { return true; };

  virtual bool    at(uint8_t _level, uint8_t _position) { return (level == _level && position == _position); };
  virtual bool    blocksAt(uint8_t _level, uint8_t _position) { return at(_level, _position) && blocksMovement(); };
  virtual bool    inView(uint8_t _level, uint8_t _from, uint8_t _to) { return (level == _level && position >= _from && position < _to); };
};
#endif
