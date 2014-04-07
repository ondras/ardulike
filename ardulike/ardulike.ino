#include <avr/pgmspace.h>
#include <Wire.h>

#include "level.h"
#include "input.h"
#include "character.h"
#include "screen.h"
#include "stairs.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

Level lvl = Level();

Character player   = Character('@', 0, 0, 5, 3);
Character ogre     = Character('O', 0, 2, 5, 2);
Character orc      = Character('o', 1, 10, 3, 1);
Character dog      = Character('d', 1, 2 , 1, 1);

Stairs stairs_down = Stairs('>', 0, 25, 1, 6);
Stairs stairs_up   = Stairs('<', 1, 6,  0, 25);

Screen screen(lcd);

void setup(void) {
  lvl.addActors(6, &player, &ogre, &stairs_up, &stairs_down, &orc, &dog);
  screen.render(player, lvl);
}

void loop(void) {
  uint8_t input     = Input::get();

  uint8_t pos       = player.getPosition();
  uint8_t l         = player.getLevel();

  uint8_t oldpos    = player.getPosition();
  uint8_t oldl      = player.getLevel();

  if (input == BUTTON_UP) {
    if (pos == stairs_up.getPosition() && l == stairs_up.getLevel()) {
      l   = stairs_up.getTargetLevel();
      pos = stairs_up.getTargetPosition();
    }
  } else

  if (input == BUTTON_DOWN) {
    if (pos == stairs_down.getPosition() && l == stairs_down.getLevel()) {
      l   = stairs_down.getTargetLevel();
      pos = stairs_down.getTargetPosition();
    }
  } else

  if (input == BUTTON_LEFT) {
    pos == 0 ? pos = lvl.getLevelSize(l) - 1 : pos--;
  } else

  if (input == BUTTON_RIGHT) {
    pos == lvl.getLevelSize(l) - 1 ? pos = 0 : pos++;
  }

  if (l == ogre.getLevel() && pos == ogre.getPosition() && ogre.isAlive()) {
    player.attack(&ogre);
  }
  else {
    player.setLevel(l);
    player.setPosition(pos);
  }

  if (oldpos != pos || oldl != l) {
    screen.render(player, lvl);
  }
}
