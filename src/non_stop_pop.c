#include <DigiKeyboard.h>
#include <DigiKeyboardFr.h>

const int LED_PIN = 1; // Define o pino onde o LED está conectado
const int TIMER = 500; // Define um timer padrao

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
  DigiKeyboard.delay(500);
  DigiKeyboard.print("Edge");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
}

void new_tab(String url){
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT);
  DigiKeyboard.print(url);
  DigiKeyboard.delay(TIMER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(TIMER);
}

void scroll_page(int num_click){
  int scroll_timer = TIMER*4;

  if (num_click == 0){
    num_click = 10;
  }

  for (int i = 0; i <= num_click; i++){
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboard.delay(scroll_timer);
  }

  for (int i = 0; i <= num_click/2; i++){
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

const int list_size = 7;
const char* url_list[list_size] = {
  "https://g1.globo.com/",
  "https://www.uol.com.br/",
  "https://www.cnn.com/",
  "https://www.bbc.com/",
  "https://www.reuters.com/",
  "https://www.nytimes.com/",
  "https://www.bloomberg.com/"

};

void loop() {
  start();

  open_browser();
  
  for (int i = 0; i < list_size; i++){
    new_tab(url_list[i]);
  }

  DigiKeyboard.delay(TIMER);
  close_tab(30);

  int i = 0;
  int tab_count = list_size + 30;

  while (true){
    for (int j = 30; j <= tab_count; j++){
      select_tab(j);
      scroll_page(random(20, 30));
      
      if ( j % 2 == 0 && j != 30){
        DigiKeyboardFr.sendKeyStroke(43, MOD_ALT_LEFT);
        DigiKeyboardFr.delay(250);
        DigiKeyboardFr.sendKeyPress(MOD_ALT_LEFT);
        DigiKeyboardFr.delay(250);
        DigiKeyboardFr.sendKeyPress(0,0);

        DigiKeyboardFr.delay(30000);

        DigiKeyboardFr.sendKeyStroke(43, MOD_ALT_LEFT);
        DigiKeyboardFr.delay(250);
        DigiKeyboardFr.sendKeyPress(KEY_ARROW_LEFT);
        DigiKeyboardFr.delay(250);
        DigiKeyboardFr.sendKeyPress(0,0);
      }

      DigiKeyboard.delay(60000);

    }
  }

  finish();
}
