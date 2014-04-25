#ifndef __ARDULIKE_SCREEN_H__
#define __ARDULIKE_SCREEN_H__

#include <LiquidCrystal.h>

#include "constants.h"
#include "player.h"
#include "world.h"
#include "stairs.h"
#include "msgqueue.h"

class Screen {
private:
  LiquidCrystal lcd;
  uint8_t bar(uint32_t val, uint32_t max);
public:
  Screen();
  void render(World * w, MsgQueue * q);
};

#endif
