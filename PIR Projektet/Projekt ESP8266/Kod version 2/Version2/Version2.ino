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

const char* ssid = "Stefan"; // http://192.168.43.55/
const char* password = "xvip7945";

//const char* ssid = "TN_24GHz_57CFAB"; // http://192.168.10.240/
//const char* password = "322E14A1DB";

WiFiServer server(80);

int red = 14;
int PIRpin = 13; // D7 Nodemcu

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  Serial.begin(9600); 
  pinMode(red, OUTPUT);
  pinMode(PIRpin, INPUT);

    // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
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

   if(digitalRead(PIRpin)==LOW)//Detecting whether the body movement information
  {
    digitalWrite(red,LOW);//LED OFF
    Serial.println("Inget alarm !!!");
    //delay(500);
  }else
  {
    digitalWrite(red,HIGH);//LED ON
    Serial.println("Alarm !!!");
    //delay(500);
  }

 {
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
  client.flush();
 
  // Match the request

  int value = LOW; 
  
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(red, HIGH); // ändrade red (lapan) till PIRpin
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(red, LOW); // ändrade red (lampan) till PIRpin
    value = LOW;
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

  if(value == HIGH) {
    client.print("Upptagen");
  } else {
    client.print(" Ledig");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br/>");  
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println(""); 
 }
  }
  
  /*
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  */

/*
#include <SPI.h>
#include <Ethernet.h>

// network configuration. dns server, gateway and subnet are optional.

 // the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  

// the dns server ip
IPAddress dnServer(192, 168, 0, 1);
// the router's gateway address:
IPAddress gateway(192, 168, 0, 1);
// the subnet:
IPAddress subnet(255, 255, 255, 0);

//the IP address is dependent on your network
IPAddress ip(192, 168, 0, 2);

void setup() {
  Serial.begin(9600);

  // initialize the ethernet device
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  //print out the IP address
  Serial.print("IP = ");
  Serial.println(Ethernet.localIP());
}

void loop() {
}
*/
