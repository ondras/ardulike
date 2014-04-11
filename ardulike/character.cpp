#include "character.h"

uint8_t Character::getToughness(void)
{
  return toughness;
}

bool Character::isAlive(void)
{
  return alive;
}

void Character::damage(uint8_t dmg)
{
  if (alive) {
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
  hp    = 0;
  alive = 0;
  representation = '%';
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

Character::Character(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness):
Entity(_representation, _display_depth, _level, _position), hp(_hp), toughness(_toughness), alive(1)
{
}

bool Character::onInput(uint8_t input, World * w)
{
  Character * player = w->getPlayer();
  if (this == player) {
   if (input == BUTTON_LEFT) { player->setPosition(player->getPosition() - 1); return true; }
   if (input == BUTTON_RIGHT) { player->setPosition(player->getPosition() + 1); return true; }
  }
  return false;
}
