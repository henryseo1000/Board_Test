int red = 6;
int green = 5;
int blue = 3;
char val;
int brightness1 = 0;
int brightness2 = 0;
int brightness3 = 0;
int index = 0;
int LED = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int list[3] = {2,3,4};

  digitalWrite(list[index], HIGH);

  index ++;
  digitalWrite(list[index], LOW);
  if(index > 3){
    index -= 3;
  }

  index++;
  digitalWrite(list[index], LOW);
  if(index > 3){
    index -= 3;
  }

  delay(1000);*/

  /*digitalWrite(LED, HIGH);

  LED += 1;
  if(LED > 5){
    LED = 2;
  }

  delay(1000);

  for(int i = 2; i < 5; i++){
    digitalWrite(i, LOW);
  }*/

  if(Serial.available()){
    val = Serial.read();
  }

  if(val == 'a'){
    brightness1 += 20;
    if(brightness1 > 260){
    brightness1 = 255;
  }
    analogWrite(red, brightness1);
  }
  if(val == 'b'){
    brightness2 += 20;
    if(brightness2 > 260){
    brightness2 = 255;
  }
    analogWrite(green, brightness2);
  }
  if(val == 'c'){
    brightness3 += 20;
    if(brightness3 > 260){
    brightness3 = 255;
  }
    analogWrite(blue, brightness3);
  }
  if(val == 'd'){
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
  if(val == 'e'){
    brightness1 = 0;
    brightness2 = 0;
    brightness3 = 0;
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }

  delay(1000);
}
