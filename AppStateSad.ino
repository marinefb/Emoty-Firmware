// State class
//
// Pierre Rossel   2024-04-26  Initial version

void StateSad::enter()
{
  Serial.println(">>>>>>>>>>>>> StateSad.enter()");
}

State *StateSad::loop()
{
  // light one led at a time, in a sad pattern
  static unsigned long lastTime = 0;
  static int led = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastTime > 500)
  {
    lastTime = currentTime;
    strip.clear();
    strip.setPixelColor(led, strip.Color(0, 0, 128));
    strip.show();
    led = (led + 1) % strip.numPixels();
  }
  
  return NULL;
}

void StateSad::exit()
{
  Serial.println("<<<<<<<<<<<<< StateSad.exit()");
}


