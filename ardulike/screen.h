#ifndef __ARDULIKE_SCREEN_H__
#define __ARDULIKE_SCREEN_H__

#include <LiquidCrystal.h>

#include "constants.h"
#include "character.h"
#include "level.h"
#include "stairs.h"

class Screen {
private:
  LiquidCrystal lcd;
public:
  Screen(LiquidCrystal _lcd);
  void render(Level lvl, Character player, Character ogre, Stairs stairs_up, Stairs stairs_down);
};

#endif
