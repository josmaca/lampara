#include "FastLED.h"
#include "zorro.h"

bloque getLedsByPosition(int bloque, struct mapa *zorromapa)
{
  return zorromapa->bloques[bloque];  
}

void configura_mapa(struct mapa *zorromapa, bool aleatorio)
{

  int mapa_color = 0;
  if (aleatorio == true) {
    mapa_color = random(0,4);
  }
  
  color rojo;
  color blanco;
  color naranja;

  switch (mapa_color) {
    case 0:
      rojo.r = 25;
      rojo.g = 0;
      rojo.b = 0;      
      blanco.r = 25;
      blanco.g = 25;
      blanco.b = 25;      
      naranja.r = 25;
      naranja.g = 13;
      naranja.b = 0;
      break;
    case 1:
      rojo.r = 0;
      rojo.g = 25;
      rojo.b = 25;      
      blanco.r = 25;
      blanco.g = 25;
      blanco.b = 25;      
      naranja.r = 0;
      naranja.g = 13;
      naranja.b = 25;
      break;
    case 2:
      rojo.r = 25;
      rojo.g = 0;
      rojo.b = 0;      
      blanco.r = 25;
      blanco.g = 0;
      blanco.b = 0;      
      naranja.r = 25;
      naranja.g = 0;
      naranja.b = 0;
      break;
    case 3:
      rojo.r = 0;
      rojo.g = 0;
      rojo.b = 25;      
      blanco.r = 0;
      blanco.g = 0;
      blanco.b = 25;      
      naranja.r = 0;
      naranja.g = 0;
      naranja.b = 25;
      break;
    default:
      rojo.r = 25;
      rojo.g = 0;
      rojo.b = 0;      
      blanco.r = 25;
      blanco.g = 25;
      blanco.b = 25;      
      naranja.r = 25;
      naranja.g = 13;
      naranja.b = 0;
  }
  

  //abajo izquierda 12
  bloque lb1;
  lb1.puerto = 1;
  lb1.bloque = 1;

  lb1.abajo.cantidad_leds = 3;
  lb1.abajo.colordef = blanco;
  lb1.abajo.led = 15;
  
  lb1.derecha.cantidad_leds = 4;
  lb1.derecha.colordef = blanco;
  lb1.derecha.led = 0;
  
  lb1.arriba.cantidad_leds = 3;
  lb1.arriba.colordef = blanco;
  lb1.arriba.led = 4;

  lb1.izquierda.cantidad_leds = 8;
  lb1.izquierda.colordef = rojo;
  lb1.izquierda.led = 7;
  
  zorromapa->bloques[0] = lb1;

  //abajo derecha 13
  bloque lb2;
  lb2.puerto = 1;
  lb2.bloque = 2;

  lb2.abajo.cantidad_leds = 3;
  lb2.abajo.colordef = blanco;
  lb2.abajo.led = 11;
  
  lb2.derecha.cantidad_leds = 8;
  lb2.derecha.colordef = rojo;
  lb2.derecha.led = 3;
  
  lb2.arriba.cantidad_leds = 3;
  lb2.arriba.colordef = blanco;
  lb2.arriba.led = 0;
  
  lb2.izquierda.cantidad_leds = 4;
  lb2.izquierda.colordef = blanco;
  lb2.izquierda.led = 14;
  
  zorromapa->bloques[1] = lb2;

  // ojo izq abajo izq 8
  bloque lb3;
  lb3.puerto = 1;
  lb3.bloque = 3;

  lb3.abajo.cantidad_leds = 7;
  lb3.abajo.colordef = rojo;
  lb3.abajo.led = 0;
  
  lb3.derecha.cantidad_leds = 1;
  lb3.derecha.colordef = blanco;
  lb3.derecha.led = 14;
  
  lb3.arriba.cantidad_leds = 6;
  lb3.arriba.colordef = blanco;
  lb3.arriba.led = 8;
  
  lb3.izquierda.cantidad_leds = 1;
  lb3.izquierda.colordef = blanco;
  lb3.izquierda.led = 7;
  
  zorromapa->bloques[2] = lb3;

  // ojo izq abajo der 9
  bloque lb4;
  lb4.puerto = 1;
  lb4.bloque = 4;

  lb4.abajo.cantidad_leds = 1;
  lb4.abajo.colordef = blanco;
  lb4.abajo.led = 10;
  
  lb4.derecha.cantidad_leds = 4;
  lb4.derecha.colordef = naranja;
  lb4.derecha.led = 6;
  
  lb4.arriba.cantidad_leds = 1;
  lb4.arriba.colordef = naranja;
  lb4.arriba.led = 5;
  
  lb4.izquierda.cantidad_leds = 5;
  lb4.izquierda.colordef = blanco;
  lb4.izquierda.led = 0;
  
  zorromapa->bloques[3] = lb4;

  // ojo der abajo izq 10
  bloque lb5;
  lb5.puerto = 1;
  lb5.bloque = 5;

  lb5.abajo.cantidad_leds = 1;
  lb5.abajo.colordef = blanco;
  lb5.abajo.led = 10;
  
  lb5.derecha.cantidad_leds = 5;
  lb5.derecha.colordef = blanco;
  lb5.derecha.led = 0;
  
  lb5.arriba.cantidad_leds = 1;
  lb5.arriba.colordef = naranja;
  lb5.arriba.led = 5;
  
  lb5.izquierda.cantidad_leds = 4;
  lb5.izquierda.colordef = naranja;
  lb5.izquierda.led = 6;
  
  zorromapa->bloques[4] = lb5;

  // ojo der abajo der 11
  bloque lb6;
  lb6.puerto = 1;
  lb6.bloque = 6;

  lb6.abajo.cantidad_leds = 7;
  lb6.abajo.colordef = rojo;
  lb6.abajo.led = 0;
  
  lb6.derecha.cantidad_leds = 1;
  lb6.derecha.colordef = blanco;
  lb6.derecha.led = 7;
  
  lb6.arriba.cantidad_leds = 6;
  lb6.arriba.colordef = blanco;
  lb6.arriba.led = 8;
  
  lb6.izquierda.cantidad_leds = 1;
  lb6.izquierda.colordef = blanco;
  lb6.izquierda.led = 14;
  
  zorromapa->bloques[5] = lb6;

  // ojo der arriba der 
  bloque lb7;
  lb7.puerto = 1;
  lb7.bloque = 7;

  lb7.abajo.cantidad_leds = 4;
  lb7.abajo.colordef = blanco;
  lb7.abajo.led = 11;
  
  lb7.derecha.cantidad_leds = 5;
  lb7.derecha.colordef = rojo;
  lb7.derecha.led = 6;

  lb7.arriba.cantidad_leds = 1;
  lb7.arriba.colordef = blanco;
  lb7.arriba.led = 5;
  
  lb7.izquierda.cantidad_leds = 5;
  lb7.izquierda.colordef = blanco;
  lb7.izquierda.led = 0;
    
  zorromapa->bloques[6] = lb7;

  // ojo izq arriba izr
  bloque lb8;
  lb8.puerto = 1;
  lb8.bloque = 8;

  lb8.abajo.cantidad_leds = 4;
  lb8.abajo.colordef = blanco;
  lb8.abajo.led = 11;
  
  lb8.derecha.cantidad_leds = 5;
  lb8.derecha.colordef = blanco;
  lb8.derecha.led = 0;

  lb8.arriba.cantidad_leds = 1;
  lb8.arriba.colordef = blanco;
  lb8.arriba.led = 5;
  
  lb8.izquierda.cantidad_leds = 5;
  lb8.izquierda.colordef = rojo;
  lb8.izquierda.led = 6;
    
  zorromapa->bloques[7] = lb8;

  // ojo derecho arriba izquierd
  bloque lb9;
  lb9.puerto = 1;
  lb9.bloque = 9;

  lb9.abajo.cantidad_leds = 2;
  lb9.abajo.colordef = blanco;
  lb9.abajo.led = 15;
  
  lb9.derecha.cantidad_leds = 6;
  lb9.derecha.colordef = blanco;
  lb9.derecha.led = 0;

  lb9.arriba.cantidad_leds = 3;
  lb9.arriba.colordef = naranja;
  lb9.arriba.led = 6;
  
  lb9.izquierda.cantidad_leds = 6;
  lb9.izquierda.colordef = naranja;
  lb9.izquierda.led = 9;
    
  zorromapa->bloques[8] = lb9;

  // ojo izquierdo arriba derecha
  bloque lb10;
  lb10.puerto = 1;
  lb10.bloque = 10;

  lb10.abajo.cantidad_leds = 2;
  lb10.abajo.colordef = blanco;
  lb10.abajo.led = 15;
  
  lb10.derecha.cantidad_leds = 6;
  lb10.derecha.colordef = naranja;
  lb10.derecha.led = 0;

  lb10.arriba.cantidad_leds = 3;
  lb10.arriba.colordef = naranja;
  lb10.arriba.led = 6;
  
  lb10.izquierda.cantidad_leds = 6;
  lb10.izquierda.colordef = blanco;
  lb10.izquierda.led = 9;
    
  zorromapa->bloques[9] = lb10;

  // oreja dercha
  bloque lb11;
  lb11.puerto = 1;
  lb11.bloque = 11;

  lb11.abajo.cantidad_leds = 3;
  lb11.abajo.colordef = naranja;
  lb11.abajo.led = 11;
  
  lb11.derecha.cantidad_leds = 5;
  lb11.derecha.colordef = naranja;
  lb11.derecha.led = 6;

  lb11.arriba.cantidad_leds = 1;
  lb11.arriba.colordef = rojo;
  lb11.arriba.led = 5;
  
  lb11.izquierda.cantidad_leds = 5;
  lb11.izquierda.colordef = naranja;
  lb11.izquierda.led = 0;
    
  zorromapa->bloques[10] = lb11;

  // oreja izquierda
  bloque lb12;
  lb12.puerto = 1;
  lb12.bloque = 12;

  lb12.abajo.cantidad_leds = 3;
  lb12.abajo.colordef = naranja;
  lb12.abajo.led = 11;
  
  lb12.derecha.cantidad_leds = 5;
  lb12.derecha.colordef = naranja;
  lb12.derecha.led = 6;

  lb12.arriba.cantidad_leds = 1;
  lb12.arriba.colordef = rojo;
  lb12.arriba.led = 5;
  
  lb12.izquierda.cantidad_leds = 5;
  lb12.izquierda.colordef = naranja;
  lb12.izquierda.led = 0;
    
  zorromapa->bloques[11] = lb12;

  // entrecejo
  bloque lb13;
  lb13.puerto = 1;
  lb13.bloque = 13;

  lb13.abajo.cantidad_leds = 1;
  lb13.abajo.colordef = naranja;
  lb13.abajo.led = 13;
  
  lb13.derecha.cantidad_leds = 5;
  lb13.derecha.colordef = naranja;
  lb13.derecha.led = 8;

  lb13.arriba.cantidad_leds = 3;
  lb13.arriba.colordef = naranja;
  lb13.arriba.led = 5;
  
  lb13.izquierda.cantidad_leds = 5;
  lb13.izquierda.colordef = naranja;
  lb13.izquierda.led = 0;
    
  zorromapa->bloques[12] = lb13;

}
