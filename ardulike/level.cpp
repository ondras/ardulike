#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdarg.h>
#include <stdio.h>
#include "level.h"

Level::Level(void):
  actor_count(0), size(128)
{
}

void Level::addActor(Entity * actor)
{
  actors[actor_count++] = actor;
}

void Level::addActors(int count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addActor(va_arg(arguments, Entity *));
  }

  va_end(arguments);
}

uint8_t Level::getLevelSize(uint8_t level)
{
  return size;
}

char * Level::getLevelView(uint8_t level, uint8_t view_index)
{
  Entity * actor;

  uint8_t from = view_index * SCREEN_COLS;
  uint8_t to   = (view_index + 1) * SCREEN_COLS;
  uint8_t pos, lvl;
  char    rep;

  memset(level_view, '.', SCREEN_COLS);

  for (uint8_t i = 0; i < actor_count; i++) {
    actor = actors[i];
    lvl   = actor->getLevel();
    pos   = actor->getPosition();
    rep   = actor->getRepresentation();

    if (lvl == level && pos >= from && pos < to) {
      level_view[pos % SCREEN_COLS] = rep;
    }
  }

  level_view[SCREEN_COLS] = '\0';
  return level_view;
}

uint8_t Level::getActorCount(void)
{
  return actor_count;
}
