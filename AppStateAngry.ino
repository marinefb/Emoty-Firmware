// State class
//
// Pierre Rossel   2024-04-26  Initial version

void StateAngry::enter()
{
  Serial.println(">>>>>>>>>>>>> StateAngry.enter()");
  strip.clear();
  strip.show();
}

State *StateAngry::loop()
{
  // blink the strip in a happy pattern
  static unsigned long lastTime = 0;  
  unsigned long currentTime = millis();
  if (currentTime - lastTime > 500)
  {
    lastTime = currentTime;
    for (int i = 0; i < strip.numPixels(); i++)
    {
      int brightness = 128 + 127 * sin(2 * PI * i / strip.numPixels() + 2 * PI * currentTime / 500);
      strip.setPixelColor(i, strip.Color(brightness, brightness / 2, brightness / 2));
    }
    strip.show();
  }

  return NULL;
}

void StateAngry::exit()
{
  Serial.println("<<<<<<<<<<<<< StateAngry.exit()");
}