#include <ESP8266WiFi.h>

const char* ssid = "Wi-Fi Name";    
const char* password = "Password";   

int LED = 2; //D4)

WiFiServer server(80);

void setup()

{
  Serial.begin(115200); 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(255);
    Serial.print(".");
  }
  Serial.println("WiFi network is connected"); 
  server.begin();  
  Serial.println("Server has started");
  Serial.print("Your IP Address of network is: "); 
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()

{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 

  int value = LOW;
  if(request.indexOf("/user=ConnectWorld&passwd=123456/1/1") != -1)
  {
    digitalWrite(LED, HIGH); 
    value = HIGH;
  }

  if(request.indexOf("/user=ConnectWorld&passwd=123456/1/0") != -1)
  {
    digitalWrite(LED, LOW);
    value = LOW;
  }

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" CONTROL LED: ");
  if(value == HIGH)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
