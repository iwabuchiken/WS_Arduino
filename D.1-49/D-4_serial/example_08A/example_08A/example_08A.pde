import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.Locale;
import java.util.StringTokenizer;

import processing.net.*;
import processing.serial.*;

String feed = "http://feeds.abcnews.com/abcnews/internationalheadlines";
//String feed = "http://feeds.abcnews.com/abcnews/usheadlines";
//String feed = "http://www.foxnews.com/about/rss/";
//String feed = "https://docs.oracle.com/javase/7/docs/api/java/net/URLConnection.html";
//String feed = "http://makezine.com/feed/";
//String feed = "http://blog.makezine.com/index.xml";

int interval  = 5;
//int interval  = 10;
int lastTime;

int love  = 0;
int peace  = 0;
int arduino  = 0;

int light  = 500;	// default
//int light  = 0;

Serial port;
color c;

String cs;

String buffer = "";  // buffer for strings from Arduino

PFont font;

String kw_1 = "economic";
String kw_2 = "us";
String kw_3 = "cuba";

int numOf_kw_1;
int numOf_kw_2;
int numOf_kw_3;

int cnt_ReadByte = 0;	// coutn the number of bytes read from arduino

final int win_X = 800;
final int win_Y = 500;

//const int delay_Time  = 100;  // delay time in millsec

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
  
  // fetch
  fetchData();
  
//  //debug
//  println(Serial.list());
//  println(Serial.list().length);

  String msg;
  msg = String.format("[%s : %d] setup => done", Thread.currentThread()
//      msg = String.format(Locale.JAPAN, "[%s : %d] setup => done", Thread.currentThread()
      .getStackTrace()[1].getFileName(), Thread.currentThread()
      .getStackTrace()[1].getLineNumber());

  System.out.println(msg);
  
//  println("setup => done");
//  println("done");

}//void setup()

void draw() {

	///////////////////////////////////
	//
	// key inputs
	//
	///////////////////////////////////
	key_Input();
	
//  c = color(peace, love, arduino);
	
	background(c);
	
	int n = (interval - ((millis() - lastTime)/1000));
	
	// construct color
//	c = color(0, 184, 40);
	c = color(numOf_kw_1, numOf_kw_2, numOf_kw_3);
//	c = color(peace, love, arduino);
	
	cs = "#" + hex(c,6);  // prep the string to Arduino
	
	text("Arduino Networked Lamp", 10, 40);
	
	text("Reading feed:", 10, 100);
	
	text(feed, 10, 140);
	
	text("Next update in " + n + " seconds", 10, 450);

	// keywords
	text(kw_1, 10, 200);
	text(" " + numOf_kw_1, 200, 200);
	
	rect(300, 172, numOf_kw_1, 28);
	
	text(kw_2, 10, 240);
	text(" " + numOf_kw_2, 200, 240);
	
	rect(300, 212, numOf_kw_2, 28);
	
	text(kw_3, 10, 280);
	text(" " + numOf_kw_3, 200, 280);
	
	rect(300, 252, numOf_kw_3, 28);
	
	
	///////////////////////////////////
	//
	// color info
	//
	///////////////////////////////////
	text("sending", 10, 340);
	text(cs, 210, 340);
	
	
	text("light level", 10, 380);
	
	text(" " + light, 200, 380);
	
	rect(300, 352, light/10.23, 28);
	
	///////////////////////////////////
	//
	// update: color data
	//
	///////////////////////////////////
	if (n <= 0) {

		fetchData();
		
		lastTime = millis();
		
		println("lastTime => updated: " + lastTime + "(cs = " + cs + ")");

	}//if (n <= 0)
	
	///////////////////////////////////
	//
	// send data
	//
	///////////////////////////////////
	if (port != null) {

		port.write(cs);

		String msg;
		msg = String.format(Locale.JAPAN, "[%s : %d] cs = %s", Thread
				.currentThread().getStackTrace()[1].getFileName(), Thread
				.currentThread().getStackTrace()[1].getLineNumber(), cs);

		System.out.println(msg);
		
	}//if (port != null)
	
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
			
//			String msg;
//			msg = String.format(Locale.JAPAN, "[%s : %d] buffer = %s", Thread
//					.currentThread().getStackTrace()[1].getFileName(), Thread
//					.currentThread().getStackTrace()[1].getLineNumber(), buffer);
//
//			System.out.println(msg);
			
		}//if (inByte != 10)
		
		else {
			
			// validate: any data
			if (buffer.length() > 1) {

				buffer = buffer.substring(0, buffer.length() - 1);
				
				// validate: is numeric
				if (is_Numeric(buffer)) {

					light = int(buffer);

				}//if (is_Numeric(buffer))
				
//				light = int(buffer);

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
				
				// clear buffer
				buffer = "";
				
				// clear port
				port.clear();

				// reset counter
				cnt_ReadByte = 0;
				
			}//if (buffer.length() > 1)
			
//			// newlie arrived
//			String msg;
//			msg = String.format(Locale.JAPAN, 
//					"[%s : %d] new line! => %d (buffer = %s)", 
//					Thread.currentThread().getStackTrace()[1].getFileName(), 
//					Thread.currentThread().getStackTrace()[1].getLineNumber(), 
//					
//					inByte, buffer
//			);
//
//			System.out.println(msg);
			
//			// clear buffer
//			buffer = "";
//			
//			// clear port
//			port.clear();
			
		}//if (inByte != 10)

	}//if (port != null && port.available() > 0)
	
}//draw()

void fetchData() {

	  // strings for feed parce
	  String data;
	  String chunk;

//	  String kw_1 = "economic";

//	  int numOf_kw_1 = 0;
//	  int numOf_kw_2 = 0;
//	  int numOf_kw_3 = 0;
	  
	  // init counters => 0
	//  peace = (int)random(255);
	//  peace = (int)random(100);
	//  peace = 50;
//	  num_kw_1 = 0;
	  peace = 0;
	  
	  love = 0;
	  
	  arduino = 0;
	  
	  ///////////////////////////////////
	  //
	  // processes
	  //
	  ///////////////////////////////////
	  try {
	    
	    URL url = new URL(feed);
	    
	    URLConnection conn = url.openConnection();
	    
	    conn.connect();
	    
	    String msg;
	    msg = String.format("[%s : %d] url => connected (%s)", Thread
	        .currentThread().getStackTrace()[1].getFileName(), Thread
	        .currentThread().getStackTrace()[1].getLineNumber(), feed);

	    System.out.println(msg);
	    
//	    String msg;
		msg = String.format(Locale.JAPAN, "[%s : %d] getting input stream...", Thread.currentThread()
				.getStackTrace()[1].getFileName(), Thread.currentThread()
				.getStackTrace()[1].getLineNumber());

		System.out.println(msg);
		
	    
	    // virtual pipe
	    BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
	    
//	    String msg;
		msg = String.format(Locale.JAPAN, "[%s : %d] input stream => obtained", Thread.currentThread()
				.getStackTrace()[1].getFileName(), Thread.currentThread()
				.getStackTrace()[1].getLineNumber());

		System.out.println(msg);
		
		while((data = in.readLine()) != null) {
			
			StringTokenizer st = new StringTokenizer(data, "\"<>,.()[] ");
			
			///////////////////////////////////
			//
			// count: words
			//
			///////////////////////////////////
			while(st.hasMoreTokens()) {
				
				chunk = st.nextToken().toLowerCase();
				
				if (chunk.lastIndexOf("love") >= 0) {

					love++;

				}//if (chunk.lastIndexOf("love") >= 0)
				
				if (chunk.lastIndexOf("peace") >= 0) {
					
					peace ++;
					
				}//if (chunk.lastIndexOf("love") >= 0)
				
				if (chunk.lastIndexOf("arduino") >= 0) {
					
					arduino ++;
					
				}//if (chunk.lastIndexOf("love") >= 0)
				
				if (chunk.lastIndexOf(kw_1) >= 0) 
					
							numOf_kw_1 ++;
					
				if (chunk.lastIndexOf(kw_2) >= 0) 
					
					numOf_kw_2 ++;
				
				if (chunk.lastIndexOf(kw_3) >= 0) 
					
					numOf_kw_3 ++;
				
			}//while(st.hasMoreTokens())
			
////			String msg;
//			msg = String.format(Locale.JAPAN, "[%s : %d] tokens => %d", Thread
//					.currentThread().getStackTrace()[1].getFileName(), Thread
//					.currentThread().getStackTrace()[1].getLineNumber(), st.countTokens());
	//
//			System.out.println(msg);
			
		}//while((data = in.readLine()) != null)
	    
		// modify numbers
		if (peace > 64) peace = 64;
		if (love > 64) love = 64;
		if (arduino > 64) arduino = 64;
		
		if (numOf_kw_1 > 64) numOf_kw_1 = 64;
		if (numOf_kw_2 > 64) numOf_kw_2 = 64;
		if (numOf_kw_3 > 64) numOf_kw_3 = 64;
		
//		String msg;
		msg = String.format(Locale.JAPAN, 
				"[%s : %d] peace = %d / love = %d / ard = %d / numOf_kw_1 = %d", 
					Thread.currentThread()
					.getStackTrace()[1].getFileName(), Thread.currentThread()
					.getStackTrace()[1].getLineNumber(), 
					peace, love, arduino, numOf_kw_1
		);

		System.out.println(msg);

		msg = String.format(Locale.JAPAN, 
				"[%s : %d] kw_1 = %s (%d) / kw_2 = %s (%d) / kw_3 = %s (%d)", 
				Thread.currentThread()
				.getStackTrace()[1].getFileName(), Thread.currentThread()
				.getStackTrace()[1].getLineNumber(), 
				kw_1, numOf_kw_1, kw_2, numOf_kw_2, kw_3, numOf_kw_3
				);
		
		System.out.println(msg);
		
		
		// finalize the numbers
		peace = peace * 4;
		love = love * 4;
		arduino = arduino * 4;
		
		numOf_kw_1 = numOf_kw_1 * 4;
		numOf_kw_2 = numOf_kw_2 * 4;
		numOf_kw_3 = numOf_kw_3 * 4;
		
		System.out.println(msg);
		
		msg = String.format(Locale.JAPAN, 
				"[%s : %d] kw_1 = %s (%d) / kw_2 = %s (%d) / kw_3 = %s (%d)", 
				Thread.currentThread()
				.getStackTrace()[1].getFileName(), Thread.currentThread()
				.getStackTrace()[1].getLineNumber(), 
				kw_1, numOf_kw_1, kw_2, numOf_kw_2, kw_3, numOf_kw_3
				);
		
		System.out.println(msg);
		
//	    String msg;
//	    msg = String.format("[%s : %d] executing fetch...", Thread
////	        msg = String.format(Locale.JAPAN, "[%s : %d] executing fetch...", Thread
//	        .currentThread().getStackTrace()[1].getFileName(), Thread
//	        .currentThread().getStackTrace()[1].getLineNumber());
	//
//	    System.out.println(msg);
	    
	    
	  } catch (Exception ex) {
	    
	    ex.printStackTrace();
	    
	    String msg;
	    msg = String.format("[%s : %d] ERROR: %s", Thread
//	        msg = String.format(Locale.JAPAN, "[%s : %d] ERROR: %s", Thread
	        .currentThread().getStackTrace()[1].getFileName(), Thread
	        .currentThread().getStackTrace()[1].getLineNumber(), ex.getMessage());

	    System.out.println(msg);
	    
	  }//try
	  
}//void fetchData()

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
