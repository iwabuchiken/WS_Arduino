  /*
  * D_12_irremote_s_5.ino
  *
  *  REF: http://www.embedded-property.net/?p=986
  *
  * [Notices]
  *   1. Monitor speed  => 57600 bps
  *   2. Serial rate    => 57600
  *   
  * 
  */

///////////////////////////////////
//
// defines
//
///////////////////////////////////
#define READ_PIN 7
#define LOW_STATE 0
#define HIGH_STATE 1

const char title[] = "\n12/6 #2";

int count = 0;

///////////////////////////////////
//
// vars
//
///////////////////////////////////
unsigned long now = micros();
unsigned long lastStateChangedMicros = micros();
int state = HIGH_STATE;

//const int SERIAL_RATE  = 115200;
const int SERIAL_RATE  = 57600;

///////////////////////////////////
//
// pins
//
///////////////////////////////////
const int  LED_OUT = 8;
int     MODE  = 0;
const int   CHATTERING_TIME = 500;

unsigned long  prev;
unsigned long cur;

//////////////////////////////////////////////////////////////////////
//
// methods
//
//////////////////////////////////////////////////////////////////////
//the Interrupt routine  (2)
void interruptsw() {
  
  prev = micros();
  cur = prev;
  
  while(digitalRead(2) == 0) {
    
  }
  
  cur = micros();
  
  Serial.println("L is");
  Serial.println(cur - prev);
  
//  ///////////////////////////////////
//  //
//  // chattering
//  //
//  ///////////////////////////////////
//  delay(CHATTERING_TIME); // wait for 100 ms
////  delay(200); // wait for 100 ms
////  delay(100); // wait for 100 ms
//  
//  if (digitalRead(2) == 1) {
//
//    Serial.println("clicked!");
//
//  } else {//if (digitalRead(2) == 1)
//    
//    return;
//    
//  }//if (digitalRead(2) == 1)
  
//  ///////////////////////////////////
//  //
//  // count
//  //
//  ///////////////////////////////////
//  count += 1;
//  
//  Serial.println(count);
  
  if(MODE){
   MODE = 0;
  }else{
   MODE = 1;
  }
  
}

void waitLow() {
    while (digitalRead(READ_PIN)==LOW) {
      ;
    }
  }
   
int waitHigh() {
  unsigned long start = micros();
  while (digitalRead(READ_PIN)==HIGH) {
    if (micros() - start > 5000000) {
      return 1;
    }
  }
  return 0;
}
  
void setup()
{
//  Serial.begin(9600);
//  Serial.begin(57600);
  Serial.begin(115200);
//  Serial.begin(SERIAL_RATE);

  ///////////////////////////////////
  //
  // pins
  //
  ///////////////////////////////////
//  pinMode(7, INPUT);
//  pinMode(READ_PIN,INPUT);
  
  pinMode(LED_OUT, OUTPUT);       
  attachInterrupt(0, interruptsw, FALLING );  // (1) => pin 2
//  attachInterrupt(0, interruptsw, RISING );  // (1) => pin 2
  
  ///////////////////////////////////
  //
  // splash
  //
  ///////////////////////////////////
  Serial.println(title);
  
}
 

void loop() {

  if(MODE){
    digitalWrite(LED_OUT, LOW);
    delay(100);               
    
        digitalWrite(LED_OUT, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);               // wait for a second
        digitalWrite(LED_OUT, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);               // wait for a second
    }else{
      digitalWrite(LED_OUT, HIGH); 
    }
  
//  if (state == LOW_STATE) {
//    waitLow();
//  } else {
//    int ret = waitHigh();
//    if (ret == 1) {
//      Serial.print("\n");
//      return;
//    }
//  }
//   
//  now = micros();
//  
//  Serial.print((now - lastStateChangedMicros) / 10, DEC);
//  
//  ///////////////////////////////////
//  //
//  // show high or low
//  //
//  ///////////////////////////////////
////  if (state == HIGH_STATE) {
////    
////    Serial.print(" HIGH");
////    
////  } else {
////    
////    Serial.print(" LOW");
////    
////  }
//
//  
//  Serial.print(",");
//  
//  lastStateChangedMicros = now;
//  if (state == HIGH_STATE) {
//    state = LOW_STATE;
//  } else {
//    state = HIGH_STATE;
//  }
  
}//void loop()





