#ifndef __ARDULIKE_LEVEL_H__
#define __ARDULIKE_LEVEL_H__

#include "entity.h"
#include "constants.h"

class Level {
private:
  Entity * actors[64];
  uint8_t  actor_count;
  uint8_t  size;
  char level_view[SCREEN_COLS + 1];
public:
  Level(void);

  void    addActor(Entity * actor);
  void    addActors(int count, ...);
  char *  getLevelView(uint8_t level, uint8_t view_index);
  uint8_t getLevelSize(uint8_t level);
  uint8_t getActorCount(void);
};

#endif
