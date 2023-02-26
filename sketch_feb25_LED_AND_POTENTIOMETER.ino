//Usar potenciometro para iluminar LED

#define PIN_LED 33
#define PIN_POTENTIOMETER 26
#define analog_threshold 1000
void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POTENTIOMETER, INPUT);

  Serial.begin(115200);
}

void loop() {
  int analogVal = analogRead(PIN_POTENTIOMETER);
  if (analogVal>analog_threshold){
    digitalWrite(PIN_LED, HIGH);
  }
  else{
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}
