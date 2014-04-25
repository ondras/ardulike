#ifndef __ARDULIKE_SCREEN_CHARS_H__
#define __ARDULIKE_SCREEN_CHARS_H__

byte sword[8] = {
  B00000,
  B00001,
  B00010,
  B11100,
  B01100,
  B10100,
  B00000,
  B00000,
};

byte shield[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

byte bar_high[8] = {
  B11111,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte bar_medium[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte bar_low[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
};

byte bar_empty[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
};

#endif
