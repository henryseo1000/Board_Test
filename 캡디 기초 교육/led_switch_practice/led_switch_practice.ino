int red;
int green;
int blue;
int val;

int r_bright = 0;
int g_bright = 0;
int b_bright = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  red = analogRead(A0);
  green = analogRead(A1);
  blue = analogRead(A2);

  if(red == 0){
    if(r_bright >= 256){

    }
    else{
      r_bright += 20;
      analogWrite(11, r_bright);
    }
  }
  if(green == 0){
    if(g_bright >= 256){

    }
    else{
      g_bright += 20;
      analogWrite(10, g_bright);
    }
  }
  if(blue == 0){
    if(b_bright >= 256){

    }
    else{
      b_bright += 20;
      analogWrite(9, b_bright);
    }
  }
  Serial.print("red :");
  Serial.println(red);
  Serial.print("green :");
  Serial.println(green);
  Serial.print("blue :");
  Serial.println(blue);

  Serial.print("밝기 빨강:");
  Serial.println(r_bright);
  Serial.print("밝기 초록:");
  Serial.println(g_bright);
  Serial.print("밝기 파랑:");
  Serial.println(b_bright);
  delay(100);
}
