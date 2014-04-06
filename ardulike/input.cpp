#include "input.h"

#define RIGHT_10BIT_ADC  0
#define UP_10BIT_ADC     98
#define DOWN_10BIT_ADC   254
#define LEFT_10BIT_ADC   407
#define SELECT_10BIT_ADC 636

#define INPUT_PIN            A0
#define INPUT_TRESHOLD       10
#define INPUT_TOGGLE         30
#define INPUT_HOLD          300

uint32_t Input::last_at = 0;
uint8_t  Input::last    = 0;

uint8_t Input::read(void)
{
  uint16_t input = analogRead(INPUT_PIN);
  if (abs(input - UP_10BIT_ADC) <= INPUT_TRESHOLD) {
    return BUTTON_UP;
  }
  else if (abs(input - DOWN_10BIT_ADC) <= INPUT_TRESHOLD) {
    return BUTTON_DOWN;
  }
  else if (abs(input - RIGHT_10BIT_ADC) <= INPUT_TRESHOLD) {
    return BUTTON_RIGHT;
  }
  else if (abs(input - LEFT_10BIT_ADC) <= INPUT_TRESHOLD) {
    return BUTTON_LEFT;
  }
  else if (abs(input - SELECT_10BIT_ADC) <= INPUT_TRESHOLD) {
    return BUTTON_SELECT;
  } else {
    return BUTTON_NONE;
  }
}

uint8_t Input::get(void)
{
  uint8_t  button = read();
  uint32_t now    = millis();
  uint32_t dt     = now - last_at;

  if (dt > INPUT_TOGGLE && button != last) {
    last_at = now;
    last    = button;
    return button;
  } else
  if (dt > INPUT_HOLD && button == last) {
    last_at = now;
    last    = button;
    return button;
  } else {
    return BUTTON_NONE;
  }
}
