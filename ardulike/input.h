#ifndef __ARDULIKE_INPUT_H__
#define __ARDULIKE_INPUT_H__

#include <inttypes.h>

class Input {
  private:
  static uint32_t last_at;
  static uint8_t  last;
  static uint8_t  read(void);
  public:
  static uint8_t  get(void);
};

#endif
