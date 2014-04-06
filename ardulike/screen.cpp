#include "screen.h"

Screen::Screen(LiquidCrystal _lcd):
  lcd(_lcd)
{
  lcd.begin(SCREEN_COLS, SCREEN_ROWS);
}

void Screen::render(Level lvl, Character player, Character ogre, Stairs stairs_up, Stairs stairs_down)
{
  uint8_t screen = player.getPosition() / SCREEN_COLS;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(player.getLevel());
  lcd.print("H:");
  lcd.print(player.getHp());
  lcd.setCursor(0, 1);
  lcd.print(lvl.getLevelView(player.getLevel(), screen));

  if (player.getLevel() == stairs_up.getLevel() && stairs_up.getPosition() >= screen * SCREEN_COLS && stairs_up.getPosition() < (screen + 1) * SCREEN_COLS) {
    lcd.setCursor(stairs_up.getPosition() % SCREEN_COLS, 1);
    lcd.print(stairs_up.getRepresentation());
  }
  if (player.getLevel() == stairs_down.getLevel() && stairs_down.getPosition() >= screen * SCREEN_COLS && stairs_down.getPosition() < (screen + 1) * SCREEN_COLS) {
    lcd.setCursor(stairs_down.getPosition() % SCREEN_COLS, 1);
    lcd.print(stairs_down.getRepresentation());
  }
  if (player.getLevel() == ogre.getLevel() && ogre.getPosition() >= screen * SCREEN_COLS && ogre.getPosition() < (screen + 1) * SCREEN_COLS) {
    lcd.setCursor(ogre.getPosition() % SCREEN_COLS, 1);
    lcd.print(ogre.getRepresentation());
  }

  lcd.setCursor(player.getPosition() % SCREEN_COLS, 1);
  lcd.print(player.getRepresentation());
}

