#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdarg.h>
#include <stdio.h>

#include "world.h"
#include "player.h"
#include "entity.h"

World::World(void):
  entity_count(0), size(128), changed(true)
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

uint8_t World::getSize(void)
{
  return size;
}

char * World::getView(void)
{
  Entity * e;

  uint8_t from  = (player->getPosition() / SCREEN_COLS) * SCREEN_COLS;
  uint8_t to    = (player->getPosition() / SCREEN_COLS + 1) * SCREEN_COLS;
  uint8_t level = player->getLevel();
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

void World::addPlayer(Player * _player)
{
  player = _player;
}

Player * World::getPlayer(void)
{
  return player;
}

void World::onInput(uint8_t input)
{
  changed = false;

  if (input == BUTTON_NONE) { return; }

  for (uint8_t i = 0; i < entity_count; i++) {
    changed |= entities[i]->onInput(input, this);
  }
}

bool World::hasChanged(void)
{
  return changed;
}
