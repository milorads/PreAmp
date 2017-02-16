#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(10, 9, 11, 13, 8, 12);
void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

  Serial.print(F("Text                     "));
  Serial.println(testText2());
  delay(3000);

  Serial.print(F("Rectangles (outline)     "));
  Serial.println(testRects(ILI9341_GREEN));
  delay(500);

  Serial.print(F("Rounded rects (outline)  "));
  Serial.println(testRoundRects());
  delay(500);
  
}

unsigned long testText2() {
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_ORANGE); 
  tft.setTextSize(1);
  tft.print("Vip-Proto Association");
  tft.setCursor(15, 50);
  
//  tft.setTextColor(ILI9341_RED);    
//  tft.setTextSize(7);
//  tft.println("105,00 db");

    tft.setTextColor(0x010cb2);    
  tft.setTextSize(6);
  tft.print("105,00");
  tft.setTextSize(4);
  tft.println(" db\n\n");

      tft.setTextColor(0x8bb201);    
  tft.setTextSize(3);
  tft.println("Volume controls +/-");

//    tft.setTextColor(ILI9341_DARKGREEN);    
//  tft.setTextSize(9);
//  tft.println("105,00 db");


    tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_ORANGE); 
  tft.setTextSize(1);
  tft.print("Vip-Proto Association");
  tft.setCursor(15, 50);
  
//  tft.setTextColor(ILI9341_RED);    
//  tft.setTextSize(7);
//  tft.println("105,00 db");

    tft.setTextColor(0x010cb2);    
  tft.setTextSize(6);
  tft.print("109,00");
  tft.setTextSize(4);
  tft.println(" db\n\n");

      tft.setTextColor(0x8bb201);    
  tft.setTextSize(3);
  tft.println("Volume controls +/-");
  return micros() - start;
}

unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(5);
  tft.println("Groop");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = tft.width()  / 2,
                cy = tft.height() / 2;

  tft.fillScreen(ILI9341_BLACK);
  n     = min(tft.width(), tft.height());
  start = micros();
  for(i=2; i<n; i+=6) {
    i2 = i / 2;
    tft.drawRect(cx-i2, cy-i2, i, i, color);
  }

  return micros() - start;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  w     = min(tft.width(), tft.height());
  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 0, 0));
  }

  return micros() - start;
}

void loop(void) {
  for(uint8_t rotation=0; rotation<4; rotation++) {
    tft.setRotation(rotation);
    testText();
    delay(1000);
  }
}

