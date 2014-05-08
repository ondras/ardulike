#include <avr/pgmspace.h>
#include <Wire.h>

#include "world.h"
#include "input.h"
#include "npc_table.h"
#include "npc.h"
#include "player.h"
#include "screen.h"
#include "stairs.h"
#include "msgqueue.h"

MsgQueue q = MsgQueue(8);
World w = World();

Player player     = Player(0, 0);

Stairs stairs_down = Stairs(0, 25, 1, 6);
Stairs stairs_up   = Stairs(1, 6,  0, 25);

Tree tree        = Tree(0, 8);
Wall wall        = Wall(0, 21);

Screen screen = Screen();

void setup(void) {
  randomSeed(analogRead(A2));

  w.setOutput(&q);
  w.addPlayer(&player);
  w.addTerrains(4, &stairs_up, &stairs_down, &wall, &tree);
  w.addNpcs(1, new Npc(0, 3, CHAR_OGRE));
  screen.render(&w, &q);
}

void loop(void) {
  uint8_t input = Input::get();

  w.onInput(input);

  screen.render(&w,&q);
}
