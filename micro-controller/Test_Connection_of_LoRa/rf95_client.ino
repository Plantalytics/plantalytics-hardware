// rf95_client.pde

#include <SPI.h>
#include <RH_RF95.h>

#define FREQUENCY  915

#define LED           9 // Moteinos have LEDs on D9
#define FLASH_SS      8 // and FLASH SS on D8


// Singleton instance of the radio driver
RH_RF95 rf95;             

void setup() 
{
  Serial.begin(115200);
  if (!rf95.init())
    Serial.println("init failed");
  else { Serial.print("init OK - "); Serial.print(FREQUENCY); Serial.print("mhz"); }
  rf95.setFrequency(FREQUENCY);
  //rf95.setFrequency(915);
}

void loop()
{
  Serial.println("Sending to rf95_server");
  // Send a message to rf95_server
  uint8_t data[] = "Hello World!";
  rf95.send(data, sizeof(data));
  
  rf95.waitPacketSent();
  // Now wait for a reply
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  if (rf95.waitAvailableTimeout(3000))
  { 
    // Should be a reply message for us now   
    if (rf95.recv(buf, &len))
   {
      Serial.print("got reply: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);    
    }
    else
    {
      Serial.println("recv failed");
    }
  }
  else
  {
    Serial.println("No reply, is rf95_server running?");
  }
  Blink(LED,3);
  delay(200);
}

void Blink(byte PIN, int DELAY_MS)
{
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN,HIGH);
  delay(DELAY_MS);
  digitalWrite(PIN,LOW);
}
