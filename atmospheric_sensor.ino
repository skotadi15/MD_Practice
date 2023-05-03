//Show in two columns: temperature and pressure
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp; //'bmp' as object
char payload[80]; //variable to store output string
void setup() {
  bmp.begin(0x77); //Assigning the address provided by the WireScan
  Serial.begin(115200);
}

void loop() {
  sprintf(payload, "%f, %f", bmp.readTemperature(), bmp.readPressure()); //string want to be formatted, format specficier, values to insert
  Serial.println(payload);
  delay(200);
}
