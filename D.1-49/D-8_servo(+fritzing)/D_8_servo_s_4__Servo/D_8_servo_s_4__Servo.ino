/*
  * D_8_servo_s_4__Servo.h.ino
  *
  * 1. servo
  */

#include <Servo.h>

///////////////////////////////////
//
// vars
//
///////////////////////////////////
Servo servo1;

char version[] = "8/4 #1";

const char splash_Messsage[] = "Servo!!";

const int SERVO_OUT_PIN    = 6;

const int DELAY_TIME_MS    = 0;
int deg=0;

void setup() {
  
  ///////////////////////////////////
  //
  // serial
  //
  ///////////////////////////////////
  Serial.begin(9600);

  Serial.println(version);
  
  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  servo1.attach(SERVO_OUT_PIN);
  
  // initial moves
  servo1.write(90);
  
  delay(500);
  
  servo1.write(0);
  
  delay(100);
  
}//void setup()

void loop() {
  
  ///////////////////////////////////
//
// servo
//
///////////////////////////////////
  deg=0;  // 初期の回転角
//  int deg=0;  // 初期の回転角
  
  // 0-180度回転
//  for (deg=0; deg<180; deg++) {

    deg = 180;
    
    servo1.write(deg);  // deg度まで回転
    
//    delay(DELAY_TIME_MS);          // 20ms待機
//    delay(20);          // 20ms待機
    
//  }
  
  // 180-0度回転
  for (deg=180; deg>0; deg--) {
    
    servo1.write(deg);  // deg度まで回転
    
    delay(20);          // 20ms待機
    
  }
  
}//void loop()



