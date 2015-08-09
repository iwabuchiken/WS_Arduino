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
  const char version[] = "13/5 #1";
  
  unsigned long timenow; 

  const int BUTTON_1 = 7;  // button --> pin 7
  
  int buttonState  = 0;
//  int buttonState;
  
  // counter for timer
  int count = 0;

  // gauge the time
  unsigned long time_Cur;
  
  unsigned long time_Prev;
  
  ///////////////////////////////////
//
// strings
//
///////////////////////////////////
  String s_count("count => ");
  String s_ellapse("ellapse => ");
  
  // output pin
  const int PIN_OUT = 8;
  
  void setup() {
    
    ///////////////////////////////////
  //
  // pin modes
  //
  ///////////////////////////////////
    pinMode(BUTTON_1, INPUT);
    pinMode(PIN_OUT, OUTPUT);
    
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
//    Timer1.initialize(5000000);         // initialize timer1, and set a 1/2 second period
    Timer1.initialize(10000);         // 10 millis
//    Timer1.initialize(100000);         // 
    
  //debug
    Serial.println(millis());
    Serial.println("initialized");
    
    Timer1.pwm(9, 341, 26);    // duty: 33%
//    Timer1.pwm(9, 512, 26);                // setup pwm on pin 9, 50% duty cycle
//    Timer1.pwm(9, 512, 100);                // setup pwm on pin 9, 50% duty cycle
//    Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
    
    ///////////////////////////////////
  //
  // gauge time
  //
  ///////////////////////////////////
    time_Cur = micros();
    
  }//void setup()
  
  void loop() {
   
    //REF http://nyantacos.at.webry.info/201411/article_1.html
    digitalWrite(PIN_OUT, HIGH);
    delayMicroseconds(3);
//    delayMicroseconds(4);
//    delayMicroseconds(9);
//    delayMicroseconds(8);
    digitalWrite(PIN_OUT, LOW);
    delayMicroseconds(8);
//    delayMicroseconds(17);
//    delayMicroseconds(7);
    
    
  }//void loop()
  
  void callback()
  {
    
    Serial.println("callback()");
    
//    buttonState = digitalRead(10);

    if(count % 100 == 0) {
    
        if (buttonState == 1) {
 
          Serial.println("buttonState => 1");
          
        Timer1.disablePwm(9);
        
      } else {//if (buttonState == 1)
        
        Serial.println("buttonState => 0");
        
        Timer1.pwm(9, 341, 26);    // duty: 33%
        
      }//if (buttonState == 1)
  
        // update buttonState
        buttonState ^= 1;
        
    }
    
    ///////////////////////////////////
  //
  // gauge time
  //
  ///////////////////////////////////
  time_Prev = time_Cur;
  
  time_Cur = micros();
  
  Serial.println(s_ellapse + (time_Cur - time_Prev));
    
    
//    digitalWrite(10, digitalRead(10) ^ 1);
//    
//    timenow = Timer1.read();
//    
//    Serial.println("timenow => ");
//    Serial.println(timenow);
//    
    // count: increment
    count ++;
    
//    Serial.println(s_count + count);

  }







