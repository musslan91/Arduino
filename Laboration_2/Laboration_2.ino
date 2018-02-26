const int buttonPin = PC14;     // the number of the pushbutton pin
const int ledPin =  PA0;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = analogRead(buttonPin);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    analogWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    analogWrite(ledPin, LOW);

}
}



/*volatile int state = LOW; // must declare volatile, since it's
                          // modified within the blink() handler

void setup() {
    pinMode(BOARD_LED_PIN, OUTPUT);
    pinMode(0, INPUT);
    attachInterrupt(0, blink, CHANGE);
}

void loop() {
    digitalWrite(BOARD_LED_PIN, state);
}

void blink() {
    if (state == HIGH) {
        state = LOW;
    } else { // state must be LOW
        state = HIGH;
    }
}
*/
