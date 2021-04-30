#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT);

int pot1;
int pot2;

void setup() {
  Serial.begin(9600);           
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.clearDisplay();
}


void loop() {
  
  if(Serial.available()) {
    if(Serial.read() == 'A'){
      pot1 = Serial.parseInt();
    }
    else{
      pot2 = Serial.parseInt();
    }
  }
  
  Serial.println(String("Pot1: ") + pot1);
  Serial.println(String("Pot2: ") + pot2);


  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0); 
  oled.print("Pot. 1: ");
  oled.println(pot1);
  oled.print("Pot. 2: ");
  oled.println(pot2);
  oled.display();

 

 


}