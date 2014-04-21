#ifndef __ARDULIKE_WORLD_H__
#define __ARDULIKE_WORLD_H__

#include "constants.h"
#include "msgqueue.h"

class Player;
class Entity;
class Npc;

class World {
private:
  MsgQueue  * output;
  Player    * player;
  Entity    * entities[64];
  uint8_t  entity_count;
  uint8_t  size;
  uint32_t turns;
  char view[SCREEN_COLS + 1];
  bool changed;
public:
  World(void);

  void    setOutput(MsgQueue * q);
  void    init(void);

  void     addPlayer(Player * _player);
  Player * getPlayer(void);

  bool isPassable(uint8_t level, uint8_t position);

  Npc * findNpc(uint8_t level, uint8_t position);
  Entity * findEntity(uint8_t level, uint8_t position, uint8_t properties);

  void    addEntity(Entity * entity);
  void    addEntities(int count, ...);

  char *  getView(void);
  uint8_t getSize(void);
  uint8_t getEntityCount(void);
  uint32_t getTurns(void);

  bool    hasChanged(void);
  void    onInput(uint8_t input);
};

#endif
