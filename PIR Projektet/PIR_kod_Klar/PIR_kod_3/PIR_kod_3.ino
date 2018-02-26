#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//Definierar IO:n på Node MCU.
#define D0 1
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

//Olika SSID och password nätverk.
//const char* ssid = "Molk";
//const char* password = "Molk0901";

//const char* ssid = "Stefan";
//const char* password = "xvip7945";

//const char* ssid = "TN_24GHz_57CFAB";
//const char* password = "322E14A1DB";

char ssid[] = "Molk";
char pass[] = "Molk0901";

//char ssid[] = "SlackNet";
//char pass[] = "Slaskpatrask1234!";

WiFiServer server(80);

int PIRpin = 13; // D7 Nodemcu PIR sensor input.

//Strängar med våra olika HTML koder.
String gronhtml = "<!DOCTYPE html>\n<html>\n<head>\n<title>Page Title</title>\n</head>\n<body bgcolor='#00cc00'>\n<br><br><br><br><br><br><br><br><br><br>\n<br><br><br><br><br><br><br><br><br></br>\n<h1><center><font color='FFFFFF'><font size = 48>Ledig</center></h1>\n</body>\n</html>";
String rodhtml = "<!DOCTYPE html>\n<html>\n<head>\n<title>Page Title</title>\n</head>\n<body bgcolor='#ff0000'>\n<br><br><br><br><br><br><br><br><br><br>\n<br><br><br><br><br><br><br><br><br></br>\n<h1><center><font color='FFFFFF'><font size = 48>Upptagen</center></h1>\n</body>\n</html>";

//Variabler som kollar längden på våra HTML - strängar.
unsigned int HtmlGronLength = gronhtml.length();
unsigned int HtmlRodLength = rodhtml.length();

// Setup funktionen körs en gång när man startar programmet och när man trycker på reset på Node MCU.
void setup() {
  
  Serial.begin(9600); 
  pinMode(PIRpin, INPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  //Kollar ifall vi får Wifi om inte så kollar han igen.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Startar servern.
  server.begin();
  Serial.println("Server started");
 
  //Skriver ut våran ip adress vi fått i seriel monitor.
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 }

// Evighetsloopen.
void loop() {
  //Sparar värdet utav PIR sensorn input i en boolean.
  bool value = digitalRead(PIRpin);
  //Testkod för PIR sensorn.
  //Serial.println(value);

  // Kollar ifall en klient är ansluten.
  WiFiClient client = server.available();
  if (client){
  
  while(client.connected()){
      if(client.available()) { 
        
        // Läs första raden för request.
        String request = client.readStringUntil('\r');
        Serial.println(request);
        client.flush();// Ger ut min webbserver data en gång.

        Serial.print("1");
           
        delay(1);

        //String variabel för HTML koden.
        String responseString;

          if(value == HIGH) {

          //Om PIR sensorn känner av någonting/1:or så är det upptaget.
          responseString = String("HTTP/1.1 200 OK\r\n") +
          "Content-Type: text/html\r\n" +
          "Connection: close\r\n"+
          "Refresh: 1\r\n"+
          "Content-Length:"+ String(HtmlRodLength) + "\r\n"+
          "\r\n"+
          rodhtml
          +"\r\n";
          
          //Skriver ut våran hemsida i HTTP servern för Upptagen.
          client.println(responseString);
           
        }

            //Om PIR sensorn inte känner av någonting/0:or så är det ledigt.
            else if(value == LOW){
            responseString = String("HTTP/1.1 200 OK\r\n") +
            "Content-Type: text/html\r\n" +
            "Connection: close\r\n"+
            "Refresh: 1\r\n"+
            "Content-Length:"+ String(HtmlGronLength) + "\r\n"+
            "\r\n"+
            gronhtml
            +"\r\n";
            
          //Skriver ut våran hemsida i HTTP servern för Ledig.
            client.println(responseString);
          
         }

      }

    }
        //Visar ifall en klient har tappat anslutning och skriver ut att en klient har lämnat. 
        Serial.println("Client disonnected");
        Serial.println("");
        client.stop();
        
  }
  return;
}

