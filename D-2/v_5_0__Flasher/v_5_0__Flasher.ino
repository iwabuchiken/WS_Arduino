// v_5_0__Flasher.ino

/*
 * 1. LED flasher
 * 		1) 4 LEDs
 */

const int LED_1		= 9;	// pin number
const int LED_2		= 10;	// pin number
const int LED_3		= 11;	// pin number
const int LED_4		= 12;	// pin number

int LED_current		= LED_1;	// the one to turn on; inital --> LED_1

int LED_index		= 1;	// the index of the target LED

const int BUTTON	= 13;	// pin number

int val				= 0;	// status of the input pin

int old_val				= 0;	// previous value of 'val'

int state			= 0;	// status of LED

const int delay_Time = 100;  // in millseconds

void setup() {
  // put your setup code here, to run once:
	
	pinMode(LED_1, OUTPUT);	// LED => output
	pinMode(LED_2, OUTPUT);	// LED => output
	pinMode(LED_3, OUTPUT);	// LED => output
	pinMode(LED_4, OUTPUT);	// LED => output
	
	pinMode(BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

	val = digitalRead(BUTTON);	// read the input; store it in the val
	
	// if HIGH => change the state
	if ((val == HIGH) & (old_val == LOW)) {

		state = 1 - state;

		delay(delay_Time);
		
	}//if (val == HIGH)


	///////////////////////////////////
	//
	// update: old_val
	//
	///////////////////////////////////
	old_val = val;

	///////////////////////////////////
	//
	// LEDs: on/off
	//
	///////////////////////////////////
	// if the state of the LED is on, i.e. 1 => HIGH
	//	otherwise => LOW
	if (state == 1) {

		// turn off the current one
		digitalWrite(LED_current, LOW);
		
		// delay
		delay(delay_Time);
		
		// increment the index
		LED_index ++;
		
		// more than 4 ?
		if (LED_index > 4) {

			LED_index = 1;

		}//if (LED_index > 4)
		
		// set the next LED index
		switch(LED_index) {
		
		case 1: LED_current = LED_1; break;
		case 2: LED_current = LED_2; break;
		case 3: LED_current = LED_3; break;
		case 4: LED_current = LED_4; break;
			
		}

		// turn on the next one
		digitalWrite(LED_current, HIGH);
		
		// delay
		delay(500);
		
//		analogWrite(LED, brightness);

	} else {//if (state == 1)
		
		// all the LEDs --> off
		digitalWrite(LED_1, LOW);
		digitalWrite(LED_2, LOW);
		digitalWrite(LED_3, LOW);
		digitalWrite(LED_4, LOW);
		
	}//if (state == 1)
	
}//void loop()
