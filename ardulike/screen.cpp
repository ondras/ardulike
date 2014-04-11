#include "screen.h"

Screen::Screen():
  lcd(8, 9, 4, 5, 6, 7)
{
  lcd.begin(SCREEN_COLS, SCREEN_ROWS);
}

void Screen::render(World * w)
{
  if (!w->hasChanged()) { return; }

  Character * player = w->getPlayer();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(player->getLevel());
  lcd.print("H:");
  lcd.print(player->getHp());
  lcd.setCursor(0, 1);

  lcd.print(w->getView());
}
