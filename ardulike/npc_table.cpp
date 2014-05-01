#include "npc_table.h"

NpcDefaults::NpcDefaults(char * _name, char _representation):
  representation(_representation), display_depth(DISPLAY_DEPTH_NPCS)
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
