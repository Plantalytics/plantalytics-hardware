// rf95_server.pde

#include <SPI.h>
#include <RH_RF95.h>

#define FREQUENCY  915

// Singleton instance of the radio driver
#define LED           9 // Moteinos have LEDs on D9
#define FLASH_SS      8 // and FLASH SS on D8

RH_RF95 rf95;

void setup() 
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  if (!rf95.init())
    Serial.println("init failed");
  else { Serial.print("init OK - "); Serial.print(FREQUENCY); Serial.print("mhz"); }
  //Display frequency
  rf95.setFrequency(FREQUENCY);
}

void loop()
{
  if (rf95.available())
  {
    // Should be a message for us now   
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len))
    {
      digitalWrite(LED, HIGH);
//      RH_RF95::printBuffer("request: ", buf, len);
      Serial.print("got request: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
      
      // Send a reply
      uint8_t data[] = "And hello back to you";
      rf95.send(data, sizeof(data));
      rf95.waitPacketSent();
      Serial.println("Sent a reply");
      digitalWrite(LED, LOW);
    }
    else
    {
      Serial.println("recv failed");
    }
  }
}
