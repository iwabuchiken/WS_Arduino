// example_04.ino
//	p.49 Banzi 
/*
 * 1. LED
 * 		=> PWM
 */

const int LED		= 9;	// pin number

int i				= 0;	// loop

const int delay_Time	= 10;	// delay time in millsec

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED, OUTPUT);	// LED => output

}

void loop() {
	
	//for(i = 0; i < 255; i = i * 2) {
  for(i = 0; i < 255; i ++) {
		
		analogWrite(LED, i);
		
		delay(delay_Time);
		
	}
	
//	for(i = 255; i > 0; i --) {
//		
//		analogWrite(LED, i);
//		
//		delay(delay_Time);
//		
//	}
	
}//void loop()
