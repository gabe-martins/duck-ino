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
  int scroll_timer = 2000;
  for (int i = 0; i <= clicked; i++){
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboard.delay(scroll_timer);
  }

  for (int i = 0; i <= clicked/2; i++){
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_UP);
    DigiKeyboard.delay(scroll_timer);
  }
}

void close_tab(int tab_num){
  DigiKeyboard.sendKeyStroke(tab_num, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(TIMER);
}

void select_tab(int tab){
  DigiKeyboard.sendKeyStroke(tab, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_F5);
  DigiKeyboard.delay(TIMER);
}

char* url_list[9] = {
  "https://g1.globo.com/",
  "https://www.uol.com.br/",
  "https://www.cnn.com/",
  "https://www.bbc.com/",
  "https://www.reuters.com/",
  "https://www.nytimes.com/",
  "https://www.theguardian.com/",
  "https://www.aljazeera.com/",
  "https://www.bloomberg.com/"
};

void loop() {
  start();

  open_browser();
  
  for (int i = 0; i < 2; i++){
    new_tab(url_list[i]);
  }

  DigiKeyboard.delay(TIMER);
  close_tab(30);

  while (true){
    for (int j = 30; j <= 38; j++){
      select_tab(j);
      scroll_page(50);
      DigiKeyboard.delay(60000);
    }
  }

  finish();
}
