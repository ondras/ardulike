#include "utils.h"
#include <Wire.h>
#include <math.h>

int16_t nrand(int8_t mu, int8_t sigma)
{
  float theta = 2.0 * M_PI * (random() / (float) RANDOM_MAX);
  float rho   = sqrt(-2.0 * log(1.0 - (random() / (float) RANDOM_MAX)));
  return (int16_t) (mu + (sigma * rho) * cos(theta));
}
