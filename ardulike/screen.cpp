#include "screen.h"
#include "screen_chars.h"

Screen::Screen():
  lcd(8, 9, 4, 5, 6, 7)
{
  lcd.begin(SCREEN_COLS, SCREEN_ROWS);
  lcd.createChar(0, sword);
  lcd.createChar(1, shield);
  lcd.createChar(2, heart);
  lcd.createChar(3, bar_high);
  lcd.createChar(4, bar_medium);
  lcd.createChar(5, bar_low);
  lcd.createChar(6, bar_empty);
}

uint8_t Screen::bar(uint32_t val, uint32_t max)
{
  uint8_t rows = (4 * val) / max;
  switch(rows) {
    case 0: return 6;
    case 1: return 5;
    case 2: return 4;
    case 3: return 3;
    case 4: return B11111111;
  };
}

void Screen::render(World * w, MsgQueue * q)
{
  if (!w->hasChanged() && !q->viewChanged()) { return; }

  Player * player = w->getPlayer();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.write(byte(2));
  lcd.write(byte(bar(player->getHp(), player->getMaxHp())));
  lcd.print("x");
  lcd.write(byte(bar(player->getExperience(), player->getNextLevelExperience())));
  lcd.write(byte(0));
  lcd.write(byte(bar(player->getStrength(), 255)));
  lcd.write(byte(1));
  lcd.write(byte(bar(player->getToughness(), 255)));

  lcd.print(q->getView());
  lcd.setCursor(0, 1);
  lcd.print(w->getView());
}
