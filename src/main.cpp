#include <Arduino.h>
#include <OneWire.h>
#include <string>
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

#define pin1 4

#define HOME_SSID   "Henry_iptime"  // 우리집 WiFi 이름
#define HOME_PWD    "henryseo"      // 우리집 WiFi 비밀번호

float temperature;
char result[8];

OneWire ds(pin1);
ESP8266WebServer server(80);  // HTTP 기본 포트인 80설정
// 80포트 설정을 함으로써, 나중에 ESP8266 서버에 접속할 때 URL에 80을 안 적어도 됨
float getTemp(){  //온도 측정 후 반환하는 함수. 오류가 날 경우 -1000을 반환한다.
 byte data[12];
 byte addr[8];
 if ( !ds.search(addr)) {
   ds.reset_search();
   return -1000;
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }
 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }
 ds.reset();
 ds.select(addr);
 ds.write(0x44,1);                                   
 byte present = ds.reset();
 ds.select(addr);  
 ds.write(0xBE); 
 
 for (int i = 0; i < 9; i++) { 
  data[i] = ds.read();                                                          
 }
 
 ds.reset_search(); 
 byte MSB = data[1];
 byte LSB = data[0];
 float tempRead = ((MSB << 8) | LSB); 
 float TemperatureSum = tempRead / 16; 
 return TemperatureSum;                                                                    
}

void helloFunction() {            // 루트 path요청에 실행되는 함수
  temperature = getTemp();
  dtostrf(temperature, 6, 2, result);
  server.send(200, "text/plain", result); // Hello world 글자 응답
  Serial.println(temperature);

  // text/plain : 텍스트로만 응답할때
  /* server.send(HTTP응답코드, 콘텐츠유형, 실제콘텐츠) 
   => 콘텐츠: 클라이언트 요청에 대해 서버가 응답해주는 실제 내용물
   => 200(OK) : 요청이 성공적으로 되었습니다. */
}


void setup() {
  Serial.begin(115200);
  WiFi.begin(HOME_SSID, HOME_PWD);  // WiFi에 접속하기
 
  while (WiFi.status() != WL_CONNECTED) {  // WiFi 접속이 완료되었나?
    delay(1000);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // 로컬ip 출력
 
  server.on("/", helloFunction);    // 루트 path 요청에 실행할 함수 설정
  server.begin();                   // 웹서버 시작하기
  Serial.println("Server listening");
  pinMode(4, INPUT);
}
 
void loop() {
  server.handleClient();        // HTTP 요청 처리하기
  delay(1000);
}