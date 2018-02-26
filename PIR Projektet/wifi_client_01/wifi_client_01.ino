#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h> 
#include <SPI.h>

byte ledPin = 16;               //D0

//char ssid[] = "Molk";               // SSID of your home WiFi
//char pass[] = "Molk0901";               // password of your home WiFi

//char ssid[] = "Stefan"; // http://192.168.43.55/
//char pass[] = "xvip7945";

//char ssid[] = "TN_24GHz_57CFAB"; // http://192.168.10.240/
//char pass[] = "322E14A1DB";

char ssid[] = "MarcusASUS"; // http://192.168.153.200/
char pass[] = "HestenMacke";

unsigned long askTimer = 0;
int PIRpin = 13; // D7 Nodemcu

IPAddress server=(192,168,43,48);       // the fix IP address of the server

WiFiClient client;
void setup() {
  
  pinMode(PIRpin, INPUT);
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}
void loop () {
  client.connect(server, 80);   // Connection to the server
  client.println("Now I'm lit! \r");
  String answer = client.readStringUntil('\r');
  
  if(digitalRead(PIRpin)==HIGH){ // ändrade red (lampan) till PIRpin
    if(answer.indexOf("Upptagen") != -1){
      client.println("Upptagen"); 
      Serial.println("Upptagen");
    }
  }
  if(digitalRead(PIRpin)==LOW){ // ändrade red (lampan) till PIRpin
    if(answer.indexOf("Ledig") != -1){
      client.println("Ledig");
      Serial.println("Ledig");
  }
  }
  client.flush();
  delay(2000);
}
