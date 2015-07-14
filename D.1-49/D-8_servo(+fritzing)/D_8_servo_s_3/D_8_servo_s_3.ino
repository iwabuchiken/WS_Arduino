/*
  * D_8_servo_s_3.ino
  *
  * 1. servo
  */

#include <LiquidCrystal.h>

//#include <Servo.h>


LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);

///////////////////////////////////
//
// vars
//
///////////////////////////////////
//Servo servo1;

char version[] = "8/3 #2-2";

const char splash_Messsage[] = "Pulsing...";

const int SERVO_OUT_PIN    = 2;
//const int SERVO_OUT_PIN    = 3;

int deg=0;

//REF http://marupeke296.com/EL_Ard_No9_ServoMotor.html
const int deg0msec = 600; // msec.
const int deg180msec = 2350; // msec.
int microSec = deg0msec;

void setup() {
  
//  ///////////////////////////////////
//  //
//  // serial
//  //
//  ///////////////////////////////////
//  Serial.begin(9600);
//  
  lcd.begin(16, 2);//16x2桁
  lcd.clear();

  // splash
  splash(splash_Messsage, 500, 3);
//  splash("Light Source!", 500, 3);

  lcd.setCursor(0, 0);
  lcd.print(version);

  ///////////////////////////////////
  //
  // pins
  //
  ///////////////////////////////////
  pinMode( SERVO_OUT_PIN, OUTPUT );
  
  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  
//  servo1.attach( SERVO_OUT_PIN );
//  
//  // initial moves
//  servo1.write(90);
//  
//  delay(500);
//  
//  servo1.write(0);
//  
//  delay(100);
  
//  servo1.attach(9);
  
}//void setup()

void loop() {
// digitalWrite(LCD_BL,HIGH);
//  int anain_1 ;
//  lcd.setCursor(0, 0);
//  lcd.print(version);
  
  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  // degree: 0
  deg = 0;
  
//  microSec = deg0msec + deg / 180.0 * ( deg180msec - deg0msec );
  
  microSec = 1000;
//  microSec = 700;
//  microSec = 500;
  
  digitalWrite( SERVO_OUT_PIN, HIGH );
    delayMicroseconds( microSec ); // ON
    
    digitalWrite( SERVO_OUT_PIN, LOW );
    delayMicroseconds( 10000 ); // OFF
    delayMicroseconds( 10000 - microSec ); // OFF
  
    // wait
    delay(2000);
    
    // degree: 180
    deg = 180;
    
//    microSec = deg0msec + deg / 180.0 * ( deg180msec - deg0msec );
    microSec = 2000;
//    microSec = 1400;
//    microSec = 1000;
    
    digitalWrite( SERVO_OUT_PIN, HIGH );
    delayMicroseconds( microSec ); // ON
    
    digitalWrite( SERVO_OUT_PIN, LOW );
    delayMicroseconds( 10000 ); // OFF
    delayMicroseconds( 10000 - microSec ); // OFF
    
 // wait
    delay(2000);
    
  //analogWrite( SERVO_OUT_PIN, 20 );
//  analogWrite( SERVO_OUT_PIN, 100 );
  
//  deg=0;  // 初期の回転角
////  int deg=0;  // 初期の回転角
//  
//  // 0-180度回転
//  for (deg=0; deg<180; deg++) {
//    
//    servo1.write(deg);  // deg度まで回転
//    
//    delay(20);          // 20ms待機
//    
//  }
//  
//  // 180-0度回転
//  for (deg=180; deg>0; deg--) {
//    
//    servo1.write(deg);  // deg度まで回転
//    
//    delay(20);          // 20ms待機
//    
//  }
  
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
  
}//void splash(String message, int dur, int iter)

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

