#define bokstavtid 1000 //Tid för bokstäverna i segmenten.
#define siffertid 1500 //Tid för siffrorna i segmenten
#define pir 12 //Pir sensor

//Variabler
int a=7, b=6, c=4, d=11, e=10, f=8, g=9, dp=5;

//Här börjar jag definera funktioner
  int digital_av()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}

void digital_3(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}

void digital_2(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}

void digital_1(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}

void digital_A(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}

void digital_B(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}
void digital_C(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}
void digital_D(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}
void digital_E(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void digital_F(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void digital_G(void)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);  
  digitalWrite(c,LOW);  
  digitalWrite(d,LOW); 
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
}

void digital_H(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,HIGH);
}

void digital_I(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,HIGH);
}
void digital_J(void)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,HIGH);
}

void setup()
{
  pinMode(pir, INPUT);
//Räknare
int i;
for(i=4;i<=11;i++){
  pinMode(i, OUTPUT);
}
}

void loop()
{
  //Kallar på alla funktioner ifall PIR sensorn känner av något
  if(digitalRead(pir)==HIGH)
  {
    
  digital_3();
  delay(siffertid);
  digital_2();
  delay(siffertid);
  digital_1();
  delay(siffertid);

  
  digital_A();
  delay(bokstavtid);
  digital_B(); 
  delay(bokstavtid); 
  digital_C(); 
  delay(bokstavtid); 
  digital_D(); 
  delay(bokstavtid); 
  digital_E(); 
  delay(bokstavtid); 
  digital_F(); 
  delay(bokstavtid); 
  digital_G(); 
  delay(bokstavtid); 
  digital_H(); 
  delay(bokstavtid); 
  digital_I(); 
  delay(bokstavtid); 
  digital_J(); 
  delay(bokstavtid);
  }

// stannar segmenten ifall PIR sensorn inte känner av något.
  if(digitalRead(pir)==LOW){
   digital_av();
  }
}

