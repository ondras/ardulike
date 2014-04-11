#include "player.h"
Player::Player(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _hp, uint8_t _toughness):
Character(_representation, _display_depth, _level, _position, _hp, _toughness)
{
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
