// example_05__Lamp_Modified.ino
//	p.50 Banzi 
/*
 * 1. keep pushing the button
 * 	=> brightness changes
 */

const int LED		= 9;	// pin number
const int BUTTON	= 7;	// pin number

int val				= 0;	// status of the input pin

int old_val				= 0;	// previous value of 'val'

int state			= 0;	// status of LED

const int delay_Time = 100;  // in millseconds

int brightness		= 128;	// default value

unsigned long startTime	= 0;	// start time when the button was pushed

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

		startTime = millis();
		
		delay(delay_Time);
		
	}//if (val == HIGH)

	///////////////////////////////////
	//
	// check: button is being pushed
	//
	///////////////////////////////////
	if ((val == HIGH) && (old_val == HIGH)) {

		// pushed => > 500 ms?
		if (state == 1 && (millis() - startTime) > 500) {

			brightness += 10;
//      brightness ++;
			
			delay(delay_Time);
			
			// Reset brightness
			if (brightness > 255) {

				brightness = 0;

			}//if (brightness > 255)

		}//if (state == 1 && (millis() - startTime) > 500)

	}//if ((val == HIGH) && (old_val == HIGH))
	
	// store 'val'
	old_val = val;
	
	// if the state of the LED is on, i.e. 1 => HIGH
	//	otherwise => LOW
	if (state == 1) {

		analogWrite(LED, brightness);

	} else {//if (state == 1)
		
		analogWrite(LED, LOW);
		
	}//if (state == 1)
	
}//void loop()
