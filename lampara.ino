
#include "FastLED.h"
#include "zorro.h"

boolean iniciado = false;
volatile boolean encendido = false;
int intervalo_cambio = 10;
int waiting_time = intervalo_cambio;

#define bloque_1_leds  18
CRGB leds_1[bloque_1_leds];
#define PIN_1 12

#define bloque_2_leds  18
CRGB leds_2[bloque_2_leds];
#define PIN_2 11

#define bloque_3_leds  18
CRGB leds_3[bloque_3_leds];
#define PIN_3 10

#define bloque_4_leds  18
CRGB leds_4[bloque_4_leds];
#define PIN_4 9

#define bloque_5_leds  18
CRGB leds_5[bloque_5_leds];
#define PIN_5 8

#define bloque_6_leds  18
CRGB leds_6[bloque_6_leds];
#define PIN_6 7

#define bloque_7_leds  18
CRGB leds_7[bloque_7_leds];
#define PIN_7 6

#define bloque_8_leds  18
CRGB leds_8[bloque_8_leds];
#define PIN_8 5

#define bloque_9_leds  18
CRGB leds_9[bloque_9_leds];
#define PIN_9 4

#define bloque_10_leds  18
CRGB leds_10[bloque_10_leds];
#define PIN_10 16

#define bloque_11_leds  18
CRGB leds_11[bloque_11_leds];
#define PIN_11 13

#define bloque_12_leds  18
CRGB leds_12[bloque_12_leds];
#define PIN_12 14

#define bloque_13_leds  18
CRGB leds_13[bloque_13_leds];
#define PIN_13 15


#define LedRojo 3

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2811, PIN_1, GRB>(leds_1, bloque_1_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_2, GRB>(leds_2, bloque_2_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_3, GRB>(leds_3, bloque_3_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_4, GRB>(leds_4, bloque_4_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_5, GRB>(leds_5, bloque_5_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_6, GRB>(leds_6, bloque_6_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_7, GRB>(leds_7, bloque_7_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_8, GRB>(leds_8, bloque_8_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_9, GRB>(leds_9, bloque_9_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_10, GRB>(leds_10, bloque_10_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_11, GRB>(leds_11, bloque_11_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_12, GRB>(leds_12, bloque_12_leds).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, PIN_13, GRB>(leds_13, bloque_13_leds).setCorrection( TypicalLEDStrip );
  attachInterrupt(digitalPinToInterrupt(2), interruptor, RISING);
  //randomSeed(analogRead(0));
}

void loop() {
  if (encendido) {
    mapa zorromapa;
    if (!iniciado) {
      waiting_time = intervalo_cambio;
      apaga_leds();
      configura_mapa(&zorromapa, false);
      animacion_inicio(&zorromapa);
      iniciado = true;
      delay(2000);
    } else {
      //waiting_time --;
      //if (waiting_time <= 0) {
        //waiting_time = intervalo_cambio;
        //configura_mapa(&zorromapa, true);
        //animacion_intermedia(&zorromapa);
      //}
    }
    
  } else {
    apaga_leds();
    apaga_ojos();
  }
}

void apaga_leds() {
    setAll(leds_1,0,0,0);
    setAll(leds_2,0,0,0);
    setAll(leds_3,0,0,0);
    setAll(leds_4,0,0,0);
    setAll(leds_5,0,0,0);
    setAll(leds_6,0,0,0);
    setAll(leds_7,0,0,0);
    setAll(leds_8,0,0,0);
    setAll(leds_9,0,0,0);
    setAll(leds_10,0,0,0);
    setAll(leds_11,0,0,0);
    setAll(leds_12,0,0,0);
    setAll(leds_13,0,0,0);
    showStrip();
}

void animacion_inicio(struct mapa *zorromapa) {
  enciende_ojos();
  enciende_leds(zorromapa);
  delay(300);
  enciende_leds_segunda(zorromapa);
  delay(300);
  enciende_leds_tercera(zorromapa);
  delay(300);
  enciende_leds_cuarta(zorromapa);
}

void animacion_intermedia(struct mapa *zorromapa) {
  apaga_leds();
  enciende_leds(zorromapa);
  delay(300);
  enciende_leds_segunda(zorromapa);
  delay(300);
  enciende_leds_tercera(zorromapa);
  delay(300);
  enciende_leds_cuarta(zorromapa);
}

void enciende_ojos() {
    for(int k = 0; k < 256; k++) { 
        analogWrite(LedRojo,k);
        delay(5);
    }
    for(int k = 255; k > 20; k--) { 
        analogWrite(LedRojo,k);
        delay(5);
    }
}

void apaga_ojos() {
  analogWrite(LedRojo,0);
}

void enciende_leds(struct mapa *zorromapa) {

  bloque cuadro = getLedsByPosition(0, zorromapa);  
  enciende_bloque(cuadro);
  bloque cuadro1 =  getLedsByPosition(1, zorromapa);  
  enciende_bloque(cuadro1);

  showStrip();
}

void enciende_leds_segunda (struct mapa *zorromapa) {
  bloque cuadro2 = getLedsByPosition(2, zorromapa);  
  enciende_bloque(cuadro2);
  bloque cuadro3 =  getLedsByPosition(3, zorromapa);  
  enciende_bloque(cuadro3);
  bloque cuadro4 =  getLedsByPosition(4, zorromapa);  
  enciende_bloque(cuadro4);
  bloque cuadro5 =  getLedsByPosition(5, zorromapa);  
  enciende_bloque(cuadro5);

  showStrip();
}

void enciende_leds_tercera (struct mapa *zorromapa) {
  bloque cuadro6 =  getLedsByPosition(6, zorromapa);  
  enciende_bloque(cuadro6);
  bloque cuadro7 =  getLedsByPosition(7, zorromapa);  
  enciende_bloque(cuadro7);
  bloque cuadro8 =  getLedsByPosition(8, zorromapa);  
  enciende_bloque(cuadro8);
  bloque cuadro9 =  getLedsByPosition(9, zorromapa);  
  enciende_bloque(cuadro9);
  bloque cuadro12 =  getLedsByPosition(12, zorromapa);  
  enciende_bloque(cuadro12);

  showStrip();
}

void enciende_leds_cuarta (struct mapa *zorromapa) {
  bloque cuadro11 =  getLedsByPosition(11, zorromapa);  
  enciende_bloque(cuadro11);
  bloque cuadro10 =  getLedsByPosition(10, zorromapa);  
  enciende_bloque(cuadro10);

  showStrip();
}

void enciende_bloque(bloque cuadro) {  
  enciende_linea(cuadro.arriba, cuadro.bloque);
  enciende_linea(cuadro.izquierda, cuadro.bloque);
  enciende_linea(cuadro.abajo, cuadro.bloque);
  enciende_linea(cuadro.derecha, cuadro.bloque);
}

void enciende_linea(linea_bloque linea, int puerto)
{
  switch(puerto) {
    case 1:
      for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_1, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
      }
    break;
    case 2:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_2, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 3:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_3, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 4:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_4, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 5:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_5, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 6:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_6, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 7:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_7, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 8:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_8, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 9:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_9, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 10:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_10, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 11:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_11, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 12:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_12, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
    case 13:
    for (int i = 0; i < linea.cantidad_leds; i++) {
        setPixel(leds_13, linea.led+i, linea.colordef.r, linea.colordef.g, linea.colordef.b);
    }
    break;
  }
}

void muestraestructura(bloque tiraled)
{
    linea_bloque linea = tiraled.arriba;
    Serial.println("Cantidad de leds");
    Serial.println(linea.cantidad_leds);
    String Color = "Color ";
    String Separador = ",";
    String Strcolor = Color + linea.colordef.r + Separador +  linea.colordef.g + Separador + linea.colordef.b;
    Serial.println(Strcolor);
    for (int i = 0; i < linea.cantidad_leds; i++) {
        Serial.println(linea.led+i);
    }

    linea = tiraled.izquierda;
    Serial.println("Cantidad de leds");
    Serial.println(linea.cantidad_leds);
    Strcolor = Color + linea.colordef.r + Separador +  linea.colordef.g + Separador + linea.colordef.b;
    Serial.println(Strcolor);
    for (int i = 0; i < linea.cantidad_leds; i++) {
        Serial.println(linea.led+i);
    }

    linea = tiraled.abajo;
    Serial.println("Cantidad de leds");
    Serial.println(linea.cantidad_leds);
    Strcolor = Color + linea.colordef.r + Separador +  linea.colordef.g + Separador + linea.colordef.b;
    Serial.println(Strcolor);
    for (int i = 0; i < linea.cantidad_leds; i++) {
        Serial.println(linea.led+i);
    }

    linea = tiraled.derecha;
    Serial.println("Cantidad de leds");
    Serial.println(linea.cantidad_leds);
    Strcolor = Color + linea.colordef.r + Separador +  linea.colordef.g + Separador + linea.colordef.b;
    Serial.println(Strcolor);
    for (int i = 0; i < linea.cantidad_leds; i++) {
        Serial.println(linea.led+i);
    }

}

void interruptor()
{
  encendido = !encendido;
  iniciado = false;
}
