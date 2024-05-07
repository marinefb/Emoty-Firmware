// State class
//
// Pierre Rossel   2024-04-26  Initial version

void StateIdle::enter()
{
  Serial.println(">>>>>>>>>>>>> StateIdle.enter()");
  strip.clear();
  strip.show();

}

State *StateIdle::loop()
{
  // pulse the strip in sinusoidal pattern, with a period of 5 seconds
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastTime > 50)
  {
    lastTime = currentTime;
    for (int i = 0; i < strip.numPixels(); i++)
    {
      int brightness = 128 + 127 * sin(2 * PI * i / strip.numPixels() + 2 * PI * currentTime / 5000);
      strip.setPixelColor(i, strip.Color(brightness, 0, 0));
    }
    strip.show();
  }

  return NULL;
}

void StateIdle::exit()
{
  Serial.println("<<<<<<<<<<<<< StateIdle.exit()");
}


