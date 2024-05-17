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

void open_browser(){
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.print("Edge");
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(TIMER);
}

void new_tab(String url){
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT);
  DigiKeyboard.println(url);
  DigiKeyboard.delay(TIMER);
}

void scroll_page(int clicked){
  for (int i = 0; i <= clicked; i++){
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboard.delay(TIMER);
  }

  for (int i = 0; i <= clicked/2; i++){
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_UP);
    DigiKeyboard.delay(TIMER);
  }
}

char* url_list[2] = {
  "https://g1.globo.com/",
  "https://www.uol.com.br/"
};

void loop() {
  start();
 
  open_browser();
  
  for (int i = 0; i < 2; i++){
    new_tab(url_list[i]);
    scroll_page(30);
  }
    
  finish();
}
