#ifndef __ARDULIKE_STAIRS_H__
#define __ARDULIKE_STAIRS_H__

#include "constants.h"
#include "terrain.h"

class World;

class Stairs : public Terrain {
  private:
  uint8_t target_level, target_position;

  public:
  Stairs(uint8_t _level, uint8_t _position, uint8_t _target_level, uint8_t _target_position);
  uint8_t getTargetLevel(void) { return target_level; };
  uint8_t getTargetPosition(void) { return target_position; };
  char getRepresentation(void) { return target_level < level ? CHAR_STAIRS_UP : CHAR_STAIRS_DOWN; };

  virtual bool blocksMovement(void) { return false; }
  virtual bool onInput(uint8_t input, World * w);
};

#endif
