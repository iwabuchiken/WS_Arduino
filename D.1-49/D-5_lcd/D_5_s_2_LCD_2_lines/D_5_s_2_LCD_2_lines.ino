/*
 * D_5_s_2_LCD_2_lines.ino
 *
 * REF: http://happy-arduino.blogspot.jp/2012/02/lcd_22.html
 * 
 * 1. LCD, 2 lines
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
//LiquidCrystal lcd(7,8,9,10,11,12,13);
//int LCD_BL=6;

void setup()
{
//  pinMode(LCD_BL,OUTPUT);
  lcd.begin(16, 2);//16x2桁 
  
}

void loop()
{
//  digitalWrite(LCD_BL,HIGH);
  
//  delay(100);
  delay(50);
  lcd.clear();
  
  lcd.print("LCD TestPrint");
  lcd.setCursor(0,1);
  lcd.print("2nd TestPrint");
  
}
