


// *** COSAS DE LOS LEDS ***

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(struct CRGB *bloque, int Pixel, byte red, byte green, byte blue) {

 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   bloque[Pixel].r = red;
   bloque[Pixel].g = green;
   bloque[Pixel].b = blue;
 #endif
}

void setAll(struct CRGB *bloque, byte red, byte green, byte blue) {
  for(int i = 0; i < bloque_1_leds; i++ ) {
    setPixel(bloque, i, red, green, blue); 
  }
  showStrip();
}
