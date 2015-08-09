  /*
  * D_12_irremote_s_1.ino
  *
  * 
  */

const char title[] = "12/4 #1-2";

///////////////////////////////////
//
// vars
//
///////////////////////////////////
int last        = -1;
unsigned long last_time = 0;

int state_obtained = 0;

int val;

unsigned long now;

//////////////////////////////////////////////////////////////////////
//
// methods
//
//////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);

  ///////////////////////////////////
  //
  // pins
  //
  ///////////////////////////////////
  pinMode(7, INPUT);
  
  ///////////////////////////////////
  //
  // get: time
  //
  ///////////////////////////////////
  last_time = micros();
  
  ///////////////////////////////////
  //
  // splash
  //
  ///////////////////////////////////
  Serial.println(title);
  
}
 
void loop() {

//  int val;
  
  while(1) {
    
    val = !digitalRead(7);

//    // state
//    if (state_obtained == 0) {
//
//      state_obtained = 1;
//      
//      Serial.print("val = ");
//      Serial.println(val);

//  }//if (state_obtained == 0)
    
    if(val != last) break;
//    if(val != last) {
//      
//      state_obtained = 0;
//      
//      break;
//    }
    
  }//while(1)
  
  now = micros();
//  unsigned long now = micros();
  
  Serial.print("last = ");
  Serial.print(last);
//  Serial.print("last_time = ");
//  Serial.print(last_time);
  Serial.print(", dur = ");
  Serial.println(now - last_time);
  
  ///////////////////////////////////
  //
  // update
  //
  ///////////////////////////////////
  last = val;
  
  last_time = now;
  
}//void loop()









