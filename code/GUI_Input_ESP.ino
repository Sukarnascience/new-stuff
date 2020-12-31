/*
 * We will Use this board as Hotspot as well as a WebServer
 * Made By:- Sukarna Jana
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "Page.h"

const char* ssid = "LocalNetwork";
const char* pass = "sukarna jana";

ESP8266WebServer server(80);

int Mode = 1;
String ST0;
String ST1;
String ST2;
String PageD="";

void setup(void)
{
  Serial.begin(115200);
  
   WiFi.begin(ssid,pass);

   Serial.print("Connecting");
   while(WiFi.status() != WL_CONNECTED)
   {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("Cunnected");
   Serial.print("IP Address:-");
   Serial.println(WiFi.localIP());
  
   server.on("/",MainPG);
   server.on("/Read1/10",S1);
   server.on("/Read1/11",S2);
   server.on("/Read1/20",S3);
   server.on("/Read1/21",S4);
   server.begin();
 
}

void MainPG()
{
  String pg = MG;
  server.send(200,"text/html",pg);
}

void S1()
{
  Serial.println("Swetch 1 ON");
  server.send(200,"text/plain","Switch 1 ON");
  ST1="Switch 1 is ON";
}
void S2()
{
  Serial.println("Swetch 1 OFF");
  server.send(200,"text/plain","Switch 1 OFF");
  ST1="Switch 1 is OFF";
}
void S3()
{
  Serial.println("Swetch 2 ON");
  server.send(200,"text/plain","Switch 2 ON");
  ST2="Switch 2 is ON";
}
void S4()
{
  Serial.println("Swetch 2 OFF");
  server.send(200,"text/plain","Switch 2 OFF");
  ST2="Switch 2 is OFF";
}

void Data()
{
  Serial.println("Called by my client");
  int Connection = WiFi.softAPgetStationNum();
  PageD+=("<!DOCTYPE html><html>");
  PageD+=("<title>Data Back From Server</title>");
  PageD+=("<body style=\"background-color:black\"><h1 style=\"color:white; font-family:Comic Sans MS\">Data Return From<br>the server side</h1>");
  PageD+=("<hr>");
  PageD+=("<p style=\"color:orange; font-family:Comic Sans MS\">");
  PageD+=("IP Adress:-"+String(WiFi.localIP())+"<br>");
  PageD+=("No. of cunnection:-"+String(Connection)+"<br>");
  PageD+=("Switch 1 State:-"+ST1+"<br>");
  PageD+=("Switch 2 State:-"+ST2+"<br>");
  PageD+=("</p>");
  PageD+=("</body></html>");
  server.send(200,"text/html",PageD);
}

void loop(void)
{
  server.handleClient();
}
