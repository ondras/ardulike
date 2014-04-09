#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdarg.h>
#include <stdio.h>
#include "world.h"

World::World(void):
  entity_count(0), size(128)
{
}

void World::addEntity(Entity * entity)
{
  entities[entity_count++] = entity;
}

void World::addEntities(int count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addEntity(va_arg(arguments, Entity *));
  }

  va_end(arguments);
}

uint8_t World::getSize(uint8_t level)
{
  return size;
}

char * World::getView(uint8_t level, uint8_t view_index)
{
  Entity * e;

  uint8_t from = view_index * SCREEN_COLS;
  uint8_t to   = (view_index + 1) * SCREEN_COLS;
  uint8_t pos, lvl;

  memset(view, '.', SCREEN_COLS);

  for (uint8_t depth = 0; depth < SCREEN_DEPTH; depth++) {
    for (uint8_t i = 0; i < entity_count; i++) {
      e = entities[i];

      if (e->getDisplayDepth() != depth) { continue; }

      lvl   = e->getLevel();
      pos   = e->getPosition();

      if (lvl != level || pos < from || pos >= to) { continue; }

      view[pos % SCREEN_COLS] = e->getRepresentation();
    }
  }

  view[SCREEN_COLS] = '\0';
  return view;
}

uint8_t World::getEntityCount(void)
{
  return entity_count;
}
