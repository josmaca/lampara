#ifndef ZORRO_H
#define ZORRO_H

#include <Arduino.h>

struct color {
  int r;
  int g;
  int b;  
};

struct linea_bloque
{
    int cantidad_leds;
    color colordef;
    int led;
};

struct bloque
{
  int puerto;
  int bloque;
  linea_bloque arriba;
  linea_bloque abajo;
  linea_bloque derecha;
  linea_bloque izquierda;
};

struct mapa
{
  bloque bloques[35];
};

bloque getLedsByPosition(int bloque, struct mapa *zorromap);

void configura_mapa(struct mapa *zorromap, bool aleatorio);

#endif
