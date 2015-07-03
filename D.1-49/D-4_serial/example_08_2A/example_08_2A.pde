import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.Locale;
import java.util.StringTokenizer;

import processing.net.*;
import processing.serial.*;

int interval  = 5;
//int interval  = 10;
int lastTime;

Serial port;
color c;

String cs = "XYZ";

String buffer = "";  // buffer for strings from Arduino

PFont font;

int cnt_ReadByte = 0;	// coutn the number of bytes read from arduino

final int win_X = 800;
final int win_Y = 500;

final int delay_Time  = 100;  // delay time in millsec

int time_Cur;
int time_Prev = 0;


void setup() {
	// put your setup code here, to run once:

	size(win_X, win_Y);
//  size(640, 480);
	
	frameRate(10);
	
	font = loadFont("ScalaSans-Caps-32.vlw");
//  font = loadFont("HelveticaNeue-Bold-32.vlw");
	
	fill(255);
	
	textFont(font, 32);

	///////////////////////////////////
	//
	// validate
	//
	///////////////////////////////////
	println("getting the serial list...");
	
	int len = Serial.list().length;
	
	if (len < 1) {
	  
	  println("Serial list => less than 1");
	  
	  return;
	  
	}//if (len < 1)
	
	// get: arduino port
	String arduinoPort = Serial.list()[0];
	
	port = new Serial(this, arduinoPort, 9600);  // connect to Arduino
	
	lastTime = 0;

	// random seed
//  randomSeed(millis());

	///////////////////////////////////
	//
	// init: time
	//
	///////////////////////////////////
	time_Cur = millis();
	
	String msg;
	msg = String.format("[%s : %d] setup => done", Thread.currentThread()
//      msg = String.format(Locale.JAPAN, "[%s : %d] setup => done", Thread.currentThread()
	    .getStackTrace()[1].getFileName(), Thread.currentThread()
	    .getStackTrace()[1].getLineNumber());

	System.out.println(msg);
	
}//void setup()

void draw() {

	///////////////////////////////////
	//
	// key inputs
	//
	///////////////////////////////////
	key_Input();
	
	background(100,100,100);
	
	text("Arduino Networked Lamp", 10, 40);
	
	///////////////////////////////////
	//
	// send data
	//
	///////////////////////////////////
	if (port != null) {

		time_Cur = millis();
		
		int diff = time_Cur - time_Prev;
		
		if (diff > 2000) {
			
			port.write(cs);
//		port.write(cs);
			
			String msg;
			msg = String.format(Locale.JAPAN, 
					"[%s : %d] cs written => %s (time_Cur = %d)", 
					Thread
					.currentThread().getStackTrace()[1].getFileName(), Thread
					.currentThread().getStackTrace()[1].getLineNumber(), 
					cs, time_Cur);
			
			System.out.println(msg);

			// update: time_Prev
			time_Prev = time_Cur;
			
		}//if (diff > 2000)
		
	}//if (port != null)
	
	///////////////////////////////////
	//
	// read data: from arduino
	//
	///////////////////////////////////
	if (port != null && port.available() > 0) {

//		int inByte = port.read();	// read 1 byte
//		
//		// validate: newline(LF)?
//		if (inByte != 10) {
//
//			buffer = buffer + char(inByte);
//
//			cnt_ReadByte ++;
//			
////			String msg;
////			msg = String.format(Locale.JAPAN, "[%s : %d] buffer = %s", Thread
////					.currentThread().getStackTrace()[1].getFileName(), Thread
////					.currentThread().getStackTrace()[1].getLineNumber(), buffer);
////
////			System.out.println(msg);
//			
//		}//if (inByte != 10)
//		
//		else {
//			
//			// validate: any data
//			if (buffer.length() > 1) {
//
//				buffer = buffer.substring(0, buffer.length() - 1);
//				
//				// validate: is numeric
//				if (is_Numeric(buffer)) {
//
//					light = int(buffer);
//
//				}//if (is_Numeric(buffer))
//				
////				light = int(buffer);
//
//				String msg;
//				msg = String.format(Locale.JAPAN, 
//						"[%s : %d] buffer = %s (%d bytes)", 
//						Thread
//						.currentThread().getStackTrace()[1].getFileName(),
//						Thread.currentThread().getStackTrace()[1]
//								.getLineNumber(), 
//								
//						buffer, cnt_ReadByte
//						
//				);
//
//				System.out.println(msg);
//				
//				// clear buffer
//				buffer = "";
//				
//				// clear port
//				port.clear();
//
//				// reset counter
//				cnt_ReadByte = 0;
//				
//			}//if (buffer.length() > 1)
//			
////			// newlie arrived
////			String msg;
////			msg = String.format(Locale.JAPAN, 
////					"[%s : %d] new line! => %d (buffer = %s)", 
////					Thread.currentThread().getStackTrace()[1].getFileName(), 
////					Thread.currentThread().getStackTrace()[1].getLineNumber(), 
////					
////					inByte, buffer
////			);
////
////			System.out.println(msg);
//			
////			// clear buffer
////			buffer = "";
////			
////			// clear port
////			port.clear();
//			
//		}//if (inByte != 10)

	}//if (port != null && port.available() > 0)
	
}//draw()

void key_Input() {
	
	if (keyPressed) {
		
	    if (key == 's') {
	    	
	      exit();
	      
	    }
	    
	}
	
}

boolean is_Numeric(String str) {
	
	boolean result = str.matches("((-|\\+)?[0-9]+(\\.[0-9]+)?)+");
	
	return result;
	
//	return false;
	
}
