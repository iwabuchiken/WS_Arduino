/*
  * D_8_servo.ino
  *
  * 1. servo
  */

#include <LiquidCrystal.h>

#include <Servo.h>


LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);
//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

///////////////////////////////////
//
// vars
//
///////////////////////////////////
Servo servo1;

char version[] = "8-1 s1";

const char splash_Messsage[] = "Servo!!";

const int SERVO_OUT_PIN    = 6;

void setup() {
  
  ///////////////////////////////////
  //
  // serial
  //
  ///////////////////////////////////
  Serial.begin(9600);
  
  lcd.begin(16, 2);//16x2桁
  lcd.clear();

  // splash
  splash(splash_Messsage, 500, 3);
//  splash("Light Source!", 500, 3);

  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  servo1.attach(SERVO_OUT_PIN);
//  servo1.attach(9);
  
}//void setup()

void loop() {
// digitalWrite(LCD_BL,HIGH);
//  int anain_1 ;
  lcd.setCursor(0, 0);
  lcd.print(version);
  
  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  int deg=0;  // 初期の回転角
  // 0-180度回転
  for (deg=0; deg<180; deg++) {
    servo1.write(deg);  // deg度まで回転
    delay(20);          // 20ms待機
  }
  // 180-0度回転
  for (deg=180; deg>0; deg--) {
    servo1.write(deg);  // deg度まで回転
    delay(20);          // 20ms待機
  }
  
//  lcd.setCursor(0, 1);
//  lcd.print(a_1 + " " + a_2 + " " + a_3);
  
}//void loop()

void splash(String message, int dur, int iter) {

  lcd.setCursor(0, 0);
  
  for(int i = 0; i < iter; i++) {
    
    lcd.print(message);

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


