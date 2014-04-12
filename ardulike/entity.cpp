#include "entity.h"
#include "world.h"

Entity::Entity(uint8_t _level, uint8_t _position, char _representation):
  representation(_representation), position(_position), level(_level), display_depth(DISPLAY_DEPTH_TERRAIN)
{
}

void Entity::setDisplayDepth(uint8_t _display_depth)
{
  display_depth = _display_depth;
}

char Entity::getRepresentation(void)
{
  return representation;
}

void Entity::setRepresentation(char _representation)
{
  representation = _representation;
}

void Entity::setLevel(uint8_t _level)
{
  level = _level;
}

void Entity::setPosition(uint8_t _position)
{
  position = _position;
}

uint8_t Entity::getDisplayDepth(void)
{
  return display_depth;
}

uint8_t Entity::getLevel(void)
{
  return level;
}

uint8_t Entity::getPosition(void)
{
  return position;
}

bool Entity::onInput(uint8_t input, World * w)
{
  return false;
}
