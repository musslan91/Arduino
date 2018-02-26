#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

//byte ledPin = 2;
char ssid[] = "MarcusASUS";               // SSID of your home WiFi
char pass[] = "HestenMacke";               // password of your home WiFi

//char ssid[] = "Stefan"; // http://192.168.43.55/
//char pass[] = "xvip7945";

//char ssid[] = "TN_24GHz_57CFAB"; // http://192.168.10.240/
//char pass[] = "322E14A1DB";

WiFiServer server(80);                    
IPAddress ip(192, 168, 153, 200);            // IP address of the server
IPAddress gateway(192,168,0,1);           // gateway of your network
IPAddress subnet(255,255,255,0); // subnet mask of your network

void setup() {
  Serial.print(WiFi.localIP());
  Serial.begin(115200);  // only for debug
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);      // connects to the WiFi router
  Serial.print(WiFi.localIP());  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("wwwww");
    delay(500);
  }
  server.begin();                         // starts the server
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());*/
  //pinMode(ledPin, OUTPUT);
}
void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      String request = client.readStringUntil('\r');
      Serial.println(request);

      // Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>"); 
  client.print("Toaletten är nu: ");

  if(request=="Upptagen"){
  client.print("Upptagen");
    }
  else if(request =="Ledig")
    {
    client.print("Ledigt");
    }else{
    client.print("Client disonnected");
    }
  Serial.println(""); 
  client.println("<br>");
  client.println("</html>");
  delay(1);
 }
      client.flush();
      
      /*digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("Hello Client! Are you there? "); Serial.println(request);
      client.flush();
      Serial.println("Now we can talk! \r"); // sends the answer to the client
      //client.println("Hi client! No, I am listening.\r");
      //digitalWrite(ledPin, HIGH);*/
    }
    client.stop();                // terminates the connection with the client
  }
