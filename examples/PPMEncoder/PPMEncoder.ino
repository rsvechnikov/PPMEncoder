#include "PPMEncoder.h"

#define OUTPUT_PIN 10

PPMEncoder<> ppmEncoder{};

ISR(TIMER1_COMPA_vect) {
    ppmEncoder.interrupt();
}

void setup() {
  ppmEncoder.begin(OUTPUT_PIN);
}

void loop() {

  // Min value
  ppmEncoder.setChannel(0, 500);
  ppmEncoder.setChannel(0, ppmEncoder.minValue);
  ppmEncoder.setChannelPercent(0, 0);

  // Max value
  ppmEncoder.setChannel(0, 2500);
  ppmEncoder.setChannel(0, ppmEncoder.maxValue);
  ppmEncoder.setChannelPercent(0, 100);
}
