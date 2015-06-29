// example_07.ino
//	p.56 Banzi 
/*
 * 1. analog write
 */

const int SENSOR		= 0;	// sensor pin

int val		= 0;	// value from the sensor

const int delay_Time	= 100;	// delay time in millsec

void setup() {
  // put your setup code here, to run once:

	Serial.begin(9600);

}

void loop() {

	val = analogRead(SENSOR);

	Serial.println(val);
	
	delay(delay_Time);
	
}//void loop()
