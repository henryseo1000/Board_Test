int water_value;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  water_value = analogRead(A0);

  if(water_value > 200){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
  Serial.println(analogRead(A0));
  delay(100);
}
