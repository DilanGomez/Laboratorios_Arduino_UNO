#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ==========================
// CONFIGURACIÓN LCD
// ==========================
LiquidCrystal_I2C lcd(0x27, 16, 2);


// ==========================
// CONFIGURACIÓN DHT11
// ==========================
#define DHTPIN 2      // Pin de datos conectado al D2
#define DHTTYPE DHT11 // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

// ==========================
// SETUP
// ==========================
void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();

  // Mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("Temp y Humedad");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);

  lcd.clear();
}

// ==========================
// LOOP
// ==========================
void loop() {

  // Leer datos del DHT11
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Verificar errores
  if (isnan(humedad) || isnan(temperatura)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Revise DHT11");
    delay(2000);
    return;
  }

  // Mostrar temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.write(byte(223)); // simbolo °
  lcd.print("C");

  // Mostrar humedad
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humedad, 1);
  lcd.print("%");

  delay(2000);
}