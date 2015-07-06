/*
  * D_5_s_2_LCD_2_lines.ino
  *
  * REF: http://deviceplus.jp/hobby/entry_007/
  * 
  * 1. LCD, analog values
  */

int sensorPin = A0;     //アナログ0番ピンを指定
int sensorValue = 0;

void setup() {
	
	Serial.begin(9600);           //シリアルモニタに表示する為の設定
	
}

void loop() {
	
	sensorValue = analogRead(sensorPin);    //アナログ0番ピンからの入力値を取得
	float temp  = modTemp(sensorValue);     //温度センサーからの入力値を変換
	Serial.println(temp);                   //結果をシリアルモニタに表示
	delay(500);                             //0.5秒ウェイト

}

//アナログ入力値を摂氏度℃に変換
float modTemp(int analog_val){
	
	float v  = 5;     // 基準電圧値( V )
	float tempC = ((v * analog_val) / 1024) * 100;  // 摂氏に換算
	return tempC;

}