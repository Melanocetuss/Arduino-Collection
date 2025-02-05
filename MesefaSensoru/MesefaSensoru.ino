#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define BUZZER 2
#define REDLED 3
#define YELLOWLED 4
#define GREENLED 5

int time;
int distance;
void setup() {

  pinMode(BUZZER, OUTPUT);

  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGGER_PIN, 1);
  delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN, 0);
  time = pulseIn(ECHO_PIN, 1);
  distance = (time / 2) / 28.5;

  if (distance <= 10) {
    digitalWrite(REDLED, 1);
    digitalWrite(BUZZER, 1);
    delay(50);
    digitalWrite(REDLED, 0);
    digitalWrite(BUZZER, 0);
    delay(100);
  }

  else if (distance <= 25) {
    digitalWrite(YELLOWLED, 1);
    digitalWrite(BUZZER, 1);
    delay(50);
    digitalWrite(YELLOWLED, 0);
    digitalWrite(BUZZER, 0);
    delay(250);
  }

  else{
    digitalWrite(GREENLED, 1);
    delay(50);
    digitalWrite(GREENLED, 0);
    delay(750);
  }
}
