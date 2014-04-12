#include "npc.h"


Npc::Npc(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, char _representation):
  Character(_level, _position, _hp, _toughness, _representation), hostile(true)
{
  setDisplayDepth(DISPLAY_DEPTH_NPCS);
}

bool Npc::onInput(uint8_t input, World * w)
{
  Player * p = w->getPlayer();
  int8_t  d = p->getPosition() - position;

  if (!hostile || p->getLevel() != level) { return false; }

  if (abs(d) <= 1 || abs(d) > 5) {
    return false;
  } else {
    if (d > 0) { position++; }
    if (d < 0) { position--; }
    return true;
  }
}