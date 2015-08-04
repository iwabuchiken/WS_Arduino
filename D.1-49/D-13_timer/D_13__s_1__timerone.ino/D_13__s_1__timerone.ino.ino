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
  const char version[] = "13/1 #4-2";
  
  unsigned long timenow; 

  const int BUTTON_1 = 7;  // button --> pin 7
  
  int buttonState;
  
  void setup() {
    
    ///////////////////////////////////
  //
  // pin modes
  //
  ///////////////////////////////////
    pinMode(BUTTON_1, INPUT);
    
    ///////////////////////////////////
    //
    // serial
    //
    ///////////////////////////////////
    Serial.begin(9600);
  
    Serial.println(version);
    
    //debug
    Serial.println(millis());
    
    Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
    
  //debug
    Serial.println(millis());
    Serial.println("initialized");
    
    Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
    
    
    
  }//void setup()
  
  void loop() {
    
    buttonState = digitalRead(BUTTON_1);  // read input
    
    if (buttonState == HIGH) {

      Serial.println("Pushed!");

      timenow = Timer1.read();
      
      Serial.println("time is => ");
      Serial.println(timenow);

//      Timer1.restart();
      
//      TCNT1 = 0;  // reset the counter ?
      
      // restart timer
//      Timer1.start();
      Timer1.initialize();
      
      
      timenow = Timer1.read();
      
      Serial.println("initialize(): time is => ");
      Serial.println(timenow);
      
      delay(200);   // wait for 200 ms

    }//if (buttonState)
    
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











