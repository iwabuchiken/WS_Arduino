// D_7_1_s_1_2_Cds.ino
//  
/*
 * 1. 2 Cds'
 */

const int SEN_1    = 0;  // sensor pin
const int SEN_2   = 1;  // sensor pin

int   val_1   = 0;    // value from the sensor
int   val_2   = 0;    // value from the sensor

const int delay_Time  = 100;  // delay time in millsec
//const int delay_Time  = 500;  // delay time in millsec

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {

  val_1 = analogRead(SEN_1);
  val_2 = analogRead(SEN_2);

  String v_1(val_1);
  String v_2(val_2);
  
  Serial.println(v_1 + " " + v_2);

  delay(delay_Time);
  
}//void loop()





