#include "stairs.h"

Stairs::Stairs(uint8_t _level, uint8_t _position, uint8_t _target_level, uint8_t _target_position):
Entity((_target_level <= _level) ? CHAR_STAIRS_UP : CHAR_STAIRS_DOWN, _level, _position), target_level(_target_level), target_position(_target_position)
{
  setDisplayDepth(DISPLAY_DEPTH_TERRAIN);
}

uint8_t Stairs::getTargetLevel(void)
{
  return target_level;
}

uint8_t Stairs::getTargetPosition(void)
{
  return target_position;
}

/*
 * FIXME:
 * 1) this implicitly prevents NPCs from going down the stairs
 */
bool Stairs::onInput(uint8_t input, World * w)
{
  Player * player = w->getPlayer();

  if (player->getPosition() != position || player->getLevel() != level) { return false; }

  if ( ((target_level > level) && input == BUTTON_DOWN) || ((target_level <= level) && input == BUTTON_UP)) {
    player->setPosition(target_position);
    player->setLevel(target_level);
  }

  return true;
}
