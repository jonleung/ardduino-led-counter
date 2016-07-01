int LED_PIN_OUT[] = {3, 5, 6, 9, 10, 11}; // 3, 5, 6, 9, 10, 11 // 2,3,4,5,6,7
//                   ^ left most     ^
//                                   └ right most
int LED_PIN_OUT_LEN = (int) (sizeof(LED_PIN_OUT)/sizeof(LED_PIN_OUT[0]));

#define ANALOG_IN A0
#define TOUCH_SENSOR_THRESHOLD 800
#define TOUCH_COUNTER_THRESHOLD 10000

int numOn;
int touchCounter;
int turnedOnOne;

void setup() {
  Serial.begin(9600);
  int i;
  
  for (int i = 0; i<LED_PIN_OUT_LEN; i++) {
    int curPin = LED_PIN_OUT[i];
    pinMode(curPin, OUTPUT);
  }
  
  numOn = 0;
  turnedOnOne = false;
}

void loop() {
  // Button Counter
  int touchSensorValue = analogRead(ANALOG_IN);
  if (touchSensorValue > TOUCH_SENSOR_THRESHOLD && turnedOnOne == false) {
    touchCounter++;
    int nextPin = LED_PIN_OUT[numOn];
    int brightness = 255 * (touchCounter + 2000) / TOUCH_COUNTER_THRESHOLD;
//    Serial.println(brightness)0
    analogWrite(nextPin, brightness);
  }
  else {
    if (touchCounter >= 0) {
      touchCounter -= 1000;
      if (touchCounter < 0) {
        touchCounter = 0;
        turnedOnOne = false;
      }
    }
  }

  if (touchCounter > TOUCH_COUNTER_THRESHOLD && turnedOnOne == false) {
    numOn++;
    if (numOn == LED_PIN_OUT_LEN+1) {
      numOn = 0;
    }
    
    touchCounter = 0;
    turnedOnOne = true;
  }
  
  // Turnon appropriate LEDs based on numOn
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
    
}
