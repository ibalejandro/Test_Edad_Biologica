//Ejemplo 7.2  Instrucciones básicas.

//Encender y apagar un led  conectado a RB0 cada segundo.


#INCLUDE <16f886.h>
#USE     DELAY(CLOCK=4000000)
#FUSES   XT,NOPROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE  LED PORTB,0
#BYTE    PORTB= 6

VOID MAIN()
{
   SET_TRIS_B(0B11111110);       // Configura el puerto B
   
   WHILE(TRUE)                   // Haga por siempre
   { 
      BIT_SET(LED);              // Active el led
      DELAY_MS(1000);            // Retardo de 1 segundo
      BIT_CLEAR(LED);            // Apagar el led
      DELAY_MS(1000);            // Retardo de 1 segundo
   }
}

