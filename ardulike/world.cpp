#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdarg.h>
#include <stdio.h>
#include "world.h"

World::World(void):
  actor_count(0), size(128)
{
}

void World::addActor(Entity * actor)
{
  actors[actor_count++] = actor;
}

void World::addActors(int count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addActor(va_arg(arguments, Entity *));
  }

  va_end(arguments);
}

uint8_t World::getSize(uint8_t level)
{
  return size;
}

char * World::getView(uint8_t level, uint8_t view_index)
{
  Entity * actor;

  uint8_t from = view_index * SCREEN_COLS;
  uint8_t to   = (view_index + 1) * SCREEN_COLS;
  uint8_t pos, lvl;

  memset(view, '.', SCREEN_COLS);

  for (uint8_t depth = 0; depth < SCREEN_DEPTH; depth++) {
    for (uint8_t i = 0; i < actor_count; i++) {
      actor = actors[i];

      if (actor->getDisplayDepth() != depth) { continue; }

      lvl   = actor->getLevel();
      pos   = actor->getPosition();

      if (lvl != level || pos < from || pos >= to) { continue; }

      view[pos % SCREEN_COLS] = actor->getRepresentation();
    }
  }

  view[SCREEN_COLS] = '\0';
  return view;
}

uint8_t World::getActorCount(void)
{
  return actor_count;
}
