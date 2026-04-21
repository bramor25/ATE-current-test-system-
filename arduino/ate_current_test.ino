int relayPin = 8;
int buttonPin = 4;
int redLED = 11;
int greenLED = 12;

float sensitivity = 0.066;   // ACS712 sensitivty (30A Version)
float zeroOffset = 2.85;     // measured zero-current voltage

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);

  digitalWrite(relayPin, HIGH);   // relay OFF at startup (active LOW)
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {  // button pressed
    Serial.println("TEST START");

    digitalWrite(relayPin, LOW);  // turn relay ON
    delay(1000);                  // let current stabilize

    int sensorValue = analogRead(A0);
    float sensorVoltage = sensorValue * (5.0 / 1023.0);
    float current = (sensorVoltage - zeroOffset) / sensitivity;

    Serial.print("Current: ");
    Serial.println(current);

    if (current > 0.03 && current < 0.08) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      Serial.println("PASS");
    } else {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      Serial.println("FAIL");
    }

    delay(2000);                  // show result
    digitalWrite(relayPin, HIGH); // turn relay OFF

    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }

    delay(200); // debounce
  }
}
