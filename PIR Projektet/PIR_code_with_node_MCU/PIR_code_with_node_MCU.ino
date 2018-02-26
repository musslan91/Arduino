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

//const char* ssid = "Molk"; // http://192.168.153.200/
//const char* password = "Molk0901";

//const char* ssid = "Stefan"; // http://192.168.43.55/
//const char* password = "xvip7945";

//const char* ssid = "TN_24GHz_57CFAB"; // http://192.168.10.240/
//const char* password = "322E14A1DB";

char ssid[] = "MarcusASUS"; // http://192.168.1.184/
char pass[] = "HestenMacke";

WiFiServer server(80);

// int red = 14;
int PIRpin = 13; // D7 Nodemcu

// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin LED_BUILTIN as an output.
  
  Serial.begin(9600); 
//  pinMode(red, OUTPUT);
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

// the loop function runs over and over again forever
void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);

 
  // Match the request

    if(digitalRead(PIRpin)==LOW)
    {
       (request.indexOf("Ledig") != -1);
    }
    else if(digitalRead(PIRpin)==HIGH)
    {
        (request.indexOf("Upptagen") != -1);
    }
  
  
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>"); 
  client.print("Toaletten är nu: ");

  if(PIRpin==HIGH) {
    client.print("Upptagen");
  } else if(PIRpin==LOW {
    client.print(" Ledig");
  }
  client.println("<br>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println(""); 
 
   client.flush();
 }
 
  /*
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  */
