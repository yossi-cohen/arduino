/*
  LCD Display with I2C Interface Demo
  lcd-i2c-demo.ino
  Use NewLiquidCrystal Library
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>

// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x27;

LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

void setup()
{
  // Set display type as 16 char, 2 rows
  lcd.begin(16,2);
  
  // Print on first row
  lcd.setCursor(0,0);
  lcd.print("hello");
  
  // Wait 1 second
  delay(1000);
  
  // Print on second row
  lcd.setCursor(0,1);
  lcd.print("How are you?");
  
  // Wait 2 seconds
  delay(2000);
  
  // Clear the display
  lcd.clear();
}


void loop()
{
  // scroll
  lcd.setCursor(0,0);
  lcd.print("My name is");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Yonatan Cohen");
  delay(1000);

  // scroll 13 positions (string length + display length) to the right
  for (int i = 0; i < 13; i++)
  {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit
    delay(250);
  }
  
  // clear screen 
  lcd.clear();

  // flash backlight
  lcd.setCursor(0,0);
  lcd.print("bye");
  lcd.setCursor(0,1);
  lcd.print("bye");

  delay(1000);
  
  // flash backlight 4 times
  for(int i = 0; i< 4; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }

  lcd.clear();
  
  // turn backlight on
  lcd.backlight();
  delay(1000);
}
