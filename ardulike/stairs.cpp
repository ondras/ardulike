#include "stairs.h"

Stairs::Stairs(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position, uint8_t _target_level, uint8_t _target_position):
Entity(_representation, _display_depth, _level, _position), target_level(_target_level), target_position(_target_position)
{
}

uint8_t Stairs::getTargetLevel(void)
{
  return target_level;
}

uint8_t Stairs::getTargetPosition(void)
{
  return target_position;
}

bool Stairs::onInput(uint8_t input, World * w)
{
  Character * player = w->getPlayer();

  if (player->getPosition() != position || player->getLevel() != level) { return false; }

  /* FIXME: it'd be better to have direction attribute here */
  if ( (representation == '>' && input == BUTTON_DOWN) || (representation == '<' && input == BUTTON_UP)) {
    player->setPosition(target_position);
    player->setLevel(target_level);
  }

  return true;
}
