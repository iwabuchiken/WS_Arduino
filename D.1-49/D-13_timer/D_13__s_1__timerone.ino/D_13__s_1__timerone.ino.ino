//#include <Prescaler.h>

  /*
    * D_13__s_1__timerone.ino\D_13__s_1__timerone.ino.ino
    *
    * 1. TimeOne
    */

//REF http://playground.arduino.cc/Code/Timer1
#include "TimerOne.h"

//#include <Prescaler.h>

//#include "..\\..\\ir_controller-master\\types.h"
//#include "/WS_Arduino/D.1-49/D-13_timer/ir_controller-master/types.h"
//#include "../../ir_controller-master/types.h"
//#include "../ir_controller-master/types.h"
#include "types.h"

  ///////////////////////////////////
  //
  // vars
  //
  ///////////////////////////////////
  const char version[] = "13/3 #1";
  
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
  
//========================================================
//Config
//========================================================

#define SERIAL_BPS             (57600)   /* Serial bps */
#define IR_IN                  (8)       /* Input      */
#define IR_OUT                 (13)      /* Output     */

#define TIMEOUT_RECV_NOSIGNAL  (50000)
#define TIMEOUT_RECV           (5000000)
#define TIMEOUT_SEND           (2000000)

//========================================================
//Define
//========================================================
#define STATE_NONE             (-1)
#define STATE_OK               (0)
#define STATE_TIMEOUT          (1)
#define STATE_OVERFLOW         (2)
#define DATA_SIZE              (800)

//========================================================
// Program
//========================================================
u2 data[DATA_SIZE];

void sendSignal(){
  u1 x;
  s1 state = STATE_NONE;
  u2 time = 0;
  u4 tmp = 0;
  u4 index = 0;
  u4 count = 0;
  u4 us = 0;
  
  us = micros();
  
  while(state == STATE_NONE){
    if(Serial.available() == 0){
      if((micros() - us) > TIMEOUT_SEND){
        state = STATE_TIMEOUT;
        break;
      }
    } else {
      x = Serial.read();
      if(x>='0' && x<='9'){
        /* 数字を受信した場合 */
        tmp *= 10;
        tmp += x - '0';
      } else {
        /* 数字以外を受信した場合 */
        if((tmp == 0) && (index == 0)){
          /* 最初の一文字目は読み飛ばす */
        } else {
          data[index] = (u2)tmp;
          if(tmp == 0){
            state = STATE_OK;
            break;
          } else if(index >= DATA_SIZE){
            state = STATE_OVERFLOW;
            break;
          }
          index++;
        }
        tmp = 0;
      }
    }
  }

  if(state == STATE_OK){
    for(count = 0; count < index; count++){
      time = data[count];
      us = micros();
      do {
        digitalWrite(IR_OUT, !(count&1));
        delayMicroseconds(8);
        digitalWrite(IR_OUT, 0);
        delayMicroseconds(7);
      }while(s4(us + time - micros()) > 0);
    }
    Serial.println("OK");
  } else {
    Serial.print("NG:");
    Serial.println(state);
  }
}//void sendSignal()

void recvSignal(){
  
  u1 pre_value = HIGH;
  u1 now_value = HIGH;
  u1 wait_flag = TRUE;
  s1 state = STATE_NONE;
  u4 pre_us = micros();
  u4 now_us = 0;
  u4 index = 0;
  u4 i = 0;
  
  while(state == STATE_NONE){
    now_value = digitalRead(IR_IN);
    if(pre_value != now_value){
      now_us = micros();
      if(!wait_flag){
        data[index++] = now_us - pre_us;
      }
      wait_flag = FALSE;
      pre_value = now_value;
      pre_us = now_us;
    }
    
    if(wait_flag){
        if((micros() - pre_us) > TIMEOUT_RECV){
          state = STATE_TIMEOUT;
          break;
        }
      } else {
        if((micros() - pre_us) > TIMEOUT_RECV_NOSIGNAL){
          state = STATE_OK;
          break;
        }
      }
  }
  
  if(state == STATE_OK){
    Serial.print("s,");
    for(i = 0; i<index; i++){
      Serial.print(data[i]);
      Serial.print(',');
    }
    Serial.println("0,");
  } else {
    Serial.println("NG");
  }
}//void recvSignal()
  
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
    
    ///////////////////////////////////
    //
    // prescaler
    //
    ///////////////////////////////////
    //REF http://arms22.blog91.fc2.com/blog-entry-309.html
    //Prescaler.set(clock_div_8);
//    Prescaler.set(clock_div_1);

    ///////////////////////////////////
  //
  // timer
  //
  ///////////////////////////////////
    Timer1.initialize(500000);         // initialize timer1, and set a 1/2 second period
    
  //debug
    Serial.println(millis());
    Serial.println("initialized");
    
    Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
    Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
    
    ///////////////////////////////////
	//
	// pins
	//
	///////////////////////////////////
    pinMode(IR_IN, INPUT);
    pinMode(IR_OUT, OUTPUT);

    ///////////////////////////////////
	//
	// send signal
	//
	///////////////////////////////////
    sendSignal();
    
//    ///////////////////////////////////
//  //
//  // prescaler
//  //
//  ///////////////////////////////////
//    //REF http://arms22.blog91.fc2.com/blog-entry-309.html
//    Prescaler.set(clock_div_1);
    
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
      
      TCNT1 = 0;  // reset the counter ?
      
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
    
    // count: increment
    count ++;
    
    Serial.println(s_count + count);

  }


