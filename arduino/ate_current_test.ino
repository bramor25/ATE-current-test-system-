int relayPin = 8;
int buttonPin = 4;
int redLED = 11;
int greenLED = 12;

float sensitivity = 0.066;   // ACS712 sensitivity (30A version)
float zeroOffset = 2.85;     // no-current voltage (calibrated)

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  digitalWrite(relayPin, HIGH);   // relay OFF at startup
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {  // button pressed
    digitalWrite(relayPin, LOW);  // turn relay ON
    delay(1000);                  // let current stabilize

    int sensorValue = analogRead(A0);
    float sensorVoltage = sensorValue * (5.0 / 1023.0);
    float current = (sensorVoltage - zeroOffset) / sensitivity;

    bool passCondition = (current > 0.03 && current < 0.08);

    if (passCondition) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
    } else {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
    }

    // Clean format for Python: current,result
    Serial.print(current, 3);
    Serial.print(",");
    Serial.println(passCondition ? "PASS" : "FAIL");

    delay(2000);                  // show result
    digitalWrite(relayPin, HIGH); // turn relay OFF

    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }

    delay(200); // debounce
  }
