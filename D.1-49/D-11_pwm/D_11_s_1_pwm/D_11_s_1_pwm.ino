// D_11_s_1_pwm.ino
//  
/*
* 1. pwm + LED
*/

const int analogOutPin = 3; // LEDを接続したピンを指定。必ず～印のついたPWMピンを指定すること
//const int analogOutPin = 2; // LEDを接続したピンを指定。必ず～印のついたPWMピンを指定すること
//const int analogOutPin = 9; // LEDを接続したピンを指定。必ず～印のついたPWMピンを指定すること
char input[3];//シリアル通信の文字列格納用

int outputValue = 0;        // PWM 出力する値

void setup()
{
Serial.begin(9600);//シリアル通信を開始
}

void loop()
{
serialin();//下記のvoid serialinの内容を実行
analogWrite(analogOutPin, outputValue);//PWM出力
}

void serialin()
{
  if (Serial.available()>=3)//シリアルから送られてきた3桁の数字を読み込む
    {
    
    Serial.println("serial received");
    
//    int i=0;
//     for( i=0; i=2; i++ )//iが0～2まで変動するので、合計3桁分
       for( int i=0; i < 3; i++ )//iが0～2まで変動するので、合計3桁分
//         for( int i=0; i == 2; i++ )//iが0～2まで変動するので、合計3桁分
//         for( int i=0; i=2; i++ )//iが0～2まで変動するので、合計3桁分
      {
       input[i]=Serial.read();//一桁づつ入れてゆく
       
        //debug
       Serial.println(input[i]);
       
      }
     
       //debug
       Serial.println(input);
       
     int buf=atoi(input);//シリアル入力された文字列をint型に変換
     
     if( ( buf <= 255 ) && ( buf >= 0 ) )//安全のため、PWMで扱える0～255の範囲の時のみPWM出力の値に反映
//       if(buf<=255&&buf>=0)//安全のため、PWMで扱える0～255の範囲の時のみPWM出力の値に反映
       {
        outputValue=buf;
       }

    }
}


