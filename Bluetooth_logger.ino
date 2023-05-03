//Send sensor readings via BT Serial
#include <Adafruit_BMP085.h>

#define LED_PIN 33
#define LDR_PIN 35
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

Adafruit_BMP085 bmp; //bmp object
BluetoothSerial SerialBT; //bluetooth object
char payload[80];

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  bmp.begin(0x77);
  SerialBT.begin("Axolote_Daniel"); //device name
  Serial.println("Bluetooth_Configurado");
}

void loop() {
 //Start payload for readings
 float pressure = bmp.readPressure();
 float temperature = bmp.readTemperature();
 int luminosity = analogRead(LDR_PIN);
 sprintf(payload, "%6.2f, %3.2f, %d", pressure, temperature, luminosity);
  
 digitalWrite(LED_PIN, HIGH);
  SerialBT.println(payload);
  Serial.println(payload);
 digitalWrite(LED_PIN, LOW);
  delay(500);
}
