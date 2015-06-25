// example_03A.ino
//	p.38 Banzi 
/*
 * push button
 * 	=> LED keeps on
 */

const int LED		= 13;	// pin number
const int BUTTON	= 7;	// pin number

int val				= 0;	// status of the input pin

int state			= 0;	// status of LED

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED, OUTPUT);	// LED => output
	pinMode(BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

	val = digitalRead(BUTTON);	// read the input; store it in the val
	
	// if HIGH => change the state
	if (val == HIGH) {

		state = 1 - state;

	}//if (val == HIGH)
	
	// if the state of the LED is on, i.e. 1 => HIGH
	//	otherwise => LOW
	if (state == 1) {

		digitalWrite(LED, HIGH);

	} else {//if (state == 1)
		
		digitalWrite(LED, LOW);
		
	}//if (state == 1)
	
}
