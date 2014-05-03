#ifndef __ARDULIKE_NPC_H__
#define __ARDULIKE_NPC_H__

#include "constants.h"
#include "character.h"

#define NPC_MAX_NAME_LENGTH 15

class World;

class Npc : public Character {
    bool hostile;

    uint8_t  toughness;
    uint8_t  strength;
    uint8_t  max_hp;

    char name[NPC_MAX_NAME_LENGTH + 1];
  public:
    Npc(uint8_t _level, uint8_t _position);

    char * getName(void) { return name; }
    uint8_t getStrength(void) { return strength; };
    uint8_t getToughness(void) { return toughness; };
    uint8_t getMaxHp(void) { return max_hp; };

    uint32_t getExperienceBonus(void) { return getToughness() * EXP_KILL_MULTIPLIER; };

    bool isHostile(void) { return hostile; };
    void setHostile(bool _hostile) { hostile = _hostile; };

    char getRepresentation(void) { return CHAR_OGRE; };

    virtual bool onInput(uint8_t input, World * w);
};

#endif
