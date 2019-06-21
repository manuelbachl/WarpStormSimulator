#include <Arduino.h>
#include "_config.h"
#include "lightningFunctions.h"

long duration;
float distance;

void checkForViewer() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  // Calculate the distance. Use 343m/s as speed of sound
  distance = (duration * 0.034) / 2;
  
  if(distance < MAX_DISTANCE && distance > MIN_DISTANCE) {
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm");
    int strobeCount = random(5, 20);
    lightning(strobeCount, 1000);
  }

  delay(500); 
}