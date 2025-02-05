#define gLED 2
#define yLED 3
#define rLED 4

void setup() {
  pinMode(rLED,OUTPUT);
  pinMode(yLED,OUTPUT);
  pinMode(gLED,OUTPUT);
}

void loop() {
  digitalWrite(rLED,1);
  delay(10000);
  digitalWrite(rLED,0);
  digitalWrite(yLED,1);
  delay(1000);
  digitalWrite(yLED,0);
  digitalWrite(gLED,1);
  delay(5000);
  digitalWrite(gLED,0);
  digitalWrite(yLED,1);
  delay(1000);
  digitalWrite(yLED,0);  
}
