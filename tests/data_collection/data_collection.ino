/* 
 * Plantalytics
 *     Copyright (c) 2016 Sapphire Becker, Katy Brimm, Scott Ewing, 
 *       Matt Fraser, Kelly Ledford, Michael Limb, Steven Ngo, Eric Turley.
 *     This project is licensed under the MIT License.
 *     Please see the file LICENSE in this distribution for license terms.
 * Contact: plantalytics.capstone@gmail.com
 */

#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Sets baud
  Serial.begin(115200);
  // Sets temp & hum pin to input
  // int pin = 5;
  // pinMode(pin, INPUT);
  dht.begin();
}

void loop() {
  // Reads leaf wetness/resistance sensor
  int r = analogRead(A0);
  Serial.print("Leaf Wetness (kOhms): ");
  Serial.print(r);
  Serial.println("");

  // Reads humidity sensor
  float h = dht.readHumidity();
  Serial.print("Humidity (%): ");
  Serial.print(h);
  Serial.println("");

  // Reads temperature sensor
  float t = dht.readTemperature(true);
  Serial.print("Temperature (F): ");
  Serial.print(t);
  Serial.println("");

  delay(1000);
}

