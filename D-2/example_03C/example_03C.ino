// example_03C.ino
//	p.41 Banzi 
/*
 * 1. push button
 * 	=> LED keeps on
 * 2. Bouncing	=> countermeasure done
 */

const int LED		= 13;	// pin number
const int BUTTON	= 7;	// pin number

int val				= 0;	// status of the input pin

int old_val				= 0;	// previous value of 'val'

int state			= 0;	// status of LED

const int delay_Time = 100;  // in millseconds

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED, OUTPUT);	// LED => output
	pinMode(BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

	val = digitalRead(BUTTON);	// read the input; store it in the val
	
	// if HIGH => change the state
	if ((val == HIGH) & (old_val == LOW)) {

		state = 1 - state;

		delay(delay_Time);
//		delay(10);
		
	}//if (val == HIGH)
	
	// store 'val'
	old_val = val;
	
	// if the state of the LED is on, i.e. 1 => HIGH
	//	otherwise => LOW
	if (state == 1) {

		digitalWrite(LED, HIGH);

	} else {//if (state == 1)
		
		digitalWrite(LED, LOW);
		
	}//if (state == 1)
	
}//void loop()
