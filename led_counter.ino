int LED_PIN_OUT[] = {2, 3, 4, 5, 6, 7};
int LED_PIN_OUT_LEN = (int) (sizeof(LED_PIN_OUT)/sizeof(LED_PIN_OUT[0]));

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(LED_PIN_OUT_LEN);  
}
