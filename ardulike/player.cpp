#include "player.h"
#include "npc.h"

Player::Player(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness, uint8_t _strength):
Character(_level, _position, _hp, _toughness, _strength, CHAR_PLAYER, ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT)
{
  display_depth = DISPLAY_DEPTH_PLAYER;
}

void Player::levelUp(void)
{
  Character::levelUp();
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

  npc = w->findNpc(level, new_position);
  if (npc && npc->isAlive() && npc->isHostile()) {
    if (attack(npc)) {
      if (!npc->isAlive()) {
        say(PSTR("You kill the creature."));
        say(PSTR("You gain %d XP."), experienceGained(npc));
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
