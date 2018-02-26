    #include <Button.h>
    // Använder 220 resistorer i den här uppgiften.


    // Deklarera variabel
    const int RedGo = 9;
    const int GreenGo = 8;
    const int GreenCar = 10;
    const int YellowCar = 11;
    const int RedCar = 12;
    const int Sound = 3;


    // Dekalera en knapp
    Button btnAddWalk(2); 


    void setup() 
    {
      
    // Trafikljus för bilar
    pinMode(RedGo, OUTPUT);
    pinMode(GreenGo, OUTPUT);
    pinMode(GreenCar, OUTPUT);


    // Trafikljus för Gående
    pinMode(YellowCar, OUTPUT);
    pinMode(RedCar, OUTPUT);


    // Startar Ljud.
    pinMode(Sound,OUTPUT);


    // Starta USB-port
    Serial.begin(9600);


    // Starta knappen
    btnAddWalk.begin();


    // Clear flag
    btnAddWalk.pressed(); 


    // Ska alltid lysa från början (Alltid vara på)
    digitalWrite(GreenCar, HIGH);
    digitalWrite(RedGo, HIGH);
    
    }
    void loop() {


    if(btnAddWalk.pressed())
    {  


    // Testar att knappen fungerar  
    Serial.println("pin is down");


    // Går från grönt till rött (trafikljus för bil)
    digitalWrite(GreenCar, LOW);
    delay(1200);
    digitalWrite(YellowCar, HIGH);
    delay(1200);
    digitalWrite(YellowCar, LOW);
    digitalWrite(RedCar, HIGH);
    delay(1200);


    // Släcker den röda ljuset och blir sedan grönt för trafikanterna.
    digitalWrite(RedGo, HIGH);  
    delay(1200);
    digitalWrite(RedGo, LOW);
    digitalWrite(GreenGo, HIGH);


    // Skapar en paus på 4 sekunder så de gående kan gå över säkert.
    delay(4000);
    
    // Blinkande grönt ljus för varna att de snart ska slå om till rött.
    for( int i = 0; i <= 4 ; i++ )
    {
    digitalWrite(GreenGo, HIGH);
    delay(300);
    digitalWrite(GreenGo, LOW);
    delay(300);
    tone(Sound,196,10);
    }


    // Tänder röd och gul trafikljus samtidigt.
    digitalWrite(RedGo , HIGH);
    delay(3000);
    digitalWrite(YellowCar , HIGH);
    delay(2000);  


    // Trafikljuset för bilar går från Röd till grönt fast sken.
    delay(300);
    digitalWrite(RedCar , LOW);
    digitalWrite(YellowCar , LOW);
    delay(300);
    digitalWrite(GreenCar , HIGH);
    }
    }
