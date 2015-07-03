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

char  message[] = "buffer = ";

const int delay_Time  = 100;  // delay time in millsec

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
  
}

void loop() {

  val = analogRead(SENSOR);

  Serial.println(val);

  ///////////////////////////////////
  //
  // read data
  //
  ///////////////////////////////////
  if (Serial.available() > 0) {

    inByte = Serial.read();
    
    while (pointer < 6) {
      
      buffer[pointer] = Serial.read();
      
      pointer ++;
      
    }//while (pointer < 6)

    //debug
//    Serial.println(String.format("%s", buffer));  //=> "error: expected primary-expression before '.' token"
    Serial.println(buffer);  //=> w
//    Serial.println(message + buffer);
//    Serial.println("buffer = " + buffer);
    
//    String msg;
//    msg = String.format(Locale.JAPAN, "[%s : %d] buffer => %s", Thread
//        .currentThread().getStackTrace()[1].getFileName(), Thread
//        .currentThread().getStackTrace()[1].getLineNumber(), buffer);
//
//    System.out.println(msg);

  }//if (Serial.available() > 0)
  
  delay(delay_Time);
  
}//void loop()




