#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "_config.h"
#include "uvLightFunctions.h"

// Set initial colors to 0
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

Adafruit_NeoPixel Pixels = Adafruit_NeoPixel(NUM_NEO_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setColor() {
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
}

void setPixels() {
  for(int pixel = 0; pixel < NUM_NEO_PIXELS; pixel++ ) {
    int showPixel = random(0, 10);
    
    if(showPixel <= 2) {
      setColor();
      Pixels.setPixelColor(pixel, Pixels.Color(redColor, greenColor, blueColor));
    } else {
	    Pixels.setPixelColor(pixel, Pixels.Color(0, 0, 0));
    } 
  }
  
  Pixels.show();
  int flashDelay = random(0, 100);
  delay(flashDelay);
}

void resetPixels() {
  for(int pixel = 0; pixel < NUM_NEO_PIXELS; pixel++ ) {
    Pixels.setPixelColor(pixel, Pixels.Color(0, 0, 0));
  }
  
  Pixels.show();
}

void lightning(int strobeCount, int endPause) {
  uvLightOn();
  
  for(int flash = 0; flash < strobeCount; flash++) {
    setPixels();
  }
  
  uvLightOff();
  resetPixels();
 
  delay(endPause);
}