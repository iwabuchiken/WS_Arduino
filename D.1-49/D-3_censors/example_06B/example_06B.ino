// example_06B.ino
//	p.55 Banzi 
/*
 * 1. analog write
 */

const int LED		= 9;	// pin number

int val		= 0;	// value from the sensor

const int delay_Time	= 10;	// delay time in millsec

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED, OUTPUT);	// LED => output

}

void loop() {

	val = analogRead(0);
	
	analogWrite(LED, val/4);
	
	delay(delay_Time);
	
}//void loop()
