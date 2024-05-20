#include <DigiKeyboard.h>
#include <DigiKeyboardFr.h>

const int LED_PIN = 1; // Define o pino onde o LED está conectado
const int TIMER = 1500; // Define um timer padrao

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void start(){
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  digitalWrite(LED_PIN, HIGH); // LED on <--> Action start
}

void finish(){
  digitalWrite(LED_PIN, LOW); // LED off <--> Action end
  for(;;){ /*Infinite loop to disconnect device*/ }
}

void open_browser(){
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.print("Edge");
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(TIMER);
}

void loop() {
  start();
  open_browser();
  DigiKeyboard.println(F("https://fakeupdate.net/win10ue/"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  finish();
}