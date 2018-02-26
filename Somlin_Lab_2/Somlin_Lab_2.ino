int led=PB6,led_value=0;
void (*state)();
void setup() {
  state=state_up;
}

void state_up() {
  if(led_value<255) {
    led_value++;
    delay(4);
  } else {
    state=state_top;
  }
}

void state_top() {
  delay(1020);
  state=state_down;
}

void state_down() {
  if(led_value) {
    led_value--;
    delay(4);
  } else {
    state=state_bottom;
  }
}

void state_bottom() {
    delay(1020);
    state=state_up;
}

void loop() {
  state();
  analogWrite(led, led_value);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
