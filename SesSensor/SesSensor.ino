#define led 2
#define sensor 3
int btn = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorData = digitalRead(sensor);
  if (sensorData == 1) {  
    if (btn == 0) {
      btn = 1;
    } 
    else {
      btn = 0;
    }
  }
  delay(10);
  digitalWrite(led, btn);
}
