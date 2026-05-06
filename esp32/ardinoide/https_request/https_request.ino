#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <WebServer.h>
#include <WiFiClientSecure.h>  // HTTPS 용 클라이언트

WiFiMulti WiFiMulti;
WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("SSID", "PASSWORD"); //여기에 공유기의 SSID와 PASSWORD를 넣어 줍니다.
}

void update_started() {
  Serial.println("CALLBACK:  HTTP update process started");
}

void update_finished() {
  Serial.println("CALLBACK:  HTTP update process finished");
}

void update_progress(int cur, int total) {
  Serial.printf("CALLBACK:  HTTP update process at %d of %d bytes...\n", cur, total);
}

void update_error(int err) {
  Serial.printf("CALLBACK:  HTTP update fatal error code %d\n", err);
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    //WiFiClient client; // HTTP 링크 사용시
    WiFiClientSecure client; //HTTS 링크 사용시

    client.setInsecure();     // SSL 인증서 검증을 생략
    httpUpdate.onStart(update_started);
    httpUpdate.onEnd(update_finished);
    httpUpdate.onProgress(update_progress);
    httpUpdate.onError(update_error);
    //사용자프로젝트와 사용자바이너리는 Firebase설정에 따라 다릅니다. 이 링크는 복사해서 붙여 넣으시면 됩니다.
    t_httpUpdate_return ret = httpUpdate.update(client, "https://firebasestorage.googleapis.com/v0/b/사용자프로젝트.appspot.com/o/사용자바이너리.bin?alt=media&token=latest-generated-token");


    switch (ret) {
      case HTTP_UPDATE_FAILED:
        Serial.printf("HTTP_UPDATE_FAILED Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
        break;

      case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

      case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OK");
        break;
    }
  }
}