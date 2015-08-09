  /*
  * D_12_irremote_s_1.ino
  *
  * [Notices]
  * 	1. Monitor speed	=> 57600 bps
  * 	2. Serial rate		=> 57600
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

const char title[] = "\n12/4 #2-1";

///////////////////////////////////
//
// vars
//
///////////////////////////////////
unsigned long now = micros();
unsigned long lastStateChangedMicros = micros();
int state = HIGH_STATE;

//////////////////////////////////////////////////////////////////////
//
// methods
//
//////////////////////////////////////////////////////////////////////
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
  Serial.begin(57600);

  ///////////////////////////////////
  //
  // pins
  //
  ///////////////////////////////////
//  pinMode(7, INPUT);
  pinMode(READ_PIN,INPUT);
  
  ///////////////////////////////////
  //
  // splash
  //
  ///////////////////////////////////
  Serial.println(title);
  
}
 

void loop() {

  if (state == LOW_STATE) {
    waitLow();
  } else {
    int ret = waitHigh();
    if (ret == 1) {
      Serial.print("\n");
      return;
    }
  }
   
  now = micros();
  Serial.print((now - lastStateChangedMicros) / 10, DEC);
  Serial.print(",");
  lastStateChangedMicros = now;
  if (state == HIGH_STATE) {
    state = LOW_STATE;
  } else {
    state = HIGH_STATE;
  }
  
}//void loop()











