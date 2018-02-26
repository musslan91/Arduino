#include <Button.h>

const int RedGo = 9;
const int GreenGo = 8;
const int GreenCar = 10;
const int YellowCar = 11;
const int RedCar = 12;
Button btnAddWalk(2);  //Dekalera en knapp

void setup(){
  // put your setup code here, to run once:
pinMode(RedGo, OUTPUT);
pinMode(GreenGo, OUTPUT);
pinMode(GreenCar, OUTPUT);
pinMode(YellowCar, OUTPUT);
pinMode(RedCar, OUTPUT);

Serial.begin(9600); //Starta USB-port
btnAddWalk.begin(); //Starta knappen

digitalWrite(GreenCar, HIGH);
digitalWrite(RedGo, HIGH);
btnAddWalk.pressed(); //Clear flag//Om du släpper så kommer den inte göra någonting.
}
void loop(){
  // put your main code here, to run repeatedly:

  if(btnAddWalk.pressed()== true){
  Serial.println("pin is down");
  digitalWrite(GreenCar, HIGH);
  delay(1000);
  digitalWrite(GreenCar, LOW);
  delay(1000);
  digitalWrite(YellowCar, HIGH);
  delay(1000);
  digitalWrite(YellowCar, LOW);
  delay(1000);
  digitalWrite(RedCar, HIGH);
  delay(1000);
  digitalWrite(RedCar, LOW);
  delay(1000);
  digitalWrite(RedGo, HIGH);  
  delay(1000);
  digitalWrite(RedGo, LOW);
  delay(1000);
  digitalWrite(GreenGo, HIGH);
  }
  for(int i=0;i<=15;i++){
  digitalWrite(GreenGo, HIGH);
  delay(15);
  digitalWrite(GreenGo, LOW);
  delay(150);
  }
  
}

