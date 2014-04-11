#include "npc.h"


Npc::Npc(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, bool _hostile):
  Character(_representation, _display_depth, _level, _position, _hp, _toughness), hostile(_hostile)
{
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
