/*
 * A simple demostration of interrupts working on ESP32
 */
#define PIN_BUTTON 34
int numButtonPress = 0; //number of times the button has been pressed
uint32_t lastMillis = 0; //last count mark on ms

void IRAM_ATTR isrButton(){
  //x = millis() time in ms that has elapsed since the microcontroller was turned on
  if(millis() - lastMillis > 10){
    numButtonPress += 1;
    lastMillis = millis();
    } // This block if for debouncing due to button press
  }   //Save that function in the internal RAM memory

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT);

  attachInterrupt(PIN_BUTTON, isrButton, RISING);
}

void loop() {
  Serial.printf("El boton se ha presionado %u veces\n", numButtonPress);
}
