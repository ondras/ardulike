#ifndef __ARDULIKE_WORLD_H__
#define __ARDULIKE_WORLD_H__

#include "entity.h"
#include "constants.h"
#include "character.h"

class World {
private:
  Character * player;
  Entity    * entities[64];
  uint8_t  entity_count;
  uint8_t  size;
  char view[SCREEN_COLS + 1];
public:
  World(void);

  void        addPlayer(Character * _player);
  Character * getPlayer(void);

  void    addEntity(Entity * entity);
  void    addEntities(int count, ...);
  char *  getView(uint8_t level, uint8_t view_index);
  uint8_t getSize(uint8_t level);
  uint8_t getEntityCount(void);
};

#endif
