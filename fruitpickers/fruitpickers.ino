  
  //Declare global variables for total number of fruits
  int fruitsAlice;
  int fruitsBob;
  
  int littleBasketSize = 25;
  int bigBasketSize = 40;
  
  int littleBasketAlice = 20;
  int bigBasketAlice = 15;
  int littleBasketBob = 17;
  int bigBasketBob = 17;
  
  void setup() {
    // put your setup code here, to run once:
    // Open serial connection a 9600Bd/Baud.
    Serial.begin(9600);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
  // Count total number of apples.
  // Skriver ut i seriel monitor hur många äpplen bob och alice har plockat. Repeterand med 5000ms delay/5s.
  
  fruitsAlice = littleBasketAlice * littleBasketSize + bigBasketAlice * bigBasketSize;
  fruitsBob = littleBasketBob * littleBasketSize + bigBasketBob * bigBasketSize;
  
  Serial.print("Alice has picked: ");
  Serial.print(fruitsAlice);
  Serial.println(" apples");
  Serial.print("Bob has picked: ");
  Serial.print(fruitsBob);
  Serial.println(" apples");
  
  //Add delay.
  delay(5000);
}
