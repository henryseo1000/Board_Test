
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) // 시리얼 통신으로 들어온 값이 있는가?
  {
    char word = Serial.read();
    Serial.println(word);
  }
}
// No Line Ending : 줄바꿈이 없는 것