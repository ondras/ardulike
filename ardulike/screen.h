#ifndef __ARDULIKE_SCREEN_H__
#define __ARDULIKE_SCREEN_H__

#include <LiquidCrystal.h>

#include "constants.h"
#include "character.h"
#include "world.h"
#include "stairs.h"

class Screen {
private:
  LiquidCrystal lcd;
public:
  Screen(LiquidCrystal _lcd);
  void render(Character player, World w);
};

#endif
