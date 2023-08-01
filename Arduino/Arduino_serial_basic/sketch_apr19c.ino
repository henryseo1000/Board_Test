int a = 10;
double b = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(a);
  Serial.println(b);
  Serial.print("print와 println의 차이점");
  Serial.println("차이점을 아시겠나요?");
  delay(1000);
}
