#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

bool displayReady = false;
void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Hello, ESP32-C3!");
}
void loop(){ 
    delay(1000);
    if(display.begin(SSD1306_SWITCHCAPVCC, 0x3C) && displayReady==false) { // Address 0x3D for 128x64
        Serial.println("LCD ready");
        //set default text
        display.setTextSize(1);      // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE); // Draw white text
        display.setCursor(0, 0);     // Start at top-left corner
        display.cp437(true);         // Use full 256 char 'Code Page 437' font
        displayReady = true;
    }else if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C) && displayReady==false){
        Serial.println(F("SSD1306 allocation failed"));
        return;
    }else{
        //LCD already ready
    }
    Serial.println("LCD text set");

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Hello World!"); 
    display.println("test 01");

    display.setCursor(0, 31);
    display.print("test 02");

    display.setCursor(0, 16);
    display.print("test 03");
    display.display();

    delay(2000);
}
