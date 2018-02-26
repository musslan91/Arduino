#include <TimerOne.h>
#include <MsTimer2.h>
bool LED2up = true;
int LEDval = 0;
void flipLED2() {
  if(LED2up) {
    if(LEDval == 255) {
      LED2up = false;
      LEDval--;
    }
    else {
      LEDval++;
    }
  }
  else {
    if(LEDval == 0) {
      LED2up = true;
      LEDval++;
    }
    else {
      LEDval--;
    }
  }
  analogWrite(A2,LEDval);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  Timer2.setChannel1Mode(TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(1000);  // in microseconds
  Timer2.setCompare1(1);      // overflow might be small
  Timer2.attachCompare1Interrupt(flipLED2);
}
void loop() {
  // put your main code here, to run repeatedly:
  for (;;) {
    int ix;
    delay(100);
    for(ix = 0; ix < 256; ix++) {
      analogWrite(A2, ix);
      delay(1);
    }
    delay(100);
    for(ix = 255; ix >= 0; ix--) {
      analogWrite(A2, ix);
      delay(1);
    }
  }
}
