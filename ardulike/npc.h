#ifndef __ARDULIKE_NPC_H__
#define __ARDULIKE_NPC_H__

#include "character.h"
#include "player.h"

#define NPC_MAX_NAME_LENGTH 15

class Npc : public Character {
    char name[NPC_MAX_NAME_LENGTH + 1];
  public:
    Npc(char * _name, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, uint8_t _strength, char _representation);
    char * getName(void);
    bool isHostile(void);
    virtual bool onInput(uint8_t input, World * w);
};

#endif
