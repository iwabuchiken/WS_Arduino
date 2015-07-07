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

// LEDs
const int LED_1   = 0;
const int LED_2   = 1;
const int LED_3   = 6;
const int LED_4   = 7;
const int LED_5   = 8;

int leds[] = {LED_1, LED_2, LED_3, LED_4, LED_5};
//int[] leds = {LED_1, LED_2, LED_3, LED_4, LED_5};

int led_states[5];

///////////////////////////////////
//
// vars
//
///////////////////////////////////
int anain_1 ;
int anain_2;
int anain_3;

int anains[3];

void setup() {
//  pinMode(LCD_BL,OUTPUT);
  
  ///////////////////////////////////
  //
  // serial
  //
  ///////////////////////////////////
  Serial.begin(9600);
  
  ///////////////////////////////////
  //
  // LCD
  //
  ///////////////////////////////////
  lcd.begin(16, 2);//16x2桁
  lcd.clear();
  
  // splash
  splash("Light Source!", 500, 3);
//  splash();
  
  ///////////////////////////////////
  //
  // LEDs
  //
  ///////////////////////////////////
//  pinMode(LED_1, OUTPUT);
//  pinMode(LED_2, OUTPUT);
//  pinMode(LED_3, OUTPUT);
//  pinMode(LED_4, OUTPUT);
//  pinMode(LED_5, OUTPUT);

//  digitalWrite(LED_1, LOW);
//  digitalWrite(LED_2, LOW);
//  digitalWrite(LED_3, LOW);
//  digitalWrite(LED_4, LOW);
//  digitalWrite(LED_5, LOW);

}//void setup()

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

//  anains[0] = anain_1;
//  anains[1] = anain_2;
//  anains[2] = anain_3;
  
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
  
  ///////////////////////////////////
  //
  // LEDs
  //
  ///////////////////////////////////
//  onoff_LEDs();
//  digitalWrite(LED_1, HIGH);
//  digitalWrite(LED_2, HIGH);
//  digitalWrite(LED_3, HIGH);
//  digitalWrite(LED_4, HIGH);
//  digitalWrite(LED_5, HIGH);
  
//  digitalWrite(LED_1, LOW);
//  digitalWrite(LED_2, LOW);
//  digitalWrite(LED_3, LOW);
//  digitalWrite(LED_4, LOW);
//  digitalWrite(LED_5, LOW);
//  
  delay(500);
//  delay(500);
  
}

void onoff_LEDs() {

  ///////////////////////////////////
  //
  // build: states array
  //
  ///////////////////////////////////
  int anain_Max = get_Max(anains);

  Serial.println(anain_Max);
  
  for(int i = 1; i < 5; i ++) {
    
    digitalWrite(leds[i], HIGH);
    
  }
  
//  digitalWrite(LED_1, HIGH);
//  digitalWrite(LED_2, HIGH);
//  digitalWrite(LED_3, HIGH);
//  digitalWrite(LED_4, HIGH);
//  digitalWrite(LED_5, HIGH);

}//void onoff_LEDs()

int get_Max(int values[]) {
//  int get_Max(values) {
  
  int tmp = values[0];
  
  int len = sizeof(values) / sizeof(int);
//  int len = values.length;
//  int len = values.length();
  
  for(int i = 1; i < len; i ++) {
    
    if (tmp < values[i]) {

      tmp = values[i];

    }//if (tmp < values[i])
    
  }
  
  return tmp;
  
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



