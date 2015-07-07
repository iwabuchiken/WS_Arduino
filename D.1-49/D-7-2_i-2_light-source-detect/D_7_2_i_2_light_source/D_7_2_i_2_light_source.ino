/*
  * D_7_2_i_2_light_source.ino
  *
  * 1. 3 Cds', light source
  */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

const int ANALOG_1  = 0;
const int ANALOG_2  = 1;
const int ANALOG_3  = 2;

///////////////////////////////////
//
// vars
//
///////////////////////////////////
int anain_1 ;
int anain_2;
int anain_3;

void setup()
{
//  pinMode(LCD_BL,OUTPUT);
  
  lcd.begin(16, 2);//16x2桁
  lcd.clear();
  
  // splash
  splash("Light Source!", 500, 3);
//  splash();
  
}

void loop()
{
// digitalWrite(LCD_BL,HIGH);
//  int anain_1 ;
  lcd.setCursor(0, 0);
  lcd.print("Detecting...");
//  lcd.print("Light source detect");

  ///////////////////////////////////
  //
  // read: anains
  //
  ///////////////////////////////////
  anain_1 = analogRead(ANALOG_1) ;  // CDSを接続したアナログ０番ピンを読み取る
  anain_2 = analogRead(ANALOG_2) ;  // CDSを接続したアナログ０番ピンを読み取る
  anain_3 = analogRead(ANALOG_3) ;  // CDSを接続したアナログ０番ピンを読み取る
  
  ///////////////////////////////////
  //
  // conv: int to string
  //
  ///////////////////////////////////
  String a_1(anain_1);
  String a_2(anain_2);
  String a_3(anain_3);
  
//  anain_1 = analogRead(0) ;  // CDSを接続したアナログ０番ピンを読み取る

  lcd.setCursor(0, 1);
  lcd.print(a_1 + " " + a_2 + " " + a_3);
//  lcd.print(anain_1 + " " + anain_2 + " " + anain_3);
  
  c5
  delay(500);
//  delay(500);
  
}

void splash(String message, int dur, int iter) {

  lcd.setCursor(0, 0);
  
  for(int i = 0; i < iter; i++) {
//    for(int i = 0; i < 3; i++) {
    
    lcd.print(message);
//    lcd.print("Light Source");

    delay(dur);
    
    lcd.clear();

    delay(dur);
    
  }
  
}


