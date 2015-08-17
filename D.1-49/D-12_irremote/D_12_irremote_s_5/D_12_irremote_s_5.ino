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

#define IRpin       2    // 赤外線受信モジュール接続ピン番号

const char splash[] = "12/6 #3";

// 初期化処理
void setup()
{
     Serial.begin(9600) ; // パソコン(ArduinoIDE)とシリアル通信の準備を行う
     pinMode(IRpin,INPUT) ; // 赤外線受信モジュールに接続ピンをデジタル入力に設定
     
     Serial.println(splash);
     
}
// メインの処理
void loop()
{
     unsigned long t ;
     int i , cnt ;
     char IRbit[64] ;

     t = 0 ;
     if (digitalRead(IRpin) == LOW) {
          // リーダ部のチェックを行う
          t = micros() ;                          // 現在の時刻(us)を得る
          while (digitalRead(IRpin) == LOW) ; // HIGH(ON)になるまで待つ
          t = micros() - t ;          // LOW(OFF)の部分をはかる
     }
     // リーダ部有りなら処理する(3.4ms以上のLOWにて判断する)
     if (t >= 3400) {
          i = 0 ;
          while(digitalRead(IRpin) == HIGH) ; // ここまでがリーダ部(ON部分)読み飛ばす
          // データ部の読み込み
          while (1) {
               while(digitalRead(IRpin) == LOW) ; // OFF部分は読み飛ばす
               t = micros() ;
               cnt = 0 ;
               while(digitalRead(IRpin) == HIGH) {// LOW(OFF)になるまで待つ
                    delayMicroseconds(10) ;
                    cnt++ ;
                    if (cnt >= 1200) break ;    // 12ms以上HIGHのままなら中断
               }
               t = micros() - t ;
               if (t >= 10000) break ;      // ストップデータ
               if (t >= 1000)  IRbit[i] = (char)0x31 ;  // ON部分が長い
               else            IRbit[i] = (char)0x30 ;  // ON部分が短い
               i++ ;
          }
          // データ有りなら表示を行う
          if (i != 0) {
               IRbit[i] = 0 ;
//               DspData(i,IRbit) ;
               
               Serial.println("has data");
               
          }
     }
}

