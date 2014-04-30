#include <avr/pgmspace.h>
#include <Wire.h>

#include "world.h"
#include "input.h"
#include "npc.h"
#include "player.h"
#include "screen.h"
#include "stairs.h"
#include "msgqueue.h"

MsgQueue q = MsgQueue(8);
World w = World();

Player   player    = Player(0, 0, 10, 3, 3);

Npc ogre     = Npc("ogre", 0, 2, 5, 1, 3, CHAR_OGRE);

Stairs stairs_down = Stairs(0, 25, 1, 6);
Stairs stairs_up   = Stairs(1, 6,  0, 25);

Entity tree        = Entity(0, 8, CHAR_TREE, ENTITY_TERRAIN);
Entity wall        = Entity(0, 21, CHAR_WALL, ENTITY_TERRAIN | ENTITY_BLOCKS_MOVEMENT);

Screen screen = Screen();

void setup(void) {
  randomSeed(analogRead(A2));

  w.setOutput(&q);
  w.addPlayer(&player);
  w.addEntities(6, &player, &ogre, &stairs_up, &stairs_down, &wall, &tree);
  w.init();
  screen.render(&w, &q);
}

void loop(void) {
  uint8_t input = Input::get();

  w.onInput(input);

  screen.render(&w,&q);
}
