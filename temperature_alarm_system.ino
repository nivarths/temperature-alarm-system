#include "DHT.h"

#define DHT11_PIN 2
#define DHTTYPE DHT11
#define BUZZER 8
#define LED_PIN 4
#define TEMPERATURE_THRESHOLD 27.00

// constructor for the sensor, args: pin number and type of sensor
DHT dht11(DHT11_PIN, DHT11);

void setup() 
{
  // initializing sensor and serial communication
  Serial.begin(9600);
  dht11.begin();
  delay(2000);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  float temperatureCelsius = dht11.readTemperature();
  
  if(isnan(temperatureCelsius))
  {
    Serial.println("Failed to detect temperature reading");
    delay(2000);  
    return;       
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(temperatureCelsius);
    Serial.println(" °C");
  }


  if(temperatureCelsius >= TEMPERATURE_THRESHOLD)
  {
    tone(BUZZER, 1000);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
  else
  {
    noTone(BUZZER);
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);

}
