#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <vector>

const int numLeds = 10;

const int minBrightness = 25;
const int maxBrightness = 95;
const int initialBrightness = minBrightness + ((maxBrightness - minBrightness) / 2);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, 6, NEO_GRB + NEO_KHZ800);
std::vector<uint32_t> ledColorArray{};

bool pulse(Adafruit_NeoPixel& stripObj, int minBrightness, int maxBrightness, int durationMilliSecs = 0, int stepTime = 0) {

  static int direction = 1;
  static int milliSecsLeft = durationMilliSecs;

  if (milliSecsLeft <= 0)
    return false;

  stripObj.setBrightness(stripObj.getBrightness() + (-3 + (direction*6)));
  if (stripObj.getBrightness() <= minBrightness && direction == 0)
    direction = 1;
  else if (stripObj.getBrightness() >= maxBrightness && direction == 1)
    direction = 0;

  stripObj.show();
  milliSecsLeft -= stepTime;

  return true;
}


void flare(Adafruit_NeoPixel& stripObj, int numLeds, int direction) {
  switch(direction) {
    case 0:
      for (int i = numLeds - 1; i > -1; i--) {
        stripObj.setPixelColor(i, Adafruit_NeoPixel::Color(0,0,0));
        stripObj.show();
        delay(50);
      }

    break;

    case 1:
      for(int i = 0; i < numLeds; i++) {
        strip.setPixelColor(i, ledColorArray.at(i));
        strip.show();
        delay(35); // Smallest delay is 30 ms!!!
    }
  }
  
}

void setup() {

  strip.begin();
  strip.setBrightness(initialBrightness);

  for (auto i = 0; i < numLeds; i++)
    ledColorArray.push_back(Adafruit_NeoPixel::Color(255 - i * (255/numLeds),0 + i * (255/numLeds) , 0));

  flare(strip, 10, 1);  
}

void loop() {
    if (pulse(strip, 25, 95, 1500, 50));
    else
      flare(strip, 10, 0);

    delay(50);
}


