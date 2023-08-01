int state;
int state2;
int mode = 0;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = analogRead(A1);

  if(state == 1023){
    if(mode == 0){
      digitalWrite(11, HIGH);
    }
    else if(mode == 1){
      digitalWrite(11, LOW);
    }
  }

  /*state = analogRead(A1);
  delay(100);
  state2 = analogRead(A1);

  int diff = state - state2;

  if(state > state2 && (diff < -1000 || diff > 1000)){
    count ++;
  }
  else if(state == state2){

  }

  if(count % 2 == 1){
    digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);
  }*/

  Serial.println(state);
  delay(100);
}
