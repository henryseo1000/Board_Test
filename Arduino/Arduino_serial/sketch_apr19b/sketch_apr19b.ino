int pin = 0;
int mode = 1;
int plus = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
}

void All_led(int mode){
  for(int pin = 0; pin <= 13; pin++){
    digitalWrite(pin, mode);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  if(pin > 13){
    mode = 1;
  }
  if(pin < 0){
    mode = 0;
  }

  if (mode == 1){
    digitalWrite(pin, LOW);
    pin --;
  }
  else{
    digitalWrite(pin, HIGH);
    pin ++;
  }

  Serial.println(pin);
  delay(1000);

  /*delay(500);

  if(plus == 1){
    digitalWrite(pin, HIGH);
  }
  else {
    digitalWrite(pin, LOW);
  }

  delay(500);

  if (pin == 14){
    digitalWrite(pin, LOW);
    plus = -1;
  }
  else if(pin == 1){
    digitalWrite(pin, HIGH);
    plus = 1;
  }

  pin += plus;*/

  /*digitalWrite(pin, HIGH);

  if(pin < 14){
    pin++;
  }
  else {
    All_led(0);
    pin = 0;
  }


  delay(1000);*/

  /*All_led(1);
  delay(1000);
  All_led(0);
  delay(1000);*/

}
// 시리얼 통신은 데이터를 하나 하나씩 보낸다.