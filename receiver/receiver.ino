/*
 * UIPEthernet EchoServer example.
 *
 * UIPEthernet is a TCP/IP stack that can be used with a enc28j60 based
 * Ethernet-shield.
 *
 * UIPEthernet uses the fine uIP stack by Adam Dunkels <adam@sics.se>
 *
 *      -----------------
 *
 * This Hello World example sets up a server at 192.168.1.6 on port 1000.
 * Telnet here to access the service.  The uIP stack will also respond to
 * pings to test if you have successfully established a TCP connection to
 * the Arduino.
 *
 * This example was based upon uIP hello-world by Adam Dunkels <adam@sics.se>
 * Ported to the Arduino IDE by Adam Nielsen <malvineous@shikadi.net>
 * Adaption to Enc28J60 by Norbert Truchsess <norbert.truchsess@t-online.de>
 */

#include <UIPEthernet.h>
#define LED_PIN 2

EthernetServer server = EthernetServer(3127);

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
  byte ip[] = { 10, 0, 0, 177 };

  Ethernet.begin(mac, ip);

  server.begin();
  Serial.println("Ready.");
}
unsigned long int prevMillis = 0;
boolean opened = false;
void loop()
{
  size_t size;

  if (EthernetClient client = server.available())
  {
    while ((size = client.available()) > 0)
    {
      uint8_t* data = (uint8_t*)malloc(size);
      size = client.read(data, size);
      Serial.print("Received ");
      Serial.print(size);
      Serial.println(" bytes of data.");
      if (strncmp("opened", (const char *)data, size) == 0) {
        Serial.println("Mailbox opened.");
        opened = true;
      } else if (strncmp("reset", (const char *)data, size) == 0) {
        Serial.println("Mailbox reset.");
        opened = false;
        digitalWrite(LED_PIN, LOW);
      } else { 
        Serial.print("Unknown message: ");
        Serial.write(data, size);
        Serial.println("");
      }
      free(data);
    }
    client.println("DATA from Server!");
    client.stop();
  }

  unsigned long int currentMillis = millis();
  if (opened) {
    if (currentMillis - prevMillis >= 1000) {
      if (digitalRead(LED_PIN) == HIGH) {
        digitalWrite(LED_PIN, LOW);
      } else {
        digitalWrite(LED_PIN, HIGH);
    }
    prevMillis = currentMillis;
  }
    
  }
}
