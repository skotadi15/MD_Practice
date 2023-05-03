/*
 * Simple demonstration of PWM and LED brightness
 */

#define PIN_LED 33 // PIN for PWM 
#define PIN_POT 26 //(potentiometer) PIN for ADC
#define PIN_LDR 35 //(LDR) PIN for ADC
int pwm_in = 0;
int ldr_in = 0;
void setup() {
 Serial.begin(115200); 
 pinMode(PIN_LED, OUTPUT);
}

void loop() {
  pwm_in = analogRead(PIN_POT);
  ldr_in = analogRead(PIN_LDR);
  Serial.println(pwm_in);
  Serial.println(ldr_in);
  //Control brightness via potentiometer
  //analogWrite(PIN_LED, pwm_in/16); //We need values because ADC periferial reads at 4095

  //Control brightness via LDR
  analogWrite(PIN_LED, (255-(ldr_in/16)));
  
  /*
   * Increasing and decreasing LED brightness
   * /
  
  /* for(int i=0; i<255; i++){
    analogWrite(PIN_LED, i);
    delay(10);
    } //Assigning the duty cycle value for PWM 0=0%, 255=100% (ideal)

  for(int i=255; i>0; i--){
    analogWrite(PIN_LED, i);
    delay(10);
    }
   */
     
  delay(100);
}
