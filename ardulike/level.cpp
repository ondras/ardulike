#include <avr/pgmspace.h>
#include <avr/io.h>
#include <string.h>
#include "level.h"

prog_char lvl_0[] PROGMEM = "A..............BC..............D";
prog_char lvl_1[] PROGMEM = "A..............BC..............D";

PGM_P levels[] = {
  lvl_0,
  lvl_1,
};

Level::Level(void)
{
}

uint8_t Level::getLevelSize(uint8_t level)
{
  return strlen_P(levels[level]);
}

char * Level::getLevelView(uint8_t level, uint8_t view_index)
{
  strncpy_P(level_view, &(levels[level][view_index * SCREEN_COLS]), SCREEN_COLS);
  level_view[SCREEN_COLS] = '\0';
  return level_view;
}

uint8_t Level::getLevelCount(void)
{
  return sizeof(levels) / sizeof(levels[0]);
}
