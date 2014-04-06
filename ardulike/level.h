#ifndef __ARDULIKE_LEVEL_H__
#define __ARDULIKE_LEVEL_H__

#include "constants.h"

class Level {
private:
  char level_view[SCREEN_COLS + 1];
public:
  Level(void);

  char *  getLevelView(uint8_t level, uint8_t view_index);
  uint8_t getLevelSize(uint8_t level);
  uint8_t getLevelCount(void);
};

#endif
