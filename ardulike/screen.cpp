#include "screen.h"

Screen::Screen(LiquidCrystal _lcd):
  lcd(_lcd)
{
  lcd.begin(SCREEN_COLS, SCREEN_ROWS);
}

void Screen::render(World * w)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(w->getPlayer()->getLevel());
  lcd.print("H:");
  lcd.print(w->getPlayer()->getHp());
  lcd.setCursor(0, 1);

  lcd.print(w.getView(w->getPlayer()->getLevel(), w->getPlayer()->getPosition() / SCREEN_COLS));
}

