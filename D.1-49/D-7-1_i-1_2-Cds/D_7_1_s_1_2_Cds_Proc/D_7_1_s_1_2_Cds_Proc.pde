/*
 *	D_7_1_s_1_2_Cds_Proc.pde
 *
 *	07/07/2015 13:53:03
 * 
 * 	i = 1
 * 
 */

import processing.net.*;
import processing.serial.*;


PFont font;

Serial port;

int cnt_ReadByte = 0;	// coutn the number of bytes read from arduino
String buffer = "";  // buffer for strings from Arduino

int c_1 = 0;	// fill value for rectangle 1
int c_2 = 0;	// fill value for rectangle 2
int c_default = 255;	// fill value for background


final int win_X = 800;
final int win_Y = 500;

String[] vals;

void setup() {
	// put your setup code here, to run once:

	size(win_X, win_Y);
	//  size(640, 480);
	
	frameRate(10);
	
	font = loadFont("ScalaSans-Caps-32.vlw");
	//  font = loadFont("HelveticaNeue-Bold-32.vlw");
	
	fill(c_default);
//	fill(255);
	
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
	  
	} else {//if (len < 1)
		
		println("Listening... (list length = " + len + ")");
		
	}//if (len < 1)
	
	// get: arduino port
	String arduinoPort = Serial.list()[0];
	
	port = new Serial(this, arduinoPort, 9600);  // connect to Arduino

	///////////////////////////////////
	//
	// init: vars
	//
	///////////////////////////////////
//	vals = new String[2];
	
	String msg;
	msg = String.format("[%s : %d] setup => done", Thread.currentThread()
//	      msg = String.format(Locale.JAPAN, "[%s : %d] setup => done", Thread.currentThread()
	    .getStackTrace()[1].getFileName(), Thread.currentThread()
	    .getStackTrace()[1].getLineNumber());

	System.out.println(msg);	
}//void setup()

void draw() {
	
	///////////////////////////////////
	//
	// fill: rect
	//
	///////////////////////////////////
	fill(c_1);
	
	rect(100, 100, 110, 110);
	
	fill(c_2);
	
	rect(310, 100, 110, 110);
	
	
	
	fill(c_default);
	
	///////////////////////////////////
	//
	// read data: from arduino
	//
	///////////////////////////////////
	if (port != null && port.available() > 0) {

		int inByte = port.read();	// read 1 byte
		
		// validate: newline(LF)?
		if (inByte != 10) {

			buffer = buffer + char(inByte);

			cnt_ReadByte ++;
			
		}//if (inByte != 10)
		
		else {
			
			// validate: any data
			if (buffer.length() > 1) {

				// omit => LF char
//				String[] tmp = subset(buffer, 0, 3);
				
//				String msg;
//				msg = String.format(Locale.JAPAN, "[%s : %d] tmp = %s", Thread
//						.currentThread().getStackTrace()[1].getFileName(),
//						Thread.currentThread().getStackTrace()[1]
//								.getLineNumber(), tmp);
//
//				System.out.println(msg);
				
				
//				buffer = (String)subset(buffer, 0, buffer.length() - 1);	//=> null pointer exception
//				buffer = (String[])subset(buffer, 0, buffer.length() - 1);	//=> cannot convert from String[] to String
//				buffer = subset(buffer, 0, buffer.length() - 1);	//=> cannot convert from Object to String
//				buffer[buffer.length - 1] = "\0";
//				buffer[buffer.length - 1] = '\0';
				
				String msg;
				msg = String.format(Locale.JAPAN, 
						"[%s : %d] buffer = %s (%d bytes)", 
						Thread
						.currentThread().getStackTrace()[1].getFileName(),
						Thread.currentThread().getStackTrace()[1]
								.getLineNumber(), 
								
						buffer, cnt_ReadByte
						
				);

				System.out.println(msg);
				
				///////////////////////////////////
				//
				// get: vals
				//
				///////////////////////////////////
				vals = split(buffer, " ");
				
//				String msg;
				msg = String.format(Locale.JAPAN, 
						"[%s : %d] vals[0] = %s / vals[1] = %s", Thread
//						"[%s : %d] val_1 = %s / val_2 = %s", Thread
						.currentThread().getStackTrace()[1].getFileName(),
						Thread.currentThread().getStackTrace()[1]
								.getLineNumber(), vals[0], vals[1]);

				System.out.println(msg);
				
				///////////////////////////////////
				//
				// conv: vals
				//
				///////////////////////////////////
				c_1 = int((int(vals[0]) / (float) 1024) * 255);
				
				String tmp = vals[1].substring(0, vals[1].length() - 1);
				
				c_2 = int((int(tmp) / (float) 1024) * 255);
//				c_2 = int(vals[1]);
//				c_2 = int((int(vals[1]) / (float) 1024) * 255);
				
//				String msg;
//				msg = String.format(Locale.JAPAN, "[%s : %d] c_2 => %d", Thread
//						.currentThread().getStackTrace()[1].getFileName(),
//						Thread.currentThread().getStackTrace()[1]
//								.getLineNumber(), c_2);
//
//				System.out.println(msg);

//				String tmp = vals[1].substring(0, vals[1].length() - 1);
				
//				String msg;
//				msg = String.format(Locale.JAPAN, "[%s : %d] tmp => (%s)", Thread
//						.currentThread().getStackTrace()[1].getFileName(),
//						Thread.currentThread().getStackTrace()[1]
//								.getLineNumber(), tmp);
//
//				System.out.println(msg);
				
				
//				String msg;
				msg = String.format(Locale.JAPAN, "[%s : %d] c_1 = %d / c_2 = %d", 
						Thread
						.currentThread().getStackTrace()[1].getFileName(),
						Thread.currentThread().getStackTrace()[1]
								.getLineNumber(), 
						c_1, c_2);

				System.out.println(msg);
				
				
				// clear buffer
				buffer = "";
				
				// clear port
				port.clear();

				// reset counter
				cnt_ReadByte = 0;
				
			}//if (buffer.length() > 1)
			
			else {
				
				String msg;
				msg = String.format(Locale.JAPAN, "[%s : %d] buffer length => < 1", Thread
						.currentThread().getStackTrace()[1].getFileName(),
						Thread.currentThread().getStackTrace()[1]
								.getLineNumber());

				System.out.println(msg);
				
			}//if (buffer.length() > 1)
			
		}//if (inByte != 10)

	}//if (port != null && port.available() > 0)

	
}//void draw()



