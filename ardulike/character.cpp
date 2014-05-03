#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "character.h"
#include "msgqueue.h"
#include "utils.h"

Character::Character(uint8_t _level, uint8_t _position, uint8_t _hp):
Entity(_level, _position), hp(_hp)
{
}

void Character::say(const char * msg, ...)
{
  va_list args;
  va_start(args, msg);
  output->addMessage(msg, args);
  va_end(args);
}

void Character::damage(uint8_t dmg)
{
  if (isAlive()) {
    if (hp > dmg) {
      hp -= dmg;
    } else {
      hp = 0;
    }
  }
}

bool Character::attack(Character * other)
{
  int16_t dmg =
         (nrand(2 * getStrength())
       - (nrand(2 * other->getToughness()))
     );

  if (dmg > 0) {
    other->damage(dmg);
    return true;
  } else {
    return false;
  }
}
