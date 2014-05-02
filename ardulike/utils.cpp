#include <Arduino.h>
#include "utils.h"

uint8_t nrand(uint8_t max)
{
  uint16_t acc    = 0;
  for (uint8_t i = 0; i < 32; i++) { acc += random(max); }
  return acc / trials;
}
