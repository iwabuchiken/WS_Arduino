  /*
    * D_8_servo_s_4___2_Servo_Cds.ino
    *
    * 1. servo + 2 Cds
    */
  
  #include <Servo.h>
  
  ///////////////////////////////////
  //
  // vars
  //
  ///////////////////////////////////
  Servo servo1;
  
  char version[] = "8/4 #2-3 (8/5 #1)";
  
  const char splash_Messsage[] = "Servo!!";
  
  const int SERVO_OUT_PIN    = 6;
  
  const int DELAY_TIME_MS    = 0;
  int deg=0;
  
  const int ANALOG_0 = 0;
  const int ANALOG_1 = 1;
  
  int val_0;
  int val_1;
  
  String s0("A0 => ");
  String s1("A1 => ");
  
  // states
  int      state;
  const int CENTER  = 0;
  const int RIGHT = -1;
  const int LEFT  = 1;
  
  const int DEG_CENTER  = 90;
  const int DEG_RIGHT = 0;
  const int DEG_LEFT  = 180;

  const int WITHIN_BALANCE  = 100;
  
  int diff;
  int larger;
  
  const int THRESH    = 20;
//  const int THRESH    = 100;
  
  void setup() {
    
    ///////////////////////////////////
    //
    // serial
    //
    ///////////////////////////////////
    Serial.begin(9600);
  
    Serial.println(version);
    
    ///////////////////////////////////
  //
  // servo
  //
  ///////////////////////////////////
    servo1.attach(SERVO_OUT_PIN);
    
    // initial moves
    servo1.write(90);
    
    delay(500);
    
    servo1.write(0);
    
    delay(100);
    
    ///////////////////////////////////
  //
  // state
  //
  ///////////////////////////////////
    state = CENTER;
    
    // move servo
    move_Servo(state);
    
  }//void setup()
  
  void loop() {
    
    ///////////////////////////////////
    //
    // read: analog
    //
    ///////////////////////////////////
    val_0 = analogRead(ANALOG_0);
    val_1 = analogRead(ANALOG_1);
  
//    Serial.println(s0 + val_0);
//    Serial.println(s1 + val_1);
    
    // difference
    diff = abs(val_0 - val_1);
    
    //debug
    String s("diff => ");
    Serial.println(s + diff);
  //
  ////  // larger
  ////  larger = larger_value(val_0, val_1);
  //  
  ////  //debug
  ////  String s2("larger => ");
  ////  Serial.println(s2 + larger);
  //  
    ///////////////////////////////////
  //
  // move: servo
  //
  ///////////////////////////////////
    if (diff > THRESH) {

      if (diff < WITHIN_BALANCE) {
      
        if (state != CENTER) {

          state = CENTER;
          
          move_Servo(state);

      }//if (state != CENTER)
      
    } else {//if (diff < WITHIN_BALANCE)
      
      // larger
      larger = larger_value(val_0, val_1);
      
      //debug
      String s2("larger => ");
      Serial.println(s2 + larger);
      
      
      switch(larger) {
      
      case RIGHT:
        
        if (state != RIGHT) {
          
          state = RIGHT;
          
          move_Servo(state);
          
        }//if (state != RIGHT)
        
        break;
        
      case LEFT:
        
        if (state != LEFT) {
          
          state = LEFT;
          
          move_Servo(state);
          
        }//if (state != RIGHT)
        
        break;
        
        break;
        
      }
      
    }//if (diff < WITHIN_BALANCE)
    
    }//if (diff > THRESH)
  
    
    // wait
    delay(500);
    
  }//void loop()
  
  void move_Servo(int state) {
    
    //debug
    String s("move servo => ");
    Serial.println(s + state);
    
    switch(state) {
    
    case CENTER:
    
      servo1.write(DEG_CENTER); break;
    
    case RIGHT:
    
      servo1.write(DEG_RIGHT);  break;
    
    case LEFT:
    
      servo1.write(DEG_LEFT); break;
  
    default:
      
      //debug
      String s2("unknown state => ");
    Serial.println(s2 + state);
  
    }
    
  }
  
  void update_Servo(int val_0, int val_1) {
  
    // get: larger
    larger = larger_value(val_0, val_1);
    
  }
  
  ///////////////////////////////////
  //
  // @param
  //  val_0 => right cds value
  //  val_1 => left cds value
  //
  // @return
  //  RIGHT or LEFT
  ///////////////////////////////////
  int larger_value(int val_0, int val_1) {
  
    return (val_0 > val_1) ? RIGHT : LEFT;
    
  }
  
  




