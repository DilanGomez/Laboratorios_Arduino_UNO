#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.print("LM35 Test");

  delay(1000);
}

void loop() {

  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperatura = voltage * 100;

  Serial.println("Voltage:");
  Serial.println(voltage);

  Serial.println("Temperatura:");
  Serial.println(temperatura);

  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(temperatura);
  lcd.print((char)223);
  lcd.print("C");

  delay(5000);
}