#include <avr/pgmspace.h>
#include <Wire.h>

#include "world.h"
#include "input.h"
#include "character.h"
#include "screen.h"
#include "stairs.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

World w = World();

Character player   = Character('@', 2, 0, 0, 5, 3);
Character ogre     = Character('O', 1, 0, 2, 5, 2);
Character orc      = Character('o', 1, 1, 10, 3, 1);
Character dog      = Character('d', 1, 1, 2 , 1, 1);

Stairs stairs_down = Stairs('>', 0, 0, 25, 1, 6);
Stairs stairs_up   = Stairs('<', 0, 1, 6,  0, 25);

Entity tree        = Entity('T', 0, 0, 8);
Entity wall        = Entity('#', 4, 0, 21);

Screen screen(lcd);

void setup(void) {
  w.addPlayer(&player);
  w.addEntities(8, &player, &ogre, &stairs_up, &stairs_down, &orc, &dog, &wall, &tree);
  screen.render(&w);
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
    pos == 0 ? pos = w.getSize() - 1 : pos--;
  } else

  if (input == BUTTON_RIGHT) {
    pos == w.getSize() - 1 ? pos = 0 : pos++;
  }

  if (l == ogre.getLevel() && pos == ogre.getPosition() && ogre.isAlive()) {
    player.attack(&ogre);
  }
  else {
    player.setLevel(l);
    player.setPosition(pos);
  }

  if (oldpos != pos || oldl != l) {
    screen.render(&w);
  }
}
