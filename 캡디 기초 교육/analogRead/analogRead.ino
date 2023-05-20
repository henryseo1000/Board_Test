int map_value = 0;
int vcc_value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(n = 0; n <= 5; n++){
    map_value = (float)1023 * n / (float) 5;
    Serial.println(map_value);
    delay(2000);
  }*/
  if(vcc_value < 6){
    Serial.print("vcc_value = ");
    Serial.println(vcc_value);
    map_value = map(vcc_value, 0 , 5, 0, 1023);
    Serial.print("Map_value = ");
    Serial.println(map_value);
    vcc_value = vcc_value + 1;
    delay(1000);
  }
}
