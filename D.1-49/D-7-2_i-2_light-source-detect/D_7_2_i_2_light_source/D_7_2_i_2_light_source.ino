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

const int LED_1  = 0;
const int LED_2  = 1;
const int LED_3  = 6;
const int LED_4  = 7;
const int LED_5  = 8;

const int leds[] = {LED_1, LED_2, LED_3, LED_4, LED_5};

const int numOf_LEDs = 5;

///////////////////////////////////
//
// vars
//
///////////////////////////////////
int anain_1 ;
int anain_2;
int anain_3;

char version[] = "D-7-2 s-2 s4";

void setup()
{
//  pinMode(LCD_BL,OUTPUT);
  
  lcd.begin(16, 2);//16x2桁
  lcd.clear();

  ///////////////////////////////////
  //
  // LEDs
  //
  ///////////////////////////////////
  for(int i = 0; i < numOf_LEDs; i ++) {
    
    pinMode(leds[i], OUTPUT); // LED => output
    
  }
  
//  pinMode(LED_1, OUTPUT); // LED => output
//  pinMode(LED_2, OUTPUT); // LED => output
//  pinMode(LED_3, OUTPUT); // LED => output
//  pinMode(LED_4, OUTPUT); // LED => output
//  pinMode(LED_5, OUTPUT); // LED => output
  
  // init -> off
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_5, LOW);
  
  // splash
  splash("Light Source!", 500, 3);
//  splash();
  
}

void loop()
{
// digitalWrite(LCD_BL,HIGH);
//  int anain_1 ;
  lcd.setCursor(0, 0);
  lcd.print(version);
//  lcd.print("Detecting...");
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
  
//  anain_1 = analogRead(0) ; // CDSを接続したアナログ０番ピンを読み取る

  lcd.setCursor(0, 1);
  lcd.print(a_1 + " " + a_2 + " " + a_3);
//  lcd.print(anain_1 + " " + anain_2 + " " + anain_3);
  
  delay(500);
//  delay(500);

  //test
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, HIGH);
  digitalWrite(LED_5, HIGH);
  
  delay(100);
  
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_5, LOW);
  
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


