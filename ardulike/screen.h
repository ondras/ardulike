#ifndef __ARDULIKE_SCREEN_H__
#define __ARDULIKE_SCREEN_H__

#include <LiquidCrystal.h>

#include "constants.h"
#include "player.h"
#include "world.h"
#include "stairs.h"

class Screen {
private:
  LiquidCrystal lcd;
public:
  Screen();
  void render(World * w);
};

#endif
