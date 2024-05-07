// State class
//
// Pierre Rossel   2024-04-26  Initial version

void StateSurprised::enter()
{
  Serial.println(">>>>>>>>>>>>> StateSurprised.enter()");
}

State *StateSurprised::loop()
{
  // Blink all LEDs rapidly
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastTime > 100) // Blinking faster to express surprise
  {
    lastTime = currentTime;
    for(int i=0; i<strip.numPixels(); i++) {
      if((currentTime / 100) % 2 == 0) { // Blink on even intervals
        strip.setPixelColor(i, strip.Color(50, 50, 50)); // Set all LEDs to white
      } else {
        strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off all LEDs
      }
    }
    strip.show();
  }
  
  return NULL;
}

void StateSurprised::exit()
{
  Serial.println("<<<<<<<<<<<<< StateSurprised.exit()");
}


