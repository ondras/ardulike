#include <avr/pgmspace.h>
#include <stdlib.h>

#include "player.h"
#include "npc.h"
#include "world.h"

Npc::Npc(uint8_t _level, uint8_t _position):
  Character(_level, _position, PLAYER_STARTING_HP), hostile(true)
{
  strength  = PLAYER_STARTING_STRENGTH;
  toughness = PLAYER_STARTING_TOUGHNESS;
  max_hp    = PLAYER_STARTING_HP;
}

bool Npc::onInput(uint8_t input, World * w)
{
  Player * p = w->getPlayer();
  int8_t   d = p->getPosition() - position;
  uint8_t  new_position = position;

  if (!isHostile() || !isAlive() || p->getLevel() != level) { return false; }

  if (abs(d) > 5) { return false; }

  if (d > 1) {
    new_position = position + 1;
  } else
  if (d < -1) {
    new_position = position - 1;
  }

  if (w->isPassable(level, new_position)) {
    position = new_position;
    return true;
  }

  if (abs(d) == 1 && p->isAlive()) {
    if (attack(p)) {
      if (!p->isAlive()) {
        say(PSTR("You die."));
      } else {
        say(PSTR("The %s hits."), name);
      }
    } else {
      say(PSTR("The %s misses."), name);
    }
    return true;
  }

  return false;
}
