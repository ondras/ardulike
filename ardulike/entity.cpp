#include "entity.h"

Entity::Entity(char _representation, uint8_t _display_depth, uint8_t _level, uint8_t _position):
  representation(_representation), display_depth(_display_depth), position(_position), level(_level)
{
}

char Entity::getRepresentation(void)
{
  return representation;
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
