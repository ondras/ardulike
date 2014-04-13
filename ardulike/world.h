#ifndef __ARDULIKE_WORLD_H__
#define __ARDULIKE_WORLD_H__

#include "constants.h"

class Player;
class Entity;

class World {
private:
  Player    * player;
  Entity    * entities[64];
  uint8_t  entity_count;
  uint8_t  size;
  char view[SCREEN_COLS + 1];
  bool changed;
public:
  World(void);

  void     addPlayer(Player * _player);
  Player * getPlayer(void);

  Entity * findEntity(uint8_t level, uint8_t position, uint8_t properties);

  void    addEntity(Entity * entity);
  void    addEntities(int count, ...);

  char *  getView(void);
  uint8_t getSize(void);
  uint8_t getEntityCount(void);

  bool    hasChanged(void);
  void    onInput(uint8_t input);
};

#endif
