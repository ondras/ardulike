#include <avr/pgmspace.h>

#include "player.h"
#include "npc.h"
#include "world.h"

Player::Player(uint8_t _level, uint8_t _position):
Character(_level, _position, PLAYER_STARTING_HP), exp(0), next_level_exp(100), character_level(1)
{
  strength  = PLAYER_STARTING_STRENGTH;
  toughness = PLAYER_STARTING_TOUGHNESS;
  max_hp    = PLAYER_STARTING_HP;
}

void Player::gainExperience(Npc * other)
{
  uint32_t required = 0;
  uint32_t d_exp    = other->getExperienceBonus();

  do {
    required = next_level_exp - exp;
    if (d_exp >= required) {
      levelUp();
      exp   += required;
      d_exp -= required;
    } else {
      exp   += d_exp;
      d_exp  = 0;
    }
  } while (d_exp > 0);
}

void Player::levelUp(void)
{
  character_level++;

  toughness *= LEVELUP_TOUGHNESS_MULTIPLIER;
  strength  *= LEVELUP_STRENGTH_MULTIPLIER;
  max_hp    *= LEVELUP_HP_MULTIPLIER;
  next_level_exp *= EXP_LEVEL_MULTIPLIER;

  if (LEVELUP_HEAL) { hp = max_hp; }
  say(PSTR("You level up!"));
}

bool Player::onInput(uint8_t input, World * w)
{
  Npc * npc;
  uint8_t new_position = position;

  if (!isAlive()) { return false; }
  if (input != BUTTON_RIGHT && input != BUTTON_LEFT) { return false; }

  if (input == BUTTON_LEFT) {
    new_position = position - 1;
  }

  if (input == BUTTON_RIGHT) {
    new_position = position + 1;
  }

  if (w->isPassable(level, new_position)) {
    position = new_position;
    return true;
  }

  npc = w->getNpc(level, new_position);
  if (npc && npc->isAlive() && npc->isHostile()) {
    if (attack(npc)) {
      if (!npc->isAlive()) {
        say(PSTR("You kill the %s."), npc->getName());
        say(PSTR("You gain %d XP."), npc->getExperienceBonus());
        gainExperience(npc);
      } else {
        say(PSTR("You hit."));
      }
    } else {
      say(PSTR("You miss."));
    }
    return true;
  }

  return false;
}
