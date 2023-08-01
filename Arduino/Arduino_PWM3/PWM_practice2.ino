int LED = 3;
int brightness = 0;
int value = 'a';
char value2 = '0';
// int mode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("밝기 : ");
  Serial.println(brightness);
  

  if(Serial.available()){
    value = Serial.read();
    value2 = value;
  }

  if(value == 'A'){
    brightness += 20;
    if(brightness > 260){
      brightness = 255;
    }
  }

  else if(value == 'B'){
    brightness = 0;
  }
  
  else if (value == 'C'){
    brightness -= 20;
    if (brightness <= 0){
      brightness = 0;
    }
  }

  analogWrite(LED,brightness);
  delay(1000);
  Serial.print("value : ");
  Serial.println(value2);
}
