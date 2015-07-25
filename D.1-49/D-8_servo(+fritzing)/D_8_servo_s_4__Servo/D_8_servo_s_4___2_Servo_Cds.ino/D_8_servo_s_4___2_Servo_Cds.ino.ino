/*
  * D_8_servo_s_4___2_Servo_Cds.ino
  *
  * 1. servo + 2 Cds
  */

#include <Servo.h>

///////////////////////////////////
//
// vars
//
///////////////////////////////////
Servo servo1;

char version[] = "8/4 #2-2 t1";

const int SERVO_OUT_PIN    = 6;

const int DELAY_TIME_MS    = 0;

int deg=0;

const int ANALOG_0 = 0;
const int ANALOG_1 = 1;

int val_0;
int val_1;

String s0("A0 => ");
String s1("A1 => ");

// states
int      state;
const int CENTER  = 0;
const int RIGHT = -1;
const int LEFT  = 1;

const int DEG_CENTER  = 90;
const int DEG_RIGHT = 0;
const int DEG_LEFT  = 180;

int diff;
int larger;

const int THRESH    = 100;

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
  
//  ///////////////////////////////////
////
//// state
////
/////////////////////////////////////
//  state = CENTER;
//  
//  // move servo
//  move_Servo(state);
  
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

void move_Servo(int state) {
  
  //debug
  String s("move servo => ");
  Serial.println(s + state);
  
  switch(state) {
  
  case CENTER:
  
    servo1.write(DEG_CENTER); break;
  
  case RIGHT:
  
    servo1.write(DEG_RIGHT);  break;
  
  case LEFT:
  
    servo1.write(DEG_LEFT); break;

  default:
    
    //debug
    String s2("unknown state => ");
  Serial.println(s2 + state);

  }
  
}

void update_Servo(int val_0, int val_1) {

  // get: larger
  larger = larger_value(val_0, val_1);
  
}

///////////////////////////////////
//
// @param
//  val_0 => right cds value
//  val_1 => left cds value
//
// @return
//  RIGHT or LEFT
///////////////////////////////////
int larger_value(int val_0, int val_1) {

  return (val_0 > val_1) ? RIGHT : LEFT;
  
}


