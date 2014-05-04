#include <string.h>
#include <stdarg.h>
#include "npc_table.h"

NpcDefaults::NpcDefaults(char * _name, char _representation, uint8_t _toughness, uint8_t _strength, uint8_t _max_hp):
  representation(_representation), toughness(_toughness), strength(_strength), max_hp(_max_hp)
{
  strncpy(name, _name, NPC_MAX_NAME_LENGTH);
  name[NPC_MAX_NAME_LENGTH] = '\0';
}

void NpcTable::addNpc(NpcDefaults * defaults)
{
  table[count++] = defaults;
}

void NpcTable::addNpcs(uint8_t count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addNpc(va_arg(arguments, NpcDefaults *));
  }

  va_end(arguments);
}

NpcTable::NpcTable():
  count(0)
{
}
