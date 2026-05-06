#define led1 2
#define led2 4

TaskHandle_t Task1;
TaskHandle_t Task2;

void task1(void *pvParameters) {
    for(;;){
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      delay(1000);
    } 
}

void task2(void *pvParameters) {
    for(;;){
      digitalWrite(led2, HIGH);
      delay(700);
      digitalWrite(led2, LOW);
      delay(700);
    }
}


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // put your setup code here, to run once:
  xTaskCreatePinnedToCore(
    task1,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    0,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0
  );

  xTaskCreatePinnedToCore(
    task2,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    0
  );
}

void loop() {
  // put your main code here, to run repeatedly:

}
