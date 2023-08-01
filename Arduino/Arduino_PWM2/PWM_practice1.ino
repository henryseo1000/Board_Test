int LED = 3;
int brightness = 0;
char value;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("밝기 : ");
  Serial.println(brightness);
  Serial.print("모드 : ");
  Serial.println(mode);

  if(Serial.available()){
    value = Serial.read();
  }

  if(value == 'A'){
    mode = 1;
  }
  else if(value == 'B'){
    mode = 0;
  }

  if(mode == 1){
    analogWrite(LED,brightness);
    delay(1000);
    brightness += 20;
    if(brightness > 260){
      brightness = 255;
    }
  }
  else {
    brightness = 0;
  }
  
  analogWrite(LED,brightness);
  delay(1000);
}
