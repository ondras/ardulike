#include "stairs.h"
#include "world.h"
#include "player.h"

Stairs::Stairs(uint8_t _level, uint8_t _position, uint8_t _target_level, uint8_t _target_position):
Terrain(_level, _position), target_level(_target_level), target_position(_target_position)
{
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
