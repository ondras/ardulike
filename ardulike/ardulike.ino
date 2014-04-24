#include <avr/pgmspace.h>
#include <Wire.h>

#include "world.h"
#include "input.h"
#include "npc.h"
#include "player.h"
#include "screen.h"
#include "stairs.h"
#include "msgqueue.h"

MsgQueue q = MsgQueue(9);
World w = World();

Player   player    = Player(0, 0, 10, 3, 3);

Npc ogre     = Npc(0, 2, 5, 2, 2, CHAR_OGRE);
Npc orc      = Npc(1, 10, 3, 1, 2, CHAR_ORC);
Npc dog      = Npc(1, 2 , 1, 1, 2, CHAR_DOG);

Stairs stairs_down = Stairs(0, 25, 1, 6);
Stairs stairs_up   = Stairs(1, 6,  0, 25);

Entity tree        = Entity(0, 8, CHAR_TREE, ENTITY_TERRAIN);
Entity wall        = Entity(0, 21, CHAR_WALL, ENTITY_TERRAIN | ENTITY_BLOCKS_MOVEMENT);

Screen screen = Screen();

void setup(void) {
  w.setOutput(&q);
  w.addPlayer(&player);
  w.addEntities(8, &player, &ogre, &stairs_up, &stairs_down, &orc, &dog, &wall, &tree);
  w.init();
  screen.render(&w, &q);
}

void loop(void) {
  uint8_t input = Input::get();

  w.onInput(input);

  screen.render(&w,&q);
}
