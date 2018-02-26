void setup(){
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(10, OUTPUT);
}
void loop(){

  //put your main code here, to run repeatedly:
  static int i = 1;//Static int som blir 1 första gågngen finktionen körs.
  Serial.print("mitt forsta program! Loop nr: ");
  Serial.println(i++, DEC);//Räknar upp loopvariabeln.
    digitalWrite(10,LOW);
 delay(10*i);
  digitalWrite(10,1);
  digitalWrite(10,HIGH);
  //digitalWrite(10,HIGH);
delay(12*i);
  
}

