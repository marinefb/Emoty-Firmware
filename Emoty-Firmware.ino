#include <Arduino.h>

#include <Adafruit_NeoPixel.h>

const int stripPin = A5;

Adafruit_NeoPixel strip(37, stripPin, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

// uint8_t rgb_values[3];

// pin numbers
#define BTN_IDLE 2
#define BTN_HAPPY 3
#define BTN_SAD 4

#include "AppStates.h"

StateMachine sm;

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 4000)
    ;
  Serial.println("Started");

  // NeoPixel strip initialization
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();  // Turn OFF all pixels ASAP

  pinMode(stripPin, OUTPUT);
  digitalWrite(stripPin, LOW);

  pinMode(BTN_IDLE, INPUT_PULLUP);
  pinMode(BTN_HAPPY, INPUT_PULLUP);
  pinMode(BTN_SAD, INPUT_PULLUP);
  // TODO: les autres

  sm.changeState(new StateIdle());
}

void loop()
{

  State *newState = checkSerial();
  if (newState != NULL)
  {
    sm.changeState(newState);
  }

  checkButtons();

  sm.loop();
}

State *checkSerial()
{
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    switch (c)
    {
    case '0':
      return new StateIdle();
    case '1':
      return new StateHappy();
    case '2':
      return new StateSad();
    case '3':
      return new StateSurprised();
    case '4':
      return new StateDisgusted();
    case '5':
      return new StateScared();
    case '6':
      return new StateAngry();
    }
  }

  return NULL;
}

void checkButtons()
{
  if (sm.getState()->getStateTime() > 1000)
  {
    if (digitalRead(BTN_IDLE) == LOW)
    {
      sm.changeState(new StateIdle());
      delay(100);
    }
    if (digitalRead(BTN_HAPPY) == LOW)
    {
      sm.changeState(new StateHappy());
      delay(100);
    }
    if (digitalRead(BTN_SAD) == LOW)
    {
      sm.changeState(new StateSad());
      delay(100);
    }
  }
}