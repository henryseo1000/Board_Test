int level;
int water;
int brightness;
int standard;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(A1);
  water = analogRead(A0);
  standard = map(level, 0, 1023, 0, 700);
  
  //brightness = map(level, 0, 1023, 0, 255);
  //analogWrite(9, brightness);

  if(water >= level){
    digitalWrite(9, HIGH);
  }
  else{
    digitalWrite(9, LOW);
  }
  Serial.println(level);
  Serial.println(water);

  delay(100);
}
