#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <vector>

const int numLeds = 30;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, 27, NEO_GRB + NEO_KHZ800);
std::vector<uint32_t> ledColorArray{};

// the setup function runs once when you press reset or power the board
void setup() {

  strip.begin();
  strip.setBrightness(50);
  strip.show();

  for (auto i = 0; i < numLeds; i++) {
    ledColorArray.push_back(Adafruit_NeoPixel::Color(255 - i * (255/numLeds),0 + i * (255/numLeds) , 0));
  }
}

void loop() {

  

  for (int i = 0; i < numLeds; i++)
    strip.setPixelColor(i, 0, 0, 0);

  strip.show();

  for(int i = 0; i < numLeds; i++) {
    strip.setPixelColor(i, ledColorArray.at(i));
    strip.show();
    // Smallest delay is 30 ms!!!
    delay(35);

  }
    delay(2000);
}