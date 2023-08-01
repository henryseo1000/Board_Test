/*
 제목    : I2C LCD에 문자 출력하기
 내용   : I2C LCD에 원하는 문자를 표시해 봅니다.  
 */

// LCD를 쉽게 제어하기 위한 라이브러리를 추가합니다.
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 0x3F I2C 주소를 가지고 있는 16x2 LCD객체를 생성합니다.(I2C 주소는 LCD에 맞게 수정해야 합니다.)
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pin = A0;
int value = 0;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
  // I2C LCD를 초기화 합니다..
  lcd.init();
  // I2C LCD의 백라이트를 켜줍니다.
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("hi!");
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() { 
  delay(2000); // 2초의 딜레이
  lcd.clear(); // 그 후 디스플레이를 전부 지운다.
  
  value = analogRead(pin); // 우리가 연결한 센서의 핀에서 값을 받아 저장한다.
  lcd.setCursor(0,0);
  lcd.print("brightness:");
  
  lcd.setCursor(12,0);
  lcd.print(value);

  delay(2000);
  lcd.setCursor(0,1);
  if(value >= 800){
    lcd.print("too bright!");
  }
  else if(value >= 700){
    lcd.print("I love light!");
  }
  else {
    lcd.print("too dark...");
  }
}
