#define A3 220
#define C4 262
#define G4 392

int melody[]={A3,C4,G4,A3,C4,G4,C4,C4,C4,C4,G4,G4};
int noteDurations[]={9,8,7,6,5,4,3,2,1,1,1,1,1,1,1};
const byte buzzerPin=10;

void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(10,OUTPUT);
}

void loop() {
 playTone(melody, noteDurations, sizeof(melody)/sizeof(int));
}

void playTone(int melody[], int noteDurations[], int length){
 for(int thisNote = 0; thisNote<length;thisNote++){
 int noteDuration = 1000/noteDurations[thisNote];  
 tone(buzzerPin, melody[thisNote],noteDuration);
 int pauseBetweenNotes = noteDuration*1.3;
 delay(pauseBetweenNotes);
 }
 noTone(buzzerPin);
}
