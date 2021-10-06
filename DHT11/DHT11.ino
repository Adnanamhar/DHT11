#define BLYNK_PRINT Serial

// Setting Library
#include <DHT.h>
#include <ESP8266WiFi.h> /* untuk modul wifi */
#include <BlynkSimpleEsp8266.h> /* file untuk blynk */

char auth[] = "BBFF-zMjqF1JdZmYu1Ob8IrZCcSmP6KQ4UC"; /* token yang diambil dari webiste ubidots */
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void SendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) { /* mengecek kondisi apabila suhu dan kelembapan tidak ada */
    Serial.println("Failed to read temp and humidity")
    return;
  }

  Blynk.virtualWrite(V1, t); /* setting virtual suhu di Blynk */
  Blynk.virtualWrite(V2, h); /* setting virtual kelembapan di Blynk */
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin /* sensor mulai membaca suhu dan kelembapan */
  timer.setInterval(1000, sendSensor); /* waktu untuk mengirimkan data setiap 1 detik sekali */
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run
  timer.run

}
