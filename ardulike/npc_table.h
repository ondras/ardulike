#ifndef __ARDULIKE_NPC_TABLE_H__
#define __ARDULIKE_NPC_TABLE_H__

#include "npc.h"

#define NPC_MAX_TYPES 16

class NpcDefaults {
  char    representation;
  char    name[NPC_MAX_NAME_LENGTH + 1];
  uint8_t toughness;
  uint8_t strength;
  uint8_t max_hp;
  public:
  NpcDefaults(char * _name, char _representation, uint8_t _toughness, uint8_t _strength, uint8_t _max_hp);
  char * getName(void) { return name; };
  char getRepresentation(void) { return representation; };
  uint8_t getToughness(void) { return toughness; };
  uint8_t getStrength(void) { return strength; };
  uint8_t getMaxHp(void) { return max_hp; };
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
