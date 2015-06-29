// example_08A.ino
//	p.64 Banzi 
/*
 * 1. cloud lamp: Processing
 */

import processing.serial.*;

String feed = "http://makezine.com/feed/";
//String feed = "http://blog.makezine.com/index.xml";

int interval	= 10;
int lastTime;

int love	= 0;
int peace	= 0;
int arduino	= 0;

int light	= 0;

Serial port;
color c;

String cs;

String buffer = "";	// buffer for strings from Arduino

PFont font;

//const int delay_Time	= 100;	// delay time in millsec

void setup() {
  // put your setup code here, to run once:

	size(640, 480);
	
	frameRate(10);
	
	font = loadFont("ScalaSans-Caps-32.vlw");
//	font = loadFont("HelveticaNeue-Bold-32.vlw");
	
	fill(255);
	
	textFont(font, 32);

	///////////////////////////////////
	//
	// validate
	//
	///////////////////////////////////
	int len = Serial.list().length;
	
	if (len < 1) {
		
		println("Serial list => less than 1");
		
		return;
		
	}//if (len < 1)
	
	// get: arduino port
	String arduinoPort = Serial.list()[0];
	
	port = new Serial(this, arduinoPort, 9600);	// connect to Arduino
	
	lastTime = 0;

	// fetch
	fetchData();
	
//	//debug
//	println(Serial.list());
//	println(Serial.list().length);
  
	println("done");

}//void setup()

void draw() {

	c = color(peace, love, arduino);
	
	background(c);
	
}//draw()

void fetchData() {

	peace = 50;
	
	love = 100;
	
	arduino = 200;
	
}