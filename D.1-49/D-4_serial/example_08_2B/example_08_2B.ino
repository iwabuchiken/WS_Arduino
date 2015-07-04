// example_08B.ino
//  p.56 68 
/*
 * 1. lamp
 */

const int SENSOR    = 0;  // sensor pin
const int R_LED     = 9;  // 
const int G_LED     = 10; // 
const int B_LED     = 11; // 
const int BUTTON    = 12; // 

int   val   = 0;  // value from the sensor

int   btn   = LOW;
int   old_btn = LOW;

int   state = 0;
char  buffer[7];
int   pointer = 0;
byte  inByte  = 0;

byte  r = 0;
byte  g = 0;
byte  b = 0;

char  message[] = "Arduino received message => ";
//char  message[] = "buffer = ";

const int delay_Time  = 100;  // delay time in millsec

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {

  ///////////////////////////////////
  //
  // read data
  //
  ///////////////////////////////////
  if (Serial.available() > 0) {

//    inByte = Serial.read();
    
//    while (pointer < 4) {
      while (pointer < 3) {
//      while (pointer < 6) {
      
      buffer[pointer] = Serial.read();
      
      pointer ++;
      
    }//while (pointer < 6)

  //REF http://stackoverflow.com/questions/17158890/transform-char-array-into-string answered Jun 18 '13 at 2:28
    String str(buffer);
    
    Serial.println(message + str);  //=> w
//    Serial.println(buffer);  //=> w
    
    // reset pointer
    pointer = 0;

  }//if (Serial.available() > 0)
  
  delay(delay_Time);
  
}//void loop()




