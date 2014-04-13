#include "player.h"
Player::Player(uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness):
Character(_level, _position, _hp, _toughness, CHAR_PLAYER, ENTITY_ALIVE | ENTITY_BLOCKS_MOVEMENT)
{
  display_depth = DISPLAY_DEPTH_PLAYER;
}

bool Player::onInput(uint8_t input, World * w)
{
   if (input == BUTTON_LEFT) {
     position == 0 ? position = w->getSize() - 1 : position--;
     return true;
   }
   if (input == BUTTON_RIGHT) {
     position == w->getSize() - 1 ? position = 0 : position++;
     return true;
   }
   return false;
}
