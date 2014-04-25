#include "character.h"

Character::Character(uint8_t _level, uint8_t _position, uint8_t _max_hp, uint8_t _toughness, uint8_t _strength, char _representation, uint8_t _properties):
Entity(_level, _position, _representation, _properties), hp(_max_hp), max_hp(_max_hp), toughness(_toughness), strength(_strength), exp(0), character_level(1)
{
}

void Character::say(const char * message)
{
  output->addMessage(message);
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
  level++;
  toughness *= LEVELUP_TOUGHNESS_MULTIPLIER;
  strength  *= LEVELUP_STRENGTH_MULTIPLIER;
  max_hp    *= LEVELUP_HP_MULTIPLIER;
  if (LEVELUP_HEAL) { hp = max_hp; }
}

uint32_t Character::nextLevelExperience(void)
{
  return 100 * pow(EXP_LEVEL_EXPONENT, level);
}

void Character::gainExperience(Character * other)
{
  uint16_t d_exp = (other->getToughness() * EXP_KILL_MULTIPLIER);
  uint32_t required = 0;

  do {
    required = nextLevelExperience() - exp;
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
  int16_t dmg = (strength + random(strength)) - (other->getToughness() + random(other->getToughness()));

  if (dmg > 0) {
    other->damage(dmg);
    return true;
  } else {
    return false;
  }
}

bool Character::onInput(uint8_t input, World * w)
{
  return false;
}
