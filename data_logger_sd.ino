//Loguear informacion del sensor BMP y LDR

#include "SD.h"
#include "SPI.h"
#include "FS.h"
#include <Adafruit_BMP085.h>

#define LED_PIN 33
#define LDR_PIN 35

File readings;

Adafruit_BMP085 bmp;

char payload[80];

void setup() {
  pinMode(LED_PIN, OUTPUT);
  bmp.begin(0x77);
  Serial.begin(115200);
  if (!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
    }
}

void loop() {
 //Iniciar el payload de lecturas de los sensores
 float pressure = bmp.readPressure();
 float temperature = bmp.readTemperature();
 int luminosity = analogRead(LDR_PIN);
 sprintf(payload, "%6.2f, %3.2f, %d", pressure, temperature, luminosity);
  
 digitalWrite(LED_PIN, HIGH); 
  readings = SD.open("/lecturas_sensor.csv", FILE_APPEND);
  readings.println(payload);
  readings.close();
  Serial.println(payload);
 digitalWrite(LED_PIN, LOW);
  delay(500);
}
