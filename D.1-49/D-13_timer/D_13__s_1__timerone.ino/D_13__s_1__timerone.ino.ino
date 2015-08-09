//#include <Prescaler.h>

  /*
  * D_13__s_1__timerone.ino\D_13__s_1__timerone.ino.ino
  *
  * 1. TimeOne
  */

//REF http://playground.arduino.cc/Code/Timer1
#include "TimerOne.h"

#include "types.h"

///////////////////////////////////
//
// vars
//
///////////////////////////////////
const char version[] = "13/5 #3-2";

// pin states
int state_PIN_7    = 0;
int state_PIN_BUTTON_1  = 0;
int state_PIN_OUT_1  = 0;

///////////////////////////////////
//
// pwm state
//
///////////////////////////////////
int state_PWM  = 0; // default --> 0 (pwm --> off)

int state_OUT_1 = 0;  // default --> 1

//  int buttonState;

///////////////////////////////////
//
// others
//
///////////////////////////////////
// counter for timer
int count = 0;

// gauge the time
unsigned long time_Cur;

unsigned long time_Prev;

///////////////////////////////////
//
// pwm
//
///////////////////////////////////
const int PWM_DUTY    = 341;

///////////////////////////////////
//
// strings
//
///////////////////////////////////
String s_count("count => ");
String s_ellapse("ellapse => ");

///////////////////////////////////
//
// pins
//
///////////////////////////////////
const int PIN_PWM  = 9;
const int PIN_BUTTON_1  = 8;

const int PIN_OUT_1  = 7;

//////////////////////////////////////////////////////////////////////
//
// methods
//
//////////////////////////////////////////////////////////////////////
void setup() {
  
  ///////////////////////////////////
  //
  // pin modes
  //
  ///////////////////////////////////
  pinMode(PIN_BUTTON_1, INPUT);
  pinMode(PIN_PWM, OUTPUT);
  
  ///////////////////////////////////
  //
  // serial
  //
  ///////////////////////////////////
  Serial.begin(9600);
  
  Serial.println(version);
  
  ///////////////////////////////////
  //
  // timer
  //
  ///////////////////////////////////
//    Timer1.initialize(5000000);        // initialize timer1, and set a 1/2 second period
  Timer1.initialize(100000);         // 100 millis
//    Timer1.initialize(10000);        // 10 millis
//    Timer1.initialize(100000);         // 
  
  //debug
  Serial.println(millis());
  Serial.println("initialized");
  
//    Timer1.pwm(9, 341, 26);   // duty: 33%
//    Timer1.pwm(9, 512, 26);               // setup pwm on pin 9, 50% duty cycle
//    Timer1.pwm(9, 512, 100);                // setup pwm on pin 9, 50% duty cycle
//    Timer1.pwm(9, 512);               // setup pwm on pin 9, 50% duty cycle
//    Timer1.attachInterrupt(callback); // attaches callback() as a timer overflow interrupt
  
  //REF http://playground.arduino.cc/Code/Timer1 [attachInterrupt(function, period)]
//    Timer1.attachInterrupt(callback, 100000); // every 100 millis
//  Timer1.attachInterrupt(callback, 500000); // every 100 millis
  
    //test
//    Timer1.pwm(PIN_PWM, PWM_DUTY, 26);    // duty: 33%
    
  ///////////////////////////////////
  //
  // gauge time
  //
  ///////////////////////////////////
  time_Cur = micros();
  
}//void setup()
  
void loop() {
   
  while(digitalRead(PIN_BUTTON_1) == 1) {
    
//    Timer1.disablePwm(PIN_PWM);
//    
    Serial.println("disabled");
    
    digitalWrite(PIN_PWM, HIGH);
    
    delayMicroseconds(100);
//    delayMicroseconds(9);
    
    digitalWrite(PIN_PWM, LOW);

    delayMicroseconds(1000 - 100);
//    delayMicroseconds(17);
    
  }
  
//    state_PIN_BUTTON_1 = digitalRead(PIN_BUTTON_1);
  
//  while(digitalRead(PIN_BUTTON_1) == 1) {
//    
//    Serial.println("clicked");
//    
//    if (state_PWM != 1) {
//
//      state_PWM = 1;
//      
//      Serial.println("state_PWM => now 1");
//      
//      // start pwm
////      Timer1.pwm(PIN_PWM, PWM_DUTY, 26);    // duty: 33%
////      Timer1.pwm(PIN_PWM, 341, 26);   // duty: 33%
////        Timer1.pwm(9, 341, 26);   // duty: 33%
//
//    }//if (state_PWM != 1)
//    
//  }
//  
//  ///////////////////////////////////
//  //
//  // if button is not pushed
//  //    --> stop pwm
//  //
//  ///////////////////////////////////
//  if (state_PWM != 0) {
//
//    Serial.println("state_PWM => not 0");
//    
//    state_PWM = 0;
////    state_PWM = 1;
//    
//    Serial.println("state_PWM => now 0");
//    
////    Timer1.disablePwm(PIN_PWM);
//    
//  }//if (state_PWM != 0)
  
}//void loop()
  
void callback() {
  
  Serial.println("callback()");
  
//    buttonState = digitalRead(10);

  if(count % 100 == 0) {
  
  if (state_OUT_1 != 1) {

    state_OUT_1 = 1;
    
    digitalWrite(PIN_OUT_1, HIGH);

  }//if (state_OUT_1 != 1)
  
  } else {//if(count % 100 == 0)
    
  if (state_OUT_1 != 0) {
    
    state_OUT_1 = 0;
    
    digitalWrite(PIN_OUT_1, LOW);
    
  }//if (state_OUT_1 != 1)
    
  }//if(count % 100 == 0)

  ///////////////////////////////////
  //
  // gauge time
  //
  ///////////////////////////////////
  time_Prev = time_Cur;
  
  time_Cur = micros();
  
  Serial.println(s_ellapse + (time_Cur - time_Prev));
  
  // count: increment
  count ++;
  
}




