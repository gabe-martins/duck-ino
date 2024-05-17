const int LED_PIN = 13; // Define o pino onde o LED está conectado
const int TIMER = 1000;

// Função para ligar o LED
void ligarLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(TIMER);
}

// Função para desligar o LED
void desligarLED() {
  digitalWrite(LED_PIN, LOW);
  delay(TIMER);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  ligarLED();
  desligarLED();
}
