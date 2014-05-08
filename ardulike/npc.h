#ifndef __ARDULIKE_NPC_H__
#define __ARDULIKE_NPC_H__

#include "constants.h"
#include "character.h"
#include "npc_table.h"

class World;

class Npc : public Character {
    bool    hostile;
    uint8_t defaults_index;
  public:
    Npc(uint8_t _level, uint8_t _position);
    Npc(uint8_t _level, uint8_t _position, char representation);

    char * getName(void) { return NpcTable::get(defaults_index)->getName(); }
    uint8_t getStrength(void) { return NpcTable::get(defaults_index)->getStrength(); };
    uint8_t getToughness(void) { return NpcTable::get(defaults_index)->getToughness(); };
    uint8_t getMaxHp(void) { return NpcTable::get(defaults_index)->getMaxHp(); };
    char getRepresentation(void) { return NpcTable::get(defaults_index)->getRepresentation(); };

    uint32_t getExperienceBonus(void) { return getToughness() * EXP_KILL_MULTIPLIER; };

    bool isHostile(void) { return hostile; };
    void setHostile(bool _hostile) { hostile = _hostile; };

    virtual bool onInput(uint8_t input, World * w);
};

#endif
