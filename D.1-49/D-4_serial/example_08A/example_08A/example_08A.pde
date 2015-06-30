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

int numOf_kw_1;

int light  = 0;

Serial port;
color c;

String cs;

String buffer = "";  // buffer for strings from Arduino

PFont font;

String kw_1 = "economic";

//const int delay_Time  = 100;  // delay time in millsec

void setup() {
  // put your setup code here, to run once:

  size(640, 480);
  
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

//  c = color(peace, love, arduino);
  
  background(c);
  
  int n = (interval - ((millis() - lastTime)/1000));
  
  // construct color
  c = color(peace, love, arduino);
  
  cs = "#" + hex(c,6);  // prep the string to Arduino
  
  text("Arduino Networked Lamp", 10, 40);
  
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
  
//  fetchData();
  
}//draw()

void fetchData() {

	  // strings for feed parce
	  String data;
	  String chunk;

//	  String kw_1 = "economic";

	  int numOf_kw_1 = 0;
	  
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
					
				//if (chunk.lastIndexOf("love") >= 0)
				
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
		
//		String msg;
		msg = String.format(Locale.JAPAN, 
				"[%s : %d] peace = %d / love = %d / ard = %d / numOf_kw_1 = %d", 
					Thread.currentThread()
					.getStackTrace()[1].getFileName(), Thread.currentThread()
					.getStackTrace()[1].getLineNumber(), 
					peace, love, arduino, numOf_kw_1
		);

		System.out.println(msg);

		
		// finalize the numbers
		peace = peace * 4;
		love = love * 4;
		arduino = arduino * 4;
		
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

