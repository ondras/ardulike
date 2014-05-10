#include <string.h>
#include <stdarg.h>
#include <Arduino.h>
#include "npc_table.h"

NpcTable * NpcTable::self = NULL;

NpcTable * NpcTable::instance()
{
  if (self == NULL) { self = new NpcTable(); }
  return self;
}

NpcDefaults::NpcDefaults(char * _name, char _representation, uint8_t _toughness, uint8_t _strength, uint8_t _max_hp):
  representation(_representation), toughness(_toughness), strength(_strength), max_hp(_max_hp)
{
  strncpy(name, _name, NPC_MAX_NAME_LENGTH);
  name[NPC_MAX_NAME_LENGTH] = '\0';
}

NpcDefaults * NpcTable::get(uint8_t index)
{
  if (index >= instance()->count) { return NULL; }
  return instance()->table[index];
}

uint8_t NpcTable::randomMonsterIndex(void)
{
  return random(instance()->count);
}

uint8_t NpcTable::monsterIndex(char representation)
{
  for (uint8_t i = 0; i < instance()->count; i++) {
    if (get(i)->getRepresentation() == representation) { return i; }
  }
  return -1;
}

void NpcTable::addNpc(NpcDefaults * defaults)
{
  table[count++] = defaults;
}

NpcTable::NpcTable():
  count(0)
{
  addNpc(new NpcDefaults("ogre",  CHAR_OGRE,  5, 1, 3));
  addNpc(new NpcDefaults("orc",   CHAR_ORC,   5, 1, 3));
  addNpc(new NpcDefaults("gnome", CHAR_GNOME, 5, 1, 3));
  addNpc(new NpcDefaults("rat",   CHAR_RAT,   5, 1, 3));
}
