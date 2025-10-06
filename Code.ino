#include <DHT.h>          // Include the DHT sensor library

#define DHTPIN 2          // Pin where the DHT11 data pin is connected
#define DHTTYPE DHT11     // Define sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

const int buzzerPin = 8;  // Pin where the buzzer module is connected

void setup() {
  Serial.begin(9600);     // Start serial communication for debugging
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  dht.begin();            // Initialize the DHT sensor
}

void loop() {
  // Wait a couple of seconds between readings
  delay(2000);

  // Read temperature as Celsius (the DHT library returns a float)
  float temperature = dht.readTemperature();

  // Check if the reading is valid
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Output temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Check the temperature and control the buzzer
  if (temperature > 25.0) {
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
  } else {
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
  }
}
