void setup() {
  // put your setup code here, to run once:
  // Use GPIO 2 as an input.
  pinMode(2, INPUT);

  //Open serial connectionat 9600 Baud/Bd.
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Print switch status in serial monitor.
  Serial.print(digitalRead(2));

}
