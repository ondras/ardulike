#include "npc.h"

Npc::Npc(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, char _representation):
  Character(_level, _position, _hp, _toughness, _representation, ENTITY_NPC | ENTITY_HOSTILE | ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT)
{
  display_depth = DISPLAY_DEPTH_NPCS;
}

bool Npc::isHostile(void)
{
  return properties & ENTITY_HOSTILE;
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
        say("You die.");
      } else {
        say("The creature hits you.");
      }
    } else {
      say("The creature misses you.");
    }
    return true;
  }

  return false;
}
