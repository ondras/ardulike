#include "character.h"

Character::Character(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, char _representation, uint8_t _properties):
Entity(_level, _position, _representation, _properties), hp(_hp), toughness(_toughness), exp(0), character_level(1)
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

void Character::die(void)
{
  hp             = 0;
  properties    &= ~(ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT);
  representation = '%';
}

void Character::gainExperience(Character * other)
{
}

bool Character::attack(Character * other)
{
  int dmg = (toughness + random(toughness)) - (other->getToughness() + random(other->getToughness()));
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
