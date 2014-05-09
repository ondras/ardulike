#ifndef __ARDULIKE_WORLD_H__
#define __ARDULIKE_WORLD_H__

#include "constants.h"
#include "msgqueue.h"
#include "terrain.h"

class Player;
class Entity;
class Npc;

class World {
private:
  MsgQueue  * output;
  Player    * player;

  Terrain   * terrain[64];
  Npc       * npcs[64];

  uint8_t  terrain_count;
  uint8_t  npc_count;

  uint32_t turns;

  char view[SCREEN_COLS + 1];
  bool changed;
public:
  World(void);

  bool    hasChanged(void) { return changed; };
  uint8_t getSize(void) { return WORLD_SIZE; };

  uint32_t getTurns(void) { return turns; };
  void     turn(void) { turns++; };

  void     setOutput(MsgQueue * _output) { output = _output; };

  void     addPlayer(Player * _player);
  Player * getPlayer(void) { return player; };

  bool  isPassable(uint8_t level, uint8_t position);
  Npc * getNpc(uint8_t level, uint8_t position);

  void    addTerrain(Terrain * _terrain);
  void    addTerrains(uint8_t count, ...);

  void    addNpc(Npc * _npc);
  void    addNpcs(uint8_t count, ...);

  char *  getView(void);

  void    onInput(uint8_t input);
};

#endif
