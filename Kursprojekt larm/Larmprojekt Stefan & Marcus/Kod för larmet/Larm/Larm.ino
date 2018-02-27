#include <Keypad.h>
#include <SoftwareSerial.h>

int ledgreen=13; // Grön lampa
int msensor1=12; // Rörelsesensor
int ledred=11; // Röd lampa
int sound = 10; // Siren

char password_on[] = {'1','2','3','4','A'}; //Koden för att aktivera larmet
char password_off[] = {'1','2','3','4','D'}; //Koden för att inaktivera larmet
char keypressed[5];// Hur stort fältet för pressade pins på keypaden
bool kod_on_ok = true;// Boolean för om kod är okej för att starta en funktion
bool alarm_activated = false;//Boolean som kollar vilken av de senaste koder du skrivit in

int kodsiffra = 0; //Talar om vilken plats i password-arrayerna vi befinner oss på

/* --------------- KOD FÖR ATT INITIERA KEYPAD ----------------------*/

const byte ROWS = 4; //fyra rader
const byte COLS = 4; //fyra kolumner
//Definerar keypads värden på knapparna i en två dimensionellt fält.
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // ORANGE, BLÅ, BLÅ ,BLÅ //färger på kablarna
byte colPins[COLS] = {5, 4, 3, 2}; // GRÖN, GRÖN, GRÖN, GUL // färger på kablarna
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
/* ____________________________________________________________*/

/* Vår sensor är aktiv */
void alarm_on()
{
Serial.println("ALARM PÅ");
if(digitalRead(msensor1)==HIGH){
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledred, HIGH); // Senare ska detta vara 20 sekunder och GSM före.
    digitalWrite(sound, HIGH);
} 
else
{
    digitalWrite(ledred, LOW);
    digitalWrite(sound, LOW);
  }
}   

/* Vår sensor är inaktiv */
void alarm_off()
{
Serial.println("ALARM AV");
digitalWrite(ledgreen, HIGH);
digitalWrite(ledred, LOW);
digitalWrite(sound, LOW);
}

void setup() {
  
  Serial.begin(9600);
  pinMode(ledgreen,OUTPUT);
  pinMode(ledred,OUTPUT);
  pinMode(msensor1,INPUT); 
  pinMode(sound,OUTPUT);
}

void loop() {
  
char customKey = customKeypad.getKey();

  if (customKey) //Tittar och ser vad du trycker på pin knapparna.
  {
    keypressed[kodsiffra] = customKey;//Med villkor att kodsiffran ökar så länge som du inte trycker över 5 knappar.
      kodsiffra++;
     if (kodsiffra >= 5)//Här bestämmer den max antal knappar du kan trycka.
      {
  
        bool kod_on_ok = true;       
       //Kollar siffra för siffra och ser om den överensstämmer med vår kod för aktivering.
        for (int i = 0; i <5; i++)
        {
          if (keypressed[i] != password_on[i])
            kod_on_ok = false;
        }

        /*Om on - koden är sann så kallar han på alarm_on funktionen.*/
        if (kod_on_ok == true){
           // alarm_on();//Kallar på alarm_on funktion.
           alarm_activated = true;
        }

        bool kod_off_ok = true;       
       //Kollar siffra för siffra och ser om den överensstämmer med vår kod för deaktivering
          for (int i = 0; i <5; i++)
          {
            if (keypressed[i] != password_off[i])
               kod_off_ok = false;
          }

        /*Om deaktiveringskoden är sann*/
              if (kod_off_ok == true)
             {
                //alarm_off();//Kallar på alarm_off funktionen.
                alarm_activated = false;
             }
        
        /*Kod för hantering utav fel inmatade pins. Om båda är falska så
        så kommer den att säga det är fel och även blinka rött att du tryckt in fel kod
        för att enkelt se det.*/
        kodsiffra = 0;
          if ((kod_on_ok == false) && (kod_off_ok == false))
          {
             Serial.println("FEL KOD!");
             digitalWrite(ledred , HIGH);
             delay(1000);
             digitalWrite(ledred , LOW);
             delay(1000);
             digitalWrite(ledred , HIGH);
             delay(1000);
             digitalWrite(ledred , LOW);
             delay(1000);
             digitalWrite(ledred , HIGH);
             delay(1000);
             digitalWrite(ledred , LOW); 
        }
     }
  }
     if(alarm_activated==true)//Om den är true så sparas allt innan i loopen och ser ifall den var sann senast så kallar den på alarm_on() funktionen
    {
    alarm_on();
  }
    else
       {
        alarm_off();//Annars kallar han i loopen alarm_off funktionen här.
  }
}
