int water_value;
int led_value;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  water_value = analogRead(A0);

  led_value = map(water_value, 0 , 300, 255 , 0);
  led_value = constrain(led_value, 0 , 255);

  analogWrite(3, led_value);
  Serial.println(water_value);
  delay(100);
}
