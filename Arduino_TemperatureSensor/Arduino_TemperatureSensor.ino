#include <OneWire.h> // Onewire 라이브러리를 include 해주어야 한다.

int pin1 = 2; //온도 센서를 2번 핀에 연결했다.

OneWire ds(pin1); //온도 센서에 대한 OneWire 객체를 생성해준다.

float getTemp(){  //온도 측정 후 반환하는 함수. 오류가 날 경우 -1000을 반환한다.
 byte data[12];
 byte addr[8];
 if ( !ds.search(addr)) {
   ds.reset_search();
   return -1000;
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }
 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }
 ds.reset();
 ds.select(addr);
 ds.write(0x44,1);                                   
 byte present = ds.reset();
 ds.select(addr);  
 ds.write(0xBE); 
 
 for (int i = 0; i < 9; i++) { 
  data[i] = ds.read();                                                          
 }
 
 ds.reset_search(); 
 byte MSB = data[1];
 byte LSB = data[0];
 float tempRead = ((MSB << 8) | LSB); 
 float TemperatureSum = tempRead / 16; 
 return TemperatureSum;                                                                    
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getTemp());
  delay(1000);
}