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

const int LED_1 = 0;
const int LED_2 = 1;
const int LED_3 = 6;
const int LED_4 = 7;
const int LED_5 = 8;

const int leds[] = {LED_1, LED_2, LED_3, LED_4, LED_5};

const int numOf_LEDs = 5;

// LED state
int led_states[] = {0, 0, 0, 0, 0};
//int led_states[] = {LOW, LOW, LOW, LOW, LOW};

int anains[3];

///////////////////////////////////
//
// vars
//
///////////////////////////////////
int anain_1 ;
int anain_2;
int anain_3;

char version[] = "7-2/2 s7p1t8p1t2";

void setup() {
  
  ///////////////////////////////////
  //
  // serial
  //
  ///////////////////////////////////
  Serial.begin(9600);
  
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
  
  // init -> off
  for(int i = 0; i < numOf_LEDs; i ++) {
      
    digitalWrite(leds[i], led_states[i]); // initial --> LOW
//    digitalWrite(leds[i], LOW); // initial --> LOW
      
  }

  // splash
  splash("Light Source!", 500, 3);
  
}//void setup()

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
// build: anains
//
///////////////////////////////////
  anains[0] = anain_1;
  anains[1] = anain_2;
  anains[2] = anain_3;
  
  ///////////////////////////////////
  //
  // conv: int to string
  //
  ///////////////////////////////////
  String a_1(anain_1);
  String a_2(anain_2);
  String a_3(anain_3);
  
  lcd.setCursor(0, 1);
  lcd.print(a_1 + " " + a_2 + " " + a_3);
  
  delay(500);
//  delay(500);

  //test
  for(int i = 0; i < numOf_LEDs; i ++) {
      
      digitalWrite(leds[i], HIGH); // initial --> LOW
        
  }

  delay(200);
//  delay(100);

  // set => off pattern
  led_states[1] = 1;
  led_states[3] = 1;
  
  //test
  int tmp = get_Max_Index(anains, 3);
//  
//  Serial.println("max index =>");
//  
//  Serial.println(tmp);
  
  // turning off
  for(int i = 0; i < numOf_LEDs; i ++) {
      
      digitalWrite(leds[i], led_states[i]); // initial --> LOW
//      digitalWrite(leds[i], LOW); // initial --> LOW
        
  }
  
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

int get_Max_Index(int values[], int len) {
//  int get_Max(values) {
  
  int tmp = 0;
  
  for(int i = 1; i < len; i ++) {
    
    if (values[tmp] < values[i]) {
      
      tmp = i;
      
    }//if (tmp < values[i])
    
  }
  
  return tmp;
  
}



