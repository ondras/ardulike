#include "player.h"
#include "npc.h"

Player::Player(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness):
Character(_level, _position, _hp, _toughness, CHAR_PLAYER, ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT)
{
  display_depth = DISPLAY_DEPTH_PLAYER;
}

bool Player::onInput(uint8_t input, World * w)
{
  Npc * npc;
  uint8_t new_position = position;

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
    attack(npc);
    return true;
  }

  return false;
}
