#include <DHT.h>
#include <math.h>

#define DHT_PIN 10
#define DHT_TYPE DHT22   // Define o tipo de sensor (DHT11 ou DHT22)
DHT dht(DHT_PIN, DHT_TYPE);

float lerDHT(){
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    float umidade = -999;
    float temperatura = -999;
  }
  return temperatura, umidade;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperatura, umidade = lerDHT();

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print("%");
  Serial.print(" | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(1000);
}