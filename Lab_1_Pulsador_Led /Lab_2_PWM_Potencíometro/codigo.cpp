int ledPin = 10;
int potPin = A2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potVal = analogRead(potPin);
  int light = map(potVal, 0, 1023, 0, 255);

  Serial.print("Pot = ");
  Serial.print(potVal);

  Serial.print("  Brillo = ");
  Serial.println(light);

  analogWrite(ledPin, light);

  delay(200);
}