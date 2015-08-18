  /*
  * D_12_irremote_s_5.ino
  *
  *  REF: http://www.embedded-property.net/?p=986
  *
  * [Notices]
  *   1. Monitor speed  => 57600 bps
  *   2. Serial rate    => 57600
  *   
  * 
  */

///////////////////////////////////
//
// defines
//
///////////////////////////////////
const char title[] = "\n12/7 #1";

int count = 0;

///////////////////////////////////
//
// vars
//
///////////////////////////////////
//const int SERIAL_RATE  = 115200;
const int SERIAL_RATE  = 9600;

const int IRpin        = 2;

const int DATA_POINT  = 3;

//int count = 0;

///////////////////////////////////
//
// pins
//
///////////////////////////////////
const int  LED_OUT = 8;

//////////////////////////////////////////////////////////////////////
//
// methods
//
//////////////////////////////////////////////////////////////////////
//the Interrupt routine  (2)
void interruptsw() {

//  Serial.println("interrupt!");
//  Serial.println(micros());
//  
//  delayMicroseconds(500);
//  Serial.println("delayed 500");
  
  // stop interrupts
  cli();
  
    int ans ;

    ans = IRrecive() ;                      // 赤外線リモコンのデータを受信する
    
    Serial.println("ans => ");
    Serial.println(ans);
    
    if (ans != 0) Serial.println(ans,HEX) ; // リモコンからデータを受信したら表示する

    // counter 
    Serial.println("count => ");
    Serial.println(count);
    
    count ++;
    
    // resume interrupts
    sei();
  
}//void interruptsw()

//赤外線リモコンのデータを受信する処理関数
int IRrecive() {
  unsigned long t ;
  int i , j ;
  int cnt , ans ;
  char IRbit[64] ;
  
  ans = 0 ;
  t = 0 ;
  if (digitalRead(IRpin) == LOW) {
       // リーダ部のチェックを行う
       t = micros() ;                          // 現在の時刻(us)を得る
       while (digitalRead(IRpin) == LOW) ; // HIGH(ON)になるまで待つ
       t = micros() - t ;         // LOW(OFF)の部分をはかる
  }
  // リーダ部有りなら処理する(3.4ms以上のLOWにて判断する)
  if (t >= 3400) {
       i = 0 ;
       while(digitalRead(IRpin) == HIGH) ; // ここまでがリーダ部(ON部分)読み飛ばす
       // データ部の読み込み
       while (1) {
            while(digitalRead(IRpin) == LOW) ;// OFF部分は読み飛ばす
            t = micros() ;
            cnt = 0 ;
            while(digitalRead(IRpin) == HIGH) {// LOW(OFF)になるまで待つ
                 delayMicroseconds(10) ;
                 cnt++ ;
                 if (cnt >= 1200) break ;   // 12ms以上HIGHのままなら中断
            }
            t = micros() - t ;
            if (t >= 10000) break ;     // ストップデータ
            if (t >= 1000)  IRbit[i] = (char)0x31 ; // ON部分が長い
            else            IRbit[i] = (char)0x30 ; // ON部分が短い
            i++ ;
       }
       // データ有りなら指定位置のデータを取り出す
       if (i != 0) {
         
         DspData(i,IRbit) ;
         
            i = (DATA_POINT-1) * 8 ;
            for (j=0 ; j < 8 ; j++) {
                 if (IRbit[i+j] == 0x31) bitSet(ans,j) ;
            }
       }
  }
  
  return( ans ) ;
  
}//IRrecive()

//受信データをシリアルモニタ画面に送り表示をさせる処理
void DspData(int num,char *data) {
  int i , j , x , dt ;
  
   Serial.print(data) ;    // ビットデータで表示
   Serial.write(" ( ") ;
   x = num / 8 ;
   // ビット文字列データから数値に変換する
   for (j=0 ; j < x ; j++) {
        dt = 0 ;
        for (i=0 ; i < 8 ; i++) {
             if (*data++ == 0x31) bitSet(dt,i) ;
        }
        Serial.print(dt,HEX) ;  // ＨＥＸ(16進数)で表示
        Serial.write(' ') ;
   }
   
   Serial.println(')') ;     
   
}//DspData(int num,char *data)

void setup()
{
  
  Serial.begin(SERIAL_RATE);

  ///////////////////////////////////
  //
  // pins
  //
  ///////////////////////////////////
  pinMode(LED_OUT, OUTPUT);       
  
  attachInterrupt(0, interruptsw, FALLING );  // 0 --> pin 2; 1 --> pin 3
  
  ///////////////////////////////////
  //
  // splash
  //
  ///////////////////////////////////
  Serial.println(title);
  
}
 

void loop() {
  
}//void loop()










