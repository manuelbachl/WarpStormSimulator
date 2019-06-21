#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "_config.h"
#include "ultrasonicSensorFunctions.h"

Adafruit_NeoPixel Pixels = Adafruit_NeoPixel(NUM_NEO_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize pins as inputs and outputs
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(UV_CLUSTER_1_PIN, OUTPUT);
  pinMode(UV_CLUSTER_2_PIN, OUTPUT);
  pinMode(UV_CLUSTER_3_PIN, OUTPUT);
  // Start serial monitor
  Serial.begin(9600);
  // Initialize NeoPixel
  Pixels.begin();
  Pixels.show();
}

void loop() {
  checkForViewer(TRIGGER_PIN, ECHO_PIN, MIN_DISTANCE, MAX_DISTANCE);
}