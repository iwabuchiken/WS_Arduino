/*
  * D_5_s_2_LCD_2_lines.ino
  *
  * REF: http://happy-arduino.blogspot.jp/2012/02/lcd_26.html
  * 
  * 1. LCD, analog values
  */

  #include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

//int LCD_BL=6;

void setup()
{
//  pinMode(LCD_BL,OUTPUT);
  
  lcd.begin(16, 2);//16x2桁
  lcd.clear();
  
}

void loop()
{
// digitalWrite(LCD_BL,HIGH);
  int anain ;
  lcd.setCursor(0, 0);
  lcd.print("CDS Input Value");

  anain = analogRead(0) ;  // CDSを接続したアナログ０番ピンを読み取る

  delay(500);
  lcd.setCursor(0, 1);
  lcd.print(anain);
  
}

