int BLUE = 11; // 13번 핀에 LED를 연결하였다는 뜻이다.
int RED = 13;
int GREEN = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE, OUTPUT); // 13번 핀을 출력으로 설정
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // 하나씩 켠다.
  digitalWrite(RED, HIGH); // 13번 핀에 하이값을 준다.
  delay(1000); // 지연 : 500ms
  digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(BLUE, HIGH);
  delay(1000);

  // 모든 LED를 끈다.
  digitalWrite(RED, LOW); 
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(1000);

  // 모든 LED를 다시 켠다.
  digitalWrite(RED, HIGH); 
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(1000);

  // 모든 LED를 다시 끈다.
  digitalWrite(RED, LOW); 
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(1000);
}

// digitalWrite : 핀 번호와 HIGH, LOW 값을 받아 신호를 출력한다.
// HIGH = 5v
// LOW = 0v

// 128p는 칩이 더 크고 핀이 더욱 많다.
// USB 전원 : 5V
// PIN : 칩의 특성 - 40mA로 제한이 걸려버린다. 그라운드는 200mA로 제한됨