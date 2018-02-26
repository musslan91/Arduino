#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

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
//const char* ssid = "Molk"; // http://192.168.153.200/
//const char* password = "Molk0901";

//const char* ssid = "Stefan"; // http://192.168.43.55/
//const char* password = "xvip7945";

//const char* ssid = "TN_24GHz_57CFAB"; // http://192.168.10.240/
//const char* password = "322E14A1DB";

//char ssid[] = "MarcusASUS"; // http://192.168.1.184/
//char pass[] = "HestenMacke";

char ssid[] = "SlackNet"; // http://192.168.1.184/
char pass[] = "Slaskpatrask1234!";

WiFiServer server(80);

int PIRpin = 13; // D7 Nodemcu PIR - Sensor

// Setup funktionen körs en gång när man startar programmet och när man trycker på reset på Node MCU
void setup() {
  
  Serial.begin(9600); 
  pinMode(PIRpin, INPUT);

    // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 }

// Evighetsloopen.
void loop() {
  bool value = digitalRead(PIRpin);
  //Serial.println(value);

  // Kollar ifall en klient är ansluten.
  WiFiClient client = server.available();
  if (client){
  
  while(client.connected()){
      if(client.available())
    { 
        // Läs första raden för request.
        String request = client.readStringUntil('\r');
        Serial.println(request);
        client.flush();// Ger ut min webbserver data en gång.

        Serial.print("1");
           
        delay(1);

if(value == HIGH) {
          
client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<head>");
client.println("<body bgcolor='00cc00'>");//Röd bakgrund

client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");

client.println("<h1>");
client.println("<center>");
client.println("<font color='ffffff'>");// Text färg vit.
client.println("<font size = 48>Ledig</center></h1>");

client.println("</body>");
client.println("</html>");

Serial.print("2");


        }
        else if(value == LOW){
          
client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<head>");
client.println("<body bgcolor='00ff00'>");//Grön bakgrund

client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");
client.println("<br>");

client.println("<h1>");
client.println("<center>");
client.println("<font color='ffffff'>");// Text färg vit.
client.println("<font size = 48>Ledig</center></h1>");
    
client.println("</body>");
client.println("</html>");

Serial.print("3");

}

    }

  }
        Serial.println("Client disonnected");
        Serial.println("");
        client.stop();
        
  }
  return;
}

