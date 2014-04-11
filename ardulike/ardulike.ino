#include <avr/pgmspace.h>
#include <Wire.h>

#include "world.h"
#include "input.h"
#include "character.h"
#include "screen.h"
#include "stairs.h"

World w = World();

Character player   = Character('@', 2, 0, 0, 5, 3);
Character ogre     = Character('O', 1, 0, 2, 5, 2);
Character orc      = Character('o', 1, 1, 10, 3, 1);
Character dog      = Character('d', 1, 1, 2 , 1, 1);

Stairs stairs_down = Stairs('>', 0, 0, 25, 1, 6);
Stairs stairs_up   = Stairs('<', 0, 1, 6,  0, 25);

Entity tree        = Entity('T', 0, 0, 8);
Entity wall        = Entity('#', 4, 0, 21);

Screen screen = Screen();

void setup(void) {
  w.addPlayer(&player);
  w.addEntities(8, &player, &ogre, &stairs_up, &stairs_down, &orc, &dog, &wall, &tree);
  screen.render(&w);
}

void loop(void) {
  uint8_t input = Input::get();

  w.onInput(input);

  screen.render(&w);
}
