#ifndef __ARDULIKE_TERRAIN_H__
#define __ARDULIKE_TERRAIN_H__

#include "entity.h"

class World;

class Terrain : public Entity {
  public:
  Terrain(uint8_t _level, uint8_t _position);
  virtual bool onInput(uint8_t input, World * w) { return false; };
  virtual bool blocksMovement(void) { return false; }
};

class Tree : public Terrain {
  public:
  Tree(uint8_t _level, uint8_t _position): Terrain(_level, _position) {};
  virtual char getRepresentation(void)  { return CHAR_TREE; };
};

class Wall : public Terrain {
  public:
  Wall(uint8_t _level, uint8_t _position): Terrain(_level, _position) {};
  virtual char getRepresentation(void) { return CHAR_WALL; };
  virtual bool blocksMovement(void) { return true; };
};

#endif
