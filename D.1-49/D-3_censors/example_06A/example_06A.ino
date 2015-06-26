// example_06A.ino
//	p.55 Banzi 
/*
 * 1. use a sensor
 */

//import java.lang.Math;

const int LED		= 13;	// pin number

int val		= 0;	// value from the sensor

const int delay_Time	= 10;	// delay time in millsec

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED, OUTPUT);	// LED => output

}

void loop() {

	val = analogRead(0);
	
	digitalWrite(13, HIGH);
	
	delay(val * 2);
	//REF pow https://www.arduino.cc/en/Reference/Pow
//	delay(pow(val,2));
//	delay(Math.pow(val,2));
//	delay(val);
	
	digitalWrite(13, LOW);
	
	delay(val * 2);
//	delay(val);
	
}//void loop()
