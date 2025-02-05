#include <IRremote.h>
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define yellowLed 2
#define blueLed 3
#define redLed 4
#define greenLed 5

#define yellowBtn 0x1054
#define blueBtn 0x1055
#define redBtn 0x1056
#define greenBtn 0x1053
#define clearBtn 0x1075
void setup() {
  pinMode(yellowLed, OUTPUT);
  digitalWrite(yellowLed, 0);

  pinMode(blueLed, OUTPUT);
  digitalWrite(blueLed, 0);

  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, 0);

  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, 0);

  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == yellowBtn || results.value == 0x1854) {
      digitalWrite(yellowLed, !digitalRead(yellowLed));
    } 
    else if (results.value == redBtn || results.value == 0x1856) {
      digitalWrite(redLed, !digitalRead(redLed));
    } 
    else if (results.value == blueBtn || results.value == 0x1855) {
      digitalWrite(blueLed, !digitalRead(blueLed));
    } 
    else if (results.value == greenBtn || results.value == 0x1853) {
      digitalWrite(greenLed, !digitalRead(greenLed));
    }
    else if (results.value == clearBtn || results.value == 0x1875){
      digitalWrite(yellowLed, !digitalRead(yellowLed));
      digitalWrite(blueLed, !digitalRead(blueLed));
      digitalWrite(redLed, !digitalRead(redLed));
      digitalWrite(greenLed, !digitalRead(greenLed));
    }
    irrecv.resume();
  }
}