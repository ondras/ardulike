#ifndef __ARDULIKE_NPC_TABLE_H__
#define __ARDULIKE_NPC_TABLE_H__

#include "npc.h"

#define NPC_MAX_TYPES 16

class NpcDefaults {
  char    representation;
  uint8_t display_depth;
  char    name[NPC_MAX_NAME_LENGTH + 1];
  public:
  NpcDefaults(char * _name, char _representation);
};

class NpcTable {
  uint8_t count;
  NpcDefaults * table[NPC_MAX_TYPES];
  public:
  NpcTable();
  void addNpc(NpcDefaults * defaults);
  void addNpcs(uint8_t count, ...);
};

#endif
