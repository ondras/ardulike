#ifndef __ARDULIKE_NPC_H__
#define __ARDULIKE_NPC_H__

#include "character.h"
#include "player.h"

class Npc : public Character {
  protected:
    bool hostile;
  public:
    Npc(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, char _representation);
    virtual bool onInput(uint8_t input, World * w);
};

#endif
