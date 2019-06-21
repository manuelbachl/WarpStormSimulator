#include <Arduino.h>
#include "_config.h"

void uvLightOn() {
  digitalWrite(UV_CLUSTER_1_PIN, HIGH);
  digitalWrite(UV_CLUSTER_2_PIN, HIGH);
  digitalWrite(UV_CLUSTER_3_PIN, HIGH);
}

void uvLightOff() {
  digitalWrite(UV_CLUSTER_1_PIN, LOW);
  digitalWrite(UV_CLUSTER_2_PIN, LOW);
  digitalWrite(UV_CLUSTER_3_PIN, LOW);
}