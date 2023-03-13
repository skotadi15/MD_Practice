
#include <WiFi.h>
#include <Credentials.h>
/*
 * Do not include this:
const char* SSID  = "" //This must be changed
const char* PASSWORD = "" //This must be changed
Use your Credentials.h file on library
*/

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
