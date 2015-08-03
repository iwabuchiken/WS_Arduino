  /*
    * D_13__s_1__timerone.ino\D_13__s_1__timerone.ino.ino
    *
    * 1. TimeOne
    */

//REF http://playground.arduino.cc/Code/Timer1
#include "TimerOne.h"

  ///////////////////////////////////
  //
  // vars
  //
  ///////////////////////////////////
  const char version[] = "13/1 #2";
  
  unsigned long timenow; 

  void setup() {
    
    ///////////////////////////////////
    //
    // serial
    //
    ///////////////////////////////////
    Serial.begin(9600);
  
    Serial.println(version);
    
    Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
    Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
    
  }//void setup()
  
  void loop() {
    
//    delay(200);
//    
//    timenow = Timer1.read();
//    
//    Serial.println("timenow => ");
//    Serial.println(timenow);
    
  }//void loop()
  
  void callback()
  {
    digitalWrite(10, digitalRead(10) ^ 1);
    
    timenow = Timer1.read();
    
    Serial.println("timenow => ");
    Serial.println(timenow);

  }



