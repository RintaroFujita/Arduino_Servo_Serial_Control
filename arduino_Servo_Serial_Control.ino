#include <Servo.h>

Servo servo1;
Servo servo2;

int servoPin1 = 9;  // サーボモーター1のデータピン
int servoPin2 = 10; // サーボモーター2のデータピン

void setup() {
  servo1.attach(servoPin1);  // サーボモーター1をデータピン1に接続
  servo2.attach(servoPin2);  // サーボモーター2をデータピン2に接続
  Serial.begin(9600);  // シリアル通信の初期化
}

void loop() {
  if (Serial.available()) {
    int servoNum = Serial.parseInt();  // サーボ番号を読み取る
    int angle = Serial.parseInt();     // 角度を読み取る
    
    // サーボ番号に応じてサーボモーターを制御
    if (servoNum == 1) {
      servo1.write(angle);  // サーボモーター1を指定の角度に回転
    } else if (servoNum == 2) {
      servo2.write(angle);  // サーボモーター2を指定の角度に回転
    }
  }
}
