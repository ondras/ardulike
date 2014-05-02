#include "npc.h"

Npc::Npc(char * _name, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, uint8_t _strength):
  Character(_level, _position, _hp, _toughness, _strength)
{
  strncpy(name, _name, NPC_MAX_NAME_LENGTH);
  name[NPC_MAX_NAME_LENGTH] = '\0';
  display_depth = DISPLAY_DEPTH_NPCS;
}

char * Npc::getName(void)
{
  return name;
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
