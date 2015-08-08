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
  const char version[] = "13/4 #2";
  
  unsigned long timenow; 

  const int BUTTON_1 = 7;  // button --> pin 7
  
  int buttonState;
  
  // counter for timer
  int count = 0;
  
  ///////////////////////////////////
//
// strings
//
///////////////////////////////////
  String s_count("count => ");
  
  void setup() {
    
    ///////////////////////////////////
  //
  // pin modes
  //
  ///////////////////////////////////
    pinMode(BUTTON_1, INPUT);
    pinMode(9, OUTPUT);
    
    ///////////////////////////////////
    //
    // serial
    //
    ///////////////////////////////////
    Serial.begin(9600);
  
    Serial.println(version);
    
    //debug
    Serial.println(millis());
    
    ///////////////////////////////////
  //
  // timer
  //
  ///////////////////////////////////
    Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
    
  //debug
    Serial.println(millis());
    Serial.println("initialized");
    
//    Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
    
  }//void setup()
  
  void loop() {
   
    //REF http://nyantacos.at.webry.info/201411/article_1.html
    digitalWrite(9, HIGH);
    delayMicroseconds(3);
//    delayMicroseconds(4);
//    delayMicroseconds(9);
//    delayMicroseconds(8);
    digitalWrite(9, LOW);
    delayMicroseconds(8);
//    delayMicroseconds(17);
//    delayMicroseconds(7);
    
    
  }//void loop()
  
  void callback()
  {
//    digitalWrite(10, digitalRead(10) ^ 1);
//    
//    timenow = Timer1.read();
//    
//    Serial.println("timenow => ");
//    Serial.println(timenow);
//    
//    // count: increment
//    count ++;
//    
//    Serial.println(s_count + count);

  }








