#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
위 두 라이브러리가 필요하다. 위 두 라이브러리는 

https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

위 깃허브를 압축 파일로 다운로드 받아 압축을 풀고, ESP8266WIFI 폴더를 추가해주면 된다.

그럼 본격적으로 웹 서버를 열어보자. 일단 나는 이 게시물의 가장 상단에 있는 블로그의 소스코드를 이용해 그대로 테스트했다.

해당 소스코드의 출처는 여기다 ; https://github.com/wootekken/esp8266/blob/main/esp8266_006_simpleWebserver/esp8266_006_simpleWebserver.ino

#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

#define HOME_SSID   "KT_GiGA_1234"  // 우리집 WiFi 이름
#define HOME_PWD    "12345678"      // 우리집 WiFi 비밀번호

ESP8266WebServer server(80);  // HTTP 기본 포트인 80설정
// 80포트 설정을 함으로써, 나중에 ESP8266 서버에 접속할 때 URL에 80을 안 적어도 됨
 
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
}
 
void loop() {
  server.handleClient();        // HTTP 요청 처리하기
}
 
void helloFunction() {            // 루트 path요청에 실행되는 함수
  server.send(200, "text/plain", "Hello world"); // Hello world 글자 응답
  
  // text/plain : 텍스트로만 응답할때
  /* server.send(HTTP응답코드, 콘텐츠유형, 실제콘텐츠) 
   => 콘텐츠: 클라이언트 요청에 대해 서버가 응답해주는 실제 내용물
   => 200(OK) : 요청이 성공적으로 되었습니다. */
}