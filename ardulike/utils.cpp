#include <Arduino.h>
#include "utils.h"

uint8_t nrand(uint8_t max, uint8_t trials)
{
  uint16_t acc    = 0;
  for (uint8_t i = 0; i < trials; i++) { acc += random(max); }
  return acc / trials;
}
