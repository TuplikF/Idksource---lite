#include <Adafruit_LiquidCrystal.h>

int Hi = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);

  lcd_1.print("welcome to Idksource---lite");
  delay(1000); // Wait for 1000 millisecond(s)
}

void loop()
{
  if (1 == "hi" ) {
    lcd_1.print("hello world");
  } else {
  }
  delay(10); // Delay a little bit to improve simulation performance
}
