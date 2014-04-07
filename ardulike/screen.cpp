#include "screen.h"

Screen::Screen(LiquidCrystal _lcd):
  lcd(_lcd)
{
  lcd.begin(SCREEN_COLS, SCREEN_ROWS);
}

void Screen::render(Character player, Level lvl)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(player.getLevel());
  lcd.print("H:");
  lcd.print(player.getHp());
  lcd.setCursor(0, 1);

  lcd.print(lvl.getLevelView(player.getLevel(), player.getPosition() / SCREEN_COLS));
}

