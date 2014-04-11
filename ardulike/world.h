#ifndef __ARDULIKE_WORLD_H__
#define __ARDULIKE_WORLD_H__

#include "constants.h"

class Character;
class Entity;

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

  char *  getView(void);
  uint8_t getSize(void);
  uint8_t getEntityCount(void);

  void    onInput(uint8_t input);
};

#endif
