/* 
 * Plantalytics
 *     Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, 
 *       Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.
 *     This project is licensed under the MIT License.
 *     Please see the file LICENSE in this distribution for license terms.
 * Contact: plantalytics.capstone@gmail.com
 */

// rf95_client.pde

#include <SPI.h>
#include <RH_RF95.h>
#include <stdlib.h>

#define FREQUENCY  915

#define LED           9 // Moteinos have LEDs on D9
#define FLASH_SS      8 // and FLASH SS on D8

#define NODEID        1    //unique for each node on same network
#define NETWORKID     100  //the same on all nodes that talk to each other

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
  randomSeed(analogRead(0)); //Generate seed based off of analog 0
}

void loop()
{
  //Switch to 5 minutes later
  //delay(60000); //60 seconds sleep
  
  Serial.println("Sending to rf95_server");

  //variables used in formatting:
  byte sendLen;
  char buffer[RH_RF95_MAX_MESSAGE_LEN]; //final byte array that gets passed to radio.send
  memset(buffer, '\0', sizeof(buffer));
  //Randomly generate data for MVP
  int temp = random(50,100); //range of 50 to 100
  int humi = random(100);    //max of 100
  int wet = random(20);      //max of 20

  sprintf(buffer,  "NETWORKID:%d NODEID:%d L:%d F:%d H:%d",
          NETWORKID,
          NODEID,
          wet, //getLeafWetness()
          temp,//getFahrenheitHundredths() 
          humi//getHumidityPercent()
          //Will later implement functions to get data from sensors
          );
  sendLen = strlen(buffer);  //get the length of buffer

  rf95.send((uint8_t *) buffer, sendLen); //finally pass the string (byte array) to the radio to send
  Serial.println(buffer);
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
