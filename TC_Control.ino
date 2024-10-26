#include <max6675.h>

int soPin1 = 4;     // SO pin of MAX6675 #1
int csPin1 = 5;     // CS pin of MAX6675 #1
int sckPin1 = 6;    // SCK pin of MAX6675 #1
int soPin2 = 8;     // SO pin of MAX6675 #2
int csPin2 = 9;     // CS pin of MAX6675 #2
int sckPin2 = 10;    // SCK pin of MAX6675 #2
int relayPin = 7;  // Relay control pin
float upperTemp = 220.0;  // Temperature threshold in Celsius
float lowerTemp = 180.0;

MAX6675 thermocouple1(sckPin1, csPin1, soPin1);
MAX6675 thermocouple2(sckPin2, csPin2, soPin2);

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Start with relay off
}

void loop() {
  // Read temperature
  float temperature1 = thermocouple1.readCelsius();
  // Serial.print("Temperature #1: ");
  // Serial.print(temperature1);
  // Serial.println(" °C");
  float temperature2 = thermocouple2.readCelsius();
  // Serial.print("Temperature #2: ");
  // Serial.print(temperature2);
  // Serial.println(" °C");

  float avg_temp = (temperature1 + temperature2)/2;
  // Serial.print("Average Temperature");
  // Serial.print(avg_temp);
  // Serial.println(" °C");
  

  char onOrOff[10];
  // Control relay based on temperature threshold
  if (avg_temp >= upperTemp) {
    // Too hot turn off heater, turn relay off
    digitalWrite(relayPin, LOW);
    // Serial.println("TOO HOT turn relay off");
    sprintf(onOrOff, "OFF");
  } else if (avg_temp <= lowerTemp) {
    digitalWrite(relayPin, HIGH);
    // Serial.println("TOO COLD turn relay on");
    sprintf(onOrOff, "ON");
  }

  char str[256];
  sprintf(str, "%d, %d, %d, %d, %s", (int)(millis()/1000), (int)temperature1, (int)temperature2, (int)avg_temp, onOrOff);
  Serial.println(str);

  delay(1000); // Delay for 1 second
}
