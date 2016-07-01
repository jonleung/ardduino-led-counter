int LED_PIN_OUT[] = {3, 5, 6, 9, 10, 11}; // 3, 5, 6, 9, 10, 11 // 2,3,4,5,6,7
//                   ^ left most     ^
//                                   └ right most
int LED_PIN_OUT_LEN = (int) (sizeof(LED_PIN_OUT)/sizeof(LED_PIN_OUT[0]));

int numOn;

void setup() {
  Serial.begin(9600);
  int i;
  
  for (int i = 0; i<LED_PIN_OUT_LEN; i++) {
    int curPin = LED_PIN_OUT[i];
    pinMode(curPin, OUTPUT);
  }
  
  numOn = 0;
}



void loop() {  
  int curPin = LED_PIN_OUT[0];
  for(int i = 0; i<LED_PIN_OUT_LEN; i++) {
      int curPin = LED_PIN_OUT[i];
    if (numOn > i) {
      analogWrite(curPin, 255);  
    }
    else {
      analogWrite(curPin, 0);
    }
  }
  
  numOn++;
  if(numOn == LED_PIN_OUT_LEN+1) {
    numOn = 0;
  }
  
  delay(100);
}
