/*

 This example connects to a WEP-encrypted Wifi network.
 Then it prints the MAC address of the Wifi Duo
 the IP address obtained, and other network details.

 If you use 40-bit WEP, you need a key that is 10 characters long,
 and the characters must be hexadecimal (0-9 or A-F).
 e.g.  for 40-bit, ABBADEAF01 will work, but ABBADEAF won't work
 (too short) and ABBAISDEAF won't work (I and S are not
 hexadecimal characters).

 For 128-bit, you need a string that is 26 characters long.
 D0D0DEADF00DABBADEAFBEADED will work because it's 26 characters,
 all in the 0-9, A-F range.

 Circuit:
 * DUO WiFi Board 
 
 
 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 modified 2 July 2014
 by Noah Luskey
 modified 1 DEC 2015
 by Jackson Lv

 */
 
#include "Arduino.h"
#include "spark_wiring_wifi.h"
#include "spark_wiring_client.h"

// your network name also called SSID
char ssid[] = "Duo";
// your network password (key)
char password[] = "password";

//SYSTEM_MODE(AUTOMATIC);
SYSTEM_MODE(MANUAL);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid);
  
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.on();
  WiFi.setCredentials(ssid,password,WEP, WLAN_CIPHER_NOT_SET);
  WiFi.connect();
  
  while ( WiFi.connecting()) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");

  printCurrentNet();
  printWifiData();
}

void loop() {
  // check the network connection once every 10 seconds:
  delay(10000);
  printCurrentNet();
}

void printWifiData() {
  // print your WiFi IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
    
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  Serial.print("Encryption Type:");
  Serial.println(WEP, HEX);
  Serial.println();
}


