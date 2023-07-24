#include "StatusView.h"
#include "hardware/Display.h"

#include <Adafruit_GFX.h> // Core graphics library

void StatusView::draw()
{

  // retrieve values from state
  float temp = state.getTemperature();
  float humidity = state.getHumidity();
  float setPoint = state.getSetPoint();
  HVACMode mode = state.getHVACMode();

  // populate text based on state values
  // (you'll need to convert the floats to strings)
  tft.setTextColor(ST77XX_RED, ST77XX_BLACK);

  tft.setTextSize(7);
  BaseView::drawTextRightAligned(0, String(int(temp)) + "F");

  tft.setTextColor(ST77XX_BLUE, ST77XX_BLACK);
  tft.setTextSize(4);
  BaseView::drawTextRightAligned(60, String(int(humidity)) + "%RH");

  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setTextSize(2);
  BaseView::drawTextRightAligned(100, "Set: " + String(setPoint));

  tft.setTextSize(2);

  tft.setTextSize(2);

  tft.setCursor(0, 0);
  tft.print("COOL");

  tft.setCursor(0, (height / 2) - 10);
  tft.print("OFF");

  tft.setCursor(0, height - 20);
  tft.print("HEAT");
}

void StatusView::handleInputEvent(InputEvent event) {
  
}