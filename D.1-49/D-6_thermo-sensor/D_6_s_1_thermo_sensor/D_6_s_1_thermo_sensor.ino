/*
  * D_5_s_2_LCD_2_lines.ino
  *
  * REF: http://happy-arduino.blogspot.jp/2012/02/lcd_26.html
  * 
  * 1. LCD, analog values
  */

  #include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

///////////////////////////////////
//
// vars
//
///////////////////////////////////
float anain_F;

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

  // convert
  anain_F = modTemp(anain);

  String st_anain_F(anain_F);
  
  delay(500);
  
  lcd.setCursor(0, 1);
  
  lcd.print(st_anain_F + " Celcius");
//  lcd.print(st_anain_F);  //=> w
//  lcd.print(anain_F);
//  lcd.print(anain);
  
}

//アナログ入力値を摂氏度℃に変換
float modTemp(int analog_val){
  
  float v  = 5;     // 基準電圧値( V )
  float tempC = ((v * analog_val) / 1024) * 100;  // 摂氏に換算
  return tempC;

}






