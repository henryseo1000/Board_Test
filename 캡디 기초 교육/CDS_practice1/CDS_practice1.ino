int brightness;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  brightness = analogRead(A0);

  /*val = map(brightness, 300, 600, 255, 0);
  val = constrain(val, 0, 255);

  analogWrite(11, val);*/

  if(brightness <= 300){
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);
  }

  Serial.print("밝기 :");
  Serial.println(brightness);
  /*Serial.print("PWM :");
  Serial.println(val);*/

  delay(100);
}
