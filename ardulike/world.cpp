#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "world.h"
#include "player.h"
#include "entity.h"
#include "npc.h"

World::World(void):
  terrain_count(0), npc_count(0), turns(0), changed(true)
{
}

void World::addTerrains(uint8_t count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addTerrain(va_arg(arguments, Terrain *));
  }

  va_end(arguments);
}

void World::addTerrain(Terrain * _terrain)
{
  terrain[terrain_count++] = _terrain;
}

void World::addPlayer(Player * _player)
{
 _player->setOutput(output);
 player = _player;
}

void World::addNpc(Npc * _npc)
{
  _npc->setOutput(output);
  npcs[npc_count++] = _npc;
}

void World::addNpcs(uint8_t count, ...)
{
  va_list arguments;
  va_start(arguments, count);

  for (uint8_t i = 0; i < count; i++) {
    addNpc(va_arg(arguments, Npc *));
  }

  va_end(arguments);
}

char * World::getView(void)
{
  Terrain * t;
  Npc     * n;

  uint8_t from  = (player->getPosition() / SCREEN_COLS) * SCREEN_COLS;
  uint8_t to    = (player->getPosition() / SCREEN_COLS + 1) * SCREEN_COLS;
  uint8_t level = player->getLevel();

  memset(view, CHAR_FLOOR, SCREEN_COLS);

  for (uint8_t i = 0; i < terrain_count; i++) {
    t = terrain[i];

    if (t->inView(level, from, to)) {
      view[t->getPosition() % SCREEN_COLS] = t->getRepresentation();
    }
  }

  for (uint8_t i = 0; i < npc_count; i++) {
    n = npcs[i];

    if (n->inView(level, from, to)) {
      view[n->getPosition() % SCREEN_COLS] = n->getRepresentation();
    }
  }

  view[player->getPosition() % SCREEN_COLS] = player->getRepresentation();
  view[SCREEN_COLS] = '\0';

  return view;
}

void World::onInput(uint8_t input)
{
  changed = false;

  if (input == BUTTON_NONE) { return; }
  if (input != BUTTON_SELECT) { turns++; }

  output->clear();

  changed |= player->onInput(input, this);

  for (uint8_t i = 0; i < npc_count; i++) {
    changed |= npcs[i]->onInput(input, this);
  }

  for (uint8_t i = 0; i < terrain_count; i++) {
    changed |= terrain[i]->onInput(input, this);
  }
}

bool World::isPassable(uint8_t level, uint8_t position)
{
  if (position < 0 || position >= getSize()) {
    return false;
  } else {
    for (uint8_t i = 0; i < npc_count; i++) {
      if (npcs[i]->blocksAt(level, position)) { return false; }
    }
    for (uint8_t i = 0; i < terrain_count; i++) {
      if (terrain[i]->blocksAt(level, position)) { return false; }
    }
    return true;
  }
}

Npc * World::getNpc(uint8_t level, uint8_t position)
{
  for (uint8_t i = 0; i < npc_count; i++) {
    if (npcs[i]->at(level, position) && npcs[i]->isAlive()) { return npcs[i]; }
  }
  return NULL;
}
