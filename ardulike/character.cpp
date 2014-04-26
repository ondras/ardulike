#include "character.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

Character::Character(uint8_t _level, uint8_t _position, uint8_t _max_hp, uint8_t _toughness, uint8_t _strength, char _representation, uint8_t _properties):
Entity(_level, _position, _representation, _properties), hp(_max_hp), max_hp(_max_hp), toughness(_toughness), strength(_strength), exp(0), next_level_exp(100), character_level(1)
{
}

uint8_t Character::getCharacterLevel(void)
{
  return character_level;
}

void Character::say(const char * msg, ...)
{
  va_list args;
  va_start(args, msg);
  output->addMessage(msg, args);
  va_end(args);
}

uint8_t Character::getToughness(void)
{
  return toughness;
}

uint8_t Character::getStrength(void)
{
  return strength;
}

bool Character::isAlive(void)
{
  return properties & ENTITY_ALIVE;
}

void Character::damage(uint8_t dmg)
{
  if (isAlive()) {
    if (hp <= dmg) {
      die();
    } else {
      hp -= dmg;
    }
  }
}

uint8_t Character::getHp(void)
{
  return hp;
}

uint8_t Character::getMaxHp(void)
{
  return max_hp;
}

void Character::die(void)
{
  hp             = 0;
  properties    &= ~(ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT);
  representation = '%';
}

void Character::levelUp(void)
{
  character_level++;

  toughness *= LEVELUP_TOUGHNESS_MULTIPLIER;
  strength  *= LEVELUP_STRENGTH_MULTIPLIER;
  max_hp    *= LEVELUP_HP_MULTIPLIER;
  next_level_exp *= EXP_LEVEL_MULTIPLIER;

  if (LEVELUP_HEAL) { hp = max_hp; }
}

uint32_t Character::experienceGained(Character * other)
{
  return (other->getToughness() * EXP_KILL_MULTIPLIER);
}

void Character::gainExperience(Character * other)
{
  uint32_t required = 0;
  uint32_t d_exp    = experienceGained(other);

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

bool Character::attack(Character * other)
{
  int16_t dmg =
       (nrand(2 * strength, character_level * LEVEL_SKILL_MULTIPLIER)
     - (nrand(2 * other->getToughness(), other->getCharacterLevel() * LEVEL_SKILL_MULTIPLIER)));

  if (dmg > 0) {
    other->damage(dmg);
    return true;
  } else {
    return false;
  }
}

uint32_t Character::getExperience(void)
{
  return exp;
}

uint32_t Character::getNextLevelExperience(void)
{
  return next_level_exp;
}

bool Character::onInput(uint8_t input, World * w)
{
  return false;
}
